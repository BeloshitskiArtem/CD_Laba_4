#pragma once
#include <string>

using namespace std;

struct Element
{
	/**
	 * @brief Ключ элемента
	*/
	string _key;

	/**
	 * @brief Непосредственно, значение элемента
	*/
	string _value;

	/**
	 * @brief Указатель на следующий элемент
	*/
	Element* _next;
};

class HashMap
{

private:

	/**
	 * @brief Функция нахождения взаимно-простого, меньшего числа
	 * @return - получившееся значение элемента.
	*/
	int PearsonHashing(string string);

	/**
	 * @brief Функция перехэширования.
	*/
	void Rehashing();

	/**
	 * @brief Указатель на массив элементов Хэш-таблицы
	*/
	Element** _iternalData;

	/**
	 * @brief Capacity таблицы
	*/
	int _capacity;

	/**
	 * @brief Кол-во записей в таблице
	*/
	int _size;

	const double _growthFactor = 1.5;
	const double _fillFactor = 0.75;
public:
	HashMap();
	~HashMap();

	/**
	 * @brief Добавляет элемент в хэш-таблицу.
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
	 * @brief Возвращает элемент хэш-таблицы с заданным ключём, если элемент с заданным ключём не найден, то nullptr.
	 * @param key - ключ по которому осуществяется поиск элемента.
	 * @return Элемент или nullptr если не найден элемент.
	*/
	Element* Get(string key);

	/**
	 * @brief Возвращает элемент по оффсету и глубине, вернёт nullptr если элемента с такими индексами нету.
	 * @param offset - Номер односвязного списка по офсету.
	 * @param depth - Количество шагов вглубь по односвязному списку.
	 * @return Элемент или нулевой указатель.
	*/
	Element* GetElementByIndexes(int offset, int depth);

	/**
	 * @return Возвращает Capacity из HashMap
	*/
	int GetCapacity()
	{
		return _capacity;
	}

	/**
	 * @return Возвращает Size из HashMap
	*/
	int GetSize()
	{
		return _size;
	}
};
