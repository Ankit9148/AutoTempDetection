# CMakeList.txt : CMake project for AutoTempDetection, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (AutoTempDetection "AutoTempDetection.cpp" "AutoTempDetection.h" "utils.cpp" "utils.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AutoTempDetection PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
