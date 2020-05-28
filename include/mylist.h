#ifndef  MYLIST_H_
#define MYLIST_H_
#include <iostream>
#include <exception>
using namespace std;
/*
**Title:自己实现List双向链表
**Author:kapechen
**Version:v0.1
**Log:
*----------------------------------------------------------------------
*----|	index	|	Date	|	Content				|	Problems      |	
*		  1		  2020/5/20    基本框架构建			边界检测细节未完成
*		  2       2020/5/28    增加了注释和边界检测类      尚未发现 
*
*---------------------------------------------------------------------
*/
/*
|——List类
	|
	|——Node结构体
	|——const_iterator类
			|——iterator类
*/
class IteratorOutOfBoundsException:public exception
{
public:
	IteratorOutOfBoundsException()
	{
		cout << "Iterator Out Of Bounds!" << endl;
	}
	IteratorOutOfBoundsException(const char* message) :message_{ message }
	{}
	IteratorOutOfBoundsException(consy IteratorOutOfBoundsException &other):message_{other.message_}
	{}
	const char* what()const
	{
		return message_.c_str();
	}
private:
	string message_;
};
template <typename Object>
class List
{
	
private:
	struct Node {
		Object data;
		Node* prev;
		Node* next;
		Node(const Object&d=Object{},Node *p=nullptr,Node* n=nullptr):data{d},prev{p},next{n}{ }
		Node(Object&& d, Node* p = nullptr, Node* n = nullptr):data{std::move(d)},prev{p},next{n}{ }
	};
public:
	/*迭代器类的定义:const_iterator类
						|
						 ——iterator类*/
	class const_iterator
	{
	public:
		const_iterator():current{nullptr}
		{}
		/// <summary>
		/// 取得迭代器当前指向节点值的引用
		/// </summary>
		/// <returns>当前节点的值的引用</returns>
		const Object&operator*()const
		{
			return retrieve();
		}
		/// <summary>
		/// 迭代器前置加加
		/// </summary>
		/// <returns>const迭代器的引用</returns>
		const_iterator& operator++()//++itr
		{
			current = current->next;
			return *this;
		}
		/// <summary>
		/// 迭代器后置加加
		/// </summary>
		/// <param name="int">int</param>
		/// <returns>const迭代器</returns>
		const_iterator operator++(int)//itr++
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}
		bool operator==(const const_iterator &rhs)const
		{
			return current == rhs.current;
		}
		bool operator!=(const const_iterator &rhs)const
		{
			return !(*this == rhs);
		}

	protected:
		const List<Object>* theList;//指向当前List的const指针
		Node* current;
		Object &retrieve()const
		{
			return current->data;
		}
		const_iterator(const List<Object>& lst, Node* p) :theList{&lst},current { p }
		{}
		void assertIsValid()const
		{
			if (theList == nullptr || current == nullptr || current == theList->head)
				throw IteratorOutOfBoundsException{};//C++11统一风格 为了统一针对vector类型初始化对象语法
		}
		friend class List<Object>;
	};
	class iterator :public const_iterator
	{
	public:
		iterator(){}
		Object &operator*()
		{
			return const_iterator::retrieve();
		}
		const Object &operator*()const
		{
			return const_iterator::operator*();
		}
		iterator &operator++()
		{
			this->current = this->current->next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}
	protected:
		iterator(Node *p):const_iterator{p}
		{}
		friend class List<Object>;
	};
public:
	/*List类基本函数部分*/
	List(){
		init();
	}
	List(const List& rhs)
	{
		init();
		for (auto& x : rhs)
			push_back(x);
	}
	~List(){
		clear();
		delete head;
		delete tail;
	}
	List&operator=(const List&rhs)
	{
		List copy = rhs;
		std::swap(*this, copy);
		return *this;
	}
	List(List && rhs):theSize{rhs.theSize},head{rhs.head},tail{rhs.tail}
	{
		rhs.theSize = 0;
		rhs.head = nullptr;
		rhs.tail = nullptr;
	}
	List& operator=(List&& rhs) {
		std::swap(theSize, rhs.theSize);
		std::swap(head, rhs.head);
		std::swap(tail, rhs.tail);
		return *this;
	}
	/*迭代器相关操作*/
	iterator begin()
	{
		return {
			head->next
		};
	}
	const_iterator begin()const
	{
		return { head->next };
	}
	iterator end()
	{
		return { tail };
	}
	const_iterator end()const
	{
		return { tail };
	}
	//itr之前插入x
	iterator insert(iterator itr, const Object& x)
	{
		itr.assertIsValid();
		if (itr.theList != this)
			throw IteratorMismatchException{};
		Node* p = itr.current;
		theSize++;
		return { p->prev = p->prev->next = new Node{x,p->prev,p} };
	}
	//itr之前插入x
	iterator insert(iterator itr, Object&& x)
	{
		itr.assertIsValid();
		if (itr.theList != this)
			throw IteratorMismatchException{};
		Node* p = itr.current;
		theSize++;
		return { p->prev = p->prev->next = new Node{std::move(x),p->prev,p} };
	}
	iterator erase(iterator itr)
	{
		Node* p = itr.current;
		iterator retVal{ p->next };
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		theSize--;
		return retVal;
	}
	iterator erase(iterator from, iterator to)
	{
		for (iterator itr = from; itr != to;)
			itr = erase(itr);
		return to;
	}
	/*List类常用函数*/
	int size()const
	{
		return theSize;
	}
	bool empty()const
	{
		return size() == 0;
	}
	void clear()
	{
		while (!empty())
			pop_front();
	}
	Object& front()
	{
		return *begin();
	}
	const Object& front()const
	{
		return *begin();
	}
	Object& back()
	{
		return *--end();
	}
	const Object& back()const
	{
		return *--end();
	}
	void push_front(const Object& x)
	{
		insert(begin(), x);
	}
	void push_front(Object&& x)
	{
		insert(begin(), std::move(x));
	}
	void push_back(const Object& x)
	{
		insert(end(), x);
	}
	void push_back(Object&& x)
	{
		insert(end(), std::move(x));
	}
	void pop_front()
	{
		erase(begin());
	}
	void pop_back()
	{
		erase(--end());
	}
	
private:
	/*私有成员，包括初始化函数*/
	int theSize;
	Node* head;
	Node* tail;
	void init() {
		theSize = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}

};
#endif // ! MYLIST_H_
