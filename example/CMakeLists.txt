cmake_minimum_required(VERSION 3.0)

project(example_project LANGUAGES C)

if(BUILD_CONFIG STREQUAL "Debug")
    set(INCLUDE_DIR "out_super_debug/include")
    set(LIB_DIR "out_super_debug/lib")
elseif(BUILD_CONFIG STREQUAL "Release")
    set(INCLUDE_DIR "out_super_release/include")
    set(LIB_DIR "out_super_release/lib")
else()
    message(FATAL_ERROR "Unknown BUILD_CONFIG: ${BUILD_CONFIG}. Must be 'Debug' or 'Release'.")
endif()

add_executable(example main.c)

target_include_directories(example PRIVATE ${INCLUDE_DIR})

get_filename_component(ABS_LIB_DIR "${LIB_DIR}" ABSOLUTE)
target_link_libraries(example PRIVATE "${ABS_LIB_DIR}/-0_debug$<IF:$<PLATFORM_ID:Windows>,.lib,.a>")

install(TARGETS example
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)
