cmake_minimum_required (VERSION 2.6) 
set(PROJECT SSAD1)
project (${PROJECT}) 

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
include_directories (../../../)
set (LIBRARIES
		boost_1_60_0
		SFML-2.3.2-32)
 
foreach (LIBRARY ${LIBRARIES})
	add_subdirectory (../${LIBRARY}/build bin/${LIBRARY})
endforeach ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set (HEADERS 
	Playable.h
	Player.h
	Playlist.h
	PlaylistIterator.h
	PlaylistIteratorImpl.h
	PlaylistIteratorPlainImpl.h
	PlaylistIteratorShuffleImpl.h
	Track.h
	TrackList.h
	TrackListPosition.h)

set (SOURCES 
	Playable.cpp
	Player.cpp
	Playlist.cpp
	PlaylistIterator.cpp
	PlaylistIteratorImpl.cpp
	PlaylistIteratorPlainImpl.cpp
	PlaylistIteratorShuffleImpl.cpp
	Track.cpp
	TrackList.cpp
	TrackListPosition.cpp
	main.cpp)

add_executable (${PROJECT} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT} ${Boost_LIBRARIES})
