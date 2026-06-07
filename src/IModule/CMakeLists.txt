project(imodule)

add_library(${PROJECT_NAME} INTERFACE
)

target_include_directories(${PROJECT_NAME} INTERFACE
    ${MODULE_TEST_INCLUDE_DIR}
)