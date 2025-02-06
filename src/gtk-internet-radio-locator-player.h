/* $Id$
 *
 * Internet Radio Locator for GTK 4
 *
 * Copyright (C) 2014, 2015, 2018, 2022  Aamot Software
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

#ifndef GTK_INTERNET_RADIO_LOCATOR_PLAYER_H
#define GTK_INTERNET_RADIO_LOCATOR_PLAYER_H

#include <gst/gst.h>
#include <gst/player/player.h>

typedef struct
{
  gchar **uris;
  guint num_uris;
  gint cur_idx;

  GstPlayer *player;
  GstState desired_state;

  gboolean repeat;

  GMainLoop *loop;
} GstPlay;

void play_uri (GstPlayer *player, const gchar * next_uri);

void gtk_internet_radio_locator_player_new (GstPlayer * player, const gchar * next_uri);

void gtk_internet_radio_locator_player_new (GstPlayer * player, const gchar * next_uri);

void gtk_internet_radio_locator_player_quit (GstPlayer *player);

void gtk_internet_radio_locator_player_pause (GstPlayer *player);

void gtk_internet_radio_locator_player_stop (GstPlayer *player);

static gdouble get_volume (GtkWidget *widget, GstPlay *play);

#endif /* GTK_INTERNET_RADIO_LOCATOR_PLAYER_H */
