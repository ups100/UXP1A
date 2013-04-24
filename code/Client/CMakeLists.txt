MESSAGE( "Building client target." )

#directories with headers for this target
INCLUDE_DIRECTORIES( 	${QT_INCLUDES}
						${Boost_INCLUDE_DIRS}
						${UXP1A_SOURCE_DIR}/Client/include
						${UXP1A_SOURCE_DIR}/Shared/include 
)

#if some class inherits QObject (has Q_OBJECT macro) add it's header file here
SET( CLIENT_SRC
		${UXP1A_SOURCE_DIR}/Client/src/FromServerPipe.cpp
		${UXP1A_SOURCE_DIR}/Client/src/LindaClient.cpp
		${UXP1A_SOURCE_DIR}/Client/src/ServerCommunication.cpp
		${UXP1A_SOURCE_DIR}/Client/src/ToServerPipe.cpp
		
)

add_library( lindaCommunication STATIC ${CLIENT_SRC} )

#here add some additional qt modules
TARGET_LINK_LIBRARIES(	lindaCommunication
		${QT_LIBRARIES}
		${Boost_LIBRARIES}
		${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/liblindaShared.a
)
