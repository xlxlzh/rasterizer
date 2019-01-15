#ifndef _SINGLETON_H_
#define _SINGLETON_H_

namespace rs
{
  template <typename T>
  void SafeDelete(T*&  t)
  {
    if (t != nullptr)
    {
      delete t;
      t = nullptr;
    }
  }


  template <typename T>
  class SingleTon
  {
  public:
    static T* getInstance()
    {
      if (!instance_)
      {
        instance_ = new T;
      }

      return instance_;
    }

    static void deleteInstance()
    {
      SafeDelete(instance_);
    }

  protected:
    SingleTon() { }

    virtual ~SingleTon() { }

  private:
    SingleTon<T>& operator = (const SingleTon<T>& rhs);
    SingleTon(const SingleTon<T>& rhs);

  private:
    static T* instance_;
  };

  template <typename T>
  T* SingleTon<T>::instance_ = nullptr;
}

#endif
