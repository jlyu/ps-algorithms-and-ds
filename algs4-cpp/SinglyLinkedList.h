#pragma once
#include <iostream>
using namespace std;

template <class T>
struct LinkNode { //��������ṹ
	T data;
	LinkNode<T> *next;

	LinkNode<T> (LinkNode<T> *ptr = NULL) { next = ptr; }
	LinkNode<T> (T item, LinkNode<T> *ptr= NULL) { data = item; next = ptr; }
};

template <class T>
class List : public LinkNode<T>{
public:
	List() { first = new LinkNode<T>; }
	List(const T& x) { first = new LinkNode<T>(x); }
	List(List<T>& L); //���ƹ��캯��
	~List() { makeEmpty();} //��������
	void makeEmpty();  //�����ÿ�
	int Length()const; //����������
	LinkNode<T> *getHead()const { return first; } //�������ͷָ��
	LinkNode<T> *Search(T x);     //���������к�X��Ԫ��
	LinkNode<T> *Locate(int i);   //������i��Ԫ�صĵ�ַ
	bool getData(int i, T&x)const; //ȡ�õ�i������ֵ
	void setData(int i, T&x);      //���õ�i������ֵ
	bool Insert(int i, T&x);       //�ڵ�i���������x
	bool Remove(int i, T&x);       //ɾ����i����㣬x����ɾ��ֵ
	bool IsEmpty()const { return(first->next==NULL)? true : false; } //�����Ƿ�Ϊ��
	//bool IsFull()const { return false; } //�����Ƿ����
	void Sort(); //��������
	void Input(); 
	void Output();

protected:
	LinkNode<T> *first; //�����ͷָ��
};

template <class T>
List<T>::List(List<T>& L) //���ƹ��캯��
{
	T copyV;
	List<T> *srcPtr = L.getHead();
	List<T> *destPtr = first = new List<T>;
	while (srcPtr->next != NULL)
	{
		copyV = srcPtr->next->data;
		destPtr->next = new List<T>(copyV);
		destPtr = destPtr->next;
		srcPtr = srcPtr->next;
	}
	destPtr->next = NULL;
}

template<class T>
void List<T>::makeEmpty()  //�����ÿ�
{
	LinkNode<T> *p;
	if (IsEmpty())
	{
		p = first->next;
		first->next = p->next;
		delete p;
	}
}

template <class T>
int List<T>::Length()const //����������
{
	int length = 0;
	LinkNode<T> *tmpp = first->next;
	while (tmpp!=NULL)
	{
		length++;
		tmpp = tmpp->next;
	}
	return length;
}

template <class T>
LinkNode<T>* List<T>::Search(T x)     //���������к�X��Ԫ��
{
	LinkNode<T>* current = first->next;
	while (current!=NULL)
	{
		if (current->getData == x)
			break;
		else
			current = current->next;
	}
	return current;
}

template <class T>
LinkNode<T>* List<T>::Locate(int i)   //������i��Ԫ�صĵ�ַ
{
	if (i<0 || i>Length())
		return NULL;
	LinkNode<T> *current = first;
	int count = 0;
	while (current!=NULL && count<i)
	{
		current = current->next;
		count++;
	}
	return current;
}

template <class T>
bool List<T>::getData(int i, T&x)const //ȡ�õ�i������ֵ
{
	if (i<=0 || i>Length())
		return false;

	LinkNode<T> *current = Locate(i);
	if (current == NULL)
		return false;
	else
	{
		x = current->data;
		return true;
	}
}

template <class T>
void List<T>::setData(int i, T&x)      //���õ�i������ֵ
{
	if (i<=0)
		return;
	LinkNode<T> *current = Locate(i);
	if (current == NULL)  //��������β����Χ����ʵ������Բ���
		return;
	else
		current->data = x;
}

template <class T>
bool List<T>::Insert(int i, T&x)       //�ڵ�i���������x
{
	LinkNode<T> *current = Locate(i);
	if (current == NULL)
		return false;
	LinkNode<T> *newNode = new LinkNode<T>(x);
	newNode->next = current->next;
	current->next = newNode;
	return true;
}

template <class T>
bool List<T>::Remove(int i, T&x)
{
	LinkNode<T> *current = Locate(i-1);
	if (current == NULL || current->next == NULL)
		return false;
	LinkNode<T> *delNode = current->next;
	x = delNode->data;
	current->next = delNode->next;
	delete delNode;
	return true;
}

template <class T>
void List<T>::Output()
{
	LinkNode<T> *header = first->next;
	if (IsEmpty())
	{
		cout << "������Ϊ��" << endl;
		return;
	}
	while (header != NULL)
	{
		cout << header->data << ",";
		header = header->next;
	}
	cout << endl;	
}

template <class T>
void List<T>::Input()
{//ǰ�巨
	if (!IsEmpty())
		makeEmpty();
	cout << "������1111ʱ��ֹͣ����"<< endl;

	LinkNode<T> *newNode;
	T val;
	cin >> val;
	while (val != 1111)
	{
		newNode = new LinkNode<T>(val);
		if (newNode == NULL)
		{
			cerr << "�½������ڴ����" << endl;
			return;
		}
		newNode->next = first->next;
		first->next = newNode;
		cin >> val;
	}
}