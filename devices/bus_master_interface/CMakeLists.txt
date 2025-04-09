set(bus_master_sources
    bus_master_iface.c
)

add_library(bus_master_iface ${bus_master_sources})

target_link_libraries(bus_master_iface
    PRIVATE
        utils
)

target_include_directories(bus_master_iface
    PUBLIC
        ${PROJECT_SOURCE_DIR}/devices/bus_master_interface
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set(CMAKE_C_FLAGS "")
set(CMAKE_CXX_FLAGS "")

target_compile_options(bus_master_iface
    PRIVATE
        -Wall
        -Wextra
        -lm
        -g
        -lws2_32
        -fstack-protector-all
)

# target_compile_definitions(bus_master_iface
#     PRIVATE
#         BCKP_DIR_PATH="${PROJECT_SOURCE_DIR}/backups"
# )