set(PNG_DIR "/home/hansolo/CplusplusLearn/r329_arm64/tools/png")
set(ZLIB_DIR "/home/hansolo/CplusplusLearn/r329_arm64/tools/zlib")
set(FREETYPE_DIR "/home/hansolo/CplusplusLearn/r329_arm64/tools/freetype")
include_directories(${PNG_DIR}/include/libpng16)
include_directories(${ZLIB_DIR}/include)
include_directories(${FREETYPE_DIR}/include/freetype2)


include_directories(${PROJECT_SOURCE_DIR}/src/lcd_libs/include)


add_definitions(-DSIMULATE)

link_directories(${PNG_DIR}/lib)
link_directories(${ZLIB_DIR}/lib)
link_directories(${FREETYPE_DIR}/lib)


##生成lcds库
add_library(lcds
            ${PROJECT_SOURCE_DIR}/src/lcd_libs/lcd.cpp)
target_link_libraries(lcds
                        libfreetype.so libpng.so )
