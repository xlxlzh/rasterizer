#include "RenderTexture.h"

namespace rs
{
  ///目前只支持RBGA8格式
  RenderTexture::RenderTexture(unsigned w, unsigned h, ColorFormat format /* = CF_R8G8B8A8 */) :
    Texture(w, h, format)
  {
    frame_ = new byte[w * h * 4];
  }

  RenderTexture::~RenderTexture()
  {
    if (frame_)
    {
      delete[] frame_;
      frame_ = nullptr;
    }
  }

  void RenderTexture::setPixel(unsigned x, unsigned y, Color cl, bool blend /* = false */)
  {
    ///暂时不处理混合
    (void)blend;

    if (!frame_ || x < 0 || y < 0 || x >= width_ || y >= height_)
      return;

    frame_[width_ * y + x] = cl.getAlpha();
    frame_[width_ * y + x + 1] = cl.getRed();
    frame_[width_ * y + x + 2] = cl.getGreen();
    frame_[width_ * y + x + 3] = cl.getBlue();
  }

  void RenderTexture::clear(Color cl)
  {
    ///简单实现 以后优化
    for (unsigned i = 0; i < height_; ++i)
    {
      for (unsigned j = 0; i < width_; ++j)
        setPixel(j, i, cl);
    }
  }

  void RenderTexture::swap()
  {

  }
}