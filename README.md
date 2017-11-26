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
1. `vagrant ssh server` and in another tab `vagrant ssh client`
2. both:
    ```bash
    cd repos/ns-3.27
    sudo ./waf
    ````
3. server: `sudo ./waf --run "scratch/udp-echo --server"`  
   client: `sudo ./waf --run "scratch/udp-echo --server"`

4. both: `tcpdump -nn -r udp-echo-0-1.pcap`