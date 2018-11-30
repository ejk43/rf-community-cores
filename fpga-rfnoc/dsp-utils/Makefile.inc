# RFNoC-specific Makefile for OOT repos

# Save path
RFCC_DSPUTILS_DIR := $(OOT_DIR)

# Append RFNoC source files
RFNOC_SRCS += $(addprefix $(RFCC_DSPUTILS_DIR)/, \
noc_block_ducddc.v \
)
