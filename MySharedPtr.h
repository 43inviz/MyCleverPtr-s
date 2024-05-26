#pragma once
template<typename T>
class MySharedPtr
{
	T* _objPtr;
	unsigned int _count;
public:
	MySharedPtr() : _objPtr(nullptr),_count(0){}
	MySharedPtr(T* objPtr):_objPtr(objPtr),_count(1){}

	MySharedPtr(const MySharedPtr& copy) {
		_objPtr = new T(*(copy._objPtr));
		_count = copy._count;
		_count++;
	}

	MySharedPtr<T>& operator=(const MySharedPtr& copy) {
		if (this != &copy) {
			delete _objPtr;
			
			_objPtr = new T(*(copy._objPtr));
			_count = copy._count;
			_count++;
			
		}
		return *this;
	}


	unsigned int getCount() {
		return _count;
	}

	T* get() {
		return _objPtr;
	}

	T& operator*() {
		return *_objPtr;
	}

	T* operator->() {
		return _objPtr;
	}

	~MySharedPtr() {
		delete _objPtr;
	}
};

