/*
 * rofi
 *
 * MIT/X11 License
 * Copyright © 2013-2022 Qball Cow <qball@gmpclient.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef THEME_H
#define THEME_H
#include "rofi-types.h"
#include <cairo.h>
#include <glib.h>
#include <widgets/widget.h>

/**
 * Global pointer to the current active theme.
 */
extern ThemeWidget *rofi_theme;

/**
 * Used to store theme.
 */
extern ThemeWidget *rofi_theme;

/**
 * Used to store config options.
 */
extern ThemeWidget *rofi_configuration;

/**
 * @param base Handle to the current level in the theme.
 * @param name Name of the new element.
 *
 * Create a new element in the theme structure.
 *
 * @returns handle to the new entry.
 */
ThemeWidget *rofi_theme_find_or_create_name(ThemeWidget *base,
                                            const char *name);

/**
 * @param widget The widget handle.
 *
 * Print out the widget to the commandline.
 */
void rofi_theme_print(ThemeWidget *widget);

/**
 * @param widget The widget handle.
 * @param index The indenting index.
 *
 * Print out the widget to the commandline indented by index.
 */
void rofi_theme_print_index(ThemeWidget *widget, int index);

/**
 * @param type The type of the property to create.
 *
 * Create a theme property of type.
 *
 * @returns a new property.
 */
Property *rofi_theme_property_create(PropertyType type);

/**
 * @param p The property to free.
 *
 * Free the content of the property.
 */
void rofi_theme_property_free(Property *p);

/**
 * @param p The property to free.
 * @param data User data (unused)
 *
 * Make a newly allocted copy of the property.
 *
 * @returns a copy of p
 */
Property *rofi_theme_property_copy(const Property *p, G_GNUC_UNUSED void *);
/**
 * @param widget
 *
 * Free the widget and alll children.
 */
void rofi_theme_free(ThemeWidget *widget);

/**
 * @param file filename to parse.
 *
 * Parse the input theme file.
 *
 * @returns returns TRUE when error.
 */
gboolean rofi_theme_parse_file(const char *file);

/**
 * @param string to parse.
 *
 * Parse the input string in addition to theme file.
 *
 * @returns returns TRUE when error.
 */
gboolean rofi_theme_parse_string(const char *string);

/**
 * @param widget The widget handle.
 * @param table HashTable containing properties set.
 *
 * Merge properties with widgets current property.
 */
void rofi_theme_widget_add_properties(ThemeWidget *widget, GHashTable *table);

/**
 * Public API
 */

/**
 * @param widget   The widget to query
 * @param property The property to query.
 * @param def      The default value.
 *
 * Obtain the distance of the widget.
 *
 * @returns The distance value of this property for this widget.
 */
RofiDistance rofi_theme_get_distance(const widget *widget, const char *property,
                                     int def);

/**
 * @param widget   The widget to query
 * @param property The property to query.
 * @param def      The default value.
 *
 * Obtain the integer of the widget.
 *
 * @returns The integer value of this property for this widget.
 */
int rofi_theme_get_integer(const widget *widget, const char *property, int def);

/**
 * @param widget   The widget to query
 * @param property The property to query.
 * @param def      The default value.
 *
 * Obtain the position of the widget.
 *
 * @returns The position value of this property for this widget.
 */
int rofi_theme_get_position(const widget *widget, const char *property,
                            int def);

/**
 * @param widget   The widget to query
 * @param property The property to query.
 * @param def      The default value.
 *
 * Obtain the boolean of the widget.
 *
 * @returns The boolean value of this property for this widget.
 */
int rofi_theme_get_boolean(const widget *widget, const char *property, int def);

/**
 * @param widget   The widget to query
 * @param property The property to query.
 * @param def      The default value.
 *
 * Obtain the orientation indicated by %property of the widget.
 *
 * @returns The orientation of this property for this widget or %def not found.
 */
RofiOrientation rofi_theme_get_orientation(const widget *widget,
                                           const char *property,
                                           RofiOrientation def);

/**
 * @param widget   The widget to query
 * @param property The property to query.
 * @param def      The default value.
 *
 * Obtain the cursor indicated by %property of the widget.
 *
 * @returns The cursor for this widget or %def if not found.
 */
RofiCursorType rofi_theme_get_cursor_type(const widget *widget,
                                          const char *property,
                                          RofiCursorType def);
/**
 * @param widget   The widget to query
 * @param property The property to query.
 * @param def      The default value.
 *
 * Obtain the string of the widget.
 *
 * @returns The string value of this property for this widget.
 */
const char *rofi_theme_get_string(const widget *widget, const char *property,
                                  const char *def);

