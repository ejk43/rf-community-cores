# RF Community Cores

Welcome to the RF Community Cores repo -- where the community creates open
source FPGA cores for RF processing.

> That's what the community calls you. I'm glad you like it, I guess

We started this repo because we noticed a profound lack of open-source FPGA
code for digital signal processing applications, and in particular RF signal
processing. This is intended to be a centralized location for shared, supported
code that can be maintained and used in the future.

Notionally, FPGA code here may be standalone; or it may tie into the [RFNoC
FPGA framework](https://www.ettus.com/sdr-software/detail/rf-network-on-chip).
The repo maintainers are, for the most part, RFNoC users, so the repo will
likely trend towards providing RFNoC support across FPGA and software. However,
it remains a fair use case to interact with primarily the standalone FPGA
code if desired, but your mileage may vary, of course.

## Organization

This repo is broken into several subfolders which the user may interact with
in number of "supported" ways:

- **fpga-src**: Standalone FPGA source code! Amazing!
- **fpga-rfnoc**: FPGA code that *depends on* the RFNoC codebase
([uhd-fpga](https://github.com/ettusresearch/fpga)), including RFNoC
FPGA testbenches.
- **uhd-rfcc**: RFNoC-based software drivers, C++ only. These software blocks
link to the public RFNoC API provided in the [UHD repo](https://github.com/ettusresearch/fpga).
The uhd-rfcc project is designed to be compatible with a project that
*only* depends on UHD (no gnuradio).
- **gr-rfcc**: Gnuradio plugins to access RFNoC blocks from gnuradio companion
and inside a gnuradio flowgraph.

## FPGA Builds and Testbenches

FPGA code in the `fpga-src` folder is a "wild west", as it is designed to be
basic standalone code with minimal pre-requirements. See each project
individually for details.

The testbenches in `fpga-rfnoc` may be run in an RFNoC simulation
(`make xsim`). The testbenches are designed to be "self-checking" so they will
run to completion and indicate success or failure. However, consistent with
the RFNoC workflow, testbenches may also be run with `make xsim GUI=1` to
bring up the Vivado waveform viewer for debugging.

## Software Builds

Feature flags are exposed via CMake to enable UHD or Gnuradio software builds:

- ENABLE_UHD: Turns on the build of uhd-rfcc
- ENABLE_GNURADIO: Turns on the build of gr-rfcc

For example, the following cmake process will build and install all software
source code to a prefix of `/home/user/prefix/gnuradio` (this assumes a
pybombs prefix is initialized and includes the uhd, gnuradio, and gr-ettus
repos):

```
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX /home/user/prefix/gnuradio -DENABLE_UHD=ON -DENABLE_GNURADIO=ON
make
make install
```
