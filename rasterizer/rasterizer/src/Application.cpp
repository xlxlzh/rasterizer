#include "SDL.h"
#include "Application.h"

namespace rs
{
  void Application::setTitle(const std::string& title)
  {
    title_ = title;
    if (window_)
      SDL_SetWindowTitle(window_, title_.c_str());
  }

  void Application::setPos(unsigned x, unsigned y)
  {
    posX_ = x;
    posY_ = y;

    if (window_)
      SDL_SetWindowPosition(window_, posX_, posY_);
  }

  bool Application::initialize(unsigned width, unsigned height, const std::string& title)
  {
    SDL_Init(SDL_INIT_EVERYTHING);

    width_ = width;
    height_ = height;
    title_ = title;

    window_ = SDL_CreateWindow(title_.c_str(), 20, 20, width_, height_, 0);
    if (!window_)
    {
      //LOG
      return false;
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    rt_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width_, height_);

    surface_ = SDL_GetWindowSurface(window_);

    setTitle(title_);
    SDL_ShowWindow(window_);

    return true;
  }

  bool Application::run()
  {
    //context_->clear();
    while (!exit_)
    {
      SDL_Event event;
      while (SDL_PollEvent(&event))
      {
        if (event.type == SDL_QUIT)
          exit_ = true;

        update(0.0f);
        //swap();
      }
    }

    return exit_;
  }

  void Application::swap()
  {
    void* pixels = nullptr;
    int pitch = 0;

    SDL_LockTexture(rt_, nullptr, &pixels, &pitch);

    memcpy(pixels, context_->getColorBuffer(), surface_->pitch * surface_->h);

    SDL_UnlockTexture(rt_);

    SDL_RenderCopy(renderer_, rt_, nullptr, nullptr);
    SDL_RenderPresent(renderer_);
  }
}