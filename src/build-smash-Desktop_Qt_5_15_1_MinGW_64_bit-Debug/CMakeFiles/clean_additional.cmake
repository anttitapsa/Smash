# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\smash_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\smash_autogen.dir\\ParseCache.txt"
  "smash_autogen"
  )
endif()
