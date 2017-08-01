#!/usr/bin/env bash

set -e

/veyon/.travis/common/linux-build.sh /veyon /build

# generate source tarball
cd /veyon
VERSION=$(git describe --tags --abbrev=0)

cd /build
cp CONTRIBUTORS /veyon
tar --transform "s,^veyon,^veyon-$VERSION," -cfj --exclude=".git" veyon-$VERSION-src.tar.gz /veyon

# move generated DEB to mounted Docker volume
rename "s/_amd64/-debian-stretch_amd64/g" *.deb

dpkg -I *.deb

mv -v *.deb /veyon

