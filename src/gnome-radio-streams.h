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

#ifndef GNOME_RADIO_STREAMS_H
#define GNOME_RADIO_STREAMS_H

#include "gnome-radio.h"

typedef struct _GNOMERadioStreamsInfo GNOMERadioStreamsInfo;
typedef struct _GNOMERadioEncoderInfo GNOMERadioEncoderInfo;

struct _GNOMERadioStreamsInfo {
	GtkWidget *widget;
	gchar *mimetype;
	gchar *uri;
	gchar *codec;
	gchar *samplerate;
	gchar *streams;
	gchar *bitrate;
	/* GNOMERadioChannels channels; */
	GNOMERadioEncoderInfo *encoder;
	GNOMERadioStreamsInfo *next;
	GNOMERadioStreamsInfo *prev;
};

struct _GNOMERadioEncoderInfo {
	gchar *id;
	gchar *name;
	GNOMERadioEncoderInfo *next;
	gchar *mimetype;
	glong bitrate;
	glong samplerate;
	/* GNOMERadioChannels channels; */
	gchar *uri;
};

GNOMERadioStreamsInfo *gnome_radio_streams_new (GNOMERadioStreamsInfo * head,
				   gchar *mime,
				   gchar *uri,
				   gchar *codec,
				   gchar *samplerate,
				   gchar *channels,
	                           gchar *bitrate);

void gnome_radio_streams_free(GNOMERadioStreamsInfo * info);
GNOMERadioStreamsInfo *gnome_radio_streams_load_from_file(GNOMERadioStreamsInfo * head,
					     char *filename);
GNOMERadioStreamsInfo *gnome_radio_streams_load_from_http(GNOMERadioStreamsInfo * head,
					     gpointer data);

#endif /* GNOME_RADIO_STREAMS_H */
