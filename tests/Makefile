#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := SDDevice.cpp Partition.cpp MasterBootRecord.cpp BootSector.cpp DirectoryEntry.cpp BootSector_test.cpp

# header files in this project
HEADERS := SDDevice.hpp Partition.hpp MasterBootRecord.hpp BootSector.hpp DirectoryEntry.hpp test.hpp

# other places to look for files for this project
SEARCH  := ../phat

# set RELATIVE to the next higher directory 
# and defer to the appropriate Makefile.* there
RELATIVE := ../..
include $(RELATIVE)/Makefile.native
