#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "Types.h"
#include "Color.h"

namespace rs
{
  class Texture
  {
  public:
    ///构造函数
    Texture(uint32 width, uint32 height);
    ///构造函数
    Texture(uint32 width, uint32 height, ColorFormat fmt);
    ///析构函数
    virtual ~Texture();

  protected:
    ///宽度
    uint32 width_;
    ///高度
    uint32 height_;
    ///纹理格式
    ColorFormat format_;
  };
}

#endif // _TEXTURE_H_
