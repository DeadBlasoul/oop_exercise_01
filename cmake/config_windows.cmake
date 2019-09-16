if (WIN32)
    if (MSVC)
        # Allows to use functions from cstdlib like `printf`
        add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    endif ()
endif()
