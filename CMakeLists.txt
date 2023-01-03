cmake_minimum_required(VERSION 3.16.0)

project(RtSoundIODemo VERSION 1.0.0)

# RTAUDIO
add_subdirectory(rtaudio)

# RTSOUNDIO
add_subdirectory(rtsoundio)

# EXECUTABLE
add_subdirectory(src)



