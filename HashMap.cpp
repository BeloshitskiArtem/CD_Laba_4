#include "HashMap.h"

HashMap::HashMap() : _capacity{ 8 }, _size{ 0 }
{
	_iternalData = new Element * [_capacity]();
}

HashMap::~HashMap()
{
	for (int i = 0; i < _capacity; ++i)
	{
		Element* iterator = _iternalData[i];
		while (iterator != nullptr)
		{
			Element* next = iterator->_next;

			delete iterator;

			iterator = next;
		}
	}
	delete[] _iternalData;
}

void HashMap::Insert(string key, string value)
{
	if (_size / double(_capacity) > _fillFactor)
	{
		Rehashing();
	}

	int index = PearsonHashing(key);

	if (_iternalData[index] == nullptr)
	{
		_iternalData[index] = new Element{ key, value, nullptr };
	}
	else
	{
		_iternalData[index] = new Element{ key, value, _iternalData[index] };
	}

	_size += 1;
}

void HashMap::Erase(string key)
{
	int index = PearsonHashing(key);

	Element** previous = &_iternalData[index];
	Element* iterator = _iternalData[index];

	while (iterator != nullptr)
	{
		if (iterator->_key == key)
		{
			*previous = iterator->_next;
			delete iterator;
			_size -= 1;
			return;
		}

		previous = &(*previous)->_next;
		iterator = iterator->_next;
	}

	throw "Невозможно удалить элемент с этим ключом.";
}

Element* HashMap::Get(string key)
{
	int index = PearsonHashing(key);

	Element* iterator = _iternalData[index];
	while (iterator != nullptr)
	{
		if (iterator->_key == key)
		{
			return iterator;
		}

		iterator = iterator->_next;
	}

	return nullptr;
}

int HashMap::PearsonHashing(string string)
{
	// Каждое простое число может быть представлено в виде (6 * x - 1) и (6 * X + 1) кроме (2 и 3).
	// Находим простое число ближайшее к значению capacity, и меньшее него. Оно и будет взаимно простым.
	int primeNumberToCapacity = int((_capacity - 1) / 6) * 6 - 1;

	int hashResult = 0;
	for (int i = 0; string[i] != '\0'; ++i)
	{
		hashResult = (hashResult * primeNumberToCapacity + string[i]) % _capacity;
	}

	return hashResult;
}

void HashMap::Rehashing()
{
	int previousCapacity = _capacity;
	_capacity = int(_capacity * _growthFactor);
	Element** newAllocation = new Element * [_capacity]();

	for (int i = 0; i < previousCapacity; ++i)
	{
		Element* iterator = _iternalData[i];
		while (iterator != nullptr)
		{
			int index = PearsonHashing(iterator->_key);

			Element* next = iterator->_next;

			if (newAllocation[index] == nullptr)
			{
				newAllocation[index] = iterator;
				newAllocation[index]->_next = nullptr;
			}
			else
			{
				iterator->_next = newAllocation[index];
				newAllocation[index] = iterator;
			}

			iterator = next;
		}
	}

	delete[] _iternalData;
	_iternalData = newAllocation;
}

Element* HashMap::GetElementByIndexes(int offset, int depth)
{
	Element* iterator = _iternalData[offset];
	for (int i = 0; i < depth; ++i)
	{
		if (iterator != nullptr)
		{
			iterator = iterator->_next;
		}
	}
	return iterator;
}