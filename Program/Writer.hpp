#include "Analysis.hpp"
#include <fstream>
#ifndef WRITER_HPP
#define WRITER_HPP


class Writer{
	public:
		virtual ~Writer(){}
		virtual void write(Analysis *a) = 0;
	protected:
		std::ofstream outfile;
};

/*
 * Выводит информацию о замере в файл формата json
 */
class JsonWriter : public Writer{
	public:
		JsonWriter(unsigned int N, unsigned int L);
		~JsonWriter();
		void write(Analysis *a);
	private:
		unsigned int i = 1, L;
};

/*
 * Выводит информацию о замере в файл формата txt
 */
class TxtWriter : public Writer{
	public:
		TxtWriter(unsigned int N, unsigned int L);
		~TxtWriter();
		void write(Analysis *a);
};

/*
 * Выводит подробную информацию о замере в файл формата txt
 */
class DetailTxtWriter : public Writer{
	public:
		DetailTxtWriter(unsigned int N, unsigned int L);
		~DetailTxtWriter();
		void write(Analysis *a);
	private:
		void printArray(int* array);
		unsigned int i = 1, L, N;
};

#endif //WRITER_HPP