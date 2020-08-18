// #pragma pack (2) // this is used in the BitmapFileHeader and BitmapInfoheader

#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace bitmapProject;
using namespace std;

namespace bitmapProject {

Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height), m_pPixels(new uint8_t[width * height * 3]{}) {

}
Bitmap::~Bitmap() {

}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t *pPixel = m_pPixels.get();
    // the y value starts in the lower left side of the bitmap
    pPixel += (y * 3) * m_width + (x * 3); // pointer arithetic to get pixel array index based on x and y
    pPixel[0] = blue; // blue is first due to little endian encoding
    pPixel[1] = green;
    pPixel[2] = red;
}

bool Bitmap::write(string filename) {
    
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height*3;
    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

    infoHeader.width = m_width;
    infoHeader.height = m_height;

    ofstream file;

    file.open(filename, ios::out|ios::binary);

    if (!file) {
        return false;
    }

    file.write((char *)&fileHeader, sizeof(fileHeader));
    file.write((char *)&infoHeader, sizeof(infoHeader));
    file.write((char *)m_pPixels.get(), m_width * m_height * 3);

    file.close();

    if (!file) {
        return false;
    }

    return true;
}

}