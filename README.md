# NuggetOS_64bit

<img src="/docs/screenshot1.png" alt="screenshot1"/>
<img src="/docs/screenshot2.png" alt="screenshot2"/>

## Setup
First run this to create [docker](https://www.docker.com/products/docker-desktop) environment.
```
docker build buildenv -t myos-buildenv
```
Next open it in docker.
```
docker run --rm -it -v "${pwd}:/root/env" myos-buildenv
```
## Building the iso file
Use make to build os for x68.
```
make build-x86_64
```
## Running the iso in an emulator
Run it from the cmd with this command using [qemu](https://www.qemu.org/download/)
```
qemu-system-x86_64 -soundhw pcspk -cdrom dist/x86_64/kernel.iso
```
## Clean up
Run this inside the docker environment. This cleans all solution files.
```
make clean
```
