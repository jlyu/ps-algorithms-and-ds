#pragma once

template <class T>
class LinearLine {
public:
	LinearLine(){ }
	~LinearLine(){ }
	virtual int Size() const = 0;   //��������
	virtual int Length() const = 0; //����
	virtual int Search(T& x) const = 0; //�������и���ֵx������λ��
	virtual int Locate(int i) const = 0; //��λ���е�i��Ԫ�ص�λ��
	virtual bool getData(int i, T& x) const = 0; //ȡ��i����ֵ
	virtual void setData(int i, T& x) = 0;  //�޸ĵ�i����ֵΪx
	virtual bool Insert(int i, T& x) = 0; //�ڵ�i��Ԫ�غ����x
	virtual bool Remove(int i, T& x) = 0; //ɾ����i����ͨ��x����(��)
	virtual bool IsEmpty() const = 0;  //�жϱ��Ƿ�Ϊ��
	virtual bool IsFull() const = 0;   //�ж����Ƿ�Ϊ��
	virtual void Sort() = 0;   //����
	virtual void Input() = 0;  //����
	virtual void Output() = 0; //���
	//virtual LinearLine<T> operator= (LinearLine<T>& L) = 0; //���ظ�ֵ������
};