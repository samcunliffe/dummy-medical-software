add_executable(tests tests.cpp dummy-medical-software_t.cpp)
target_link_libraries(tests PUBLIC dummy-medical-software Catch2::Catch2)

# allow user to run tests with `make test` or `ctest`
catch_discover_tests(tests)
