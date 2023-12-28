#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

BTCTURQUOISED=${BTCTURQUOISED:-$SRCDIR/btcturquoised}
BTCTURQUOISECLI=${BTCTURQUOISECLI:-$SRCDIR/btcturquoise-cli}
BTCTURQUOISETX=${BTCTURQUOISETX:-$SRCDIR/btcturquoise-tx}
BTCTURQUOISEQT=${BTCTURQUOISEQT:-$SRCDIR/qt/btcturquoise-qt}

[ ! -x $BTCTURQUOISED ] && echo "$BTCTURQUOISED not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BTCVER=($($BTCTURQUOISECLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for btcturquoised if --version-string is not set,
# but has different outcomes for btcturquoise-qt and btcturquoise-cli.
echo "[COPYRIGHT]" > footer.h2m
$BTCTURQUOISED --version | sed -n '1!p' >> footer.h2m

for cmd in $BTCTURQUOISED $BTCTURQUOISECLI $BTCTURQUOISETX $BTCTURQUOISEQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BTCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BTCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
