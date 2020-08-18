#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

namespace bitmapProject {

    class FractalCreator {
    private:
        int m_width;
        int m_height;
        int m_total;
        unique_ptr<int[]> m_histogram;
        unique_ptr<int[]> m_fractal;
        Bitmap m_bitmap;
        ZoomList m_zoomList;

        vector<int> m_ranges;
        vector<RGB> m_colors;
        vector<int> m_rangeTotals;

        bool m_bGotFirstRange{ false };

        void calculateIteration();
        void calculateTotalIterations();
        void calculateRangeTotals();
        void drawFractal();
        void writeBitmap(string name);
        int getRange(int iterations) const;

    public:
        FractalCreator(int width, int height);
        virtual ~FractalCreator();

        void run(string name);
        void addZoom(const Zoom& zoom);
        void addRange(double rangeEnd, const RGB& rgb);
    };

}

#endif