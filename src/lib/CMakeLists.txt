file(GLOB_RECURSE LabLib_INCLUDE
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
)

file(GLOB_RECURSE LabLib_SRC
    NAMES "*.h" "*.hpp" "*.cpp" "*.c"
    PATHS "./"
)

add_library(LabLib STATIC ${LabLib_INCLUDE} ${LabLib_SRC})

target_include_directories(LabLib PUBLIC "${PROJECT_SOURCE_DIR}/include/")
