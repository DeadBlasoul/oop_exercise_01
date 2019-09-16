set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}/")
set(CMAKE_CXX_STANDARD 17)

if (WIN32)
    include(config_windows)
endif()
