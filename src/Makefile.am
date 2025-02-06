AM_CPPFLAGS = $(GNOME_RADIO_CFLAGS) \
	-DGNOME_RADIO_DATADIR="\"$(pkgdatadir)\"" \
	-DGNOME_RADIO_LOCALEDIR="\"$(localedir)\""

AM_CFLAGS = $(GNOME_RADIO_CFLAGS) \
	-DGNOME_RADIO_DATADIR="\"$(pkgdatadir)\"" \
	-DGNOME_RADIO_LOCALEDIR="\"$(localedir)\""
	$(NULL)

AM_LDFLAGS= $(GNOME_RADIO_LIBS) 

bin_PROGRAMS = gnome-radio gnome-internet-radio-locator gtk-radio gtk-internet-radio-locator

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

gnomeinternetradiolocator_DATA = gnome-radio-48.0.dtd gnome-radio.xml

gtk_radio_SOURCES = \
		gtk-radio-gui.c \
		gtk-radio-listener.c \
		gtk-radio-markers.c \
		gtk-radio-player.c \
		gtk-radio-program.c \
		gtk-radio-runners.c \
		gtk-radio-station.c \
		gtk-radio-stations-map.c \
		gtk-radio-streams.c \
		gtk-radio-tz.c \
		gtk-radio.h \
		gtk-radio-keys.h \
		gtk-radio-gui.h \
		gtk-radio-listener.h \
		gtk-radio-markers.h \
		gtk-radio-player.h \
		gtk-radio-player-kb.h \
		gtk-radio-program.h \
		gtk-radio-runners.h \
		gtk-radio-station.h \
		gtk-radio-stations-map.h \
		gtk-radio-streams.h \
		gtk-radio-tz.h \
		gtk-radio.c

gtk_radio_CFLAGS  = $(GTK_RADIO_CFLAGS) \
	       -DGTK_RADIO_DATADIR=\"$(datadir)/gtk-radio\" \
	       -DDATADIR=\"$(datadir)\" \
	       -DGTK_RADIO_DEBUG=1 \
	       -DGTK_RADIO_CFG \
               -DGTK_RADIO_LOCALEDIR="\"$(localedir)\""

gtk_radio_LDADD = $(GTK_RADIO_LIBS)

gtk_internet_radio_locator_SOURCES = \
	gtk-internet-radio-locator-gui.c \
	gtk-internet-radio-locator-gui.h \
	gtk-internet-radio-locator-keys.h \
	gtk-internet-radio-locator-listener.c \
	gtk-internet-radio-locator-listener.h \
	gtk-internet-radio-locator-markers.c \
	gtk-internet-radio-locator-markers.h \
	gtk-internet-radio-locator-player-kb.h \
	gtk-internet-radio-locator-player-renderer.h \
	gtk-internet-radio-locator-player-resource.h \
	gtk-internet-radio-locator-player.c \
	gtk-internet-radio-locator-player.h \
	gtk-internet-radio-locator-program.c \
	gtk-internet-radio-locator-program.h \
	gtk-internet-radio-locator-runners.c \
	gtk-internet-radio-locator-runners.h \
	gtk-internet-radio-locator-station.c \
	gtk-internet-radio-locator-station.h \
	gtk-internet-radio-locator-stations-map.c \
	gtk-internet-radio-locator-stations-map.h \
	gtk-internet-radio-locator-streams.c \
	gtk-internet-radio-locator-streams.h \
	gtk-internet-radio-locator-tz.c \
	gtk-internet-radio-locator-tz.h \
	gtk-internet-radio-locator.c \
	gtk-internet-radio-locator.h

gtk_internet_radio_locator_CFLAGS  = $(GNOME_RADIO_CFLAGS) \
	       -DGTK_INTERNET_RADIO_LOCATOR_DATADIR=\"$(datadir)/gtk-internet-radio-locator\" \
	       -DDATADIR=\"$(datadir)\" \
	       -DGTK_INTERNET_RADIO_LOCATOR_DEBUG=1 \
	       -DGTK_INTERNET_RADIO_LOCATOR_CFG \
               -DGTK_INTERNET_RADIO_LOCATOR_LOCALEDIR="\"$(localedir)\""

gtk_internet_radio_locator_LDADD = $(GTK_INTERNET_RADIO_LOCATOR_LIBS)

gtkinternetradiolocatordir = $(datadir)/gtk-internet-radio-locator

gtkinternetradiolocator_DATA = internet-radio-locator-48.0.dtd internet-radio-locator.xml

EXTRA_DIST = gnome-radio.h gnome-radio-archive.h gnome-radio-encoder.h gnome-radio-location.h gnome-radio-player.h gnome-radio-keys.h gnome-radio-markers.h gnome-radio-player-kb.h gnome-radio-player-resource.h gnome-radio-radius.h gnome-radio-station.h gnome-radio-stations-map.h gnome-radio-tz.h gnome-radio-gui.h gnome-radio-listener.h gnome-radio-program.h gnome-radio-runners.h gnome-radio-streams.h gnome-radio-48.0.dtd gnome-radio.xml gnome-radio.xsl gnome-radio.gresource.xml internet-radio-locator-48.0.dtd internet-radio-locator.xml

LDADD = $(GNOME_RADIO_LIBS) $(GTK_RADIO_LIBS)

noinst_HEADERS = gnome-radio-player-renderer.h
