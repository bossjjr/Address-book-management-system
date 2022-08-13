#ifndef __SYSTEM_H__
#define __SYSTEM_H__
#include <iostream>
#include <string>
#define MAX 1000
using namespace std;


void showMenu();//显示菜单

//定义联系人结构体
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//定义通讯录的结构体
 struct Addressbooks{
	 Person personArray[MAX];
	 int m_size;
};

void addPerson(Addressbooks* abs);//添加联系人

void showPerson(Addressbooks* abs);//显示联系人

int isExist(Addressbooks* abs, string name);//检验联系人是否存在

void deletePerson(Addressbooks* abs);//删除联系人

void findPerson(Addressbooks* abs);//查找联系人

void modifyPerson(Addressbooks* abs);//修改联系人信息

void clearPerson(Addressbooks* abs);//清空联系人














#endif