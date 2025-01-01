cmake_minimum_required(VERSION 3.0)

project(G_0_debug VERSION 1.0 LANGUAGES C)

set(SOURCES
  src/abort.c
  src/die.c
)

add_library(G_0_debug_static STATIC ${SOURCES})
set_target_properties(G_0_debug_static PROPERTIES
  OUTPUT_NAME "-0_debug"
  POSITION_INDEPENDENT_CODE ON
)

add_library(G_0_debug_shared SHARED ${SOURCES})
set_target_properties(G_0_debug_shared PROPERTIES
  OUTPUT_NAME "-0_debug"
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
)

target_include_directories(G_0_debug_static
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/external_include
)

target_include_directories(G_0_debug_shared
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/external_include
)

target_compile_definitions(G_0_debug_static
  PRIVATE G_SHARED=0
)

target_compile_definitions(G_0_debug_shared
  PRIVATE G_SHARED=1
)

install(TARGETS G_0_debug_static G_0_debug_shared
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(
  FILES
    include/-0_debug.h
  DESTINATION
    include
)

install(
  FILES
    include/-0/debug.h
    include/-0/debug_types.h
    include/-0/debug_shortcut.h
  DESTINATION
    include/-0
)
