#pragma once
#include <assert.h>
#include <string.h>

#define defaultSize 128

class String {
public:
	String(int sz = defaultSize);
	String(const char *init);
	String(const String& obj);
	~String() { delete [] cha; }
	int GetLength() { return curLen; }
	String operator() (int pos, int len); //��pos��ָ��λ�ÿ�ʼ����ȡlen���ַ������Ӵ�
	int operator== (String& obj)const { return strcmp(cha, obj.cha); }
	int operator!= (String& obj)const { return !(*this==obj); }
	int operator!()const { return curLen == 0; } //�жϴ��Ƿ��
	String& operator= (String& obj); //���ظ�ֵ������
	String& operator+= (String& obj);
	char& operator[](int i); //ȡ*this�ĵ�i���ַ�
	int Find(String& pat)const; //�Ӵ�ƥ��
	int KMP_Find(String& pat, int next[])const; 
	void GetNext(int next[]);

private:
	char *cha;   //���������
	int curLen;  //��ǰ����ʵ�ʳ���
	int maxSize; //�ַ��ַ��������
};