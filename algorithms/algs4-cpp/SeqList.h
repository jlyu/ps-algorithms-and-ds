#include <iostream>
#include "LinearLine.h"

const int defaultSize = 100;
template <class T>
class SeqList : public LinearLine<T> {
protected:
	T *data; //�����飬�ö�̬����
	int maxSize; //��������Ԫ�ظ���
	int last; //��ǰ�Ѵ�����λ�ã���0��ʼ��
public:
	void reSize(int newSize); //�ı�data�ռ��С

public:
	SeqList(int sz = defaultSize); //���캯������Ĭ�ϲ���
	SeqList(SeqList<T> &sl);       //���ƹ��캯��
	~SeqList() { delete [] data; } 

	int Size() const { return maxSize; }    //��������
	int Length() const { return last+1; } //����
	int Search(T& x) const; //�������и���ֵx������λ��
	int Locate(int i) const; //��λ���е�i��Ԫ�ص�λ��
	bool getData(int i, T& x) const; //ȡ��i����ֵ
	void setData(int i, T& x);  //�޸ĵ�i����ֵΪx
	bool Insert(int i, T& x); //�ڵ�i��Ԫ�غ����x
	bool Remove(int i, T& x); //ɾ����i����ͨ��x����(��)
	bool IsEmpty() const;  //�жϱ��Ƿ�Ϊ��
	bool IsFull() const;   //�ж����Ƿ�Ϊ��
	void Sort();   //����
	void Input();  //����
	void Output(); //���
	//SeqList<T> operator= (SeqList<T>& L); //���ظ�ֵ������
};

template<class T>
SeqList<T>::SeqList(int sz = defaultSize) //���캯������Ĭ�ϲ���
{
	maxSize = defaultSize;
	last = -1;
	data = new T[maxSize];
	if (data == NULL)
	{
		std::cerr << "����ռ����ʧ�ܣ�" << endl;
		exit(1);
	}
}


template <class T>
SeqList<T>::SeqList(SeqList<T> &sl)       //���ƹ��캯��
{
	maxSize = sl.Size();
	last = sl.Length()-1;
	data = new T[maxSize];
	if (data == NULL)
	{
		std::cerr << "����ռ����ʧ�ܣ�" << endl;
		exit(1);
	}

	T tmp;
	for (int i=1; i<=last+1; ++i)
	{
		sl.getData(i, tmp);
		data[i-1] = tmp;
	}
}

template <class T>
void SeqList<T>::reSize(int newSize) //�ı�data�ռ��С
{
	if (newSize <= 0)
	{
		cerr << "��Ч�������С" << endl;
		return;
	}

	if (newSize == maxSize)
	{
		cerr << "�µ������С��ԭ�����ޱ仯" << endl;
		return;
	}

	if (IsEmpty())
	{
		delete [] data;
		maxSize = newSize;
		data = new T[maxSize];
		if (data == NULL)
		{
			std::cerr << "����ռ����ʧ�ܣ�" << endl;
			exit(1);
		}
	}
	else 
	{
		T *newArray = new T[newSize];
		if (newArray == NULL)
		{
			std::cerr << "����ռ����ʧ�ܣ�" << endl;
			exit(1);
		}
		int n = last +1;
		T *srcptr = data; //Դ�����׵�ַ
		T *dstptr = newArray; //Ŀ�������׵�ַ
		while(n--)
			*dstptr++ = *srcptr++;
		delete [] data;
		data = newArray;
		maxSize = newSize;
	}
}

template <class T>
int SeqList<T>::Search(T& x) const //�������и���ֵx������λ��
{
	for (int i=0; i<=last; ++i)
	{
		if (data[i]==x)
		{
			return i+1;
		}
	}
	return 0;
};

template <class T>
int SeqList<T>::Locate(int i) const //��λ���е�i��Ԫ�ص�λ��
{
	if (i>=1 && i<=last+1)
	{
		return i;
	}
	return 0;
}

template <class T>
bool SeqList<T>::getData(int i, T& x) const //ȡ��i����ֵ
{ 
	if (i>0 && i<=last+1) 
	{ 
		x = data[i-1]; 
		return true;
	}
	else
		return false;
}

template <class T>
void SeqList<T>::setData(int i, T& x)  //�޸ĵ�i����ֵΪx
{
	if (i>0 && i<=last+1)
	{
		data[last+1] = x;
	}
}

template <class T>
bool SeqList<T>::Insert(int i, T& x) //�ڵ�i��Ԫ�غ����x
{ 
	if (last == maxSize-1) return false;
	if (i<0 || i>last+1) return false;
	for (int j=last; j>=i; --j)
	{
		data[j+1] = data[j];
	}
	data[i] = x;
	last++;
	return true;
}

template <class T>
bool SeqList<T>::Remove(int i, T& x) //ɾ����i����ͨ��x����(��)
{ 
	if (last == -1) return false;
	if (i<1 || i>last+1) return false;
	x = data[i-1];
	for (int j=i; j<=last; ++j)
	{
		data[j-1] = data[j];
	}
	last--;
	return true;
}

template <class T>
bool SeqList<T>::IsEmpty() const  //�жϱ��Ƿ�Ϊ��
{ return (last==-1) ? true : false; }

template <class T>
bool SeqList<T>::IsFull() const   //�ж����Ƿ�Ϊ��
{ return (last==maxSize-1) ? true : false; }

template <class T>
void SeqList<T>::Sort()   //����
{ }


template <class T>
void SeqList<T>::Input()  //����
{//�ӱ�׼�����������������룬����˳���
	cout << "��ʼ������������������Ԫ�ظ�����";
	while (1)
	{
		std::cin >> last; 
		if (last <= maxSize-1)
		{
			break;
		}
		cout << "��Χ���󣬲��ܳ���"<< maxSize - 1 << endl;
	}
	for (int i = 0; i<=last; ++i)
	{
		//cin >> data[i];//
		//�Զ���0˳������
		data[i] = i;
		cout << i+1 << endl;
	}
}

template <class T>
void SeqList<T>::Output() //���
{//˳�򽫱���ȫ��Ԫ���������Ļ��
	cout << "˳���ǰԪ�ص����λ��Ϊ��" << last << endl;
	for (int i = 0; i<=last ; i++)
	{
		cout << "#" << i+1 << ":" << data[i] << endl;
	}
}

//SeqList<T> operator= (SeqList<T>& L); //���ظ�ֵ������

