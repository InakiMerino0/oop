# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ejercicio4_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ejercicio4_autogen.dir\\ParseCache.txt"
  "ejercicio4_autogen"
  )
endif()
