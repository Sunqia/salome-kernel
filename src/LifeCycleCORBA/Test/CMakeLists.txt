# Copyright (C) 2012-2014  CEA/DEN, EDF R&D, OPEN CASCADE
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
# See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
#

INCLUDE_DIRECTORIES(
  ${PTHREAD_INCLUDE_DIR}
  ${CPPUNIT_INCLUDE_DIRS}
  ${OMNIORB_INCLUDE_DIR}
  ${PROJECT_BINARY_DIR}/salome_adm
  ${CMAKE_CURRENT_SOURCE_DIR}/../../Basics
  ${CMAKE_CURRENT_SOURCE_DIR}/../../Basics/Test
  ${CMAKE_CURRENT_SOURCE_DIR}/../../SALOMELocalTrace
  ${CMAKE_CURRENT_SOURCE_DIR}/../../SALOMELocalTrace/Test
  ${CMAKE_CURRENT_SOURCE_DIR}/../../SALOMETraceCollector
  ${CMAKE_CURRENT_SOURCE_DIR}/../../SALOMETraceCollector/Test
  ${CMAKE_CURRENT_SOURCE_DIR}/../../NamingService
  ${CMAKE_CURRENT_SOURCE_DIR}/../../NamingService/Test
  ${CMAKE_CURRENT_SOURCE_DIR}/../../Utils
  ${CMAKE_CURRENT_SOURCE_DIR}/../../Utils/Test
  ${CMAKE_CURRENT_SOURCE_DIR}/../../ResourcesManager
  ${CMAKE_CURRENT_SOURCE_DIR}/../../LifeCycleCORBA
  ${PROJECT_BINARY_DIR}/idl
)

SET(COMMON_LIBS
  ${CPPUNIT_LIBRARIES}
  SALOMEBasics
  SalomeResourcesManager
  SalomeContainer
  SalomeNS
  Registry
  SalomeNotification
  UtilsTest
  OpUtil
  SALOMELocalTraceTest
  SALOMELocalTrace
  SALOMETraceCollectorTest
  SalomeIDLKernel
  SalomeLifeCycleCORBA
  ${OMNIORB_LIBRARIES}
)

ADD_DEFINITIONS(${CPPUNIT_DEFINITIONS} ${OMNIORB_DEFINITIONS})

ADD_LIBRARY(LifeCycleCORBATest LifeCycleCORBATest.cxx)
TARGET_LINK_LIBRARIES(LifeCycleCORBATest ${COMMON_LIBS})
INSTALL(TARGETS LifeCycleCORBATest DESTINATION ${SALOME_INSTALL_LIBS})

ADD_EXECUTABLE(TestLifeCycleCORBA TestLifeCycleCORBA.cxx)
TARGET_LINK_LIBRARIES(TestLifeCycleCORBA LifeCycleCORBATest NamingServiceTest SalomeLifeCycleCORBA ${COMMON_LIBS})
INSTALL(TARGETS TestLifeCycleCORBA DESTINATION ${SALOME_INSTALL_BINS})

# Executable scripts to be installed
SALOME_INSTALL_SCRIPTS(TestLifeCycleCORBA.py ${SALOME_INSTALL_SCRIPT_PYTHON})

FILE(GLOB COMMON_HEADERS_HXX "${CMAKE_CURRENT_SOURCE_DIR}/*.hxx")
INSTALL(FILES ${COMMON_HEADERS_HXX} DESTINATION ${SALOME_INSTALL_HEADERS})