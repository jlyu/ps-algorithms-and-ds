#pragma once
#include "Queue.h"
#include <assert.h>
#include <iostream>
using namespace std;


template <class T>
class CirQueue : public Queue<T> {
public:
	CirQueue(int sz = 10); //���캯��
	~CirQueue() { 
		if (elements!=NULL)
			delete [] elements; 
	} //��������
	bool EnQueue(const T &x); //�����в�������x���ӣ��������������
	bool DeQueue(T &x); //�����в��գ��򷵻�true��x��ֵ�����򷵻�false
	bool GetFront(T &x); //�����в�Ϊ�գ��򷵻ض�ͷԪ�غ�true�����򷵻�false
	void MakeEmpty() { front = rear = 0; } //�ÿղ�������ͷָ��Ͷ�βָ����0
	bool IsEmpty()const { return (front == rear)? true : false; }
	bool IsFull()const { return ((rear+1)%maxSize == front) ? true : false; }
	int GetSize()const { return(rear-front+maxSize)%maxSize; }
	void Output()const;
	template <class T>
	friend ostream& operator<< (ostream &os, CirQueue<T> &cq);

protected:
	int front, rear; //��ͷ�Ͷ�βָ��
	T *elements;     //��Ŷ���Ԫ�ص�����
	int maxSize;     //������������Ԫ�ظ���
};

template <class T>
CirQueue<T>::CirQueue(int sz)//���캯��
	: front(0), rear(0), maxSize(sz)
{
	elements = new T[maxSize];
	assert(elements!=NULL);
}

template <class T>
bool CirQueue<T>::EnQueue(const T &x) //�����в�������x���ӣ��������������
{
	if (IsFull()) return false;
	elements[rear] = x;
	rear = (rear+1) % maxSize; //��βָ��+1
	return true;
}

template <class T>
bool CirQueue<T>::DeQueue(T &x)
{
	if (IsEmpty()) return false;
	x = elements[front];
	front = (front+1) % maxSize;
	return true;
}

template <class T>
bool CirQueue<T>::GetFront(T &x) //�����в�Ϊ�գ��򷵻ض�ͷԪ�غ�true�����򷵻�false
{
	if (IsEmpty()) return false;
	x = elements[front];
	return true;
}

template <class T>
ostream& operator<< (ostream &os, CirQueue<T> &cq)
{
	os << "front = " << cq.front << " rear = " << cq.rear << std::endl;
	for (int i = cq.front; i!=cq.rear; i=(i+1)%cq.maxSize)
	{
		os << "[" << i << "]" << cq.elements[i] << std::endl;
	}
	return os;
}

template <class T>
void CirQueue<T>::Output()const
{
	std::cout << "front = " << front << " rear = " << rear << std::endl;
	for (int i = front; i!=rear; i=(i+1)%maxSize)
	{
		std::cout << "[" << i << "]" << elements[i] << std::endl;
	}
}