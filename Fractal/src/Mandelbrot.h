#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace bitmapProject {
    class Mandelbrot {
    private:

    public:
        static const int MAX_ITERATIONS = 1000;

        Mandelbrot();
        virtual ~Mandelbrot();
        static int getIterations(double x, double y);

    };
}
#endif