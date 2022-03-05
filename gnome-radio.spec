Name:           gnome-radio
Version:        14.0.0
Release:        1%{?dist}
Summary:        GNOME Radio 14 for GNOME 42
License:        GPLv3+
URL:            https://people.gnome.org/~ole/%{name}
Source:         %{url}/%{name}-%{version}.tar.xz

BuildRequires:  gcc
BuildRequires:  gtk3-devel
BuildRequires:  pango
BuildRequires:  libchamplain-devel
BuildRequires:  libxml2-devel
BuildRequires:  intltool
BuildRequires:  itstool
BuildRequires:  libappstream-glib
BuildRequires:  desktop-file-utils
BuildRequires:  geoclue2-devel
BuildRequires:  geocode-glib-devel
BuildRequires:  gstreamer1-devel
BuildRequires:  gstreamer1-plugins-bad-free-devel
BuildRequires:  gstreamer1-plugins-base-devel
Requires:       gstreamer1 >= 1.8.3
Requires:       gstreamer1-plugins-ugly-free >= 1.8.3
Requires:       geocode-glib >= 3.20.1
Requires:       gtk3 >= 3.24.28
Requires:       geoclue2 >= 2.5.7

%description
GNOME Radio 14 is a Free Software program that allows you easily
listen to National Public Radio (NPR) broadcasts under GNOME 42.

GNOME Radio 14 is developed on the GNOME 42 desktop platform and
it requires GTK+ 3.0, Clutter and GStreamer 1.0 for playback.

Enjoy National Public Radio (NPR) broadcasts under GNOME 42.

%prep
%setup -q

%build
%configure --disable-silent-rules --disable-schemas
%make_build
%install
%make_install
%find_lang %{name} --with-man

%check
appstream-util validate-relax --nonet %{buildroot}%{_metainfodir}/%{name}.appdata.xml
desktop-file-validate %{buildroot}/%{_datadir}/applications/%{name}.desktop
%files -f %{name}.lang
%doc AUTHORS NEWS README ChangeLog
%license COPYING
%{_bindir}/%{name}
%{_metainfodir}/%{name}.appdata.xml
%{_datadir}/applications/%{name}.desktop
%{_datadir}/applications/org.gnome.Radio.desktop.in
%{_datadir}/icons/hicolor/scalable/apps/gnome-radio.svg
%{_datadir}/metainfo/org.gnome.Radio.appdata.xml

%changelog
* Sun Jan 30 2022 Ole Aamot <ole@gnome.org> - 14.0.0-1
- gnome-radio 14.0.0 build on Fedora Linux 35

* Thu Jul 29 2021 Ole Aamot <ole@gnome.org> - 0.3.0-1
- gnome-radio 0.3.0 build on Fedora Linux 34
