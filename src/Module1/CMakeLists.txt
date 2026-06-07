project(module1)

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/Module1.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${MODULE_TEST_INCLUDE_DIR}/Module1
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    imodule
)