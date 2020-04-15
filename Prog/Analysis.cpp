#include "Analysis.hpp"
#include "Sort.hpp"

Analysis::Analysis(unsigned int N){
	bubble = new Measurement(N);
	quick = new Measurement(*bubble);
	bubble->begin();
	bubbleSort(bubble->getArray(), N);
	bubble->end();
	quick->begin();
	quickSort(quick->getArray(), 0, N - 1);
	quick->end();
}

Analysis::~Analysis(){
	delete bubble;
	delete quick;
}

Measurement *Analysis::getBubbleMeasurement() const{
	return bubble;
}

Measurement *Analysis::getQuickMeasurement() const{
	return quick;
}