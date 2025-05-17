project(wx-opengl-app)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED COMPONENTS core base gl)
include(${wxWidgets_USE_FILE})

add_executable(wx-opengl-app
    src/main.cpp
    src/App.cpp
    src/MainFrame.cpp
    src/OpenGLCanvas.cpp
)

target_include_directories(wx-opengl-app PRIVATE ${wxWidgets_INCLUDE_DIRS})
target_link_libraries(wx-opengl-app ${wxWidgets_LIBRARIES})
target_link_libraries(wx-opengl-app "-framework OpenGL")