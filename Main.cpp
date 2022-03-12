#include <iostream>
#include "HashMap.h"
#include "Map.h"

void Input(string str, string& inputValeu)
{
	cout << str;
	cin >> inputValeu;
}

void Input(string str, string& firstInputValeu, string& secondInputValeu)
{
	cout << str;
	cin >> firstInputValeu >> secondInputValeu;
}
	
int main()
{
	setlocale(LC_ALL, "ru");

	HashMap * hashMap = new HashMap;
	Map * map = new Map;

	cout << "������� 1, ����� �������� ������� � HashMap" << endl;
	cout << "������� 2, ����� ������� ������� �� HashMap" << endl;
	cout << "������� 3, ����� �������� ������� �� HashMap �� �����" << endl;
	cout << "������� 4, ����� ����������� ���� ������� HashMap" << endl << endl;

	cout << "������� 5, ����� �������� ������� � Map" << endl;
	cout << "������� 6, ����� ������� ������� Map" << endl;
	cout << "������� 7, ����� �������� ������� ����� �� �����" << endl;
	cout << "������� 8, ����� ������� ��� �������� Map" << endl;
	cout << "������� 0, ����� ������� ���������" << endl << endl;


	cout << "������� �������: ";

	int operationCode;
	while (cin >> operationCode)
	{
		switch (operationCode)
		{
		case 1:
		{
			string key;
			string value;
			Input("������� ���� � �������� ��������: ", key, value);

			hashMap->Insert(key, value);

			break;
		}
		case 2:
		{
			string key;
			Input("������� ���� ��������: ", key);

			try
			{
				hashMap->Erase(key);
				cout << "������� �� HashMap ��� ������� �����!" << endl;
			}
			catch (char const* error)
			{
				cerr << error << endl;
			}

			break;
		}
		case 3:
		{
			string key;
			Input("������� ����, ����� ����� �������: ", key);

			Element* element = hashMap->Get(key);
			cout << "������� �����: (" << element->_key << ", " << element->_value 
				<< ")" << " -> " << element->_next << ";" << endl;
			break;
		}
		case 4:
		{
			cout << "[\n";
			for (int i = 0; i < hashMap->GetCapacity(); ++i)
			{
				cout << "\t{ " << i << ": ";

				Element* iterator = hashMap->GetElementByIndexes(i, 0);
				while (iterator != nullptr)
				{
					cout << "(" << iterator->_key << " - " << iterator->_value << ") -> ";

					iterator = iterator->_next;
				}

				cout << "() }" << endl;
			}
			cout << "]" << endl;
			break;
		}
		case 5:
		{
			string key;
			string value;
			Input("������� ���� � �������� ��������: ", key, value);

			try 
			{
				map->Insert(key, value);
			}
			catch (char const* error)
			{
				cerr << error << endl;
			}

			break;
		}
		case 6:
		{
			string key;
			Input("������� ���� ��������: ", key);

			try
			{
				map->Erase(key);
				cout << "������� �� HashMap ��� ������� �����!\n";
			}
			catch (char const* error)
			{
				cerr << error << endl;
			}

			break;
		}
		case 7:
		{
			string key;
			Input("������� ����, ����� ����� �������: ", key);

			Element* element = map->Get(key);

			cout << "������� �����: (" << element->_key << ", " << element->_value 
				<< ")" << " -> " << element->_next << ";" << endl;

			break;
		}
		case 8:
		{
			cout << "[" << endl;
			for (int i = 0; i < map->GetCapacity(); ++i)
			{
				cout << "\t{ " << i << ": ";

				Element* iterator = map->GetElementByIndexes(i, 0);
				while (iterator != nullptr)
				{
					cout << "(" << iterator->_key << " - " << iterator->_value << ") -> ";

					iterator = iterator->_next;
				}

				cout << "() }" << endl;
			}
			cout << "]" << endl;
			break;
		}
		default:
		{
			return 0;
		}
		}

		cout << "������� ����� �������: ";
	}

	delete hashMap;
	delete map;

	return 0;
}