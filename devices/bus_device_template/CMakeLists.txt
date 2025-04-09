set(bus_device_sources
    bus_device_template.c
)

add_library(bus_device_template SHARED ${bus_device_sources})

target_link_libraries(bus_device_template
    PRIVATE
        utils
        bus_device_iface
)

target_include_directories(bus_device_template
    PUBLIC
        ${PROJECT_SOURCE_DIR}/devices/bus_device_template
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set(CMAKE_C_FLAGS "")
set(CMAKE_CXX_FLAGS "")

target_compile_options(bus_device_template
    PRIVATE
        -Wall
        -Wextra
        -lm
        -g
        -lws2_32
        -fstack-protector-all
)

# target_compile_definitions(bus_device_template
#     PRIVATE
#         BCKP_DIR_PATH="${PROJECT_SOURCE_DIR}/backups"
# )