#include <fstream>
#include "ns3/core-module.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/fd-net-device-module.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("UdpEcho");

int main(int argc, char *argv[]) {
    LogComponentEnable("UdpEcho", LOG_LEVEL_INFO);

    // Set defaults
    std::string deviceName = "enp0s8";
    bool clientMode = false;
    bool serverMode = false;
    double stopTime = 15;
    uint32_t nodeAmount = 1;

    // Override defaults with command line parameters
    CommandLine cmd;
    cmd.AddValue("client", "client mode", clientMode);
    cmd.AddValue("server", "server mode", serverMode);
    cmd.AddValue("stopTime", "stop time (seconds)", stopTime);
    cmd.Parse(argc, argv);

    // Real time simulation
    GlobalValue::Bind("SimulatorImplementationType", StringValue("ns3::RealtimeSimulatorImpl"));

    // GlobalValue::Bind ("ChecksumEnabled", BooleanValue(true));


    // Check for corerct usage
    if (clientMode && serverMode) {
        NS_FATAL_ERROR("Error, both client and server options cannot be enabled.");
    }

    // Create nodes
    NS_LOG_INFO("Create nodes");
    NodeContainer nodes;
    nodes.Create(nodeAmount);

    // Add internet stack
    InternetStackHelper internetStack;
    internetStack.Install(nodes);

    // Create FdNetDevice
    NS_LOG_INFO("Create devices");
    EmuFdNetDeviceHelper fdNetDevice;
    fdNetDevice.SetDeviceName(deviceName);

    NetDeviceContainer devices;
    Ipv4AddressHelper ipv4Helper;
    Ipv4InterfaceContainer ips;
    ApplicationContainer apps;

    // Define internal IP address space
    ipv4Helper.SetBase("10.1.1.0", "255.255.255.0");
    devices = fdNetDevice.Install(nodes.Get(0));
    NS_LOG_INFO ("Assign IP Addresses");
    // Server starts first and will get 10.1.1.1. address, therefore get the next one as client
    if (clientMode) {
        ipv4Helper.NewAddress();
    }
    ips = ipv4Helper.Assign(devices);

    // Create applications
    if (serverMode) {
        NS_LOG_INFO("Create Applications");
        UdpEchoServerHelper server(9);
        apps = server.Install(nodes.Get(0));
        apps.Start(Seconds(1.0));
        apps.Stop(Seconds(stopTime));
    }
    else if (clientMode) {
        uint32_t packetSize = 1024;
        uint32_t maxPacketCount = 20;
        Time interPacketInterval = Seconds(0.1);
        UdpEchoClientHelper client(Ipv4Address("10.1.1.1"), 9);
        client.SetAttribute("PacketSize", UintegerValue(packetSize));
        client.SetAttribute("MaxPackets", UintegerValue(maxPacketCount));
        client.SetAttribute("Interval", TimeValue(interPacketInterval));
        apps = client.Install(nodes.Get(0));
        apps.Start(Seconds(2.0));
        apps.Stop(Seconds(stopTime));
    }

    // Read Packets
    fdNetDevice.EnablePcapAll("udp-echo", true);

    // Run simulation
    NS_LOG_INFO("Run Simulation");
    Simulator::Stop(Seconds(stopTime));
    Simulator::Run();
    Simulator::Destroy();
    NS_LOG_INFO("Done");
}
