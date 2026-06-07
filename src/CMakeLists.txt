add_subdirectory(IModule)

add_subdirectory(Module1)
add_subdirectory(Module2)

add_executable(${PROJECT_NAME}
    ${MODULE_TEST_SOURCE_DIR}/main.cpp
    ${MODULE_TEST_SOURCE_DIR}/ModuleImpl.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${MODULE_TEST_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    imodule
)