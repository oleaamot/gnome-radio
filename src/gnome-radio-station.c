/* $id$
 *
 * GNOME Radio
 *
 * Copyright (C) 2021  Aamot Software
 *
 * Author: Ole Aamot <ole@gnome.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <config.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/resource.h>
#include <glib.h>
#include <glib/gstdio.h>
#include <gio/gio.h>
#include <gtk/gtk.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <math.h>
#include "gnome-radio.h"
#include "gnome-radio-station.h"

extern GNOMERadioInfo *gnome_radio;
extern GNOMERadioStationInfo *stationinfo, *localstation;

extern gchar *world_station_xml_filename, *local_station_xml_file;

extern GStatBuf stats;

extern GtkEntryCompletion *completion;
GtkListStore *model = NULL;
GtkTreeIter iter;

static void
gnome_radio_station_parser(GNOMERadioStationInfo * station, xmlDocPtr doc,
		    xmlNodePtr cur)
{
	xmlNodePtr sub;
	char *chans;

	g_return_if_fail(station != NULL);
	g_return_if_fail(doc != NULL);
	g_return_if_fail(cur != NULL);

	station->id = (gchar *)xmlGetProp(cur, (const xmlChar *)"id");
	GNOME_RADIO_DEBUG_MSG("station->id = %s\n", station->id);
	station->name = (gchar *)xmlGetProp(cur, (const xmlChar *)"name");
	GNOME_RADIO_DEBUG_MSG("station->name = %s\n", station->name);
	station->rank = (gchar *)xmlGetProp(cur, (const xmlChar *)"rank");
	GNOME_RADIO_DEBUG_MSG("station->rank = %s\n", station->rank);
	station->type = (gchar *)xmlGetProp(cur, (const xmlChar *)"type");
	GNOME_RADIO_DEBUG_MSG("station->type = %s\n", station->type);
	station->band = (gchar *)xmlGetProp(cur, (const xmlChar *)"band");
	GNOME_RADIO_DEBUG_MSG("station->band = %s\n", station->band);

	sub = cur->xmlChildrenNode;

	while (sub != NULL) {

		if ((!xmlStrcmp(sub->name, (const xmlChar *) "frequency"))) {
			station->frequency = (gchar *)
			    xmlNodeListGetString(doc, sub->xmlChildrenNode,
						 1);
			GNOME_RADIO_DEBUG_MSG("station->frequency = %s\n",
			    station->frequency);
		}

		if ((!xmlStrcmp(sub->name, (const xmlChar *) "location"))) {
			station->location = (gchar *)
			    xmlNodeListGetString(doc, sub->xmlChildrenNode,
						 1);
			GNOME_RADIO_DEBUG_MSG("station->location = %s\n", station->location);

		}

		if ((!xmlStrcmp
		     (sub->name, (const xmlChar *) "description"))) {
			station->description = (gchar *)
			    xmlNodeListGetString(doc, sub->xmlChildrenNode,
						 1);
			GNOME_RADIO_DEBUG_MSG("station->description = %s\n", station->description);
		}

		if ((!xmlStrcmp(sub->name, (const xmlChar *) "uri"))) {
			station->uri = (gchar *)
			    xmlNodeListGetString(doc, sub->xmlChildrenNode,
						 1);
			GNOME_RADIO_DEBUG_MSG("station->uri = %s\n", station->uri);
			/* fprintf(stdout, "<a href=\"%s\">%s (%s)</a>\n\n", station->uri, station->name, station->location); */
		}

		if ((!xmlStrcmp(sub->name, (const xmlChar *) "stream"))) {

			GNOMERadioStreamsInfo *stream = g_new0(GNOMERadioStreamsInfo, 1);

			/* gnome_radio->stream_count++; */

			station->stream = stream;

			station->stream->mimetype = (gchar *)
				xmlGetProp(sub, (const xmlChar *)"mime");
			GNOME_RADIO_DEBUG_MSG("station->stream->mimetype = %s\n",
			    station->stream->mimetype);

			if (xmlGetProp(sub, (const xmlChar *)"uri") != NULL) {
			        station->stream->uri = (char *)xmlGetProp(sub, (const xmlChar *)"uri");
			}

			station->stream->uri = (gchar *)xmlGetProp(sub, (const xmlChar *)"uri");
			GNOME_RADIO_DEBUG_MSG("station->stream->uri = %s\n",
			    station->stream->uri);

			chans = (gchar *)xmlGetProp(sub, (const xmlChar *)"stations");

			if (chans != NULL) {
				if (strcmp(chans, "stereo") == 0) {
					/* station->stream->channels = */
					/*     GNOME_RADIO_CHANNELS_STEREO; */
					/* GNOME_RADIO_DEBUG_MSG("station->stream->channels = %d\n", station->stream->channels); */
				} else if (strcmp(chans, "mono") == 0) {
					/* station->stream->channels = */
					/*     GNOME_RADIO_CHANNELS_MONO; */
					/* GNOME_RADIO_DEBUG_MSG("station->stream->channels = %d\n", station->stream->channels); */
				} else if (strcmp(chans, "5:1") == 0) {
					/* station->stream->channels = */
					/*     GNOME_RADIO_CHANNELS_5_1; */
					/* GNOME_RADIO_DEBUG_MSG("station->stream->channels = %d\n", station->stream->channels); */
				}
				g_free(chans);
			}

		}
		/* if... "stream" */
		sub = sub->next;
	}
	/* gnome_radio->station_count++; */
	return;
}

