
### Setting up src variable ###

file(
  GLOB_RECURSE
  src_files
  ${CMAKE_CURRENT_SOURCE_DIR}/*/src/*.cpp  
)

set(
  src
  ${src}
  ${src_files}
  PARENT_SCOPE
)

### Setting up main variable ###

file(
   GLOB_RECURSE
   main_files
   main/*.cpp
)

set(
  main
  ${main}
  ${main_files}
  PARENT_SCOPE
)



### Setting up headers variable ###
file(
  GLOB_RECURSE
  header_files
  ${CMAKE_CURRENT_SOURCE_DIR}/*/include/*.hpp
)

set(
    headers
    ${header_files}
    PARENT_SCOPE
)

set(
  header_list
  ""
)

foreach (header_file ${header_files})
    get_filename_component(dir ${header_file} PATH)
    list (APPEND header_list ${dir})
endforeach()
list(REMOVE_DUPLICATES header_list)

set(
  header_dirs
  ${header_dirs}
  ${header_list}
  PARENT_SCOPE
)

### Setting up tests variable ###

file(
  GLOB_RECURSE
  test_files
  ${CMAKE_CURRENT_SOURCE_DIR}/*/tests/*.cpp  
)

set(
  tests
  ${tests}
  ${test_files}
  PARENT_SCOPE
)
