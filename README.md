# fuchsia-samples
samples for fuchsia

# How to build (on Ubuntu 16.04 x86_64)
1. Follow the [Fuchsia build instructions](https://fuchsia.googlesource.com/docs/+/master/getting_started.md) first in order to get the cross compiling tools we need. You should be OK if you succeeded in building Fuchsia
1. Run the following commands. We are assuming you downloaded fuchsia at `~/fuchsia`.
    ```
    $ export PATH=$PATH:~/fuchsia/buildtools/linux-x64/clang/bin
    $ cd namespaces
    $ mkdir build
    $ cd build
    $ CC=clang CXX=clang++ cmake ..
    $ make
    ```

# How to run
1. Get Fuhsia running in QEMU with network enabled. Some information is [here](https://fuchsia.googlesource.com/docs/+/master/getting_started.md#enabling-network)
 
    ```
    $ sudo apt-get install uml-utilities
    $ sudo tunctl -u masato -t qemu
    $ sudo ifconfig qemu up
    $ frun -N -u ./scripts/start-dhcp-server.sh
    ```

1. Use `netcp` in order to send the built binaries to Fuchsia.

    ```
    $ ~/fuchsia/out/build-magenta/tools/netcp namespaces :/tmp/namespaces
    wrote 22064 bytes
    ```

1. Run in Fuchsia

    ```
    $ /tmp/namespaces
    Testing namespaces...
    ```
