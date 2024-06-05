# Calculator
1st year project

This is a  calculator application built using Qt framework. It supports basic arithmetic operations like addition, subtraction, multiplication, and division, as well as memory operations.

## Features

- Basic arithmetic operations (+, -, *, /)
- Memory functionality (add, subtract, recall, clear)
- Keyboard support for desktop users

## Prerequisites

To build and run this application, you will need:
- Qt 6.6 or later
- A C++ compiler compatible with the version of Qt you are using (e.g., GCC for Linux, MSVC for Windows)

## Building the Application

1. **Clone the repository:**
   git clone https://github.com/your-username/qt-calculator.git

   Make sure to replace https://github.com/your-username/qt-calculator.git
   
3. **Open the project in Qt Creator:**
- Start Qt Creator and open the project file located in the cloned repository.
- Configure the project with a suitable Kit (matching your Qt and compiler setup).

3. **Build the project:**
- Use the Build option in Qt Creator or use the command line:
  ```
  qmake
  make  # or nmake/jom depending on your platform
  ```

4. **Run the application:**
- Execute the binary created by the build process, or run from Qt Creator using the Run button.

## Usage

- Use the GUI buttons or the keyboard for input.
- Supported keyboard keys:
- Numbers (0-9)
- Operations (+, -, *, /)
- Enter to calculate
- ESC to clear
- Backspace to delete the last digit

## Contributing

Contributions are welcome! Please fork the repository and submit pull requests with your suggested changes.

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.

