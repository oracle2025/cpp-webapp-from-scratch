cmake_minimum_required(VERSION 3.18)
project(cpp-webapp-from-scratch)

set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR}/lib/cmake)

#include(ExternalProject)


#ExternalProject_Add(
	#libpoco
	#GIT_REPOSITORY https://github.com/pocoproject/poco.git
	#GIT_TAG poco-1.12.4-release
	#GIT_SHALLOW ON
	#GIT_PROGRESS OFF
	#INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
	#CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}
	#-DENABLE_ENCODINGS=OFF
	#-DENABLE_XML=ON
	#-DENABLE_JSON=ON
	#-DENABLE_MONGODB=OFF
	#-DENABLE_DATA_SQLITE=ON
	#-DENABLE_REDIS=OFF
	#-DENABLE_PDF=OFF
	#-DENABLE_ZIP=OFF
	#-DENABLE_PAGECOMPILER=OFF
	#-DENABLE_PAGECOMPILER_FILE2PAGE=OFF
       # -DENABLE_DATA=ON)

find_package(Poco REQUIRED COMPONENTS Net Util Data DataSQLite)

add_executable(server
	src/server_main.cpp
	src/SimpleRequestHandler.cpp
	src/SimpleRequestHandler.hpp
		src/IndexTemplate.cpp
		src/IndexTemplate.hpp
		src/CrudController.cpp
		src/CrudController.hpp
		src/Router.cpp
		src/Router.hpp
		src/RouteId.cpp
		src/RouteId.hpp
		src/HomeTemplate.cpp
		src/HomeTemplate.hpp
)

target_link_libraries(
	server
	PRIVATE Poco::Net
	PRIVATE Poco::Util
	)