GNOMERadioStationInfo *gnome_radio_station_load_from_http(GNOMERadioStationInfo * head,
					     gpointer data)
{
	GNOMERadioStationInfo *gstation;
	gstation = gnome_radio_station_load_from_file (head, "https://people.gnome.org/~ole/gnome-radio/gnome_radio.xml");
	return gstation;
}

GNOMERadioStationInfo *gnome_radio_station_load_from_file(GNOMERadioStationInfo * head,
					     char *filename)
{
	xmlDocPtr doc = NULL;
	xmlNodePtr cur = NULL;
	GNOMERadioStationInfo *curr = NULL;
	char *version;
	GNOMERadioStationInfo *mem_station;

	g_return_val_if_fail(filename != NULL, NULL);

	doc = xmlReadFile(filename, NULL, 0);

	if (doc == NULL) {
		perror("xmlParseFile");
		xmlFreeDoc(doc);
		return NULL;
	}

	cur = xmlDocGetRootElement(doc);

	if (cur == NULL) {
		fprintf(stderr, "Empty document\n");
		xmlFreeDoc(doc);
		return NULL;
	}

	if (xmlStrcmp(cur->name, (const xmlChar *) "gnome_radio")) {
		fprintf(stderr,
			"Document of wrong type, root node != gnome_radio\n");
		xmlFreeDoc(doc);
		return NULL;
	}

	version = (gchar *)xmlGetProp(cur, (const xmlChar *)"version");

	GNOME_RADIO_DEBUG_MSG("Valid GNOMERadio %s XML document... Parsing stations...\n",
	    version);

	free(version);

	cur = cur->xmlChildrenNode;

	while (cur != NULL) {

		if ((!xmlStrcmp(cur->name, (const xmlChar *) "station"))) {

			GNOME_RADIO_DEBUG_MSG("Found a new station.\n");

			curr = g_new0(GNOMERadioStationInfo, 1);
			mem_station = g_new0(GNOMERadioStationInfo, 1);

			gnome_radio_station_parser(curr, doc, cur);

			curr->next = head;

			head = curr;

			mem_station = head;

			gnome_radio_stations = g_list_append(gnome_radio_stations, (GNOMERadioStationInfo *)mem_station);

			GNOME_RADIO_DEBUG_MSG("Done with parsing the station.\n");

		}
		cur = cur->next;
	}

	GNOME_RADIO_DEBUG_MSG("Finished parsing XML document.\n");

	xmlFreeDoc(doc);

	return curr;
}

