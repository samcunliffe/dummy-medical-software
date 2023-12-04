cmake_minimum_required(VERSION 3.9)

# Set a name and a version number for your project:
project(
  dummy-medical-software
  VERSION 0.0.1
  LANGUAGES CXX)

# Initialize some default paths
include(GNUInstallDirs)

# Define the minimum C++ standard that is required
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compilation options
option(BUILD_DOCS "Enable building of documentation" ON)

# compile the library
add_subdirectory(src)

# compile the application
add_subdirectory(app)

# compile the tests
include(CTest)
if(BUILD_TESTING)
  add_subdirectory(ext/Catch2)
  include(./ext/Catch2/contrib/Catch.cmake)
  add_subdirectory(tests)
endif()

if(BUILD_DOCS)
  # Add the documentation
  add_subdirectory(doc)
endif()

# Add an alias target for use if this project is included as a subproject in
# another project
add_library(dummy-medical-software::dummy-medical-software ALIAS
            dummy-medical-software)

# Install targets and configuration
install(
  TARGETS dummy-medical-software
  EXPORT dummy-medical-software-config
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
  EXPORT dummy-medical-software-config
  NAMESPACE dummy-medical-software::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dummy-medical-software)

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# This prints a summary of found dependencies
include(FeatureSummary)
feature_summary(WHAT ALL)
