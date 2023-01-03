cmake_minimum_required(VERSION 3.16.0)

project(RtSoundIODemo)

set(CXX_CMAKE_STANDARD 20)
set(CXX_CMAKE_STANDARD_REQUIRED ON)

set(RTSOUNDIODEMO_SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${RTSOUNDIODEMO_SOURCES})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
target_link_libraries(${PROJECT_NAME} PUBLIC RtSoundIO)
target_link_libraries(${PROJECT_NAME} PUBLIC rtaudio)
