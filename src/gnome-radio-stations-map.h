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


#ifndef _GNOME_RADIO_STATIONS_MAP_H
#define _GNOME_RADIO_STATIONS_MAP_H

#include <gtk/gtk.h>
#include <gtk/gtkenums.h>

#include "gnome_radio-tz.h"

G_BEGIN_DECLS

#define GNOME_RADIO_TYPE_STATIONS_MAP gnome_radio_stations_map_get_type()

#define GNOME_RADIO_STATIONS_MAP(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
  GNOME_RADIO_TYPE_STATIONS_MAP, GNOMERadioStationsMap))

#define GNOME_RADIO_STATIONS_MAP_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), \
  GNOME_RADIO_TYPE_STATIONS_MAP, GNOMERadioStationsMapClass))

#define GNOME_RADIO_IS_STATIONS_MAP(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
  GNOME_RADIO_TYPE_STATIONS_MAP))

#define GNOME_RADIO_IS_STATIONS_MAP_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), \
  GNOME_RADIO_TYPE_STATIONS_MAP))

#define GNOME_RADIO_STATIONS_MAP_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), \
  GNOME_RADIO_TYPE_STATIONS_MAP, GNOMERadioStationsMapClass))

typedef struct _GNOMERadioStationsMap GNOMERadioStationsMap;
typedef struct _GNOMERadioStationsMapClass GNOMERadioStationsMapClass;
typedef struct _GNOMERadioStationsMapPrivate GNOMERadioStationsMapPrivate;

struct _GNOMERadioStationsMap
{
  GtkWidget parent;

  GNOMERadioStationsMapPrivate *priv;
};

struct _GNOMERadioStationsMapClass
{
  GtkWidgetClass parent_class;
};

GType gnome_radio_stations_map_get_type (void) G_GNUC_CONST;

GNOMERadioStationsMap *gnome_radio_stations_map_new (void);

gboolean gnome_radio_stations_map_set_location (GNOMERadioStationsMap *map,
					 const gchar   *timezone);
void gnome_radio_stations_map_set_bubble_text (GNOMERadioStationsMap *map,
                                      const gchar   *text);

TzLocation *gnome_radio_stations_map_get_location (GNOMERadioStationsMap *map);

G_END_DECLS

#endif /* _GNOME_RADIO_STATIONS_MAP_H */
