#include <string.h>
#ifndef MEASUREMENT_HPP
#define MEASUREMENT_HPP

class Measurement{
	public:
		Measurement(int* rowArray, int size);
		~Measurement();
		void begin();
		void end(int* resultArray);
		int* getRowArray() const;
		int* getResultArray() const;
		int getArraySize() const;
		int getBeginTime() const;
		int getEndTime() const;
		int getDeltaTime() const;
		string toJsonString() const;
	private:
		int* rowArray, resultArray;
		int size, beginTime = -1, endTime = -1;
}

#endif //MEASUREMENT_HPP