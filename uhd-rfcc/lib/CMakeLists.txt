
########################################################################
# Setup library
########################################################################
include_directories(
    ${UHD_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
)
link_directories(
  ${UHD_LIBRARY_DIRS}
  ${Boost_LIBRARY_DIRS}
 )

list(APPEND uhd_rfcc_sources
	ducddc_block_ctrl_impl.cpp
)

set(uhd_rfcc_sources "${uhd_rfcc_sources}" PARENT_SCOPE)

add_library(uhd-rfcc SHARED ${uhd_rfcc_sources})
target_link_libraries(uhd-rfcc ${Boost_LIBRARIES} ${ETTUS_LIBRARIES})
set_target_properties(uhd-rfcc PROPERTIES DEFINE_SYMBOL "uhd_rfcc_EXPORTS")

########################################################################
# Install built library files
########################################################################
install(TARGETS uhd-rfcc
    LIBRARY DESTINATION lib${LIB_SUFFIX} # .so/.dylib file
    ARCHIVE DESTINATION lib${LIB_SUFFIX} # .lib file
    RUNTIME DESTINATION bin              # .dll file
)
