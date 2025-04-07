# Test CPU bus controller
add_executable(bus_controller_test bus_controller_test.c)

target_link_libraries(bus_controller_test
    PRIVATE
        bus_controller
        utils
)
target_include_directories(bus_controller_test
    PRIVATE
        ${TESTS_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_test(NAME bus_controller_test COMMAND bus_controller_test)
