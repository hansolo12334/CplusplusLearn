set(FFMPEG_DIR "/home/hansolo/CplusplusLearn/r329_arm64/tools/ffmpeg")
include_directories(${PROJECT_SOURCE_DIR}/tools/ffmpeg/include)

add_definitions(-DSIMULATE)
link_directories(${FFMPEG_DIR}/lib)


add_executable(test_video test_video.c)
target_link_libraries(test_video libavformat.so libavdevice.so libavutil.so  libavcodec.so libswresample.so libavfilter.so libswscale.so
                     )
