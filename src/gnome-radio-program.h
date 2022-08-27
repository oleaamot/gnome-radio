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

#ifndef GNOME_RADIO_PROGRAM_H
#define GNOME_RADIO_PROGRAM_H

#include <gtk/gtk.h>
#include "gnome-radio.h"
#include "gnome-radio-streams.h"
#include "gnome-radio-archive.h"

typedef struct _GNOMERadioProgramInfo GNOMERadioProgramInfo;

struct _GNOMERadioProgramInfo {
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
	GNOMERadioArchiveInfo *archive;
	GNOMERadioProgramInfo *next;
	GNOMERadioProgramInfo *prev;
};

GNOMERadioProgramInfo *gnome_radio_program_new (GNOMERadioProgramInfo * head,
				   gchar *id,
				   gchar *name,
				   gchar *date,
				   gchar *time,
				   gchar *file);

void gnome_radio_program_free(GNOMERadioProgramInfo * data);
GNOMERadioProgramInfo *gnome_radio_program_load_from_file(GNOMERadioProgramInfo * head,
					     char *filename);
GNOMERadioProgramInfo *gnome_radio_program_load_from_http(GNOMERadioProgramInfo * head,
					     gpointer data);

#endif /* GNOME_RADIO_PROGRAM_H */
