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

Example Simulation Output:
```
Waf: Entering directory `/home/ubuntu/repos/ns-3.27/build'
Waf: Leaving directory `/home/ubuntu/repos/ns-3.27/build'
Build commands will be stored in build/compile_commands.json
'build' finished successfully (0.608s)
Create nodes
Create devices
Assign IP Addresses
Run Simulation
Done
reading from file udp-echo-0-1.pcap, link-type EN10MB (Ethernet)
2.008000 ARP, Request who-has 10.1.1.1 (Broadcast) tell 10.1.1.2, length 28
2.019304 ARP, Reply 10.1.1.1 is-at 00:00:00:00:00:01 (oui Ethernet), length 46
2.019304 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
2.029258 ARP, Request who-has 10.1.1.2 (Broadcast) tell 10.1.1.1, length 46
2.029258 ARP, Reply 10.1.1.2 is-at 00:00:00:00:00:01 (oui Ethernet), length 28
2.030381 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
2.100000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
2.101435 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
2.200000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
2.209580 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
2.300000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
2.309628 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
2.400000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
2.409549 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
2.500000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
2.502586 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
2.600000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
2.609666 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
2.700000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
2.702072 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
2.800000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
2.802201 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
2.900000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
2.910153 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
3.000000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
3.001775 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
3.100000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
3.101990 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
3.200000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
3.209905 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
3.300000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
3.309833 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
3.400000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
3.402421 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
3.500000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
3.501843 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
3.600000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
3.609713 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
3.700000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
3.701688 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
3.800000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
3.802409 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
3.900000 IP 10.1.1.2.49153 > 10.1.1.1.discard: UDP, length 1024
3.901809 IP 10.1.1.1.discard > 10.1.1.2.49153: UDP, length 1024
```

After the simulation has finished there is a trace of the UDP communication. Here we see that the client sends an UDP packet to the server each 0.1 seconds and the server replies with the same packet.