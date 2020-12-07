# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\Smash_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Smash_autogen.dir\\ParseCache.txt"
  "Smash_autogen"
  )
endif()
