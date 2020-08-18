#include <complex>
#include "Mandelbrot.h"

using namespace std;

namespace bitmapProject {

    Mandelbrot::Mandelbrot() {
    }

    Mandelbrot::~Mandelbrot() {
    }

    int Mandelbrot::getIterations(double x, double y) {

        complex<double> z = 0;
        complex<double> c(x, y);

        int iterations = 0;

        while (iterations < MAX_ITERATIONS) {
            z = z * z + c;

            // The x,y coordinate is not in the Mandelbrot set if it's value is above 2. Its value continue increasing to infinity.
            if (abs(z) > 2) {
                break;
            }

            iterations++;
        }
        return iterations;
    }

}