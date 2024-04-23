add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE lr1_lib)
target_link_libraries(${PROJECT_NAME} PRIVATE lr1_services_tests)
target_link_libraries(${PROJECT_NAME} PRIVATE lr1_services_file)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})