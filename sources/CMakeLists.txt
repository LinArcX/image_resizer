add_executable(${NAME} main.cpp)

add_subdirectory(image)
add_subdirectory(opencl)
add_subdirectory(resizer)
add_subdirectory(utils)

target_link_libraries(${NAME} PUBLIC image)
target_link_libraries(${NAME} PUBLIC opencl)
target_link_libraries(${NAME} PUBLIC resizer)
target_link_libraries(${NAME} PUBLIC utils)
