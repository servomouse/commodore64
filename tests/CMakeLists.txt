set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(bus_controller_test)

add_custom_target(runtests
    COMMAND ${CMAKE_CTEST_COMMAND}
    DEPENDS
        bus_controller_test
)