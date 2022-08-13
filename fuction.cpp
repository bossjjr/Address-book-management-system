#include "system.h"


void showMenu()//��ʾ����
{
	cout << "*************************" << endl;
	cout << "****** 1,�����ϵ�� ******" << endl;
	cout << "****** 2,��ʾ��ϵ�� ******" << endl;
	cout << "****** 3,ɾ����ϵ�� ******" << endl;
	cout << "****** 4,������ϵ�� ******" << endl;
	cout << "****** 5,�޸���ϵ�� ******" << endl;
	cout << "****** 6,�����ϵ�� ******" << endl;
	cout << "****** 0,�˳�ͨѶ¼ ******" << endl;
	cout << "*************************" << endl;
}

void addPerson(Addressbooks* abs)//�����ϵ��
{
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{ //��������
		string name;
		cout << " ������������ " << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;
		
	 // �����Ա�
		cout << "�������Ա� " << endl;
		cout << " 1--�� " << endl;
		cout << " 2--Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
				cout << "��ʽ��������������" << endl;
		}

	 //��������
		cout << "����������: " << endl;
		int age;
		while (true)
		{
			cin >> age;
			if (age <= 150)
			{
				abs->personArray[abs->m_size].m_Age = age;
				break;
			}
			cout << "��ʽ��������������" << endl;
		}
		
	 //��������ϵ�绰
		cout << "������绰: " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;

	 //����סַ
		cout << "������סַ: " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_Addr = address;

	 //��������
		abs->m_size++;

		cout << " ��ӳɹ��� " << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks* abs)//��ʾ��ϵ��
{
	if (abs->m_size == 0)
	{
		cout << " ��ǰ��¼Ϊ�� " << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������ " << abs->personArray[i].m_Name << "\t";
			cout << "�Ա� " << (abs->personArray[i].m_Sex == 1 ? "��":"Ů") << "\t";
			cout << "���䣺 " << abs->personArray[i].m_Age << "\t";
			cout << "�绰�� " << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ�� " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(Addressbooks* abs, string name)//������ϵ���Ƿ����
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

void deletePerson(Addressbooks* abs)//ɾ����ϵ��
{
	cout << "������Ҫɾ������ϵ��: " << endl;

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
		cout << "ɾ���ɹ���" << endl;
	}
	else if (ret == 999)
	{
			abs->m_size--;
			cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs)//������ϵ��
{
	cout << " ��������Ҫ���ҵ���ϵ�ˣ� " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������ " << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա� " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺 " << abs->personArray[ret].m_Age << "\t";
		cout << "�绰�� " << abs->personArray[ret].m_Phone << "\t";
		cout << "��ַ�� " << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs)//�޸���ϵ����Ϣ
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ� " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//��������
		string name;
		cout << " ������������ " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		// �����Ա�
		cout << "�������Ա� " << endl;
		cout << " 1--�� " << endl;
		cout << " 2--Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "��ʽ��������������" << endl;
		}

		//��������
		cout << "����������: " << endl;
		int age;
		while (true)
		{
			cin >> age;
			if (age <= 150)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "��ʽ��������������" << endl;
		}

		//��������ϵ�绰
		cout << "������绰: " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//����סַ
		cout << "������סַ: " << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ���" << endl;

	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void clearPerson(Addressbooks* abs)//�����ϵ��
{
	abs->m_size = 0;
	cout << "����ɹ���" << endl;
	system("pause");
	system("cls");
}