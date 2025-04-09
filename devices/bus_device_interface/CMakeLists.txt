set(bus_device_sources
    bus_device_iface.c
)

add_library(bus_device_iface ${bus_device_sources})

target_link_libraries(bus_device_iface
    PUBLIC
        utils
        # memory
        # bus_controller
)

get_target_property(bus_controller_path bus_controller INCLUDE_DIRECTORIES)

target_include_directories(bus_device_iface
    PUBLIC
        ${bus_controller_path}
        ${PROJECT_SOURCE_DIR}/devices/bus_device_interface
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set(CMAKE_C_FLAGS "")
set(CMAKE_CXX_FLAGS "")

target_compile_options(bus_device_iface
    PRIVATE
        -Wall
        -Wextra
        -lm
        -g
        -lws2_32
        -fstack-protector-all
)

# target_compile_definitions(bus_device_iface
#     PRIVATE
#         BCKP_DIR_PATH="${PROJECT_SOURCE_DIR}/backups"
# )