#include "Measurement.hpp"
#ifndef ANALYSIS_HPP
#define ANALYSIS_HPP

class Analysis{
	public:
		/**
		 * Конструктор.
		 * Число N - Размер массива для анализа
		 */
		Analysis(unsigned int N);
		virtual ~Analysis();
		//Возвращает данные о работе алгоритма сравнения метода пузырька
		Measurement *getBubbleMeasurement() const;
		//Возвращает данные о работе алгоритма сравнения быстрой сортировки Хоара
		Measurement *getQuickMeasurement() const;
	private:
		Measurement *bubble, *quick;
		unsigned int N;
};

#endif //ANALYSIS_HPP