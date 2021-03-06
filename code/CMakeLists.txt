cmake_minimum_required (VERSION 2.6) 

#project name
project (UXP1A) 

#look for boost library (required for this project)
FIND_PACKAGE( Boost COMPONENTS thread random REQUIRED )

#look for qt library (required for this project)
FIND_PACKAGE( Qt4 REQUIRED )

#look for doxygen to make documentation
find_package(Doxygen REQUIRED)

INCLUDE( ${QT_USE_FILE} )
ADD_DEFINITIONS(${QT_DEFINITIONS})

SET(QT_DONT_USE_QTGUI TRUE)

#turn on automoc
SET(CMAKE_AUTOMOC TRUE)

SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
SET( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

#subdirectories
add_subdirectory(Shared)
add_subdirectory(Client)
add_subdirectory(Server)
add_subdirectory(Tests)
add_subdirectory(GTest)
add_subdirectory(doxygen)
