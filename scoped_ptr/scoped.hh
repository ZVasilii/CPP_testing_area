#include <iostream>

namespace Pointer 
{

template <typename T>
class ScopedPtr
{
	T* ptr_;
	std::size_t size_;

public:
	ScopedPtr(std::size_t size);
	~ScopedPtr();
	ScopedPtr(const ScopedPtr& rhs);
	ScopedPtr& operator=(const ScopedPtr& rhs);
	#ifdef MOVE
	ScopedPtr(ScopedPtr&& rhs);
	ScopedPtr& operator=(ScopedPtr&& rhs);
	#endif
};

template <typename T>
ScopedPtr<T>::ScopedPtr(std::size_t size) :  ptr_(new T{}), size_(size)
{
	std::cout << "Ctor" << std::endl;
}

template <typename T>
ScopedPtr<T>::~ScopedPtr()
{
	std::cout << "Dtor" << std::endl;
	delete ptr_;
}

template <typename T>
ScopedPtr<T>::ScopedPtr(const ScopedPtr& rhs) : ptr_(new T{*rhs.ptr_}), size_(rhs.size_)
{
	std::cout << "CopyCtor" << std::endl;
}

template <typename T>
ScopedPtr<T>& ScopedPtr<T>::operator=(const ScopedPtr& rhs)
{
	std::cout << "Operator=" << std::endl;
	if (this != &rhs)
	{
		delete ptr_;
		size_ = rhs.size_;
		ptr_ = new T(*rhs.ptr_);
	}
	return *this;
}

#ifdef MOVE
template <typename T>
ScopedPtr<T>::ScopedPtr(ScopedPtr&& rhs) : ptr_(rhs.ptr_), size_(rhs.size_)
{
	std::cout << "MoveCtor" << std::endl;
	rhs.ptr_ = nullptr;
}

template <typename T>
ScopedPtr<T>& ScopedPtr<T>::operator=(ScopedPtr&& rhs)
{
	if (this != &rhs)
	{
		std::cout << "Move_Operator=" << std::endl;
	  size_ = rhs.size_;
	  std::swap(ptr_, rhs.ptr_);
	}
  return *this;
}

#endif




} //namespace Pointer