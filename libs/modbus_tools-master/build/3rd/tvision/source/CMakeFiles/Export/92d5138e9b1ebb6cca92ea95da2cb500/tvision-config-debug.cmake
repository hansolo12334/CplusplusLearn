#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tvision::tvision" for configuration "Debug"
set_property(TARGET tvision::tvision APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(tvision::tvision PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libtvision.a"
  )

list(APPEND _cmake_import_check_targets tvision::tvision )
list(APPEND _cmake_import_check_files_for_tvision::tvision "${_IMPORT_PREFIX}/lib/libtvision.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
