cmake_minimum_required(VERSION 3.12)

project(ThutoLibrary VERSION 0.2 DESCRIPTION "Misc library")

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
			NAME ut
			VERSION 1.1.8
			GITHUB_REPOSITORY "boost-ext/ut"
			GIT_TAG dbb3cabe219322f2ced8d87056c2421edd7cce2d
		)

		include(addTest)
		add_subdirectory(test)
	endif()
endif()