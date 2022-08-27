/* $Id$
 *
 * GNOME Radio
 *
 * Copyright (C) 2021  Aamot Software
 *
 * Author: Ole Aamot <ole@gnome.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef GNOME_RADIO_H
#define GNOME_RADIO_H 1

#include <config.h>
#include <glib.h>
#include "gnome-radio-listener.h"
#include "gnome-radio-program.h"
#include "gnome-radio-runners.h"
#include "gnome-radio-streams.h"
#include "gnome-radio-station.h"

typedef enum {
	GNOME_RADIO_CHANNELS_MONO = 0x0001,
	GNOME_RADIO_CHANNELS_STEREO = 0x0002,
	GNOME_RADIO_CHANNELS_5_1 = 0x0005,
	GNOME_RADIO_CHANNELS_NONE = 0xffff
} GNOMERadioChannels;

typedef enum {
	GNOME_RADIO_STREAM_SHOUTCAST = 0x0001,
	GNOME_RADIO_STREAM_OGG = 0x0002,
	GNOME_RADIO_STREAM_AAC = 0x0003
} GNOMERadioStreamType;

typedef enum {
	GNOME_RADIO_STREAM_PLAYER = 0x0001,
	GNOME_RADIO_STREAM_RECORD = 0x0002
} GNOMERadioHelperType;

#if GNOME_RADIO_DEBUG == 0
#define GNOME_RADIO_DEBUG_MSG(x...) g_message(x)
#else
#define GNOME_RADIO_DEBUG_MSG(x...)
#endif

#define GNOME_RADIO_RECORD_TRUE 1
#define GNOME_RADIO_RECORD_FALSE 0
#define GNOME_RADIO_PLAYER_TRUE 1
#define GNOME_RADIO_PLAYER_FALSE 0

gchar *str_channels (GNOMERadioChannels type);

void show_error(gchar * msg);
void statusbar_send_msg(const char *a, ...);

void appbar_send_msg(const char *a, ...);
gint gnome_radio_archive_new(gchar *title, gchar *file, gchar *codec);

/* Fetcher for the channels */

void on_search_button_clicked(GtkWidget * button, gpointer user_data);
void on_listen_button_clicked(GtkWidget * button, gpointer user_data);
void on_record_button_clicked(GtkWidget * button, gpointer user_data);
void on_stop_button_clicked(GtkWidget *a, gpointer user_data);
void on_next_station_click(GtkWidget *, gpointer user_data);
void on_new_station_clicked(GtkWidget *a, gpointer user_data);
void on_new_station_selector_changed(GtkWidget *a, gpointer user_data);
void on_previous_station_click(GtkWidget *, gpointer user_data);
void on_listeners_selector_button_clicked(GtkWidget *, gpointer user_data);
void on_listeners_selector_changed(GtkWidget * a, gpointer user_data);
void on_programs_selector_button_clicked(GtkWidget *, gpointer user_data);
void on_programs_selector_changed(GtkWidget * a, gpointer user_data);
void on_stations_selector_button_clicked(GtkWidget *, gpointer user_data);
void on_stations_selector_changed(GtkWidget * a, gpointer user_data);
void on_streams_selector_button_clicked(GtkWidget *, gpointer user_data);
void on_streams_selector_changed(GtkWidget * a, gpointer user_data);
void quit_app(GtkWidget *, gpointer user_data);
void about_app(GtkWidget *, gpointer user_data);
void about_listener(GtkWidget *, gpointer user_data);
void about_station(GSimpleAction *simple, GVariant *parameter, gpointer user_data);
void about_program(GSimpleAction *simple, GVariant *parameter, gpointer user_data);

gboolean on_search_matches(GtkEntryCompletion *widget,
			   GtkTreeModel *model,
			   GtkTreeIter *iter,
			   gpointer user_data);

struct _GNOMERadioInfo {
	GtkImage *pixmap;
	GtkProgressBar *progress;
	GSettings *settings;
	GtkAboutDialog *window;
	GtkStatusbar *statusbar;
	GtkWidget *player_window;
        GtkWidget *about_station;
	gchar *selected_archive_file;
	GNOMERadioListenerInfo *selected_listener;
	gchar *selected_listener_uri;
	gchar *selected_listener_name;
	gchar *selected_listener_location;
	gchar *selected_listener_band;
	gchar *selected_listener_description;
	GNOMERadioProgramInfo *selected_program;
	gchar *selected_program_uri;
	gchar *selected_program_name;
	gchar *selected_program_location;
	gchar *selected_program_band;
	gchar *selected_program_description;
	GNOMERadioRunnersInfo *selected_runners;
	gint timeout_id;
	gint current_station_number;
	GNOMERadioStationInfo *previous_station;
	GNOMERadioStationInfo *selected_station;
	gchar *selected_station_uri;
	gchar *selected_station_name;
	gchar *selected_station_location;
	gchar *selected_station_band;
        gchar *selected_station_description;
	gchar *selected_station_website;
	gint selected_bitrate;
	GNOMERadioStreamsInfo *selected_streams;
	gchar *selected_streams_mime;
	gchar *selected_streams_uri;
	gchar *selected_streams_codec;
	gchar *selected_streams_samplerate;
	gchar *selected_streams_stations;
	gchar *selected_streams_bitrate;
	GNOMERadioChannels selected_streams_channels;
	gint selected_samplerate;
	GdkPixbuf *icon;
	gint player_status;
	GPid player_pid;
	GSubprocess *player_subprocess;
	GSubprocess *record_subprocess;
	GSubprocessLauncher *player_launcher;
	GSubprocessLauncher *record_launcher;
	gint record_status;
	GPid record_pid;
	gint station_count;
	gint stream_count;
	GMainLoop *player_loop;
	GMainLoop *record_loop;  
};

typedef struct _GNOMERadioInfo GNOMERadioInfo;

void about_station(GSimpleAction *simple, GVariant *parameter, gpointer user_data);

extern GNOMERadioInfo *gnome_radio;
extern GList *gnome_radio_listeners;
extern GList *gnome_radio_programs;
extern GList *gnome_radio_stations;
extern GList *gnome_radio_streams;

#endif /* GNOME_RADIO_H */
