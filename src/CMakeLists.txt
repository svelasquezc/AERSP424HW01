file(GLOB HEADER_LIST CMAKE_CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/Aircraft/*.hpp")

add_library(aircraft ${HEADER_LIST})

add_subdirectory(Aircraft)
# We need this directory, and users of our library will need it too
target_include_directories(aircraft PUBLIC ../include)

# All users of this library will need at least C++17
target_compile_features(aircraft PUBLIC cxx_std_17)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
