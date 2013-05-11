MESSAGE( "Building gtest target." )

# Locate GTest
find_package(GTest REQUIRED)

#directories with headers for this target
INCLUDE_DIRECTORIES(    ${QT_INCLUDES}
                        ${Boost_INCLUDE_DIRS}
                        ${UXP1A_SOURCE_DIR}/Shared/include
                        ${UXP1A_SOURCE_DIR}/Server/include
                        ${UXP1A_SOURCE_DIR}/Client/include
                        ${GTEST_INCLUDE_DIRS}
)
 
#if some class inherits QObject (has Q_OBJECT macro) add it's header file here
SET( GTEST_SRC
        ${UXP1A_SOURCE_DIR}/GTest/src/main.cpp
)

add_executable( gtestProgram ${GTEST_SRC} )

#here add some additional qt modules
TARGET_LINK_LIBRARIES(  gtestProgram
        ${QT_LIBRARIES}
        ${Boost_LIBRARIES}
        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/liblindaCommunication.a
        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/liblindaShared.a
        ${GTEST_LIBRARIES}
        pthread
)