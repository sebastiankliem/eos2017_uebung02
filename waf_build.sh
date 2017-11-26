#!/bin/bash

mv /home/ubuntu/udp-echo.cc /home/ubuntu/repos/ns-3.27/scratch/udp-echo.cc
cd repos/ns-3.27
./waf configure -d debug
./waf