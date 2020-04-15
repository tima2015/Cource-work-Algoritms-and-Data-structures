#include "Sort.hpp"

void bubbleSort(int* array, int n){
	for (int i = n - 1; i > 0; i--){
		for (int j = 0; j < i; j++){
			if (array[j] > array[j + 1]){
				int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
			}
		}
	}
}

void quickSort(int* array,int first, int last){
	if (first < last){
		int left = first, right = last, middle = array[(left + right) / 2];
		do{
			while (array[left] < middle){
				left++;
			}
			while (array[right] > middle){
				right--;
			}
			if (left <= right){
				int tmp = array[left];
				array[left] = array[right];
				array[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		quickSort(array, first, right);
		quickSort(array, left, last);
    }
}