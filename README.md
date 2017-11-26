# ns-3 FdNetDevice example - EOS 2017

This example builds two VirtualBox VMs with ns-3 installed using Vagrant.

The test simulation scenario is a UDP echo between client and server: For a fix time span, every 0.1 seconds the client sends an UDP packet to the server. The server sends this packet back to the client. The result of this simulation is a PCAP trace of the UDP communication.

## Preconditions
* [VirtualBox](https://www.virtualbox.org/)
* [Vagrant](https://www.vagrantup.com/)

## Setup
```bash
vagrant up
```

## Running the simulation
You need two shells:
1. `vagrant ssh server -c "cd repos/ns-3.27;sudo ./waf --run \"scratch/udp-echo --server\"; tcpdump -tt -r udp-echo-0-1.pcap"`
2. `vagrant ssh client -c "cd repos/ns-3.27;sudo ./waf --run \"scratch/udp-echo --client\"; tcpdump -tt -r udp-echo-0-1.pcap"`