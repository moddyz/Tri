get_filename_component(PROGRAM_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
cpp_executable(
    ${PROGRAM_NAME}
    CPPFILES
        main.cpp
    LIBRARIES
        CUDA::cudart
        tri_base
        tri_memory
        tri_rendering
        gm
        cxxopts
)
