#pragma once
template<class T>
class SharedPtr
{
	//static int cnt;
public:
	SharedPtr() {
		this->ptr =nullptr;
	}
	SharedPtr( T*ptr){
		this->ptr = ptr;
		cnt=new int;
		*cnt = 1;
	}
	SharedPtr(const SharedPtr &other) {
		this->ptr = other.ptr;
		cnt=other.cnt;
		(*cnt)++;
	}
	SharedPtr& operator=(const SharedPtr&other) {
		this->ptr=other.ptr;
		cnt = other.cnt;
		(*cnt)++;
		return *this;
	}
	SharedPtr* operator->() {
		return ptr;
	}
	~SharedPtr(){
	   if (*cnt==1)
	   {
		   delete ptr;
	   }
	   else
	   {
		   (*cnt)--;
	   }
	}
	T &operator*() {
		return *ptr;
	}
	int use_count() {
		return *cnt;
	}

private:
	T *ptr;
	int *cnt;
};

//template<typename T> int SharedPtr<T>::cnt = 0;

