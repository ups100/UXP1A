MESSAGE( "Building tests target." )

#directories with headers for this target
INCLUDE_DIRECTORIES( 	${QT_INCLUDES}
						${Boost_INCLUDE_DIRS}
						${UXP1A_SOURCE_DIR}/Tests/include
						${UXP1A_SOURCE_DIR}/Shared/include
						${UXP1A_SOURCE_DIR}/Client/include
						${UXP1A_SOURCE_DIR}/Server/include
)

#if some class inherits QObject (has Q_OBJECT macro) add it's header file here
SET( TESTS_SRC
		${UXP1A_SOURCE_DIR}/Tests/src/main.cpp
		${UXP1A_SOURCE_DIR}/Tests/src/fifoTest.cpp
		${UXP1A_SOURCE_DIR}/Tests/src/ManualLinda.cpp
)

add_executable( testProgram ${TESTS_SRC} )

#here add some additional qt modules
TARGET_LINK_LIBRARIES(	testProgram
		${QT_LIBRARIES}
		${Boost_LIBRARIES}
		${Boost_THREAD_LIBRARY}
		${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/liblindaCommunication.a
		${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/liblindaShared.a
)
