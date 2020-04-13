cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME
        cpphttp)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

list(APPEND CMAKE_MODULE_PATH 
    "${CMAKE_CURRENT_LIST_DIR}/cmake")


set(BUILD_ORM FALSE CACHE INTERNAL "")
set(BUILD_CTL FALSE CACHE INTERNAL "")
set(BUILD_EXAMPLES FALSE CACHE INTERNAL "")
add_subdirectory(ext/drogon)


# this find will just give as interface target
# Drogon::Drogon
# it does not really checks for drogon libraries presence
# it assumes they exists
find_package(Drogon)

add_executable(${PROJECT_NAME}
        main.cpp
        src/controllers/InfoCtrl.cpp)

target_include_directories(${PROJECT_NAME}
    PRIVATE 
        ext/)

target_link_libraries(${PROJECT_NAME}
    PRIVATE 
        Drogon::Drogon)

if (${BUILD_TESTS})
    enable_testing()
    add_subdirectory(ext/googletest)
    add_subdirectory(tests)
endif()

