#include <iostream>

class smart_array {
public:
	smart_array(int size) {
		set_arr(size);
	}

	int add_element(int value) {
		std::cout << value << std::endl;
		return value;
	}

	int* set_arr(int size) {
		int* arr = new int[size];

		for (int i = 0; i < size; i++)
			std::cout << arr[i] << std::endl;
		return arr;
	}
	~smart_array() {

	}

	int get_element(int elem) {
		return elem;
	}
};

int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
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
