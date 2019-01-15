#ifndef _RENDER_CONTEXT_H_
#define _RENDER_CONTEXT_H_

#include "RenderTexture.h"

namespace rs
{
  class RenderContext
  {
  public:
    RenderContext();
    ~RenderContext();

    bool initialize(uint32 width, uint32 height, ColorFormat fmt);

    void clear();
    void swap();

    RenderTexture* getColorBuffer() const { return colorBuffer_; }
    
  private:
    RenderTexture* colorBuffer_;
  };
}

#endif
