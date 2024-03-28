#include <iostream>

class Smart_array {
	int* arr;
	int* new_array;
	int size = 0;					   //������ �������
	int number_of_filled_items = 0;    //���������� ����������� ���������
	int i = 0;

public:
	Smart_array(int size) {
		this->size = size;
		arr = new int[size];
		new_array = new int[size];
	}

	void add_element(int value) {
		if (number_of_filled_items >= size)
		{
			throw std::runtime_error("���������� ��������� ������ ���������� ���������, �� ������� �������� ������");
		}

		arr[i] = value;

		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
		i++;
		number_of_filled_items++;
	}

	~Smart_array() {
		/*delete arr;
		delete new_array;*/
	}
};

int main()
{
	setlocale(0, "rus");
	try {
		Smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		Smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}




/*
������ 2. ����������� ����� ��������
��������

� ���� ������� ��� ����� ���������� � ������� ����� ��������, ������� �� ����������� � ���������� �������.
������� ���������� ������� ��� ���������� ������ ������ � ���������� ���������� � ��������� ���� �������.

smart_array arr(5);
arr.add_element(1);
arr.add_element(4);
arr.add_element(155);

smart_array new_array(2);
new_array.add_element(44);
new_array.add_element(34);

arr = new_array

����������� �������������� �����������, ��� ���������, � ��������� ����������� ����������� ����� ��������.
���������

	�� ������� ���� ������ �����. ����������� ������� ������ ������ �������������� :)

��� ������������ ��� �������.

� ��������� ��������� ����������, ������ ��� ���������� �������������� ������������ �������� ������������, ������� ������ �������� ��� ���� ������ ������� �������.
� ���������, �������� ��������� ��-�� ����������� ���������: ��� ������� ������ ����� ���������� ��������� �� ������� ������ � � ����� ������������ �������� ���������� ���.
���������� ������� ������������ ������. ���������� ��������� �� ������� ������ � � ����� ������������ �������� ���������� ���. ���������� ������� ������������ ������.
*/
