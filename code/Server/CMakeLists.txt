MESSAGE( "Building server target." )

#directories with headers for this target
INCLUDE_DIRECTORIES( 	${QT_INCLUDES}
						${Boost_INCLUDE_DIRS}
						${UXP1A_SOURCE_DIR}/Server/include
						${UXP1A_SOURCE_DIR}/Shared/include 
)

#if some class inherits QObject (has Q_OBJECT macro) add it's header file here
SET( SERVER_SRC
		${UXP1A_SOURCE_DIR}/Server/src/ClientCommunication.cpp
		${UXP1A_SOURCE_DIR}/Server/include/CommandDispatcher.h
		${UXP1A_SOURCE_DIR}/Server/src/CommandDispatcher.cpp
		${UXP1A_SOURCE_DIR}/Server/src/CommandQueue.cpp
		${UXP1A_SOURCE_DIR}/Server/include/Demand.h
		${UXP1A_SOURCE_DIR}/Server/src/Demand.cpp
		${UXP1A_SOURCE_DIR}/Server/src/RecordTable.cpp
		${UXP1A_SOURCE_DIR}/Server/src/main.cpp
)

add_executable( server ${SERVER_SRC} )

#here add some additional qt modules
TARGET_LINK_LIBRARIES(	server
		${QT_LIBRARIES}
		${Boost_LIBRARIES}
		${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/liblindaShared.a
)
