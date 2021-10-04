cmake_minimum_required(VERSION 3.12)

project(ThutoLibrary VERSION 1.0.0 DESCRIPTION "Misc library")

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")

option(EXAMPLE "EXAMPLE" ON)
option(TESTS "TESTS" ON)

include(CPM)

add_subdirectory(lib)

if (EXAMPLE)
	add_subdirectory(bin)
endif()                   
  
if (TESTS)
	include(CTest)
	if(BUILD_TESTING)
		CPMAddPackage(
			NAME doctest
			GITHUB_REPOSITORY onqtam/doctest
			GIT_TAG 2.4.5
		)

		include(addTest)
		add_subdirectory(test)
	endif()
endif()