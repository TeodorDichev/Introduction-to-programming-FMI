// От конзолата се въвежда цяло положително число N. След това се подават N 
// на брой цели числа. Да се изведе дали сред тях съществува елемент, 
// равен на сумата на останалите.
#include <iostream>;

int main() {
	int n, k, sum = 0, numEqualToSum = 0;
	std::cin >> n;

	while (n > 0) {
		std::cin >> k;
		if (k > numEqualToSum) {
			sum += numEqualToSum;
			numEqualToSum = k;
		}
		else {
			sum += k;
		}
		n--;
	}

	numEqualToSum == sum ? (std::cout << "Yes: " << numEqualToSum << '\n') : std::cout << "No\n";
}
