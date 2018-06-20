#pragma once

#include <iostream>
#include <assert.h>

template <class T>
struct GenListNode;

template <class T>
struct Items { //����ֵ����ṹ����
	int utype; //=0/1/2
	union {
		int ref; //=0,����ͷ��㣬������ü���
		T value; //=1,�������
		GenListNode<T> *hlink; //=2,���ָ���ӱ��ͷ���ָ��
	} info;
	Items() : utype(0), info.ref(0) { }
	Items(Items<T>& copy) { utype = copy.utype; info = copy.info; }
};

template <class T>
class GenListNode { //��������ඨ��
public:
	GenListNode():utype(0), tlink(NULL), info.ref(0) { }
	GenListNode(GenListNode<T> &gl)
	{ utype = gl.utype; tlink = gl.tlink; info = gl.info; }
private:
	int utype;
	GenListNode<T> *tlink; //ָ��ͬһ����һ������ָ��
	union {
		int ref;
		T value;
		GenListNode<T> *hlink;
	} info;
};

template <class T>
class GenList { //������ඨ��
	template <class T>
	friend std::istream& operator>> (std::istream &in, GenList<T> &gl);
public:
	GenList();
	~GenList();
	bool Head(Items& x); //���ر�ͷԪ��x
	bool Tail(GenList<T> &lt); //���ر�βlt
	GenListNode<T>* Front(); //���ص�һ��Ԫ��
	GenListNode<T>* Next(GenListNode<T>* elem); //���ر�Ԫ��elem��ֱ�Ӻ���Ԫ��
	void Copy(const GenList<T> &gl);
	int Length(); //��������ĳ���
	int Depth();  //����ǵݹ���������

private:
	GenListNode<T> *Copy(GenListNode<T> *gl); //����һ��glָʾ���޹���ǵݹ��
	int Length(GenListNode<T> *gl); //����glָʾ�Ĺ����ĳ���
	int depth(GenListNode<T> *gl); //������glָʾ�ķǵݹ������
	bool equal(GenListNode<T> *ls, GenListNode<T> *rs); //�жϷֱ���ls��rsΪͷ����2��������Ƿ����
	void Remove(GenListNode<T> *gl); //�ͷ���glΪͷ���Ĺ����
	void GreateList(std::istream &in, GenListNode<T> *&gl);
private:
	GenListNode<T> *first; //�����ͷָ��
};

template <class T>
GenList<T>::GenList()
{
	first = new GenListNode;
	assert(first!=NULL);
}

template <class T>
bool GenList<T>::Head(Items& x) //���ر�ͷԪ��x
{
	if (first->tlink == NULL) return false;
	else 
	{
		x.utype = first->utype;
		x.info = first->info;
		return true;
	}
}

template <class T>
bool GenList<T>::Tail(GenList<T> &lt)
{
	if (first->tlink == NULL) return false; //�ձ�
	else 
	{
		lt.first->utype = 0;
		lt.first->info.ref = 0;
		lt.first->tlink = Copy(first->tlink->tlink);
		return true;
	}
}