/**
 * @param widget   The widget to query
 * @param property The property to query.
 * @param def      The default value.
 *
 * Obtain the double of the widget.
 *
 * @returns The double value of this property for this widget.
 */
double rofi_theme_get_double(const widget *widget, const char *property,
                             double def);

/**
 * @param widget   The widget to query
 * @param property The property to query.
 * @param d        The drawable to apply color.
 *
 * Obtain the color of the widget and applies this to the drawable d.
 *
 */
void rofi_theme_get_color(const widget *widget, const char *property,
                          cairo_t *d);

/**
 * @param widget   The widget to query
 * @param property The property to query.
 * @param d        The drawable to apply color.
 *
 * Obtain the image of the widget and applies this to the drawable d.
 *
 * @return true if image is set.
 */
gboolean rofi_theme_get_image(const widget *widget, const char *property,
                              cairo_t *d);

/**
 * @param widget   The widget to query
 * @param property The property to query.
 *
 * Check if a rofi theme has a property set.
 *
 */
gboolean rofi_theme_has_property(const widget *widget, const char *property);

/**
 * @param widget   The widget to query
 * @param property The property to query.
 * @param pad      The default value.
 *
 * Obtain the padding of the widget.
 *
 * @returns The padding of this property for this widget.
 */
RofiPadding rofi_theme_get_padding(const widget *widget, const char *property,
                                   RofiPadding pad);

/**
 * @param widget   The widget to query
 * @param property The property to query.
 * @param th The default value.
 *
 * Obtain the highlight .
 *
 * @returns The highlight of this property for this widget.
 */
RofiHighlightColorStyle rofi_theme_get_highlight(widget *widget,
                                                 const char *property,
                                                 RofiHighlightColorStyle th);

/**
 * @param d The distance handle.
 * @param ori The orientation.
 *
 * Convert RofiDistance into pixels.
 * @returns the number of pixels this distance represents.
 */
int distance_get_pixel(RofiDistance d, RofiOrientation ori);
/**
 * @param d The distance handle.
 * @param draw The cairo drawable.
 *
 * Set linestyle.
 */
void distance_get_linestyle(RofiDistance d, cairo_t *draw);

/**
 * Low-level functions.
 * These can be used by non-widgets to obtain values.
 */
/**
 * @param name The name of the element to find.
 * @param state The state of the element.
 * @param exact If the match should be exact, or parent can be included.
 *
 * Find the theme element. If not exact, the closest specified element is
 * returned.
 *
 * @returns the ThemeWidget if found, otherwise NULL.
 */
ThemeWidget *rofi_theme_find_widget(const char *name, const char *state,
                                    gboolean exact);

/**
 * Reset the current theme.
 */
void rofi_theme_reset(void);

/**
 * @param file File name to prepare.
 * @param parent_file Filename of parent file.
 *
 * Tries to find full path relative to parent file.
 *
 * @returns full path to file.
 */
char *rofi_theme_parse_prepare_file(const char *file, const char *parent_file);

/**
 * Process conditionals.
 */
void rofi_theme_parse_process_conditionals(void);

/**
 * Process links.
 */
void rofi_theme_parse_process_links(void);

/**
 * @param parent target theme tree
 * @param child source theme three
 *
 * Merge all the settings from child into parent.
 */
void rofi_theme_parse_merge_widgets(ThemeWidget *parent, ThemeWidget *child);

/**
 * @param type the media type to parse.
 *
 * Returns the media type described by type.
 */
ThemeMediaType rofi_theme_parse_media_type(const char *type);

/**
 * @param distance The distance object to copy.
 *
 * @returns a copy of the distance.
 */
RofiDistance rofi_theme_property_copy_distance(RofiDistance const distance);

/**
 * @param filename The file to validate.
 *
 * @returns the program exit code.
 */
int rofi_theme_rasi_validate(const char *filename);

/**
 *
 * Free memory.
 */
void rofi_theme_free_parsed_files(void);

/**
 * @param is_term Indicate if printed to terminal.
 *
 * Print the list of parsed config files.
 */
void rofi_theme_print_parsed_files(int is_term);

/**
 * @param widget The widget handle.
 * @param property The property to query.
 *
 * Returns a list of allocated RofiDistance objects that should be
 * freed.
 *
 * @returns a GList of  RofiDistance objects.
 */
GList *rofi_theme_get_list_distance(const widget *widget, const char *property);

/**
 * @param widget The widget handle.
 * @param property The property to query.
 *
 * Returns a list of allocated strings othat should be
 * freed.
 *
 * @returns a GList of strings.
 */
GList *rofi_theme_get_list_strings(const widget *widget, const char *property);
#endif
