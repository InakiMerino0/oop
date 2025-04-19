# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ejercicio1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ejercicio1_autogen.dir\\ParseCache.txt"
  "ejercicio1_autogen"
  )
endif()
