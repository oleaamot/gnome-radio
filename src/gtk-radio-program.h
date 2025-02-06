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

#ifndef GTK_RADIO_PROGRAM_H
#define GTK_RADIO_PROGRAM_H

#include <gtk/gtk.h>
#include "gtk-radio.h"

typedef struct _GTKInternetRadioLocatorProgramInfo GTKInternetRadioLocatorProgramInfo;
typedef struct _GTKInternetRadioLocatorArchiveInfo GTKInternetRadioLocatorArchiveInfo;

struct _GTKInternetRadioLocatorProgramInfo {
	GtkWidget *widget;
	gchar *id;
	gchar *name;
	gchar *rank;
	gchar *type;
	gchar *band;
	gchar *frequency;
	gchar *location;
	gchar *description;
	gchar *bitrate;
	gchar *samplerate;
	gchar *uri;
	/*   gchar *category; */
	GTKInternetRadioLocatorArchiveInfo *archive;
	GTKInternetRadioLocatorProgramInfo *next;
	GTKInternetRadioLocatorProgramInfo *prev;
};

struct _GTKInternetRadioLocatorArchiveInfo {
	gchar *id;
	gchar *name;
	GTKInternetRadioLocatorArchiveInfo *next;
	gchar *mimetype;
	glong bitrate;
	glong samplerate;
	GTKInternetRadioLocatorChannels channels;
	gchar *uri;
};

GTKInternetRadioLocatorProgramInfo *gtk_radio_program_new (GTKInternetRadioLocatorProgramInfo * head,
				   gchar *id,
				   gchar *name,
				   gchar *date,
				   gchar *time,
				   gchar *file);

void gtk_radio_program_free(GTKInternetRadioLocatorProgramInfo * info);
GTKInternetRadioLocatorProgramInfo *gtk_radio_program_load_from_file(GTKInternetRadioLocatorProgramInfo * head,
					     char *filename);
GTKInternetRadioLocatorProgramInfo *gtk_radio_program_load_from_http(GTKInternetRadioLocatorProgramInfo * head,
					     gpointer data);

#endif /* GTK_RADIO_PROGRAM_H */
