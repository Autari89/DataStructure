cmake_minimum_required(VERSION 3.22)

project(GraphExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(GraphExample)

target_sources(${PROJECT_NAME}
	PRIVATE
		src/main.cpp
        src/Graph.cpp
		src/Graph.hpp
)

target_link_options(${PROJECT_NAME}
	PRIVATE
		$<$<PLATFORM_ID:Windows>:/SUBSYSTEM:CONSOLE>
)

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		$<$<PLATFORM_ID:Windows>:setupapi.lib>
		$<$<PLATFORM_ID:Windows>:wtsapi32.lib>
)

target_compile_definitions(${PROJECT_NAME}
	PRIVATE
		$<$<PLATFORM_ID:Windows>:_UNICODE>
		$<$<PLATFORM_ID:Windows>:UNICODE>
)
