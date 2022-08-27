/* $Id$ */

#ifndef GNOME_RADIO_GUI_H
#define GNOME_RADIO_GUI_H

GtkWidget *create_gnome_radio_app(void);

GtkWidget *create_listeners_selector(char *selected_listener_uri,
				     char *filename);
GtkWidget *create_stations_selector(char *selected_station_uri,
				    char *filename);
GtkWidget *create_streams_selector(char *selected_streams_uri,
				   char *filename);
GtkWidget *create_search_selector(void);

GtkWidget *create_new_station_selector(char *location);

GtkWidget *create_gnome_radio_app(void);

#endif /* GNOME_RADIO_GUI_H */
