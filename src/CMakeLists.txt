add_library(dummy-medical-software dummy-medical-software.cpp)
target_include_directories(
  dummy-medical-software
  PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
