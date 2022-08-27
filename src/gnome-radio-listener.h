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

#ifndef GNOME_RADIO_LISTENER_H
#define GNOME_RADIO_LISTENER_H

#include <gtk/gtk.h>
#include <glib.h>
#include "gnome-radio.h"

typedef struct _GNOMERadioListenerInfo GNOMERadioListenerInfo;
typedef struct _GNOMERadioLocationData GNOMERadioLocationData;

struct _GNOMERadioListenerInfo {
	gchar *id;
	gchar *location;
	gchar *mail;
	gchar *name;
	gchar *pass;
	gchar *uri;
	gchar *band;
	gchar *description;
	GNOMERadioLocationData *locationdata;
	GNOMERadioListenerInfo *next;
};

struct _GNOMERadioLocationData {
	gchar *name;
	gchar *link;
	gchar *glat;
	gchar *glon;
	gchar *grad;
	gchar *vote;
	gchar *rack;
};

GNOMERadioListenerInfo *gnome_radio_listener_load_from_file(GNOMERadioListenerInfo * head,
					       char *filename);
GNOMERadioListenerInfo *gnome_radio_listener_load_from_http(GNOMERadioListenerInfo * head,
					       gpointer data);

#endif /* GNOME_RADIO_LISTENER_H */
