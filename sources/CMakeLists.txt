add_executable(${NAME} main.cpp)

add_subdirectory(inputOutput)
target_link_libraries(${NAME} PUBLIC inputOutput)
