set(PNG_DIR "/home/hansolo/CplusplusLearn/r329_arm64/tools/png")
set(ZLIB_DIR "/home/hansolo/CplusplusLearn/r329_arm64/tools/zlib")
set(FREETYPE_DIR "/home/hansolo/CplusplusLearn/r329_arm64/tools/freetype")
include_directories(${PNG_DIR}/include/libpng16)
include_directories(${ZLIB_DIR}/include)
include_directories(${FREETYPE_DIR}/include/freetype2)

add_definitions(-DSIMULATE)

link_directories(${PNG_DIR}/lib)
link_directories(${ZLIB_DIR}/lib)
link_directories(${FREETYPE_DIR}/lib)

add_executable(test_png ${PROJECT_SOURCE_DIR}/src/lcd/test_png.cpp)
target_link_libraries(test_png libpng.so)

add_executable(test_type ${PROJECT_SOURCE_DIR}/src/lcd/test_type.cpp)
target_link_libraries(test_type libfreetype.so libpng.so)
