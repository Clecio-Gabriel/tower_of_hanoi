add_library(${TOWER_OF_HANOI} tower_of_hanoi.cpp)

target_include_directories(
    ${TOWER_OF_HANOI}
    PUBLIC
    "../state"
)

target_include_directories(
    ${TOWER_OF_HANOI}
    PUBLIC
    "../stack"
)

target_include_directories(
    ${TOWER_OF_HANOI}
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)