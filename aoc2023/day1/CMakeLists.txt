set(TARGET day1)

add_executable(${TARGET}
    Main.cpp)

install(TARGETS ${TARGET}
    BUNDLE DESTINATION .)