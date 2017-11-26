#!/bin/bash

# install necessary software
apt-get update
apt-get install -y pkg-config libxml2 libxml2-dev gcc g++ make automake autoconf binutils python-dev mercurial tcpdump gdb vim

# install ns-3
mkdir repos
cd repos
hg clone http://code.nsnam.org/ns-3.27