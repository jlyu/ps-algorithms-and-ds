#pragma  once
#include <assert.h>
#include "iostream"
using std::ostream;

//const int maxSize = 50;

template <class T>
class Stack {
public:
	Stack() { }
	virtual void Push(const T& x) = 0; //��Ԫ�ؽ�ջ
	virtual bool Pop(T &x) = 0; //ջ��Ԫ�س�ջ����x����
	virtual bool GetTop(T &x)const = 0;//��ȡջ��Ԫ�أ���x����
	virtual bool IsEmpty()const = 0; 
	virtual bool IsFull()const = 0;
	virtual int GetSize()const = 0; //����ջ��Ԫ�ظ���
};

const int StackIncreasement = 20; //ջ���ʱ��չ�ռ������

template <class T>
class SeqStack : public Stack<T> {
public:
	SeqStack(int sz=50); //����һ����ջ
	~SeqStack() { delete [] elements; }

	void Push(const T& x); //ջ���пռ������Ԫ��x
	bool Pop(T &x); //��ջ��Ϊ���򵯳�Ԫ��x
	bool GetTop(T &x)const; 
	bool IsEmpty()const { return (top == -1) ? true : false; }
	bool IsFull()const { return (top == maxSize-1) ? true : false; }
	int GetSize()const { return top+1; }
	void Clear() { top = -1; }
	template <class T>
	friend ostream& operator<< (ostream& os, SeqStack<T>& s);

private:
	T *elements; //���ջ�е�Ԫ�ص�ջ����
	int top;	 //ջ��ָ��
	int maxSize; //ջ��������Ԫ�ظ���
	void overflowProcess(); //ջ�������
};

template <class T>
SeqStack<T>::SeqStack(int sz)
	:top(-1),maxSize(sz)
{
	elements = new T[maxSize];
	assert(elements != NULL);
}

template <class T>
void SeqStack<T>::overflowProcess() //ջ�������
{
	T *newElements = new T[maxSize + StackIncreasement];
	assert(newElements != NULL);
	for (int i=0; i<maxSize; ++i)
		newElements[i] = elements[i];
	maxSize += StackIncreasement;
	delete [] elements;
	elements = newElements;
	cout << "called SeqStack<T>::overflowProcess();" << "\n";
}

template <class T>
void SeqStack<T>::Push(const T& x) //ջ���пռ������Ԫ��x
{
	if (IsFull())
		overflowProcess();
	elements[++top] = x;
}

template <class T>
bool SeqStack<T>::Pop(T &x) //��ջ��Ϊ���򵯳�Ԫ��x
{
	if (IsEmpty())
		return false;
	x = elements[top--];
	return true;
}

template <class T>
bool SeqStack<T>::GetTop(T &x)const
{
	if (IsEmpty())
		return false;
	x = elements[top];
	return true;
}

template <class T>
ostream& operator<< (ostream& os, SeqStack<T>& s)
{
	for (int i = s.top; i>=0; --i)
	{
		os << "[" << i << "]" << s.elements[i] << std::endl;
	}
	return os;
}