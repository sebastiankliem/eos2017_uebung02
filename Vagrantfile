Vagrant.configure("2") do |config|
  config.vm.define "server" do |server|
    server.vm.box = "ubuntu/xenial64"
    server.vm.box_version = "20171122.0.0"
    server.vm.box_check_update = false
    server.vm.provider "virtualbox" do |vb|
      server.vm.network "private_network", :type => 'dhcp', :adapter => 2
      vb.customize ["modifyvm", :id, "--nicpromisc2", "allow-all"]
    end
    server.vm.provision :shell, path: "install.sh"
    server.vm.provision :file, source: "./udp-echo.cc", destination: "~/udp-echo.cc", run: "always"
    server.vm.provision :shell, path: "waf_build.sh", run: "always"
    server.vm.provision :shell, path: "configure_network.sh", run: "always"
  end
    
  config.vm.define "client" do |client|
    client.vm.box = "ubuntu/xenial64"
    client.vm.box_version = "20171122.0.0"
    client.vm.box_check_update = false
    client.vm.provider "virtualbox" do |vb|
      client.vm.network "private_network", :type => 'dhcp', :adapter => 2
      vb.customize ["modifyvm", :id, "--nicpromisc2", "allow-all"]
    end
    client.vm.provision :shell, path: "install.sh"
    client.vm.provision :file, source: "./udp-echo.cc", destination: "~/udp-echo.cc", run: "always"
    client.vm.provision :shell, path: "waf_build.sh", run: "always"
    client.vm.provision :shell, path: "configure_network.sh", run: "always"
  end
end
