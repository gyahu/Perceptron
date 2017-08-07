#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "perceptron.h"

void Perceptron::init(int size, int b, std::vector<int> w){
	input_size = size;
	bias = b;
	weights = w;
}

int Perceptron::compute(std::vector<int> input){
	int output = 0;
	for (int i=0; i<input_size; ++i){
		output += input[i]*weights[i];
	}
	return output + bias > 0 ? 1 : 0;
}