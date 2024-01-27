# generated from catkin/cmake/template/pkgConfig.cmake.in

# append elements to a list and remove existing duplicates from the list
# copied from catkin/cmake/list_append_deduplicate.cmake to keep pkgConfig
# self contained
macro(_list_append_deduplicate listname)
  if(NOT "${ARGN}" STREQUAL "")
    if(${listname})
      list(REMOVE_ITEM ${listname} ${ARGN})
    endif()
    list(APPEND ${listname} ${ARGN})
  endif()
endmacro()

# append elements to a list if they are not already in the list
# copied from catkin/cmake/list_append_unique.cmake to keep pkgConfig
# self contained
macro(_list_append_unique listname)
  foreach(_item ${ARGN})
    list(FIND ${listname} ${_item} _index)
    if(_index EQUAL -1)
      list(APPEND ${listname} ${_item})
    endif()
  endforeach()
endmacro()

# pack a list of libraries with optional build configuration keywords
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_pack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  set(_argn ${ARGN})
  list(LENGTH _argn _count)
  set(_index 0)
  while(${_index} LESS ${_count})
    list(GET _argn ${_index} lib)
    if("${lib}" MATCHES "^(debug|optimized|general)$")
      math(EXPR _index "${_index} + 1")
      if(${_index} EQUAL ${_count})
        message(FATAL_ERROR "_pack_libraries_with_build_configuration() the list of libraries '${ARGN}' ends with '${lib}' which is a build configuration keyword and must be followed by a library")
      endif()
      list(GET _argn ${_index} library)
      list(APPEND ${VAR} "${lib}${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}${library}")
    else()
      list(APPEND ${VAR} "${lib}")
    endif()
    math(EXPR _index "${_index} + 1")
  endwhile()
endmacro()

# unpack a list of libraries with optional build configuration keyword prefixes
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_unpack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  foreach(lib ${ARGN})
    string(REGEX REPLACE "^(debug|optimized|general)${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}(.+)$" "\\1;\\2" lib "${lib}")
    list(APPEND ${VAR} "${lib}")
  endforeach()
endmacro()


if(proto_msg_CONFIG_INCLUDED)
  return()
endif()
set(proto_msg_CONFIG_INCLUDED TRUE)

# set variables for source/devel/install prefixes
if("TRUE" STREQUAL "TRUE")
  set(proto_msg_SOURCE_PREFIX /home/hansolo/CplusplusLearn/ProtobufLearn/src/catkin_ws/src/proto_msg)
  set(proto_msg_DEVEL_PREFIX /home/hansolo/CplusplusLearn/ProtobufLearn/src/catkin_ws/devel/.private/proto_msg)
  set(proto_msg_INSTALL_PREFIX "")
  set(proto_msg_PREFIX ${proto_msg_DEVEL_PREFIX})
else()
  set(proto_msg_SOURCE_PREFIX "")
  set(proto_msg_DEVEL_PREFIX "")
  set(proto_msg_INSTALL_PREFIX /home/hansolo/CplusplusLearn/ProtobufLearn/src/catkin_ws/install)
  set(proto_msg_PREFIX ${proto_msg_INSTALL_PREFIX})
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "WARNING: package 'proto_msg' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  message("${_msg}")
endif()

# flag project as catkin-based to distinguish if a find_package()-ed project is a catkin project
set(proto_msg_FOUND_CATKIN_PROJECT TRUE)

if(NOT "/home/hansolo/CplusplusLearn/ProtobufLearn/src/catkin_ws/src/proto_msg/include;/home/hansolo/CplusplusLearn/ProtobufLearn/src/catkin_ws/build/proto_msg/.. " STREQUAL " ")
  set(proto_msg_INCLUDE_DIRS "")
  set(_include_dirs "/home/hansolo/CplusplusLearn/ProtobufLearn/src/catkin_ws/src/proto_msg/include;/home/hansolo/CplusplusLearn/ProtobufLearn/src/catkin_ws/build/proto_msg/..")
  if(NOT " " STREQUAL " ")
    set(_report "Check the issue tracker '' and consider creating a ticket if the problem has not been reported yet.")
  elseif(NOT " " STREQUAL " ")
    set(_report "Check the website '' for information and consider reporting the problem.")
  else()
    set(_report "Report the problem to the maintainer 'hansolo <hansolo@todo.todo>' and request to fix the problem.")
  endif()
  foreach(idir ${_include_dirs})
    if(IS_ABSOLUTE ${idir} AND IS_DIRECTORY ${idir})
      set(include ${idir})
    elseif("${idir} " STREQUAL "include ")
      get_filename_component(include "${proto_msg_DIR}/../../../include" ABSOLUTE)
      if(NOT IS_DIRECTORY ${include})
        message(FATAL_ERROR "Project 'proto_msg' specifies '${idir}' as an include dir, which is not found.  It does not exist in '${include}'.  ${_report}")
      endif()
    else()
      message(FATAL_ERROR "Project 'proto_msg' specifies '${idir}' as an include dir, which is not found.  It does neither exist as an absolute directory nor in '/home/hansolo/CplusplusLearn/ProtobufLearn/src/catkin_ws/src/proto_msg/${idir}'.  ${_report}")
    endif()
    _list_append_unique(proto_msg_INCLUDE_DIRS ${include})
  endforeach()
endif()

