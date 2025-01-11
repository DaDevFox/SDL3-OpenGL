cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 17)
set(OpenGL_GL_PREFERENCE "GLVND")

# vcpkg configuration
set(VCPKG_MANIFEST_MODE ON)
set(VCPKG_APPLOCAL_DEPS ON)

project(Tetris VERSION 0.1.0)

include(CTest)
enable_testing()

# vcpkg environment var integration (thanks https://github.com/zenustech/zeno/)
if (DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    message(STATUS "VCPKG_ROOT: $ENV{VCPKG_ROOT}")
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

if (DEFINED ENV{VCPKG_TRIPLET} AND NOT DEFINED VCPKG_TARGET_TRIPLET)
    message(STATUS "VCPKG_TRIPLET: $ENV{VCPKG_TRIPLET}")
    set(VCPKG_TARGET_TRIPLET "$ENV{VCPKG_TRIPLET}" CACHE STRING "")
endif()


if (MSVC AND NOT DEFINED CMAKE_MSVC_RUNTIME_LIBRARY)
    # MSVC sucks /MD /MT /MDd /MTd options....
    # MultiThreadedDLL = /MD, MultiThreadedDebugDLL = /MDd
    # MultiThreaded = /MT, MultiThreadedDebug = /MTd
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

# Includes and libraries
if (WIN32)
    #set(SDL3_DIR ${CMAKE_SOURCE_DIR}/external/SDL3-3.1.7)
    #set(GLEW_DIR ${CMAKE_SOURCE_DIR}/external/glew-2.2.0)
endif (WIN32)

# dependencies
find_package(OpenGL REQUIRED COMPONENTS OpenGL)

find_package(SDL3 REQUIRED)
include_directories(${SDL3_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

find_package(OpenGL)

# subdirectories
add_subdirectory( src/engine )
add_subdirectory( src/game )

# executable configuration + linking
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE game engine)
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL3_LIBRARIES} ${GLEW_LIBRARIES} ${OPENGL_gl_LIBRARY})

# copy assets to the build folder
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_LIST_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
        COMMENT "---- Copy Assets"
)

# copy dependant dynamically linked libraries to the build folder
set(COPY_DLLS_TO_OUTPUT TRUE)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)