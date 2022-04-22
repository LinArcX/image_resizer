#ifndef IMAGE_PNG_HPP
#define IMAGE_PNG_HPP

#include "Image.hpp"
#include <string>

class Png : public Image
{
protected:
    bool decode() override;
    bool encode(int quality) override;
};

#endif
