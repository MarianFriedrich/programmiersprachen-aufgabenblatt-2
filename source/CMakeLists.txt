# Build example
add_executable(example
  vec2.cpp
  mat2.cpp
  bbox.cpp
  color.cpp
  rect.cpp
  circle.cpp
  window.cpp
  glew.c
  example.cpp)
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  m)
add_dependencies(example glfw ${COPY_BINARY})

# Build tests
add_executable(tests
  color.cpp
  rect.cpp
  bbox.cpp
  circle.cpp
  vec2.cpp
  mat2.cpp
  tests.cpp)
target_link_libraries(tests
  ${GLFW_LIBRARIES})


