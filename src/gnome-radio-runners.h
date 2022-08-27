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

#ifndef GNOME_RADIO_RUNNERS_H
#define GNOME_RADIO_RUNNERS_H

typedef struct _GNOMERadioRunnersInfo GNOMERadioRunnersInfo;

struct _GNOMERadioRunnersInfo {
	GtkWidget *widget;
	GMutex *mutex;
	pid_t pid;
	gchar *name;
	gchar *date;
	gchar *time;
	gchar *file;
	gchar *command;
};

GNOMERadioRunnersInfo *gnome_radio_runners_new (pid_t pid,
				   gchar *name,
				   gchar *date,
				   gchar *time,
				   gchar *file);

void gnome_radio_runners_free(GNOMERadioRunnersInfo * info);
void gnome_radio_runners_mutex_get(GNOMERadioRunnersInfo *info);
void gnome_radio_runners_mutex_release(GNOMERadioRunnersInfo *info);
void gnome_radio_runners_mutex_lock(GNOMERadioRunnersInfo *info);
void gnome_radio_runners_mutex_unlock(GNOMERadioRunnersInfo *info);

void cb_record_execute(GtkButton *button);

#endif /* GNOME_RADIO_RUNNERS_H */
