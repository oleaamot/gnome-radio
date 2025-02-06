/* $Id$ */

#ifndef GTK_INTERNET_RADIO_LOCATOR_GUI_H
#define GTK_INTERNET_RADIO_LOCATOR_GUI_H

GtkWidget *create_gtk_internet_radio_locator_app(void);

GtkWidget *create_listeners_selector(char *selected_listener_uri,
				     char *filename);
GtkWidget *create_stations_selector(char *selected_station_uri,
				    char *filename);
GtkWidget *create_streams_selector(char *selected_streams_uri,
				   char *filename);
GtkWidget *create_search_selector(void);

GtkWidget *create_new_station_selector(char *location);

GtkWidget *create_gtk_internet_radio_locator_app(void);

#endif /* GTK_INTERNET_RADIO_LOCATOR_GUI_H */
