cmake_minimum_required (VERSION 2.6) 
set(PROJECT SSAD1)
cmake_policy(SET CMP0015 NEW)
project (${PROJECT}) 
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/SFML/cmake/Modules")

set(BOOST_ROOT ./Boost)
find_package(BOOST COMPONENTS filesystem REQUIRED)
set(BOOST_INCLUDE_DIRS ./Boost)
set(BOOST_LIBRARY_DIRS ./Boost/lib)

set(SFML_DIR ./SFML)
find_package(SFML COMPONENTS audio REQUIRED)
set(SFML_INCLUDE_DIRS ./SFML/include)
set(SFML_LIBRARY_DIRS ./SFML/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11 -Wall")

set (HEADERS 
	SSAD1/Playable.h
	SSAD1/Player.h
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
	SSAD1/Playlist.cpp
	SSAD1/PlaylistIterator.cpp
	SSAD1/PlaylistIteratorImpl.cpp
	SSAD1/PlaylistIteratorPlainImpl.cpp
	SSAD1/PlaylistIteratorShuffleImpl.cpp
	SSAD1/Track.cpp
	SSAD1/TrackList.cpp
	SSAD1/TrackListPosition.cpp
	SSAD1/main.cpp)

include_directories(${BOOST_INCLUDE_DIR})
include_directories(${SFML_INCLUDE_DIR})

link_directories(${BOOST_LIBRARY_DIRS})
link_directories(${SFML_LIBRARY_DIRS})

add_executable (${PROJECT} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT} ${BOOST_LIBRARIES})
target_link_libraries(${PROJECT} ${SFML_LIBRARIES})
