cmake_minimum_required(VERSION 3.10)
project(vpilot C)
set(CMAKE_C_STANDARD 99)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

if (RENDERER MATCHES "Raylib")
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
        GIT_TAG "master"
        GIT_PROGRESS TRUE
        GIT_SHALLOW TRUE
    )
    
    FetchContent_MakeAvailable(raylib)

    add_compile_definitions(RENDERER_RAYLIB)
endif()

if (RENDERER MATCHES "SDL2")
    FetchContent_Declare(
        SDL2
        GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
        GIT_TAG "release-2.30.10"
        GIT_PROGRESS TRUE
        GIT_SHALLOW TRUE
    )

    FetchContent_MakeAvailable(SDL2)

    FetchContent_Declare(
        SDL2_ttf
        GIT_REPOSITORY "https://github.com/libsdl-org/SDL_ttf.git"
        GIT_TAG "release-2.22.0"
        GIT_PROGRESS TRUE
        GIT_SHALLOW TRUE
    )
    
    FetchContent_MakeAvailable(SDL2_ttf)

    FetchContent_Declare(
        SDL2_image
        GIT_REPOSITORY "https://github.com/libsdl-org/SDL_image.git"
        GIT_TAG "release-2.8.4"
        GIT_PROGRESS TRUE
        GIT_SHALLOW TRUE
    )
    
    FetchContent_MakeAvailable(SDL2_image)
    
    add_compile_definitions(RENDERER_SDL2)

    if (VSYNC)
        add_compile_definitions(VSYNC)
    endif()
endif()

file(GLOB SOURCES CONFIGURE_DEPENDS src/*.h src/*.c)

add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_options(${PROJECT_NAME} PUBLIC)
target_include_directories(${PROJECT_NAME} PUBLIC .)

if (RENDERER MATCHES "Raylib")
    target_link_libraries(${PROJECT_NAME} PUBLIC raylib)
endif()

if (RENDERER MATCHES "SDL2")
    target_link_libraries(vpilot PUBLIC
        SDL2
        SDL2_ttf
        SDL2_image
    )
endif()

if (LINUX)
    add_compile_definitions(CAN_AVAILABLE)
else()
    message("WARNING: CAN OPERATIONS ARE NOT AVAILABLE ON YOUR SYSTEM -- disabled")
endif()
