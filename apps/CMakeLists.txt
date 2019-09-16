add_executable(Lab main.cpp)

set_target_properties(Lab PROPERTIES
    FOLDER apps)

add_dependencies(Lab LabLib)
target_link_libraries(Lab LabLib)
