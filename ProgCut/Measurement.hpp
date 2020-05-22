#include <ctime>
#ifndef MEASUREMENT_HPP
#define MEASUREMENT_HPP

//Даные о работе алгоритма
class Measurement{
	public:
		/**
		 * Создаёт новый объект класса данных о замерах,
		 * с случайно сгенерированым массивом размера size.
		 */
		Measurement(unsigned int size);
		//Конструктор копий
		Measurement(const Measurement &orig);
		//Деструктор
		virtual ~Measurement();
		//Установка точки начала замера
		void begin();
		//Установка точки окончания замера
		void end();
		//Возращает массив для сортировки
		int* getArray() const;
		//Возращает время замера
		clock_t getDeltaTime() const;
	private:
		//Массив для сортировки
		int* array;
		//Размер массива
		unsigned int size;
		//Время начала,конца замера
		clock_t beginTime = 0, endTime = 0;
};

#endif //MEASUREMENT_HPP