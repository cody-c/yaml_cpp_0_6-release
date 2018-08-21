cmake_minimum_required(VERSION 2.8.3)
project(yaml_cpp_0_6)

find_package(catkin REQUIRED COMPONENTS  )
include_directories(include ${catkin_INCLUDE_DIRS})

catkin_package(
    INCLUDE_DIRS yaml-cpp-0.6/include
    LIBRARIES yaml-cpp-0.6
)

add_subdirectory(yaml-cpp-0.6)

#############
## INSTALL ##
#############

# install headers
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   )

# install libraries
# install (TARGETS ${PROJECT_NAME}_behavior_exec
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#   )
