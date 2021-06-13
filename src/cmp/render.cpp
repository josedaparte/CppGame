#include <tuple>
#include <cstring>
#include <fstream>
#include <string_view>


#include "render.hpp"
#include <iostream>
namespace ECS {

auto
readPNG(const std::string_view filename)
{
    std::vector<unsigned char> pixels {};
    unsigned long dw { 0 }, dh{ 0 };
    std::ifstream file(filename.data(), std::ios::binary);
    std::vector<unsigned char> filevec(
        std::istreambuf_iterator<char> {file},
        std::istreambuf_iterator<char> {}
    );
    decodePNG(pixels, dw, dh, filevec.data(), filevec.size());
    return std::tuple{pixels, dw, dh};
}

void
RenderComponent_t::loadFromFile(const std::string_view filename)
{
    auto [pixels, mw, mh] = readPNG(filename);
    w = mw; h = mh;
    m_sprite.reserve(pixels.size()/4);
    
    for(auto p = pixels.begin(); p != pixels.end(); p+= 4)
    {
        uint32_t pixel =
                static_cast<uint32_t>(*(p+0)) << 16
            |   static_cast<uint32_t>(*(p+1)) << 8
            |   static_cast<uint32_t>(*(p+2))
            |   static_cast<uint32_t>(*(p+3)) << 24;
        m_sprite.push_back(pixel);
    }
}

}   // namespace ECS 