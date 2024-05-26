#pragma once
template <typename T>
class MyUniquePtr
{
	T* _objPtr;
public:
	MyUniquePtr() :_objPtr(nullptr){}
	MyUniquePtr(T* obj): _objPtr(obj){}


	MyUniquePtr(MyUniquePtr& copy) {
		_objPtr = copy._objPtr;
		copy._objPtr = nullptr;
	}

	MyUniquePtr& operator=(MyUniquePtr& other) noexcept {
		if (this != &other) {
			delete _objPtr; 
			_objPtr = other._objPtr; 
			other._objPtr = nullptr; 
		}
		return *this;
	}

	~MyUniquePtr() {
		delete _objPtr;
	}

	T& operator*() {
		return *_objPtr;
	}

	T* operator->() {
		return _objPtr;
	}

	T* get() const {
		return _objPtr;
	}
};

