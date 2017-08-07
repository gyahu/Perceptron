#include <vector>

class Perceptron{
	private:
		int input_size, bias;
		std::vector<int> weights;

	public:
		void init(int, int, std::vector<int>);
		int compute(std::vector<int>);
};