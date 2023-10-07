AM_CPPFLAGS = $(GNOME_RADIO_CFLAGS) \
	-DGNOME_RADIO_DATADIR="\"$(pkgdatadir)\"" \
	-DGNOME_RADIO_LOCALEDIR="\"$(localedir)\""

AM_CFLAGS = $(GNOME_RADIO_CFLAGS) \
	-DGNOME_RADIO_DATADIR="\"$(pkgdatadir)\"" \
	-DGNOME_RADIO_LOCALEDIR="\"$(localedir)\""
	$(NULL)

AM_LDFLAGS= $(GNOME_RADIO_LIBS) 

bin_PROGRAMS = gnome-radio gnome-internet-radio-locator

gnome_radio_SOURCES = \
		gnome-radio-gui.c \
		gnome-radio-listener.c \
		gnome-radio-location.c \
		gnome-radio-markers.c \
		gnome-radio-player.c \
		gnome-radio-program.c \
		gnome-radio-radius.c \
		gnome-radio-runners.c \
		gnome-radio-station.c \
		gnome-radio-stations-map.c \
		gnome-radio-streams.c \
		gnome-radio-tz.c \
		gnome-radio.c

gnome_radio_CFLAGS  = $(GNOME_RADIO_CFLAGS) \
	       -DGNOME_RADIO_DATADIR=\"$(datadir)/gnome-radio\" \
	       -DDATADIR=\"$(datadir)\" \
	       -DGNOME_RADIO_DEBUG=1 \
	       -DGNOME_RADIO_CFG \
               -DGNOME_RADIO_LOCALEDIR="\"$(localedir)\""

gnome_radio_LDADD = $(GNOME_RADIO_LIBS)

gnome_internet_radio_locator_SOURCES = \
		gnome-radio-gui.c \
		gnome-radio-listener.c \
		gnome-radio-location.c \
		gnome-radio-markers.c \
		gnome-radio-player.c \
		gnome-radio-program.c \
		gnome-radio-radius.c \
		gnome-radio-runners.c \
		gnome-radio-station.c \
		gnome-radio-stations-map.c \
		gnome-radio-streams.c \
		gnome-radio-tz.c \
		gnome-radio.c

gnome_internet_radio_locator_CFLAGS  = $(GNOME_RADIO_CFLAGS) \
	       -DGNOME_RADIO_DATADIR=\"$(datadir)/gnome-radio\" \
	       -DDATADIR=\"$(datadir)\" \
	       -DGNOME_RADIO_DEBUG=1 \
	       -DGNOME_RADIO_CFG \
               -DGNOME_RADIO_LOCALEDIR="\"$(localedir)\""

gnome_internet_radio_locator_LDADD = $(GNOME_RADIO_LIBS)

gnomeinternetradiolocatordir = $(datadir)/gnome-radio

gnomeinternetradiolocator_DATA = gnome-radio-64.0.dtd gnome-radio.xml

EXTRA_DIST = gnome-radio.h gnome-radio-archive.h gnome-radio-encoder.h gnome-radio-location.h gnome-radio-player.h gnome-radio-keys.h gnome-radio-markers.h gnome-radio-player-kb.h gnome-radio-player-resource.h gnome-radio-radius.h gnome-radio-station.h gnome-radio-stations-map.h gnome-radio-tz.h gnome-radio-gui.h gnome-radio-listener.h gnome-radio-program.h gnome-radio-runners.h gnome-radio-streams.h gnome-radio-64.0.dtd gnome-radio.xml gnome-radio.xsl gnome-radio.gresource.xml

LDADD = $(GNOME_RADIO_LIBS)

noinst_HEADERS = gnome-radio-player-renderer.h
