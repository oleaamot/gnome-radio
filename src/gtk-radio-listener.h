/* $Id$
 *
 * Internet Radio Locator for GTK 4
 *
 * Copyright (C) 2014, 2018, 2022  Aamot Software
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

#ifndef GTK_RADIO_LISTENER_H
#define GTK_RADIO_LISTENER_H

#include <gtk/gtk.h>
#include <glib.h>
#include "gtk-radio.h"

typedef struct _GTKInternetRadioLocatorListenerInfo GTKInternetRadioLocatorListenerInfo;
typedef struct _GTKInternetRadioLocatorLocationInfo GTKInternetRadioLocatorLocationInfo;

struct _GTKInternetRadioLocatorListenerInfo {
	gchar *id;
	gchar *location;
	gchar *mail;
	gchar *name;
	gchar *pass;
	gchar *uri;
	gchar *band;
	gchar *description;
	GTKInternetRadioLocatorLocationInfo *locationinfo;
	GTKInternetRadioLocatorListenerInfo *next;
};

struct _GTKInternetRadioLocatorLocationInfo {
	gchar *name;
	gchar *link;
	gchar *glat;
	gchar *glon;
	gchar *grad;
	gchar *vote;
	gchar *rack;
};

GTKInternetRadioLocatorListenerInfo *gtk_radio_listener_load_from_file(GTKInternetRadioLocatorListenerInfo * head,
					       char *filename);
GTKInternetRadioLocatorListenerInfo *gtk_radio_listener_load_from_http(GTKInternetRadioLocatorListenerInfo * head,
					       gpointer data);

#endif /* GTK_RADIO_LISTENER_H */