set(libraries "proto_msg")
foreach(library ${libraries})
  # keep build configuration keywords, target names and absolute libraries as-is
  if("${library}" MATCHES "^(debug|optimized|general)$")
    list(APPEND proto_msg_LIBRARIES ${library})
  elseif(${library} MATCHES "^-l")
    list(APPEND proto_msg_LIBRARIES ${library})
  elseif(${library} MATCHES "^-")
    # This is a linker flag/option (like -pthread)
    # There's no standard variable for these, so create an interface library to hold it
    if(NOT proto_msg_NUM_DUMMY_TARGETS)
      set(proto_msg_NUM_DUMMY_TARGETS 0)
    endif()
    # Make sure the target name is unique
    set(interface_target_name "catkin::proto_msg::wrapped-linker-option${proto_msg_NUM_DUMMY_TARGETS}")
    while(TARGET "${interface_target_name}")
      math(EXPR proto_msg_NUM_DUMMY_TARGETS "${proto_msg_NUM_DUMMY_TARGETS}+1")
      set(interface_target_name "catkin::proto_msg::wrapped-linker-option${proto_msg_NUM_DUMMY_TARGETS}")
    endwhile()
    add_library("${interface_target_name}" INTERFACE IMPORTED)
    if("${CMAKE_VERSION}" VERSION_LESS "3.13.0")
      set_property(
        TARGET
        "${interface_target_name}"
        APPEND PROPERTY
        INTERFACE_LINK_LIBRARIES "${library}")
    else()
      target_link_options("${interface_target_name}" INTERFACE "${library}")
    endif()
    list(APPEND proto_msg_LIBRARIES "${interface_target_name}")
  elseif(TARGET ${library})
    list(APPEND proto_msg_LIBRARIES ${library})
  elseif(IS_ABSOLUTE ${library})
    list(APPEND proto_msg_LIBRARIES ${library})
  else()
    set(lib_path "")
    set(lib "${library}-NOTFOUND")
    # since the path where the library is found is returned we have to iterate over the paths manually
    foreach(path /home/hansolo/CplusplusLearn/ProtobufLearn/src/catkin_ws/devel/.private/proto_msg/lib;/home/hansolo/CplusplusLearn/ProtobufLearn/src/catkin_ws/devel/lib;/opt/ros/noetic/lib)
      find_library(lib ${library}
        PATHS ${path}
        NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
      if(lib)
        set(lib_path ${path})
        break()
      endif()
    endforeach()
    if(lib)
      _list_append_unique(proto_msg_LIBRARY_DIRS ${lib_path})
      list(APPEND proto_msg_LIBRARIES ${lib})
    else()
      # as a fall back for non-catkin libraries try to search globally
      find_library(lib ${library})
      if(NOT lib)
        message(FATAL_ERROR "Project '${PROJECT_NAME}' tried to find library '${library}'.  The library is neither a target nor built/installed properly.  Did you compile project 'proto_msg'?  Did you find_package() it before the subdirectory containing its code is included?")
      endif()
      list(APPEND proto_msg_LIBRARIES ${lib})
    endif()
  endif()
endforeach()

set(proto_msg_EXPORTED_TARGETS "")
# create dummy targets for exported code generation targets to make life of users easier
foreach(t ${proto_msg_EXPORTED_TARGETS})
  if(NOT TARGET ${t})
    add_custom_target(${t})
  endif()
endforeach()

set(depends "roscpp")
foreach(depend ${depends})
  string(REPLACE " " ";" depend_list ${depend})
  # the package name of the dependency must be kept in a unique variable so that it is not overwritten in recursive calls
  list(GET depend_list 0 proto_msg_dep)
  list(LENGTH depend_list count)
  if(${count} EQUAL 1)
    # simple dependencies must only be find_package()-ed once
    if(NOT ${proto_msg_dep}_FOUND)
      find_package(${proto_msg_dep} REQUIRED NO_MODULE)
    endif()
  else()
    # dependencies with components must be find_package()-ed again
    list(REMOVE_AT depend_list 0)
    find_package(${proto_msg_dep} REQUIRED NO_MODULE ${depend_list})
  endif()
  _list_append_unique(proto_msg_INCLUDE_DIRS ${${proto_msg_dep}_INCLUDE_DIRS})

  # merge build configuration keywords with library names to correctly deduplicate
  _pack_libraries_with_build_configuration(proto_msg_LIBRARIES ${proto_msg_LIBRARIES})
  _pack_libraries_with_build_configuration(_libraries ${${proto_msg_dep}_LIBRARIES})
  _list_append_deduplicate(proto_msg_LIBRARIES ${_libraries})
  # undo build configuration keyword merging after deduplication
  _unpack_libraries_with_build_configuration(proto_msg_LIBRARIES ${proto_msg_LIBRARIES})

  _list_append_unique(proto_msg_LIBRARY_DIRS ${${proto_msg_dep}_LIBRARY_DIRS})
  _list_append_deduplicate(proto_msg_EXPORTED_TARGETS ${${proto_msg_dep}_EXPORTED_TARGETS})
endforeach()

set(pkg_cfg_extras "")
foreach(extra ${pkg_cfg_extras})
  if(NOT IS_ABSOLUTE ${extra})
    set(extra ${proto_msg_DIR}/${extra})
  endif()
  include(${extra})
endforeach()
