# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST CONFIGURE_DEPENDS
        "${Coxeter_SOURCE_DIR}/include/coxeter/*.h"
        "${Coxeter_SOURCE_DIR}/include/coxeter/*.hpp")

file(GLOB SOURCE_LIST CONFIGURE_DEPENDS
        "${Coxeter_SOURCE_DIR}/src/*.cpp")
# list(REMOVE_ITEM SOURCE_LIST "${Coxeter_SOURCE_DIR}/src/salloc.c")

# Make an automatic library - will be static or dynamic based on user setting
add_library(coxeter ${SOURCE_LIST} ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(coxeter PUBLIC ../include)

# All users of this library will need at least C++11
# target_compile_features(coxeter PUBLIC cxx_std_11)

# Cross-platform compiler lints
target_compile_options(coxeter PRIVATE)

set_property(TARGET coxeter PROPERTY POSITION_INDEPENDENT_CODE ON)

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
