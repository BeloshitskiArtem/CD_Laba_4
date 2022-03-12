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

	cout << "¬ведите 1, чтобы вставить элемент в HashMap" << endl;
	cout << "¬ведите 2, чтобы стереть элемент из HashMap" << endl;
	cout << "¬ведите 3, чтобы получить элемент из HashMap по ключу" << endl;
	cout << "¬ведите 4, чтобы распечатать весь элемент HashMap" << endl << endl;

	cout << "¬ведите 5, чтобы вставить элемент в Map" << endl;
	cout << "¬ведите 6, чтобы стереть элемент Map" << endl;
	cout << "¬ведите 7, чтобы получить элемент карты по ключу" << endl;
	cout << "¬ведите 8, чтобы вывести все элементы Map" << endl;
	cout << "¬ведите 0, чтобы закрыть программу" << endl << endl;


	cout << "¬ведите команду: ";

	int operationCode;
	while (cin >> operationCode)
	{
		switch (operationCode)
		{
		case 1:
		{
			string key;
			string value;
			Input("¬ведите ключ и значение элемента: ", key, value);

			hashMap->Insert(key, value);

			break;
		}
		case 2:
		{
			string key;
			Input("¬ведите ключ элемента: ", key);

			try
			{
				hashMap->Erase(key);
				cout << "Ёлемент из HashMap был успешно удалЄн!" << endl;
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
			Input("¬ведите ключ, чтобы найти элемент: ", key);

			Element* element = hashMap->Get(key);
			cout << "Ёлемент равен: (" << element->_key << ", " << element->_value 
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
			Input("¬ведите ключ и значение элемента: ", key, value);

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
			Input("¬ведите ключ элемента: ", key);

			try
			{
				map->Erase(key);
				cout << "Ёлемент из HashMap был успешно удалЄн!\n";
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
			Input("¬ведите ключ, чтобы найти элемент: ", key);

			Element* element = map->Get(key);

			cout << "Ёлемент равен: (" << element->_key << ", " << element->_value 
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

		cout << "¬ведите новую команду: ";
	}

	delete hashMap;
	delete map;

	return 0;
}