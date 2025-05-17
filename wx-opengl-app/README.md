# wx-opengl-app

## Overview
This project is a desktop application using **wxWidgets** for the GUI and **OpenGL** for rendering. It demonstrates how to combine a modern GUI with interactive OpenGL graphics, including UI controls that affect the rendered scene.

## Features

- **OpenGL 2D Scene Rendering**: Renders a simple 2D scene with a triangle and a circle.
- **Interactive Controls**:  
  - **PNG Button**: Overlays a clickable PNG button on the OpenGL canvas.
  - **Control Panel**: Contains a `wxSlider` (for scaling the scene) and a `wxCheckBox` (to toggle wireframe mode).
  - **Panel Visibility**: The control panel is shown/hidden by clicking the PNG button.
- **Responsive Layout**: Controls and canvas resize with the window.
- **Clean Resource Management**: Proper destructors and cleanup for OpenGL and wxWidgets resources.

## Project Structure

```
wx-opengl-app
├── images/
│   └── button.png         # PNG image for the overlay button
├── src/
│   ├── main.cpp           # Application entry point (wxIMPLEMENT_APP)
│   ├── App.h / App.cpp    # wxApp subclass
│   ├── MainFrame.h / MainFrame.cpp # Main window with layout and controls
│   ├── OpenGLCanvas.h / OpenGLCanvas.cpp # OpenGL rendering and UI logic
├── CMakeLists.txt         # Build configuration
└── README.md              # Project documentation
```

## Setup Instructions

1. **Prerequisites**  
   - Install [wxWidgets](https://www.wxwidgets.org/) and [CMake](https://cmake.org/).
   - On macOS, you can use Homebrew:
     ```
     brew install wxwidgets cmake
     ```

2. **Clone the Repository**  
   ```
   git clone <repository-url>
   cd wx-opengl-app
   ```

3. **Build the Project**  
   ```
   mkdir build
   cd build
   cmake ..
   make
   ```

4. **Run the Application**  
   ```
   ./wx-opengl-app
   ```

## Usage

- **Show/Hide Control Panel**: Click the PNG button in the top-right of the OpenGL canvas.
- **Scale Scene**: Use the slider in the control panel to scale the OpenGL scene (0.1x to 2.0x).
- **Toggle Wireframe**: Use the checkbox to switch between filled and wireframe rendering.

## Notes

- The PNG button image should be located at `images/button.png` relative to the build directory.
- The application demonstrates integration of wxWidgets controls with OpenGL rendering and event handling.

## Contributing

Contributions are welcome! Please open issues or submit pull requests for improvements or bug fixes.