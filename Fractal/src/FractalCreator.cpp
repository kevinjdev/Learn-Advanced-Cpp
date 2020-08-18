#include <iostream>
#include <assert.h>
#include "FractalCreator.h"
#include "Mandelbrot.h"

namespace bitmapProject
{

    FractalCreator::FractalCreator(int width, int height) : m_width(width),
                                                            m_height(height),
                                                            m_total(0),
                                                            m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{}),
                                                            m_fractal(new int[m_width * m_height]{}),
                                                            m_bitmap(m_width, m_height),
                                                            m_zoomList(m_width, m_height)
    {

        addZoom(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));
    }
    
    FractalCreator::~FractalCreator()
    {
    }

    void FractalCreator::run(string name)
    {
        calculateIteration();
        calculateTotalIterations();
        calculateRangeTotals();
        drawFractal();
        writeBitmap(name);
    }

    // Adds a color range to the fractal image
    void FractalCreator::addRange(double rangeEnd, const RGB &rgb)
    {
        m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
        m_colors.push_back(rgb);

        if (m_bGotFirstRange)
        {
            m_rangeTotals.push_back(0);
        }

        m_bGotFirstRange = true;
    }

    void FractalCreator::addZoom(const Zoom &zoom)
    {
        m_zoomList.add(zoom);
    }

    // Calculates the number of iterations the mandelbrot equations runs for each pixel and 
    // stores the result in in m_fractal and m_histogram
    void FractalCreator::calculateIteration()
    {

        for (int y = 0; y < m_height; y++)
        {
            for (int x = 0; x < m_width; x++)
            {

                pair<double, double> coords = m_zoomList.doZoom(x, y);
                int iterations = Mandelbrot::getIterations(coords.first, coords.second);

                m_fractal[y * m_width + x] = iterations;

                if (iterations != Mandelbrot::MAX_ITERATIONS)
                {
                    m_histogram[iterations]++;
                }
            }
        }
    }

    // Calculates the total iterations run by summing the m_histogram array. Used for debugging.
    void FractalCreator::calculateTotalIterations()
    {
        for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
        {
            m_total += m_histogram[i];
        }
    }

    // Calculates the total number of pixels for the m_rangeTotals array using the m_histogram array
    void FractalCreator::calculateRangeTotals()
    {

        int rangeIndex = 0;

        for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
        {
            int pixels = m_histogram[i];

            if (i >= m_ranges[rangeIndex + 1])
            {
                rangeIndex++;
            }

            m_rangeTotals[rangeIndex] += pixels;
        }
    }

    // Translates a number of iterations to an index in the m_ranges vector defined in main.cpp
    int FractalCreator::getRange(int iterations) const
    {
        int range = 0;
        for (int i = 1; i < m_ranges.size(); i++)
        {
            range = i;

            if (m_ranges[i] > iterations)
            {
                break;
            }
        }

        range--;

        assert(range > -1);
        assert(range < m_ranges.size());

        return range;
    }

    // iterates over each bitmap x,y coordinant, drawing the color based on the number of iterations. If the x,y pair is in the 
    // Mandelbrot set after MAX_ITERATIONS, it is colored black. Otherwise it will be colored based on the ranges defined in main.cpp.
    void FractalCreator::drawFractal()
    {

        // iterates over each pixel
        for (int y = 0; y < m_height; y++)
        {
            for (int x = 0; x < m_width; x++)
            {

                int iterations = m_fractal[y * m_width + x];

                int range = getRange(iterations);
                int rangeTotal = m_rangeTotals[range];
                int rangeStart = m_ranges[range];

                RGB &startColor = m_colors[range];
                RGB &endColor = m_colors[range + 1];
                RGB colorDiff = endColor - startColor;

                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;

                if (iterations != Mandelbrot::MAX_ITERATIONS)
                {

                    int totalPixels = 0;

                    for (int i = rangeStart; i <= iterations; i++)
                    {
                        totalPixels += m_histogram[i];
                    }

                    red = startColor.r + colorDiff.r * (double)totalPixels / rangeTotal;
                    green = startColor.g + colorDiff.g * (double)totalPixels / rangeTotal;
                    blue = startColor.b + colorDiff.b * (double)totalPixels / rangeTotal;
                }

                m_bitmap.setPixel(x, y, red, green, blue);
            }
        }
    }

    // Writes the bitmap image to a file in the root directory of the project
    void FractalCreator::writeBitmap(string name)
    {
        m_bitmap.write(name);
    }

} // namespace bitmapProject