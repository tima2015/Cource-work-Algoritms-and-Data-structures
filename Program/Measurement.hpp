#include <ctime>
#ifndef MEASUREMENT_HPP
#define MEASUREMENT_HPP

/**
 * Даные о работе алгоритма
 */
class Measurement{
	public:
		/**
		 * Создаёт новый объект класса данных о замерах,
		 * с случайно сгенерированым массивом размера size.
		 */
		Measurement(unsigned int size);
		Measurement(const Measurement &orig);
		virtual ~Measurement();
		/**
		 * Установка точки начала замера
		 */
		void begin();
		/**
		 * Установка точки окончания замера
		 */
		void end();
		/**
		 * Возращает начальный массив;
		 */
		int* getRowArray() const;
		/**
		 * Возращает массив для сортировки
		 */
		int* getArray() const;
		/**
		 * Возращает размер массивов
		 */
		unsigned int getArraySize() const;
		/**
		 * Возращает время начала замера
		 */
		clock_t getBeginTime() const;
		/**
		 * Возращает время окончания замера
		 */
		clock_t getEndTime() const;
		/**
		 * Возращает время замера
		 */
		clock_t getDeltaTime() const;
	private:
		int* rowArray;//Копия массива до сортировки
		int* array;//Массив для сортировки
		unsigned int size;//Размер массива
		clock_t beginTime = 0, endTime = 0;//Время начала/конца замера
};

#endif //MEASUREMENT_HPP