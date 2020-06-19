# Copyright (c) Nico Zink
# https://github.com/nicozink/cpp_util.git
# Licensed under GNU General Public License 3.0 or later. 
 
cmake_minimum_required(VERSION 3.0)

if (EXISTS ${CMAKE_SOURCE_DIR}/build_tools/cmake/cmake_utils.cmake)
	include(${CMAKE_SOURCE_DIR}/build_tools/cmake/cmake_utils.cmake)
endif()

#Use solution folders. 
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

PROJECT(cpp_util VERSION 1.0.0)

enable_testing()

find_package(Boost REQUIRED COMPONENTS system)

set(SRC_INCLUDE
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/command_buffer/command_buffer.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/debug/assert.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/event/event.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/event/listener.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/event/observable.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/handle/handle.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/handle/handle_generator.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/log/file_log.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/log/log_level.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/log/log_object.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/log/log_type.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/log/log_writer.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/log/logger_base.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/log/logger.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/log/memory_log.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/log/terminal_log.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/types/automatic_singleton.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/types/memory.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/types/raw_type_to_id.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/types/singleton.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/types/type_to_id.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/types/value_to_id.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/types/variant_list.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/types/variant_map.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/types/variant_type_helper.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/cpp_util/types/variant_type.h)

set(SRC_MAIN
	${CMAKE_CURRENT_SOURCE_DIR}/src/debug/assert.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/handle/handle.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/handle/handle_generator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/log/file_log.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/log/log_level.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/log/log_object.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/log/log_writer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/log/logger_base.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/log/logger.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/log/memory_log.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/log/terminal_log.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/types/memory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/types/type_to_id.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/types/value_to_id.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/types/variant_list.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/types/variant_type.cpp)

set(SRC_TEST
	${CMAKE_CURRENT_SOURCE_DIR}/test/command_buffer/test_command_buffer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/event/test_event.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/log/test_log_move.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/log/test_logger.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/log/test_memory_log.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/types/test_memory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/types/test_type_to_id.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/types/test_value_to_id.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/types/test_variant_list.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/types/test_variant_map.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/types/test_variant_type.cpp)

set(_src_root_path "${CMAKE_CURRENT_SOURCE_DIR}/")

foreach(_source IN ITEMS ${SRC_INCLUDE} ${SRC_MAIN} ${SRC_TEST})
	get_filename_component(_source_path "${_source}" PATH)
	file(RELATIVE_PATH _source_path_rel "${_src_root_path}" "${_source_path}")
	string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
	source_group("${_group_path}" FILES "${_source}")
endforeach()

create_library(cpp_util library ${SRC_INCLUDE} ${SRC_MAIN})

target_link_libraries(cpp_util Boost::system)

target_include_directories(cpp_util
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src)

if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/libraries/unittest/CMakeLists.txt)
	add_subdirectory(libraries/unittest)
endif()

target_compile_features(cpp_util PUBLIC cxx_std_17)

create_library(cpp_util_tests tests ${SRC_TEST})

target_link_libraries(cpp_util_tests cpp_util unittest)

create_executable(cpp_util_test test ${SRC_TEST})

target_link_libraries(cpp_util_test cpp_util unittest)

if (${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
	add_test(NAME cpp_util_test COMMAND node "${CMAKE_CURRENT_BINARY_DIR}/cpp_util_test.js")
else ()
	add_test(NAME cpp_util_test COMMAND cpp_util_test)
endif ()