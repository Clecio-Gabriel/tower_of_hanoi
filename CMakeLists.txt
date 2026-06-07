CMAKE_MINIMUM_REQUIRED(VERSION 4.3)
project(TOWER_OF_HANOI VERSION 1.0 LANGUAGES CXX)

if(WIN32)
    add_compile_definitions(NOMINMAX)
    
    if(MSVC)
        add_compile_options(/W4)
    endif()
endif()

set(HANOI_EXE hanoi_bin)
add_executable(${HANOI_EXE} src/main/main.cpp)
target_compile_options( ${HANOI_EXE} PRIVATE -Wall -pedantic -Werror -g)
set_target_properties( ${HANOI_EXE} PROPERTIES CXX_STANDARD 17 )

set(TOWER_OF_HANOI towerhanoi_lib)
add_subdirectory(src/includes/tower_of_hanoi)

target_link_libraries(
    ${HANOI_EXE}
    PRIVATE
    ${TOWER_OF_HANOI}
)