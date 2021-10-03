file(GLOB SOURCE_LIST CONFIGURE_DEPENDS
        "${Coxeter_SOURCE_DIR}/tests/*.h"
        "${Coxeter_SOURCE_DIR}/tests/*.hpp"
        "${Coxeter_SOURCE_DIR}/tests/*.cpp")

# This target runs all of the tests.
# Make sure CATCH_CONFIG_MAIN is only defined in one test file.
add_executable(test-coxeter ${SOURCE_LIST})

# We're using C++17 in the test
# target_compile_features(test-coxeter PRIVATE cxx_std_17)

# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(test-coxeter PRIVATE coxeter)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME test-coxeter COMMAND test-coxeter) # Command can be a target

# Add folders
set_target_properties(test-coxeter PROPERTIES FOLDER iclue)

# Cross-platform compiler lints
target_compile_options(test-coxeter PRIVATE
        # -Wall
        # -Wextra
        # -Wswitch
        # -Wconversion
        # -Wparentheses
        # -Wfloat-equal
        # -Wzero-as-null-pointer-constant
        #-Wpedantic
)

add_custom_command(
        TARGET test-coxeter
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -DSRC_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data" -DDEST_DIR="${CMAKE_CURRENT_BINARY_DIR}/data" -P "${CMAKE_SOURCE_DIR}/cmake/configure_files.cmake"
)

