#pragma once
#include <string>

using namespace std;

struct Element
{
	/**
	 * @brief ���� ��������
	*/
	string _key;

	/**
	 * @brief ���������������, �������� ��������
	*/
	string _value;

	/**
	 * @brief ��������� �� ��������� �������
	*/
	Element* _next;
};

class HashMap
{

private:

	/**
	 * @brief ������� ���������� �������-��������, �������� �����
	 * @return - ������������ �������� ��������.
	*/
	int PearsonHashing(string string);

	/**
	 * @brief ������� ���������������.
	*/
	void Rehashing();

	/**
	 * @brief ��������� �� ������ ��������� ���-�������
	*/
	Element** _iternalData;

	/**
	 * @brief Capacity �������
	*/
	int _capacity;

	/**
	 * @brief ���-�� ������� � �������
	*/
	int _size;

	const double _growthFactor = 1.5;
	const double _fillFactor = 0.75;
public:
	HashMap();
	~HashMap();

	/**
	 * @brief ��������� ������� � ���-�������.
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
	 * @brief ���������� ������� ���-������� � �������� ������, ���� ������� � �������� ������ �� ������, �� nullptr.
	 * @param key - ���� �� �������� ������������� ����� ��������.
	 * @return ������� ��� nullptr ���� �� ������ �������.
	*/
	Element* Get(string key);

	/**
	 * @brief ���������� ������� �� ������� � �������, ����� nullptr ���� �������� � ������ ��������� ����.
	 * @param offset - ����� ������������ ������ �� ������.
	 * @param depth - ���������� ����� ������ �� ������������ ������.
	 * @return ������� ��� ������� ���������.
	*/
	Element* GetElementByIndexes(int offset, int depth);

	/**
	 * @return ���������� Capacity �� HashMap
	*/
	int GetCapacity()
	{
		return _capacity;
	}

	/**
	 * @return ���������� Size �� HashMap
	*/
	int GetSize()
	{
		return _size;
	}
};
