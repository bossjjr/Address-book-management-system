#include "system.h"

int main()
{
	Addressbooks abs;
	abs.m_size = 0;


	int select = 0;
	
	while (true)
	{
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1:
		{
			addPerson(&abs);
			break;
		}
			
		case 2:
		{
			showPerson(&abs);
			break;
		}
			
		case 3:
		{
			deletePerson(&abs);
			break;
		}
	
		case 4:
		{
			findPerson(&abs);
			break;
		}
			
		case 5:
		{
			modifyPerson(&abs);
			break;
		}
		case 6:
		{
			clearPerson(&abs);
			break;
		}
		case 0:
		{
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break; 
		}
		default:
			break;
		}
	}
	system("pause");
	return 0;
}