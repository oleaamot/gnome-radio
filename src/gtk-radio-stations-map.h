/* $Id$
 *
 * Internet Radio Locator for GTK+ 4.0
 *
 * Copyright (C) 2015, 2018  Ole Aamot Software
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
 *
 */

/* 
 * Essential parts of the source code below was based on
 * gnome-control-center/panels/datetime/cc-timezone-map.h
 *
 * Copyright (C) 2010 Intel, Inc
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
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Thomas Wood <thomas.wood@intel.com>
 *
 */


#ifndef _GTK_RADIO_STATIONS_MAP_H
#define _GTK_RADIO_STATIONS_MAP_H

#include <gtk/gtk.h>
#include <gtk/gtkenums.h>

#include "gtk_radio-tz.h"

G_BEGIN_DECLS

#define GTK_RADIO_TYPE_STATIONS_MAP gtk_radio_stations_map_get_type()

#define GTK_RADIO_STATIONS_MAP(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
  GTK_RADIO_TYPE_STATIONS_MAP, GTKInternetRadioLocatorStationsMap))

#define GTK_RADIO_STATIONS_MAP_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), \
  GTK_RADIO_TYPE_STATIONS_MAP, GTKInternetRadioLocatorStationsMapClass))

#define GTK_RADIO_IS_STATIONS_MAP(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
  GTK_RADIO_TYPE_STATIONS_MAP))

#define GTK_RADIO_IS_STATIONS_MAP_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), \
  GTK_RADIO_TYPE_STATIONS_MAP))

#define GTK_RADIO_STATIONS_MAP_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), \
  GTK_RADIO_TYPE_STATIONS_MAP, GTKInternetRadioLocatorStationsMapClass))

typedef struct _GTKInternetRadioLocatorStationsMap GTKInternetRadioLocatorStationsMap;
typedef struct _GTKInternetRadioLocatorStationsMapClass GTKInternetRadioLocatorStationsMapClass;
typedef struct _GTKInternetRadioLocatorStationsMapPrivate GTKInternetRadioLocatorStationsMapPrivate;

struct _GTKInternetRadioLocatorStationsMap
{
  GtkWidget parent;

  GTKInternetRadioLocatorStationsMapPrivate *priv;
};

struct _GTKInternetRadioLocatorStationsMapClass
{
  GtkWidgetClass parent_class;
};

GType gtk_radio_stations_map_get_type (void) G_GNUC_CONST;

GTKInternetRadioLocatorStationsMap *gtk_radio_stations_map_new (void);

gboolean gtk_radio_stations_map_set_location (GTKInternetRadioLocatorStationsMap *map,
					 const gchar   *timezone);
void gtk_radio_stations_map_set_bubble_text (GTKInternetRadioLocatorStationsMap *map,
                                      const gchar   *text);

TzLocation *gtk_radio_stations_map_get_location (GTKInternetRadioLocatorStationsMap *map);

G_END_DECLS

#endif /* _GTK_RADIO_STATIONS_MAP_H */
