add_executable(${NAME} main.cpp)

add_subdirectory(arguments_handler)
add_subdirectory(input_output)
add_subdirectory(image)
add_subdirectory(opencl)
add_subdirectory(resizer)
add_subdirectory(utils)

target_link_libraries(${NAME} PUBLIC arguments_handler)
target_link_libraries(${NAME} PUBLIC input_output)
target_link_libraries(${NAME} PUBLIC image)
target_link_libraries(${NAME} PUBLIC opencl)
target_link_libraries(${NAME} PUBLIC resizer)
target_link_libraries(${NAME} PUBLIC utils)
