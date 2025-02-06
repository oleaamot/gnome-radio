Name:           gnome-radio
Version:        48.2
Release:        1%{?dist}
Summary:        Radio
License:        GPLv3+
URL:            http://www.gnomeradio.org/
Source:         %{url}/src/%{name}-%{version}.tar.xz

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
Requires:       gtk3 >= 3.24.34
Requires:       geoclue2 >= 2.5.7
Provides:       gnome-internet-radio-locator = 16.0.6
Obsoletes:      gnome-internet-radio-locator < 16.0.6

%description

Radio is a Free Software program that allows you to easily locate Free
Internet Radio stations by broadcasters on the Internet with the help
of map and text search.

Radio is developed on the GNOME desktop platform.

Radio supports Public Radio (www.npr.org) in USA.

%prep
%setup -q

%build
%configure --with-recording --disable-silent-rules --disable-schemas
%make_build
%install
%make_install
%find_lang %{name} --with-man

%check
appstream-util validate-relax --nonet %{buildroot}%{_metainfodir}/%{name}.appdata.xml
desktop-file-validate %{buildroot}/%{_datadir}/applications/%{name}.desktop
%files -f %{name}.lang
%doc AUTHORS NEWS README TODO ChangeLog
%license COPYING
%{_bindir}/%{name}
%{_bindir}/gnome-internet-radio-locator
%{_bindir}/gtk-radio
%{_bindir}/gtk-internet-radio-locator
%{_bindir}/org.gnome.Radio
%{_datadir}/%{name}/org.gnome.Radio.dtd
%{_datadir}/%{name}/org.gnome.Radio.xml
%{_datadir}/%{name}/doc/AAMOT.txt.xz
%{_datadir}/%{name}/doc/Aamot-2020.txt.xz
%{_datadir}/%{name}/gnome-radio-48.0.dtd
%{_datadir}/%{name}/gnome-radio.xml
%{_metainfodir}/%{name}.appdata.xml
%{_datadir}/applications/%{name}.desktop
%{_datadir}/gtk-internet-radio-locator/internet-radio-locator-48.0.dtd
%{_datadir}/gtk-internet-radio-locator/internet-radio-locator.xml
%{_datadir}/icons/hicolor/scalable/apps/gnome-radio.svg
%{_mandir}/man1/%{name}.1*

%changelog
* Wed Jan 22 2025 Ole Aamot <ole@aamot.org> - 48.20250122-1
- Initial gnome-radio 48.20250122 with Radio Folgefonn (Norway)

* Mon Jan 20 2025 Ole Aamot <ole@aamot.org> - 48.20250120-1
- Initial gnome-radio 48.20250120 with npr.org (United States of America)

* Wed Dec 25 2024 Ole Aamot <ole@aamot.org> - 48.1-1
- Initial gnome-radio 48.1 build with hi, is, ka, ru

* Sun Nov 03 2024 Ole Aamot <ole@aamot.org> - 48.0-1
- Initial gnome-radio 48.0 build with BBC (United Kingdom) and NRK (Norway)

* Sun Sep 25 2022 Ole Aamot <ole@gnome.org> - 47.0-1
- Initial gnome-radio 47.0 build with RBB (Frankfurt am Main, Germany)

* Mon Sep 19 2022 Ole Aamot <ole@gnome.org> - 46.0-1
- Initial gnome-radio 46.0 build with KXSC (LA, USA)

* Mon Sep 19 2022 Ole Aamot <ole@gnome.org> - 45.3-1
- Initial gnome-radio 45.3 builds with GtkEntry icon

* Sun Sep 18 2022 Ole Aamot <ole@gnome.org> - 45.2-1
- Initial gnome-radio 45.2 builds with libtool 2.4.7

* Sun Aug 14 2022 Ole Aamot <ole@gnome.org> - 45.1-1
- Initial gnome-radio 45.1 builds with Free Asia radio

* Wed Jul 20 2022 Ole Aamot <ole@gnome.org> - 45.0-1
- Initial gnome-radio 45.0 builds with GTK on Fedora 36

* Fri May 27 2022 Ole Aamot <ole@gnome.org> - 16.0.43-1
- Initial gnome-radio 16.0.43 builds on Fedora Linux 36

* Sat Apr 02 2022 Ole Aamot <ole@gnome.org> - 16.0.42-1
- Second gnome-radio 16.0.42 builds on Fedora Linux 36

* Mon Mar 28 2022 Ole Aamot <ole@gnome.org> - 16.0.6-1
- Initial gnome-radio 16.0.6 builds on Fedora Linux 36

* Mon Mar 28 2022 Ole Aamot <ole@gnome.org> - 16.0.5-1
- Initial gnome-radio 16.0.5 builds on Fedora Linux 35

* Sat Mar 19 2022 Ole Aamot <ole@gnome.org> - 16.0.4-1
- Initial gnome-radio 16.0.4 builds on Fedora Linux 36

* Tue Mar 15 2022 Ole Aamot <ole@gnome.org> - 14.0.1-1
- Initial gnome-radio 14.0.1 builds on Fedora Linux 35
