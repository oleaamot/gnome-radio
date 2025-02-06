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

#ifndef GTK_RADIO_STREAMS_H
#define GTK_RADIO_STREAMS_H

#include "gtk-radio.h"

typedef struct _GTKInternetRadioLocatorStreamsInfo GTKInternetRadioLocatorStreamsInfo;
typedef struct _GTKInternetRadioLocatorEncoderInfo GTKInternetRadioLocatorEncoderInfo;

struct _GTKInternetRadioLocatorStreamsInfo {
	GtkWidget *widget;
	gchar *mime;
	gchar *uri;
	gchar *codec;
	gchar *samplerate;
	gchar *streams;
	gchar *bitrate;
	GTKInternetRadioLocatorChannels channels;
	GTKInternetRadioLocatorEncoderInfo *encoder;
	GTKInternetRadioLocatorStreamsInfo *next;
	GTKInternetRadioLocatorStreamsInfo *prev;
};

struct _GTKInternetRadioLocatorEncoderInfo {
	gchar *id;
	gchar *name;
	GTKInternetRadioLocatorEncoderInfo *next;
	gchar *mimetype;
	glong bitrate;
	glong samplerate;
	GTKInternetRadioLocatorChannels channels;
	gchar *uri;
};

GTKInternetRadioLocatorStreamsInfo *gtk_radio_streams_new (GTKInternetRadioLocatorStreamsInfo * head,
				   gchar *mime,
				   gchar *uri,
				   gchar *codec,
				   gchar *samplerate,
				   gchar *channels,
	                           gchar *bitrate);

void gtk_radio_streams_free(GTKInternetRadioLocatorStreamsInfo * info);
GTKInternetRadioLocatorStreamsInfo *gtk_radio_streams_load_from_file(GTKInternetRadioLocatorStreamsInfo * head,
					     char *filename);
GTKInternetRadioLocatorStreamsInfo *gtk_radio_streams_load_from_http(GTKInternetRadioLocatorStreamsInfo * head,
					     gpointer data);

#endif /* GTK_RADIO_STREAMS_H */
