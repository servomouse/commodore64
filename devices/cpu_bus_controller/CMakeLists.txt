set(bus_controller_sources
    bus_controller.c
)

add_library(bus_controller ${bus_controller_sources})

target_link_libraries(bus_controller
    PRIVATE
        utils
)

target_include_directories(bus_controller
    PUBLIC
        ${PROJECT_SOURCE_DIR}/devices/bus_controller
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set(CMAKE_C_FLAGS "")
set(CMAKE_CXX_FLAGS "")

target_compile_options(bus_controller
    PRIVATE
        -Wall
        -Wextra
        -lm
        -g
        -lws2_32
        -fstack-protector-all
)

# target_compile_definitions(bus_controller
#     PRIVATE
#         BCKP_DIR_PATH="${PROJECT_SOURCE_DIR}/backups"
# )