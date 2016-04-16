cmake_minimum_required (VERSION 2.6) 
set(PROJECT SSAD1)
cmake_policy(SET CMP0015 NEW)
project (${PROJECT}) 
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/SFML/cmake/Modules")

set(BOOST_ROOT Boost)
find_package(Boost COMPONENTS filesystem REQUIRED)

set(SFML_ROOT SFML)
find_package(SFML COMPONENTS audio REQUIRED)

set (HEADERS 
	SSAD1/Playable.h
	SSAD1/Player.h
	SSAD1/PlayerCLI.h
	SSAD1/Playlist.h
	SSAD1/PlaylistIterator.h
	SSAD1/PlaylistIteratorImpl.h
	SSAD1/PlaylistIteratorPlainImpl.h
	SSAD1/PlaylistIteratorShuffleImpl.h
	SSAD1/Track.h
	SSAD1/TrackList.h
	SSAD1/TrackListPosition.h)

set (SOURCES 
	SSAD1/Playable.cpp
	SSAD1/Player.cpp
	SSAD1/PlayerCLI.cpp
	SSAD1/Playlist.cpp
	SSAD1/PlaylistIterator.cpp
	SSAD1/PlaylistIteratorImpl.cpp
	SSAD1/PlaylistIteratorPlainImpl.cpp
	SSAD1/PlaylistIteratorShuffleImpl.cpp
	SSAD1/Track.cpp
	SSAD1/TrackList.cpp
	SSAD1/TrackListPosition.cpp
	SSAD1/main.cpp)

include_directories(${Boost_INCLUDE_DIR})
include_directories(${SFML_INCLUDE_DIR})

link_directories(${Boost_LIBRARY_DIRS})
link_directories(${SFML_LIBRARY_DIRS})

add_executable (${PROJECT} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT} ${BOOST_LIBRARIES})
target_link_libraries(${PROJECT} ${SFML_LIBRARIES})