gint gnome_radio_station_update (GNOMERadioStationInfo *head, gchar *station_band, gchar *station_description, gchar *station_name, gchar *station_location, gchar *station_uri, gchar *station_website) {
	gchar msg[256];
	gchar *msg1, *msg2;
	/* Open ~/.gnome_radio/gnome_radio.xml.  Parse structure.  Insert new item.  Save structure. */
	GNOMERadioStationInfo *new_station;
	GNOMERadioStationInfo *stationinfo;
	/* GList *gnome_radio_local_stations = NULL; */
	gchar *local_station_uri, *local_station_name, *local_station_location, *local_station_band, *local_station_description, *local_station_website;
	gchar *stations = g_strconcat(g_get_home_dir(), "/.gnome-radio/gnome-radio.xml", NULL);

	gboolean local_gnome_radio_file = g_file_test (".gnome-radio/gnome-radio.xml", G_FILE_TEST_EXISTS);

	GNOME_RADIO_DEBUG_MSG("local_gnome_radio_file = %i\n", local_gnome_radio_file);

	if (local_gnome_radio_file == 0) {

		gchar *local_gnome_radio_directory = g_strconcat(g_get_home_dir(), "/.gnome-radio", NULL);
		g_mkdir_with_parents (local_gnome_radio_directory, 0700);
		
	}
	
	FILE *fp;
	
	stationinfo = gnome_radio_station_load_from_file(NULL, stations);

	new_station = g_new0(GNOMERadioStationInfo, 1);
	new_station->name = g_strdup(station_name);
	new_station->band = g_strdup(station_band);
	new_station->description = g_strdup(station_description);
	new_station->location = g_strdup(station_location);
	new_station->stream = g_new0(GNOMERadioStreamsInfo, 1);
	new_station->stream->uri = g_strdup(station_uri);
	new_station->uri = g_strdup(station_website);
	fp = g_fopen(stations, "w+");
	g_fprintf(fp, "<?xml version='1.0' encoding='UTF-8'?>\n<!DOCTYPE gnome_radio SYSTEM 'gnome-radio-14.0.dtd'>\n<gnome_radio version='%s'>\n", VERSION);
	// stationinfo-> = l->data;
	while (stationinfo != NULL) {
		local_station_uri = g_strdup(stationinfo->stream->uri);
		local_station_name = g_strdup(stationinfo->name);
		local_station_location = g_strdup(stationinfo->location);
		local_station_band = g_strdup(stationinfo->band);
		local_station_description = g_strdup(stationinfo->description);
		local_station_website = g_strdup(stationinfo->uri);
		/* FIXME: Save mime='audio/mp3' uri='%s' codec='MPEG 1 Audio, Layer 3 (MP3)' samplerate='24000 Hz' channels='Mono' bitrate='32 kbps' */
		g_fprintf(fp, "  <station band=\"%s\" id=\"%s\" lang=\"en\" name=\"%s\" rank=\"1.0\" type=\"org\">\n    <frequency uri=\"%s\">%s in %s</frequency>\n    <location>%s</location>\n    <description lang=\"en\">%s</description>\n    <stream uri=\"%s\" />\n    <uri>%s</uri>\n  </station>\n", local_station_band, local_station_name, local_station_name, local_station_website, local_station_band, local_station_location, local_station_location, local_station_description, local_station_uri, local_station_website);
		stationinfo = stationinfo->next;

	}
	g_fprintf(fp, "  <station band=\"%s\" id=\"%s\" lang=\"en\" name=\"%s\" rank=\"1.0\" type=\"org\">\n    <frequency uri=\"%s\">%s in %s</frequency>\n    <location>%s</location>\n    <description lang=\"en\">%s</description>\n    <stream uri=\"%s\" />\n    <uri>%s</uri>\n  </station>\n", new_station->band, new_station->name, new_station->name, new_station->uri, new_station->band, new_station->location, new_station->location, new_station->description, new_station->stream->uri, new_station->uri);
	g_fprintf(fp, "</gnome_radio>\n");
	fclose(fp);
	gnome_radio_stations = g_list_append(gnome_radio_stations, (GNOMERadioStationInfo *)new_station);

	g_free(stations);
	g_free(new_station);
	g_free(stationinfo);

	model = gtk_list_store_new(11, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	world_station_xml_filename = g_strconcat(GNOME_RADIO_DATADIR, "/gnome-radio.xml", NULL);
	GNOME_RADIO_DEBUG_MSG("world_station_xml_filename = %s\n",
	    world_station_xml_filename);

	if (world_station_xml_filename == NULL) {
		g_warning(("Failed to open %s.  Please install it.\n"),
			  world_station_xml_filename);
	}

	local_station_xml_file =
	    g_strconcat(g_get_home_dir(), "/.gnome-radio/gnome-radio.xml", NULL);

	if (!g_stat(local_station_xml_file, &stats)) {
		localstation = gnome_radio_station_load_from_file(NULL, local_station_xml_file);
	} else {
		localstation = NULL;
	}

	if (localstation == NULL) {
		printf("Failed to open %s.\n", local_station_xml_file);
	}

/*   g_free (local_station_xml_file); */

	stationinfo = gnome_radio_station_load_from_file(localstation, world_station_xml_filename);

	gnome_radio_stations = NULL;

	while (stationinfo != NULL) {

		gtk_list_store_append(model, &iter);
		gtk_list_store_set(model,
				   &iter,
				   STATION_NAME,
				   stationinfo->name,
				   STATION_LOCATION,
				   stationinfo->location,
				   STATION_URI,
				   stationinfo->stream->uri,
				   STATION_DESCRIPTION,
				   stationinfo->description,
				   STATION_FREQUENCY,
				   stationinfo->frequency,
				   STATION_BAND,
				   stationinfo->band,
				   STATION_TYPE,
				   stationinfo->type,
				   STATION_RANK,
				   stationinfo->rank,
				   STATION_BITRATE,
				   stationinfo->bitrate,
				   STATION_SAMPLERATE,
				   stationinfo->samplerate,
				   STATION_ID,
				   stationinfo->id,
				   -1);

		stationinfo = stationinfo->next;
	}

	gtk_entry_completion_set_model(completion, GTK_TREE_MODEL(model));

	return (0);
}
