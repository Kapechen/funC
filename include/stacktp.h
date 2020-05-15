//stacktp.h -- a stack template
#ifndef STACKTP_H_
#define STACKTP_H_
template <typename Type>
class Stack
{
	//模板类声明和定义不可分离
private:
	enum {
		SIZE=10//默认大小
	};
	int stacksize;
	Type* items;
	int top;
public:
	explicit Stack(int ss = SIZE);
	Stack(const Stack& st);
	~Stack() {
		delete[] items;
	}
	
	bool isempty() {
		return top == 0;
	}
	bool isfull() {
		return top == stacksize;
	}
	bool push(const Type& items);
	bool pop(Type& item);
	Stack& operator=(const Stack& st);//这里是Stack<Type>的缩写，这种缩写值可以在类中使用
};

template <typename Type>
Stack<Type>::Stack(int ss):stacksize(ss),top(0)
{
	items = new Type[stacksize];
}
template <typename Type>
Stack<Type>::Stack(const Stack& st)
{
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
}



template <typename Type>
bool Stack<Type>::push(const Type& item)
{
	if (top < stacksize)
	{
		items[top++] = item;
		return true;
	}
	else {
		return false;
	}
}
template <typename Type>
bool Stack<Type>::pop(Type& item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else {
		return false;
	}
}
template <typename Type>
Stack<Type>& Stack<Type>::operator=(const Stack<Type>& st)
{
	if (this == &st)
		return *this;
	delete[] items;
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
	{
		items[i] = st.items[i];
	}
	return *this;
}
#endif // !STACKTP_H_
