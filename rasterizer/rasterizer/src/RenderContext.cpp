#include "RenderContext.h"

namespace rs
{
  RenderContext::RenderContext()
  {
  }

  RenderContext::~RenderContext()
  {

  }

  void RenderContext::clear()
  {
    colorBuffer_->clear(Color::Black);
  }

  void RenderContext::swap()
  {

  }

  bool RenderContext::initialize(uint32 width, uint32 height, ColorFormat fmt)
  {
    colorBuffer_ = new RenderTexture(width, height, CF_R8G8B8A8);

    return true;
  }
}