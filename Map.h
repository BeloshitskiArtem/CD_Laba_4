#pragma once
#include "HashMap.h"

class Map
{
private:
	/**
	 * @brief ���-������� ��� ������ �����
	*/
	HashMap _iternalData;

public:
	/**
	 * @brief ��������� ������� � ������.
	 * @param key - ���� �� �������� �������������� ������ � �������� ��������.
	 * @param value - �������� ��������.
	*/
	void Insert(string key, string value);

	/**
	 * @brief ������� ������� �� ���-������� �� �����.
	 * @param key - ���� ��������, ������� �������� ���� �������.
	*/
	void Erase(string key);

	/**
	 * @brief ���������� ������� ������� � �������� ������, ���� ������� � �������� ������ �� ������, �� nullptr.
	 * @param key - ���� �� �������� ������������� ����� ��������.
	 * @return ������� ��� nullptr ���� �� ������ �������.
	*/
	Element* Get(string key);

	/**
	 * @brief ���������� ������� �� ������� � �������, ����� nullptr ���� �������� � ������ ��������� ����.
	 * @param offset - ����� ������ �� ������.
	 * @param depth - ���������� ����� ������ �� ������������ ������.
	 * @return ������� ��� ������� ���������.
	*/
	Element* GetElementByIndexes(int offset, int depth);

	/**
	 * @return ���������� Capacity �� Map 
	*/
	int GetCapacity()
	{
		return _iternalData.GetCapacity();
	}

	/**
	 * @return ���������� Size �� Map
	*/
	int GetSize()
	{
		return _iternalData.GetSize();
	}
};

