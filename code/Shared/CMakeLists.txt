MESSAGE( "Building shared target." )

#directories with headers for this target
INCLUDE_DIRECTORIES( 	${QT_INCLUDES}
						${Boost_INCLUDE_DIRS}
						${UXP1A_SOURCE_DIR}/Shared/include 
)

#if some class inherits QObject (has Q_OBJECT macro) add it's header file here
SET( SHARED_SRC
		${UXP1A_SOURCE_DIR}/Shared/src/ComparisonFactory.cpp
		${UXP1A_SOURCE_DIR}/Shared/src/Condition.cpp
		${UXP1A_SOURCE_DIR}/Shared/src/Configuration.cpp
		${UXP1A_SOURCE_DIR}/Shared/src/Functor.cpp
		${UXP1A_SOURCE_DIR}/Shared/src/Parser.cpp
		${UXP1A_SOURCE_DIR}/Shared/src/SearchPattern.cpp
)

add_library( lindaShared STATIC ${SHARED_SRC} )

#here add some additional qt modules
TARGET_LINK_LIBRARIES(	lindaShared
		${QT_LIBRARIES}
		${Boost_LIBRARIES}
)
