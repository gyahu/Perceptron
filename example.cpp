#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "perceptron.h"

using namespace std;

Perceptron nand, own_and, own_or;

int NAND(vector<int> inputs){
	return nand.compute(inputs);
}

int AND(vector<int> inputs){
	return own_and.compute(inputs);
}

int OR(vector<int> inputs){
	return own_or.compute(inputs);
}

vector<int> SUM(vector<int> inputs){
	int sum, carry;
	sum = NAND(inputs);
	carry = NAND({sum, sum});
	sum = NAND({NAND({sum, inputs[0]}), NAND({sum, inputs[1]})});
	return {sum, carry};
}

int main(){

	// Perceptron unit;
	// int size, bias, input, weight;
	// vector<int> inputs, weights;
	// printf("Enter input size and bias: ");
	// scanf("%d %d", &size, &bias);
	// for (int i=0; i<size; ++i){
	// 	printf("Enter input and weight number %d: ", i+1);
	// 	scanf("%d %d", &input, &weight);
	// 	inputs.push_back(input);
	// 	weights.push_back(weight);
	// }
	// unit.init(size, bias, weights);
	// printf("Result is: %d\n", unit.compute(inputs));
	
	nand.init(2, 3, {-2, -2});
	own_and.init(2, -3, {2, 2});
	own_or.init(2, 0, {1, 1});
	
	int a,b;
	printf("Enter value 'a' and value 'b': ");
	scanf("%d %d", &a, &b);
	printf("%d NAND %d = %d\n", a, b, NAND({a,b}));
	printf("%d AND  %d = %d\n", a, b, AND({a,b}));
	printf("%d  OR  %d = %d\n", a, b, OR({a,b}));
	vector<int> r = SUM({a,b});
	printf("The sum of %d and %d is %d, with carry of %d\n", a, b, r[0], r[1]);

	return 0;
}
