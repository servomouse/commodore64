cmake_minimum_required(VERSION 3.31)
# include(config.cmake)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
project(project_name)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   # Generate compile_commands.json for vscode
include(CTest)

add_subdirectory(lib)
add_subdirectory(devices)
add_subdirectory(tests)

add_executable(commodore64 main.c)

target_link_libraries(commodore64
    PRIVATE
        memory
)
target_include_directories(commodore64
    PRIVATE
        ${TESTS_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set(CMAKE_C_FLAGS "")
set(CMAKE_CXX_FLAGS "")

target_compile_options(commodore64
    PRIVATE
        -Wall
        -Wextra
        -lm
        -g
        -lws2_32
        -fstack-protector-all
)

# target_compile_definitions(commodore64
#     PRIVATE
#         BCKP_DIR_PATH="${PROJECT_SOURCE_DIR}/backups"
# )
