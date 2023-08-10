# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/newPluginDB_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/newPluginDB_autogen.dir/ParseCache.txt"
  "newPluginDB_autogen"
  )
endif()
