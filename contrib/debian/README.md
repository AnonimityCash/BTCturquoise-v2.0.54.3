
Debian
====================
This directory contains files used to package btcturquoised/btcturquoise-qt
for Debian-based Linux systems. If you compile btcturquoised/btcturquoise-qt yourself, there are some useful files here.

## btcturquoise: URI support ##


btcturquoise-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install btcturquoise-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your btcturquoise-qt binary to `/usr/bin`
and the `../../share/pixmaps/btcturquoise128.png` to `/usr/share/pixmaps`

btcturquoise-qt.protocol (KDE)

