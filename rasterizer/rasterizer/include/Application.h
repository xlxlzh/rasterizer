#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <string>
#include <SDL.h>

#include "SingleTon.h"
#include "RenderContext.h"


struct SDL_Window;

namespace rs
{
  class Application : public SingleTon<Application>
  {
  public:
    ///默认构造
    Application() :
      window_(nullptr),
      width_(0),
      height_(0),
      posX_(0),
      posY_(0)
    {

    }

    ///初始化窗口
    bool initialize(unsigned width, unsigned height, const std::string& title);

  public:
    ///
    void setTitle(const std::string& title);
    ///
    void setWidth(unsigned width) { width_ = width; }
    ///
    void setHeight(unsigned height) { height_ = height; }
    ///
    void setPos(unsigned x, unsigned y);

    ///
    bool run();
    ///
    void exit() { exit_ = true; }
    ///
    virtual void update(float delta) { (void)delta; }

    ///
    RenderContext* getContext() const { return context_; }

    void swap();

  protected:
    ///
    RenderContext* context_;

  protected:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    SDL_Surface* surface_;
    SDL_Texture* rt_;

  protected:
    ///
    std::string title_;
    ///
    unsigned width_;
    ///
    unsigned height_;
    ///
    unsigned posX_;
    ///
    unsigned posY_;
    ///
    bool exit_;
  };
}

#endif
