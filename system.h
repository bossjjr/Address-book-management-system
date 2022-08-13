#ifndef __SYSTEM_H__
#define __SYSTEM_H__
#include <iostream>
#include <string>
#define MAX 1000
using namespace std;


void showMenu();//��ʾ�˵�

//������ϵ�˽ṹ��
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//����ͨѶ¼�Ľṹ��
 struct Addressbooks{
	 Person personArray[MAX];
	 int m_size;
};

void addPerson(Addressbooks* abs);//�����ϵ��

void showPerson(Addressbooks* abs);//��ʾ��ϵ��

int isExist(Addressbooks* abs, string name);//������ϵ���Ƿ����

void deletePerson(Addressbooks* abs);//ɾ����ϵ��

void findPerson(Addressbooks* abs);//������ϵ��

void modifyPerson(Addressbooks* abs);//�޸���ϵ����Ϣ

void clearPerson(Addressbooks* abs);//�����ϵ��














#endif