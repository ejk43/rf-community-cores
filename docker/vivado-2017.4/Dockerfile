FROM ubuntu:16.04

MAINTAINER EJ Kreinar <ejkreinar@gmail.com>
# Based on the vivado docker image by Colm Ryan, with some minor changes for GUI compatibility (https://github.com/BBN-Q/vivado-docker)

#install dependences for:
# * xsim (gcc build-essential to also get make)
# * MIG tool (libglib2.0-0 libsm6 libxi6 libxrender1 libxrandr2 libfreetype6 libfontconfig)
# * CI (git)
RUN apt-get update && apt-get install -y \
  build-essential \
  libglib2.0-0 \
  libsm6 \
  libxi6 \
  libxtst6 \
  libxrender1 \
  libxrandr2 \
  libfreetype6 \
  libfontconfig \
  lib32z1 \
  lib32ncurses5 \
  lib32stdc++6 \
  libgtk2.0-0 \
  git \
  cmake \
  nano \
  python \
  python-dev \
  python-distribute \
  python-pip \
&& rm -rf /var/lib/apt/lists/*

# Install python dependencies
RUN pip install \
  numpy \
  scipy \
  pyyaml \
  pytest

###########################################
# Install Vivado
###########################################

# make /bin/sh symlink to bash instead of dash:
RUN echo "dash dash/sh boolean false" | debconf-set-selections
RUN DEBIAN_FRONTEND=noninteractive dpkg-reconfigure dash

#Copy in Vivado installer and config file
# TODO: is there any way to save image size here?
ADD Xilinx_Vivado_SDK_2017.4_1216_1.tar.gz /
ADD install_config.txt /Xilinx_Vivado_SDK_2017.4_1216_1/
COPY install_config.txt /Xilinx_Vivado_SDK_2017.4_1216_1.tar.gz/

#run the install
RUN /Xilinx_Vivado_SDK_2017.4_1216_1/xsetup --agree 3rdPartyEULA,WebTalkTerms,XilinxEULA --batch Install --config /Xilinx_Vivado_SDK_2017.4_1216_1/install_config.txt

# make a Vivado user
RUN adduser --disabled-password --gecos '' vivado

###########################################
# Finish Vivado prep
###########################################

USER vivado
WORKDIR /home/vivado

#add vivado tools to path
RUN echo "source /opt/Xilinx/Vivado/2017.4/settings64.sh" >> /home/vivado/.bashrc

#copy in the license file
RUN mkdir /home/vivado/.Xilinx
COPY *.lic /home/vivado/.Xilinx/
