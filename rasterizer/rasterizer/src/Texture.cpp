#include "Texture.h"

namespace rs
{
  Texture::Texture(uint32 width, uint32 height) : width_(width),
    height_(height)
  {

  }

  Texture::Texture(uint32 width, uint32 height, ColorFormat fmt) :
    width_(width), height_(height), format_(fmt)
  {

  }

  Texture::~Texture()
  {

  }
}