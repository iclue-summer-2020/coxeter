add_executable(coxeter-bin main.cpp)
# target_compile_features(coxeter-bin PRIVATE cxx_std_17)
target_link_libraries(coxeter-bin PRIVATE coxeter)

# Cross-platform compiler lints
target_compile_options(coxeter-bin PRIVATE
        #-Wall
        #-Wextra
        #-Wswitch
        #-Wconversion
        #-Wparentheses
        #-Wfloat-equal
        #-Wzero-as-null-pointer-constant
        #-Wpedantic
        #-pedantic
        #-pedantic-errors
)

set_target_properties(coxeter-bin PROPERTIES OUTPUT_NAME coxeter)

add_custom_command(
        TARGET coxeter-bin
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -DSRC_DIR="${CMAKE_SOURCE_DIR}/data" -DDEST_DIR="${CMAKE_CURRENT_BINARY_DIR}/data" -P "${CMAKE_SOURCE_DIR}/cmake/configure_files.cmake"
)