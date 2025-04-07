set(memory_sources
    memory.c
)

add_library(memory ${memory_sources})

target_link_libraries(memory
    PRIVATE
        utils
)

target_include_directories(memory
    PUBLIC
        ${PROJECT_SOURCE_DIR}/devices/memory
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set(CMAKE_C_FLAGS "")
set(CMAKE_CXX_FLAGS "")

target_compile_options(memory
    PRIVATE
        -Wall
        -Wextra
        -lm
        -g
        -lws2_32
        -fstack-protector-all
)

# target_compile_definitions(memory
#     PRIVATE
#         BCKP_DIR_PATH="${PROJECT_SOURCE_DIR}/backups"
# )