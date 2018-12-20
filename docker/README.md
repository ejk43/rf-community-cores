# vivado-docker

Vivado installed into a docker image. Includes python to run build scripts

Does not include RFNOC code.

Note: To create a compatible "install_config" run `xsetup –b ConfigGen`
after untarring a Vivado installer

## Build instructions

Create a directory to store the Dockerfile sources. You also need a copy of the Xilinx license file you want to use, but we've checked in a default Webpack license for convenience.

You also need the appropriate SDK co-located with the Dockerfile:
- Xilinx_Vivado_SDK_Lin_2015.4_1118_2.tar.gz
- Xilinx_Vivado_SDK_2017.4_1216_1.tar.gz

To build the image:
1. cd into desired vivado-<version> directory
2. Copy the Vivado installer file into this directory. Installers can be found online
3. Build the image: `docker build -t vivado:<version> .` (or from *this* directory: `docker build -t vivado:<version> <subfolder>`)

## Running

Run the docker image, mounting local files you want to build with vivado:
```
docker run -it -h vivado -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -v /local/path/to/prefix:/home/vivado/prefix --name vivado-<version> vivado:<version>
```
To start and reattach to a stopped container (with the container name "vivado"):
```bash
docker start vivado-<version>
docker attach vivado-<version>
```


