#include "Map.h"

void Map::Insert(string key, string value)
{
	if (_iternalData.Get(key) == nullptr)
	{
		_iternalData.Insert(key, value);
	}
	else
	{
		throw "Карта не может хранить два элемента с одним и тем же ключом.";
	}
}

void Map::Erase(string key)
{
	_iternalData.Erase(key);
}

Element* Map::Get(string key)
{
	return _iternalData.Get(key);
}

Element* Map::GetElementByIndexes(int offset, int depth)
{
	return _iternalData.GetElementByIndexes(offset, depth);
}
