#pragma once

const int maxSize = 10;

template <class T>
class Queue {
public:
	Queue() { }
	~Queue() { }
	virtual bool EnQueue(const T &x) = 0;  //����
	virtual bool DeQueue(T &x) = 0;        //����
	virtual bool GetFront(T &x) = 0; //��ȡ��ͷԪ��ֵ
	virtual bool IsEmpty()const = 0; //�ж϶����Ƿ��
	virtual bool IsFull()const = 0;  //�ж϶����Ƿ���
	virtual int GetSize()const = 0;  //�����Ԫ�ظ���
};