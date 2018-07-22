#pragma once
#include <iostream>

template <class T>
struct DblNode{
	T data;
	DblNode<T> *lLink; //˫����ǰ������
	DblNode<T> *rLink; //˫�����������

	DblNode(DblNode<T> *left =NULL, DblNode<T> *right = NULL)
		:lLink(left),rLink(right)
	{  }
	DblNode(T val, DblNode<T> *left =NULL, DblNode<T> *right = NULL)
		:data(val), lLink(left),rLink(right)
	{  }
};

template <class T>
class DblList : public DblNode<T> {
public:
	DblList(T uniqueVal); //���캯������������ͷ���
	~DblList(); //��������
	int Length()const; //����˫������
	bool isEmpty(){ return first->rLink== first; } //�ж�˫�����Ƿ�Ϊ��
	DblNode<T>* GetHead()const { return first; } //�õ�˫����ͷ���
	void SetHead(DblNode<T>* ptr) { first = ptr; } //����˫�����ͷ���
	DblNode<T>* Search(const T& x); //���������غ�̷���Ѱ�ҵ��ڸ���ֵx�Ľ��
	DblNode<T>* Locate(int i, int d); //d=0ǰ�����򣬡�0����������λ���Ϊi�Ľ��
	bool Insert(int i, const T& x, int d); //d=0ǰ�����򣬡�0����������, �����Ϊi�Ľ��֮�����һ��xֵ�Ľ��
	bool Remove(int i, const T& x, int d); //d=0ǰ�����򣬡�0����������, ɾ�����Ϊi�Ľ�㡣ɾ��ֵ����x
	void Output(); //���
private:
	DblNode<T> *first; 
};


template <class T>
DblList<T>::DblList(T uniqueVal) //���캯������������ͷ���
{
	first = new DblNode(uniqueVal);
	if (first == NULL)
	{
		std::cerr << "ͷ����ڴ����ʧ�ܣ�";
		exit(1);
	}
	first->rLink = first->lLink = first;
}

template <class T>
DblList<T>::~DblList() //��������
{

}

template <class T>
int DblList<T>::Length()const //����˫������
{
	int len = 0;
	DblNode<T> *current = first;
	while (current->rLink!=first)
	{
		len++;
		current = current->rLink;
	}
	return len;
}

template <class T>
DblNode<T>* DblList<T>::Search(const T& x) //���������غ�̷���Ѱ�ҵ��ڸ���ֵx�Ľ��
{ //˳������
	DblNode<T> *current = first->rLink;
	while (current != first && current->data != x)
		current = current->rLink;
	if (current!=first)
		return current;
	else
		return NULL;
}

template <class T>
DblNode<T>* DblList<T>::Locate(int i, int d) //d=0ǰ�����򣬡�0����������λ���Ϊi�Ľ��
{
	if (i<0)
		return NULL;
	if (first->rLink == first || i==0)
		return first;
	DblNode<T> *current; 
	if (d==0)  //��������
		current = first->lLink;
	else
		current = first->rLink;
	for (int j=1; j<i; j++)
	{
		if (current==first) 
			break;
		else if (d==0) 
			current = current->lLink;
		else 
			current = current->rLink;
	}
	if (current!=first)
		return current; //��λ�ɹ�
	else
		return NULL; //��λʧ��
}

template <class T>
bool DblList<T>::Insert(int i, const T& x, int d) //d=0ǰ�����򣬡�0����������, �����Ϊi�Ľ��֮�����һ��xֵ�Ľ��
{
	DblNode<T> *newNode = new DblNode(x);
	if (newNode==NULL) return false;

	DblNode<T> *current;
	if (isEmpty()) //���˫����Ϊ�գ���ֱ�Ӳ���
	{
		//current = first;
		//newNode->rLink = 
		current = first;
	}
	else
		current = Locate(i, d);
	if (current==NULL) return false;

	if (d==0) //ǰ�����룬�����޸�4��ָ��
	{
		newNode->lLink = current->lLink;
		current->lLink = newNode;
		newNode->lLink->rLink = newNode;
		newNode->rLink = current;
	}
	else
	{
		newNode->rLink = current->rLink;
		current->rLink = newNode;
		newNode->rLink->lLink = newNode;
		newNode->lLink = current;
	}
	return true;
}

template <class T>
bool DblList<T>::Remove(int i, const T& x, int d) //d=0ǰ�����򣬡�0����������, ɾ�����Ϊi�Ľ�㡣ɾ��ֵ����x
{
	DblNode<T> *current = Locate(i, d);
	if (current==NULL) return false;
	current->lLink = current->rLink;
	current->rLink = current->lLink;
	x = current->data; delete current;
	return true;
}

template <class T>
void DblList<T>::Output() //���
{
	DblNode<T> *current = first->rLink;
	while (current != first)
	{
		std::cout << current->data << ",";
		current = current->rLink;
	}
	std::cout << '\n';
}