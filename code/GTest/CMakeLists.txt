MESSAGE( "Building gtest target." )

# Locate GTest
find_package(GTest REQUIRED)

#directories with headers for this target
INCLUDE_DIRECTORIES(    ${QT_INCLUDES}
                        ${Boost_INCLUDE_DIRS}
                        ${UXP1A_SOURCE_DIR}/Shared/include
                        ${UXP1A_SOURCE_DIR}/Server/include
                        ${UXP1A_SOURCE_DIR}/Client/include
                        ${UXP1A_SOURCE_DIR}/GTest/include/Shared
                        ${GTEST_INCLUDE_DIRS}
)
 
#if some class inherits QObject (has Q_OBJECT macro) add it's header file here
SET( GTEST_SRC
        ${UXP1A_SOURCE_DIR}/GTest/src/main.cpp
        ${UXP1A_SOURCE_DIR}/GTest/src/Shared/ParserTest.cpp
        ${UXP1A_SOURCE_DIR}/GTest/src/Shared/ComparisonFactoryTest.cpp
        ${UXP1A_SOURCE_DIR}/GTest/src/Shared/SearchPatternTest.cpp
        ${UXP1A_SOURCE_DIR}/GTest/src/Shared/ConfigurationTest.cpp
)

add_executable( gtestProgram ${GTEST_SRC} )

#here add some additional qt modules
TARGET_LINK_LIBRARIES(  gtestProgram
        ${QT_LIBRARIES}
        ${Boost_LIBRARIES}
        ${Boost_RANDOM_LIBRARY}
        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/liblindaCommunication.a
        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/liblindaShared.a
        ${GTEST_LIBRARIES}
        pthread
)