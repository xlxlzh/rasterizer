#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "Types.h"
#include "Color.h"

namespace rs
{
  class Texture
  {
  public:
    ///���캯��
    Texture(uint32 width, uint32 height);
    ///���캯��
    Texture(uint32 width, uint32 height, ColorFormat fmt);
    ///��������
    virtual ~Texture();

  protected:
    ///���
    uint32 width_;
    ///�߶�
    uint32 height_;
    ///�����ʽ
    ColorFormat format_;
  };
}

#endif // _TEXTURE_H_
