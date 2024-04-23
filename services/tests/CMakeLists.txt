add_library(lr1_services_tests generate_tests.cpp generate_tests.h
)

target_link_libraries(
        lr1_lib
        lr1_services_tests
        lr1_services_file
)