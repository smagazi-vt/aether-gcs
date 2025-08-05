# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_valtec_onboard_intelligence_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED valtec_onboard_intelligence_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(valtec_onboard_intelligence_FOUND FALSE)
  elseif(NOT valtec_onboard_intelligence_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(valtec_onboard_intelligence_FOUND FALSE)
  endif()
  return()
endif()
set(_valtec_onboard_intelligence_CONFIG_INCLUDED TRUE)

# output package information
if(NOT valtec_onboard_intelligence_FIND_QUIETLY)
  message(STATUS "Found valtec_onboard_intelligence: 0.0.1 (${valtec_onboard_intelligence_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'valtec_onboard_intelligence' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${valtec_onboard_intelligence_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(valtec_onboard_intelligence_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${valtec_onboard_intelligence_DIR}/${_extra}")
endforeach()
