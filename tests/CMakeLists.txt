find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
    enable_testing()

    file(GLOB TEST_FILES
        NAMES  "*.txt"
    )
    list(REMOVE_ITEM TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt")

    foreach(TEST_FILE ${TEST_FILES})
        message(STATUS "Found test file: ${TEST_FILE}")
        add_test(NAME "${TEST_FILE}" COMMAND Python3::Interpreter "test.py" "${TEST_FILE}" "${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}/Lab.exe" WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
    endforeach()
else()
    message(STATUS "Python3 not found")
endif()
