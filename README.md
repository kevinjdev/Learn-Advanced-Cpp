# Learn-Advanced-Cpp-Udemy
In the first part of this course, we wrote simple programs demonstrating C++ syntax for working with files, exceptions, function pointers, templates, and many C++ 11 features. These one file programs are located within the C++ Features Folder. In the second part, we developed a Fractal program that draws a Mandelbrot Fractal image and saves the image as a .bmp file. This program is located in the Fractal folder, and can be built using cmake.

## Getting Started
Clone the repository to your local machine by running the following command in a terminal window or command prompt from the location you wish to copy the folder

`git clone https://github.com/kevinjdev/Learn-Advanced-Cpp-Udemy.git`

### Prerequisites
cmake, make, and g++ or clang compiler installed.

## Fractal
<img src="/media/mandelbrot.bmp" width="600" height="400" />

In this project, we implemented the algorithm for drawing a mandelbrot fractal and colored the image based on the number of iterations that each pixel's (x,y) coordinates stayed within the threshold of the mandelbrot set.

Below are links to the Wikipedia page for the Mandelbrot Set and also an interesting video about the Mandelbrot Set I enjoyed viewing while coding this project and learning more about fractals.

[Mandelbot Set Wikipedia Page](https://en.wikipedia.org/wiki/Mandelbrot_set)

[YouTube video about the MandelBrot Set](https://www.youtube.com/watch?v=56gzV0od6DU)

### How To Run
Create a build directory inside the Fractal folder, compile with cmake and make, run the executable.  
```
mkdir build
cd build
cmake ..
make
./fractal
```

## C++ Features
Each one of the .cpp files in the subfolders of can be compiled and run individually.

## Certificate
<img src="/media/certificate-kj.jpg" width="600" height="400" />
