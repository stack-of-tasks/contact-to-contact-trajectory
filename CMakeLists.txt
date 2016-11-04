# Copyright 2016, Olivier Stasse, LAAS, CNRS
#
# This file is part of contact-to-contact-trajectory.
# contact-to-contact-trajectory is free software: you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public License
# as published by the Free Software Foundation, either version 3 of
# the License, or (at your option) any later version.
#
# contact-to-contact-trajectory is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Lesser Public License for more details.  You should have
# received a copy of the GNU Lesser General Public License along with
# contact-to-contact-trajectory. If not, see <http://www.gnu.org/licenses/>.

# Requires at least CMake 2.6 to configure the package.
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# Includes from jrl-cmaketools
INCLUDE(cmake/base.cmake)
INCLUDE(cmake/eigen.cmake)

# Define properties of the project
SET(PROJECT_NAME contact-to-contact-trajectory)
SET(PROJECT_DESCRIPTION "Contact to contact trajectory for end-effectors")
SET(PROJECT_URL "")


SET(CXX_DISABLE_WERROR True)

# Initialize generic properties of the project
SETUP_PROJECT()


# Add aggressive optimization flags in release mode.
IF(CMAKE_COMPILER_IS_GNUCXX)
  SET (CMAKE_CXX_FLAGS_RELEASE
    "-O3 -DNDEBUG")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

#IF(CMAKE_COMPILER_IS_GNUCXX)
#  SET (CMAKE_CXX_FLAGS_RELEASE
#    "-O3 -funroll-loops -frerun-loop-opt -fschedule-insns2")
#  SET (CMAKE_CXX_FLAGS_RELEASE
#    "${CMAKE_CXX_FLAGS_RELEASE} -frerun-cse-after-loop -falign-functions")
#  SET (CMAKE_CXX_FLAGS_RELEASE
#    "${CMAKE_CXX_FLAGS_RELEASE} -falign-labels -falign-loops -falign-jumps")
#  SET (CMAKE_CXX_FLAGS_RELEASE
#    "${CMAKE_CXX_FLAGS_RELEASE} -fexpensive-optimizations")
#ENDIF(CMAKE_COMPILER_IS_GNUCXX)

ADD_REQUIRED_DEPENDENCY("eigen3 >= 3.0.5")

# Define subdirectories to explore for cmake
ADD_SUBDIRECTORY(src)

# Generate dependency to contact-to-contact-trajectory in pc file
PKG_CONFIG_APPEND_LIBS("contact-to-contact-trajectory")

# Ask to generate the final steps.
SETUP_PROJECT_FINALIZE()
