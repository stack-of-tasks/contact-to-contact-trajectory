# Copyright 2010, Olivier Stasse, JRL, CNRS/AIST
#
# This file is part of jrl-walkgen.
# jrl-walkgen is free software: you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public License
# as published by the Free Software Foundation, either version 3 of
# the License, or (at your option) any later version.
#
# jrl-walkgen is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Lesser Public License for more details.  You should have
# received a copy of the GNU Lesser General Public License along with
# jrl-walkgen. If not, see <http://www.gnu.org/licenses/>.

# Make sure to find Debug.h
INCLUDE_DIRECTORIES(BEFORE ${PROJECT_SOURCE_DIR}/src)


SET(SOURCES
  FootTrajectoryGeneration/FootTrajectoryGenerationAbstract.cpp
  FootTrajectoryGeneration/FootTrajectoryGenerationStandard.cpp
  FootTrajectoryGeneration/FootTrajectoryGenerationMultiple.cpp
  FootTrajectoryGeneration/LeftAndRightFootTrajectoryGenerationMultiple.cpp
  FootTrajectoryGeneration/OnLineFootTrajectoryGeneration.cpp
  Mathematics/Polynome.cpp
  Mathematics/PolynomeFoot.cpp
  )


ADD_LIBRARY(${PROJECT_NAME} SHARED ${SOURCES})
PKG_CONFIG_USE_DEPENDENCY(${PROJECT_NAME} eigen3)
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION})
INSTALL(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_LIBDIR})

