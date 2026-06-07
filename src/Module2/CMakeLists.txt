project(module2)

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/Module2.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${MODULE_TEST_INCLUDE_DIR}/Module2
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    imodule
)