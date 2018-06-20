#pragma once
#include <iostream>

template <class T>
struct CircLinkNode {
	T data;
	CircLinkNode<T> *next;
	CircLinkNode(CircLinkNode<T> *ptr = NULL): next(ptr) { }
	CircLinkNode(T d, CircLinkNode<T> *ptr = NULL): data(d), next(ptr) { }
};

template <class T>
class CircList : public CircLinkNode<T>{
public:
	CircList();
	CircList(const T& up, const T& down);
	CircList(const T& x);
	CircList(CircList<T> &L);
	~CircList();
	int Length()const;
	bool IsEmpty() { return first->next == first ? true : false; } //�ж������Ƿ�Ϊ��
	CircList<T>* GetHead()const { return first; } //����ѭ�������ͷָ��
	void SetHand(CircLinkNode<T> *p);  //���ø���ͷ����ַ
	CircLinkNode<T>* Search(T x); //������x�Ľ��
	CircLinkNode<T>* Locate(int i); //������i������ֵ
	T* GetData(int i);		//ȡ�õ�i��Ԫ�ص�ֵ
	bool Insert(T &x); // ����x
	bool Insert(int i, T &x); //�ڵ�i��Ԫ�غ����x
	bool Remove(int i, T &x); //ɾ����i����㣬x���ظ�ֵ
	void Output();

//private:
public:
	CircLinkNode<T> *first; //ѭ������ͷ���
	CircLinkNode<T> *last;  //ѭ������β���
};

template <class T>
CircList<T>::CircList()
{
	first = new CircLinkNode<T>(0);
	last = new CircLinkNode<T>(0);
	first->next = last;
	last->next = first;
}

template <class T>
CircList<T>::CircList(const T& x)
{
	first = new CircLinkNode<T>(x);
	last = new CircLinkNode<T>(x);
	first->next = last;
	last->next = first;
}

template <class T>
CircList<T>::CircList(const T& l, const T& r)
{
	first = new CircLinkNode<T>(l);
	last = new CircLinkNode<T>(r);
	first->next = last;
	last->next = first;

	for (int i=r-1; i>=l+1; --i) Insert(i);
}
template <class T>
CircList<T>::~CircList()
{
	CircLinkNode<T> *delPtr;
	while(first->next != first)
	{
		delPtr = first->next;
		first->next = delPtr->next;
		delete delPtr;
	}
}

template <class T>
int CircList<T>::Length()const
{
	int len = 0;
	CircLinkNode<T>* current = first->next;
	while (current->next!=first)
	{
		current = current->next;
		len++;
	}
	return len;
}

template <class T>
CircLinkNode<T>* CircList<T>::Locate(int i) //������i������ֵ
{
	if (i<0)
		return NULL;
	int count = 0;
	CircLinkNode<T> *current = first;
	//i = i % Length();
	//while (count != i)
	while (current!=first && count<i)
	{
		current = current->next;
		count++;
	}
	return current;
}

template <class T>
bool CircList<T>::Insert(int i, T &x) //�ڵ�i��Ԫ�غ����x
{
	CircLinkNode<T> *current = Locate(i);
	CircLinkNode<T>* newNode = new CircLinkNode<T>(x);
	if (newNode==NULL) return false;
	if (Length() == 0)
	{
		first->next = newNode;
		newNode->next = last;
	}
	else if (current==first || current == last)
	{
		newNode->next = last->next;
		last->next = newNode;
	}
	else
	{
		newNode->next = current->next;
		current->next = newNode;
	}
	return true;
}

template <class T>
bool CircList<T>::Insert(T &x) //�ڵ�i��Ԫ�غ����x
{
	CircLinkNode<T>* newNode = new CircLinkNode<T>(x);
	if (newNode == NULL) return false;
	if (Length()==0)
	{
		newNode->next = last;
		first->next = newNode;
	}
	else
	{
		//newNode->next = last->next;
		//last->next = newNode;
		newNode->next = first->next;
		first->next = newNode;
	}
	
	return true;
}

template <class T>
void CircList<T>::Output()
{
	CircLinkNode<T> *current = first;
	std::cout << first->data << "(" << &first->data <<  ")" << std::endl;
	std::cout << last->data  << "(" << &last->data  <<  ")" << std::endl; 
	int cnt = 0;
	while (current->next!=first)
	//while (cnt != 20)
	{
		//if (current!=first && current!=last)
		{
			std::cout << current->data << "(" << &current->data <<  "),";
			
		}
		current = current->next;
		cnt++;
	}
	std::cout << std::endl;
}