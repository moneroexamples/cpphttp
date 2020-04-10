macro(add_my_test _TEST_NAME)

    add_executable(${_TEST_NAME}_tests
            ${_TEST_NAME}_tests.cpp)

    target_link_libraries(${_TEST_NAME}_tests
            gtest gtest_main
            gmock gmock_main
            Drogon::Drogon)

    target_include_directories(${_TEST_NAME}_tests
        PRIVATE 
            ../ext/)

    add_test(NAME ${_TEST_NAME}_tests COMMAND ${_TEST_NAME}_tests)

endmacro()

add_my_test(unit)


