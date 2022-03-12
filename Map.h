#pragma once
#include "HashMap.h"

class Map
{
private:
	/**
	 * @brief Хэш-таблица как основа карты
	*/
	HashMap _iternalData;

public:
	/**
	 * @brief Добавляет элемент в словаь.
	 * @param key - ключ по которому осуществляется доступ к значению элемента.
	 * @param value - значение элемента.
	*/
	void Insert(string key, string value);

	/**
	 * @brief Удаляет элемент из хэш-таблицы по ключу.
	 * @param key - ключ элемента, элемент которого надо удалить.
	*/
	void Erase(string key);

	/**
	 * @brief Возвращает элемент словаря с заданным ключём, если элемент с заданным ключём не найден, то nullptr.
	 * @param key - ключ по которому осуществяется поиск элемента.
	 * @return Элемент или nullptr если не найден элемент.
	*/
	Element* Get(string key);

	/**
	 * @brief Возвращает элемент по оффсету и глубине, вернёт nullptr если элемента с такими индексами нету.
	 * @param offset - Номер списка по офсету.
	 * @param depth - Количество шагов вглубь по односвязному списку.
	 * @return Элемент или нулевой указатель.
	*/
	Element* GetElementByIndexes(int offset, int depth);

	/**
	 * @return Возвращает Capacity из Map 
	*/
	int GetCapacity()
	{
		return _iternalData.GetCapacity();
	}

	/**
	 * @return Возвращает Size из Map
	*/
	int GetSize()
	{
		return _iternalData.GetSize();
	}
};

