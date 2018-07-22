#pragma once
#include <iostream>

const int maxSize = 10;
template <class T>
struct StaticLinkNode {
	T data;
	int link;  //�������ָ��
};

template <class T>
class StaticList {
public:
	void InitList(); //��ʼ��
	int Length();    //���㾲̬����ĳ���
	int Search(T x);  //�ھ�̬�����в��Ҿ��и���ֵ�Ľ��
	int Locate(int i); //�ھ�̬�����в��ҵ�i�����
	bool Append(T x); //�ھ�̬����ı�β׷��һ���½��
	bool Insert(int i, T x); //�ھ�̬����ĵ�i��λ�ý������һ���½��
	bool Remove(int i); //�ھ�̬�������ͷŵ�i�����
	bool IsEmpty(); //�жϾ�̬�����Ƿ�Ϊ��
	void Output(); //�����ʾ
private:
	StaticLinkNode<T> elem[maxSize];
	int currHead; //��ǰ�ɷ���ռ���׵�ַ
};

template <class T>
void StaticList<T>::InitList()
{
	elem[0].link = -1;
	currHead = 1;
	 //��ǰ�ɷ���ռ��1��ʼ��������ͷ���Ŀ�����
	for (int i=1; i<maxSize-1; ++i)
	{
		elem[i].link = i+1; //���ɿ�������
	}
	elem[maxSize-1].link = -1; //����β
}

template <class T>
int StaticList<T>::Length()
{
	int len = 0;
	for (int i=0; i<maxSize; ++i)
	{
		if (elem[i].link == -1)
		{
			break;
		}
		len++;
	}
	return len;
}

template <class T>
int StaticList<T>::Search(T x)  //�ھ�̬�����в��Ҿ��и���ֵ�Ľ��
{
	int ptr = elem[0].link; //��ʼָ��
	while (ptr!=-1)
	{
		if (elem[ptr].data == x)
			break;
		else
			ptr = elem[ptr];
	}
	return ptr;
}

template <class T>
int StaticList<T>::Locate(int i) //�ھ�̬�����в��ҵ�i�����
{
	if (i<0) return -1;
	if (i==0) return 0;
	int cnt = 1;
	int p = elem[0].link;
	while (p!=-1 && cnt<i)
	{
		p = elem[p].link;
		cnt++;
	}
	return p;
}

template <class T>
bool StaticList<T>::Append(T x) //�ھ�̬����ı�β׷��һ���½��
{
	if (currHead==-1) return false;
	int q = currHead;
	currHead = elem[currHead].link;
	elem[q].data = x;
	elem[q].link = -1;
	int p = 0; //Ѱ�ұ�β
	while (elem[p].link != -1)
	{
		p = elem[p].link;
	}
	elem[p].link = q;
	return true;
}

template <class T>
bool StaticList<T>::Insert(int i, T x) //�ھ�̬����ĵ�i��λ�ý������һ���½��
{
	int p = Locate(i);
	if (p==-1) return false; 
	int q = currHead;
	currHead = elem[currHead].link;
	elem[q].data = x;
	elem[q].link = elem[p].link; //����
	elem[p].link = q;
	return true;
}

template <class T>
bool StaticList<T>::Remove(int i) //�ھ�̬�������ͷŵ�i�����
{
	int p = Locate(i-1);
	if (p == -1) return false;
	int q = elem[p].link;
	elem[p].link = elem[q].link;
	elem[q].link = currHead;
	currHead = q;
	return true;
}

template <class T>
bool StaticList<T>::IsEmpty() //�жϾ�̬�����Ƿ�Ϊ��
{
	return (elem[0].link==-1) ? true: false;
}

template <class T>
void StaticList<T>::Output() //�����ʾ
{
	for (int i =0; i<maxSize; ++i)
	{
		std::cout <<"[" <<elem[i].link << "]" << elem[i].data << ",";
	}
	std::cout << std::endl;
}