#include <iostream>

class Smart_array {
	int* arr;
	int* new_array;
	int size = 0;					   //размер массива
	int number_of_filled_items = 0;    //количество заполненных элементов
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
			throw std::runtime_error("Количество элементов больше количества элементов, на которую выделена память");
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
Задача 2. Копирование умных массивов
Описание

В этом задании вам нужно поработать с классом умных массивов, который вы реализовали в предыдущем задании.
Сначала попробуйте создать два экземпляра вашего класса с различными элементами и присвоить один другому.

smart_array arr(5);
arr.add_element(1);
arr.add_element(4);
arr.add_element(155);

smart_array new_array(2);
new_array.add_element(44);
new_array.add_element(34);

arr = new_array

Попытайтесь самостоятельно разобраться, что произошло, и правильно реализовать копирование умных массивов.
Подсказки

	Не читайте этот раздел сразу. Попытайтесь сначала решить задачу самостоятельно :)

Что использовать для решения.

В программе возникает исключение, потому что компилятор самостоятельно сгенерировал оператор присваивания, который просто копирует все поля одного объекта другому.
В частности, проблема возникает из-за копирования указателя: оба объекта класса имеют одинаковый указатель на область памяти и в своих деструкторах пытаются освободить его.
Происходит двойное освобождение памяти. одинаковый указатель на область памяти и в своих деструкторах пытаются освободить его. Происходит двойное освобождение памяти.
*/
