#ifndef IMAGE_JPEG_HPP
#define IMAGE_JPEG_HPP

#include "Image.hpp"
#include <string>

class Jpeg : public Image
{
protected:
    bool decode() override;
    bool encode(int quality) override;
};

#endif
