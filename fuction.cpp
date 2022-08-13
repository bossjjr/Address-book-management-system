#include "system.h"


void showMenu()//显示界面
{
	cout << "*************************" << endl;
	cout << "****** 1,添加联系人 ******" << endl;
	cout << "****** 2,显示联系人 ******" << endl;
	cout << "****** 3,删除联系人 ******" << endl;
	cout << "****** 4,查找联系人 ******" << endl;
	cout << "****** 5,修改联系人 ******" << endl;
	cout << "****** 6,清空联系人 ******" << endl;
	cout << "****** 0,退出通讯录 ******" << endl;
	cout << "*************************" << endl;
}

void addPerson(Addressbooks* abs)//添加联系人
{
	if (abs->m_size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{ //输入名字
		string name;
		cout << " 请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;
		
	 // 输入性别
		cout << "请输入性别： " << endl;
		cout << " 1--男 " << endl;
		cout << " 2--女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
				cout << "格式错误，请重新输入" << endl;
		}

	 //输入年龄
		cout << "请输入年龄: " << endl;
		int age;
		while (true)
		{
			cin >> age;
			if (age <= 150)
			{
				abs->personArray[abs->m_size].m_Age = age;
				break;
			}
			cout << "格式错误，请重新输入" << endl;
		}
		
	 //请输入联系电话
		cout << "请输入电话: " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;

	 //输入住址
		cout << "请输入住址: " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_Addr = address;

	 //更新人数
		abs->m_size++;

		cout << " 添加成功！ " << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks* abs)//显示联系人
{
	if (abs->m_size == 0)
	{
		cout << " 当前记录为空 " << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name << "\t";
			cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男":"女") << "\t";
			cout << "年龄： " << abs->personArray[i].m_Age << "\t";
			cout << "电话： " << abs->personArray[i].m_Phone << "\t";
			cout << "地址： " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(Addressbooks* abs, string name)//检验联系人是否存在
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks* abs)//删除联系人
{
	cout << "输入你要删除的联系人: " << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1 && ret != 999)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功！" << endl;
	}
	else if (ret == 999)
	{
			abs->m_size--;
			cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs)//查找联系人
{
	cout << " 请输入你要查找的联系人： " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名： " << abs->personArray[ret].m_Name << "\t";
		cout << "性别： " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->personArray[ret].m_Age << "\t";
		cout << "电话： " << abs->personArray[ret].m_Phone << "\t";
		cout << "地址： " << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs)//修改联系人信息
{
	cout << "请输入你要修改的联系人： " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//输入名字
		string name;
		cout << " 请输入姓名： " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		// 输入性别
		cout << "请输入性别： " << endl;
		cout << " 1--男 " << endl;
		cout << " 2--女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "格式错误，请重新输入" << endl;
		}

		//输入年龄
		cout << "请输入年龄: " << endl;
		int age;
		while (true)
		{
			cin >> age;
			if (age <= 150)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "格式错误，请重新输入" << endl;
		}

		//请输入联系电话
		cout << "请输入电话: " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//输入住址
		cout << "请输入住址: " << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功！" << endl;

	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void clearPerson(Addressbooks* abs)//清空联系人
{
	abs->m_size = 0;
	cout << "清除成功！" << endl;
	system("pause");
	system("cls");
}