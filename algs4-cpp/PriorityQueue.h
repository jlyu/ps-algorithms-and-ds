#pragma once
#include <assert.h>
#include <iostream>

template <class T>
class PriorityQueue {
public:
	PriorityQueue(int sz = 10);
	~PriorityQueue() { delete [] pqelements; }
	bool Insert(const T& x); //����Ԫ��x�����β
	bool RemoveMin(T &x); //����ͷԪ��ɾȥ
	bool GetFront(T &x)const; //��ȡ��ͷ��������С����Ȩ����ֵ
	void MarkEmpty() { const = 0; } //����С���ȼ�����Ϊ��
	bool IsEmpty() { return (count==0) ? true : false; }
	bool IsFull() { return (count==maxSize) ? true : false; }
	int GetSize()const { return count; }
	void Output();

protected:
	T* pqelements; //���ȼ���������
	int count;     //��ǰԪ�ظ���
	int maxSize;   //������������Ԫ�ظ���
	void _AdjustPriorityQueue(); //���е���
};


template <class T>
PriorityQueue<T>::PriorityQueue(int sz)
	: count(0), maxSize(sz)
{
	pqelements = new T[maxSize];
	assert(pqelements!=NULL);
}

template <class T>
bool PriorityQueue<T>::Insert(const T& x) //����Ԫ��x�����β
{
	if (IsFull()) return false;
	pqelements[count++] = x;
	_AdjustPriorityQueue();
	return true;
}

template <class T>
void PriorityQueue<T>::_AdjustPriorityQueue()
{
	T temp = pqelements[count-1];
	int j;
	for (j = count-2; j>=0; --j)
	{
		if (pqelements[j]<=temp)
		{
			break;
		}
		else
		{
			pqelements[j+1] = pqelements[j];
		}
	}
	pqelements[j+1] = temp;
}

template <class T>
bool PriorityQueue<T>::RemoveMin(T &x) //����ͷԪ��ɾȥ
{
	if (IsEmpty()) return false;
	x = pqelements[0];
	for (int i=1; i<count; ++i)
		pqelements[i-1] = pqelements[i]; //ɾ����ͷ��ȫ������
	count--;
	return true;
}

template <class T>
bool PriorityQueue<T>::GetFront(T &x)const //��ȡ��ͷ��������С����Ȩ����ֵ
{
	if (IsEmpty()) return false;
	x = pqelements[0];
	return true;
}

template <class T>
void PriorityQueue<T>::Output()
{
	for (int i=0; i<count; ++i)
	{
		std::cout << "[" << i << "]" << pqelements[i] << std::endl;
	}
}