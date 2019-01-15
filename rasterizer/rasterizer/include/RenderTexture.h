#ifndef _FRAME_BUFFER_H_
#define _FRAME_BUFFER_H_

#include "Texture.h"

namespace rs
{
  using byte = unsigned char;

  class RenderTexture : public Texture
  {
    friend class RenderContext;
  public:
    ///构造函数
    RenderTexture(unsigned w, unsigned h, ColorFormat format = CF_R8G8B8A8);
    ///析构函数
    ~RenderTexture();

    ///
    void setPixel(unsigned x, unsigned y, Color cl, bool blend = false);
    ///
    void clear(Color cl);
    ///提交
    void swap();

  private:
    ///
    byte* frame_;
  };
}

#endif
