#pragma once
#include <assert.h>
#include <iostream>
using std::ostream;

template <class T>
class Stack {
public:
	Stack() { }
	virtual void Push(const T& x) = 0; //��Ԫ�ؽ�ջ
	virtual bool Pop(T &x) = 0; //ջ��Ԫ�س�ջ����x����
	virtual bool GetTop(T &x)const = 0;//��ȡջ��Ԫ�أ���x����
	virtual bool IsEmpty()const = 0; 
	//virtual bool IsFull()const = 0;
	virtual int GetSize()const = 0; //����ջ��Ԫ�ظ���
};

template <class T>
struct LinkNode { //��������ṹ
	T data;
	LinkNode<T> *next;
	
	LinkNode<T> (LinkNode<T> *ptr = NULL) { next = ptr; }
	LinkNode<T> (T item, LinkNode<T> *ptr= NULL) { data = item; next = ptr; }
};

template <class T>
class LinkedStack : public Stack<T> {
public:
	LinkedStack():top(NULL) { }
	~LinkedStack() { Clear(); }
	void Push(const T& x); //��ջ
	bool Pop(T &x); //��ջ
	bool GetTop(T &x)const; //��ȡջ��Ԫ��
	bool IsEmpty()const { return (top==NULL)?true:false; }
	int GetSize()const; //��ջ��Ԫ�ظ���
	void Clear(); //��ջ
	
	template <class T>
	friend ostream& operator<< (ostream& os, LinkedStack<T>& LS);

private:
	LinkNode<T> *top; //ջ��ָ�룬������ͷָ��
};

template <class T>
void LinkedStack<T>::Clear() //��ջ
{
	while (top != NULL) //ÿ��ɾ��ͷ�������ͷ�ջ
	{
		LinkNode<T>* delNode = top;
		top = top->next;
		delete delNode;
	}
}

template <class T>
void LinkedStack<T>::Push(const T& x) //��ջ
{
	LinkNode<T>* newNode = new LinkNode<T>(x);
	assert(newNode!=NULL);
	newNode->next = top;
	top = newNode;
	//top = new LinkNode<T>(x, top);
	//assert(top!=NULL);
}

template <class T>
bool LinkedStack<T>::Pop(T &x) //��ջ
{
	if (IsEmpty())	return false;
	LinkNode<T>* delNode = top;
	x = top->data;
	top = top->next;
	delete delNode;
	return true;
}

template <class T>
bool LinkedStack<T>::GetTop(T &x)const //��ȡջ��Ԫ��
{
	if (IsEmpty()) return false;
	x = top->data;
	return true;
}

template <class T>
int LinkedStack<T>::GetSize()const
{
	if (IsEmpty()) return 0;
	int cnt = 0;
	LinkNode<T> *current = top;
	while (current != NULL)
	{
		cnt++;
		current = current->next;
	}
	return cnt;
}

template <class T>
ostream& operator<< (ostream&os, LinkedStack<T> &ls)
{          
	if (ls.IsEmpty())
	{
		os << "��ջ" << std::endl;
		return os;
	}
	LinkNode<T> *current = ls.top; 
	int cnt = 1;
	while (current != NULL)          
	{                                
		os << "[" << cnt << "]:" << current->data << "\n";
		current = current->next;
		cnt++;
	}
	os << std::endl;
	return os;
}