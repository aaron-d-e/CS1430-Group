cmake_minimum_required(VERSION 3.29)
project(CLion_Projects)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH "C:/Users/aaron/OneDrive/Desktop/sdl download/SDL2-2.30.8/x86_64-w64-mingw32")
set(SDL2_MIXER_PATH "C:/SDL MIXER/SDL2_mixer-devel-2.8.0-mingw/SDL2_mixer-2.8.0/x86_64-w64-mingw32")
set(SDL2_TTF_PATH "C:/SDL TTF/SDL2_ttf-2.22.0/x86_64-w64-mingw32")
set(SDL2_IMAGE_PATH "C:/SDL IMAGE/SDL2_image-2.8.2/x86_64-w64-mingw32")






find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)




include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_MIXER_INCLUDE_DIRS})
include_directories(${SDL2_TTF_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})



add_executable(CLion_Projects main.cpp
        SDL_Plotter.cpp
        SDL_Plotter.h
        "SDL Functions.cpp"
        "SDL Functions.h"
        NewForces.cpp
        NewForces.h
        Enemies.cpp
        Enemies.h
        Flipper.cpp
        Flipper.h
        LTimer.cpp
        LTimer.h
        BackgroundMusic.cpp
        BackgroundMusic.h
        SoundEffect.cpp
        SoundEffect.h
        #cmake-build-debug/SDL_Mixer.h
)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${SDL2_MIXER_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SDL2_TTF_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SDL2_IMAGE_LIBRARIES})



