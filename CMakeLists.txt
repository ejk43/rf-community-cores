# Todo: Header, copyright, license

########################################################################
# Initialize project
########################################################################
cmake_minimum_required(VERSION 2.8.2)
project(rf-community-cores)

########################################################################
# Conditionally include desired components
########################################################################

# Check for UHD
IF(NOT DEFINED ENABLE_UHD)
    set(ENABLE_UHD "ON")
ENDIF()
IF(ENABLE_UHD)
    add_subdirectory(uhd-rfcc)
ENDIF(ENABLE_UHD)

# Check for Gnuradio
IF(NOT DEFINED ENABLE_GNURADIO)
    set(ENABLE_GNURADIO "ON")
ENDIF()
IF(ENABLE_GNURADIO)
    IF(ENABLE_UHD)
        add_subdirectory(gr-rfcc)
    ELSE(ENABLE_UHD)
        message(FATAL_ERROR "ENABLE_UHD required in order to run with ENABLE_GNURADIO")
    ENDIF(ENABLE_UHD)
ENDIF(ENABLE_GNURADIO)
