#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"

using namespace std;
using namespace bitmapProject;

int main() {

    FractalCreator fractalCreator(800, 600);

    // Create color ranges based on iterations. 1.0 = max iterations
    fractalCreator.addRange(0.0, RGB(0, 0, 0)); 
    fractalCreator.addRange(0.015, RGB(0, 0, 255));
    fractalCreator.addRange(0.3, RGB(255, 255, 0));
    fractalCreator.addRange(1.0, RGB(255, 255, 255));

    // Zoom in near the middle of the image.
    // Zooming in near the edges of the Fractal show interesting details.
    fractalCreator.addZoom(Zoom(373, 300, 0.90));
    fractalCreator.run("Mandelbrot.bmp");

    cout << "Finished " << endl;

    return 0;
}