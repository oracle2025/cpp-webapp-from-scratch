cmake_minimum_required(VERSION 3.18)
project(cpp-webapp-from-scratch)

find_package(Poco REQUIRED COMPONENTS Net Util Data DataSQLite)

add_executable(server src/server_main.cpp)

target_link_libraries(
	server
	PRIVATE Poco::Net
	PRIVATE Poco::Util
	)
