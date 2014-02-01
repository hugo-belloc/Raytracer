cmake_minimum_required(VERSION 2.6)

project(Raytracer)
set(CMAKE_BUILD_TYPE DEBUG)

set(EXECUTABLE_OUTPUT_PATH build)
set(TESTS_DIR tests)
set(LIBRARY_OUTPUT_PATH lib)

set(CMAKE_CXX_FLAGS "-std=c++0x  -Wall -Wextra -pedantic  -DGL_GLEXT_PROTOTYPES -I/opt/X11/include")
set(CMAKE_CXX_FLAGS_DEBUG "-g")


LINK_DIRECTORIES("~/local_install/lib")
LINK_DIRECTORIES("/usr/local/lib")
INCLUDE_DIRECTORIES("/usr/local/include")
INCLUDE_DIRECTORIES("~/local_install/include")

find_package(OpenGL)
if (OPENGL_FOUND)
   include_directories(${OPENGL_INCLUDE_DIR})
else (OPENGL_FOUND)
    message("OpenGL environment missing")
endif (OPENGL_FOUND)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

### Defining a list of system libraries (OpenGL related)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

set(GL_LIBRARIES ${OPENGL_LIBRARIES} GLEW)
if(APPLE)
 set(CMAKE_CXX_FLAGS "-stdlib=libc++ ${CMAKE_CXX_FLAGS}")
  set(GL_LIBRARIES ${GL_LIBRARIES} "-framework Cocoa" "-framework IOkit")
endif()

#####  Setting up some global variables to produce the executables   #####

# Contains everythings but main and tests
set(src "")

# Contains a list of the files used to create main executable
set(main "")

# Contains a list of the headers directory
set(header_dirs "")

# Contains a list of the header files
set(headers "")

# Contains a list of the test files
set(tests "")

# Set the src header_dir main and tests variables
add_subdirectory(src)

#### Creating main executable ####
include_directories(${header_dirs})

add_library(
    raytracer_src_lib
    STATIC
    ${src}
)

 #link_directories(${LIBRARY_OUTPUT_PATH})

add_executable(
  raytracer
  ${main}
  ${headers}
)
target_link_libraries(raytracer raytracer_src_lib ${GL_LIBRARIES}  glfw )

#### Creating tests executable ####
if (CMAKE_BUILD_TYPE STREQUAL "DEBUG")
  if(NOT EXISTS ${EXECUTABLE_OUTPUT_PATH}/${TESTS_DIR})
    file(MAKE_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}/${TESTS_DIR})
  endif()

  foreach (test_file ${tests})
    get_filename_component(test_name ${test_file} NAME_WE)
    add_executable(
       ${TESTS_DIR}/${test_name}
       ${test_file}
    )
  target_link_libraries(${TESTS_DIR}/${test_name} raytracer_src_lib ${GL_LIBRARIES} glfw )
  endforeach()
endif()
