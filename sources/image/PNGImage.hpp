#pragma once

#include "Image.hpp"
#include <string>

class PNGImage : public Image
{
public:

protected:
    bool decode() override;
    bool encode(int quality) override;
};
