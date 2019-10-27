#include <iostream>
#define START_SIZE 10



class Queue{
	public:
		Queue()	//Конструктор выделяет память под данные.
		{
			_size = 0;
			data = new int[START_SIZE];
		}
		~Queue() {}
		//Деструктор пуст,так как подается в функции.

		void push(int val)	//Пуш элемента
		{
			resize();
			//Увеливаем память, если нужно.
			data[_size] = val;
			_size++;
			//Запишем новый элемент
		}

		int pop()	//Поп первогоэлемента со смещением всех элементов влево
		{
			int poped = data[0];
			for(int i = 0; i < _size - 1; i++) data[i] = data[i+1];
			_size--;
			return poped;
		}

		int get_elem(int index)	//Поп первогоэлемента со смещением всех элементов влево
		{
			return data[index];
		}

		int isEmpty()	//Проверяет очередь на пустоту
		{
			return !_size;
		}

		int size()
		{
			return _size;
		}

	private:
		int *data;
		//Указатель под массив имен
		int _size;
		//Размер очереди

		void resize()	//Динамическое увеличение массива data
		{
			if(_size % START_SIZE == 0 && _size)
			{
				int *pTmp = new int[_size + 10];
				for(int i = 0; i < _size; i++)
				pTmp[i] = data[i];
				delete[] data;
				data = pTmp;
			}
		}
};