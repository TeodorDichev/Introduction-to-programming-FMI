// Да се напише програма, която приема цяло положително число n и 
// отпечатва числата от 1 до n*n в спираловиден вид.
// 16 15 14 13
// 5 4 3 12
// 6 1 2 11
// 7 8 9 10
#include <iostream>;
 int main() {
	 int n;
	 std::cin >> n;
	 int num_elems = n * n;

	 for (int y = 0; y < n; y++) {
		 for (int x = 0; x < n; x++) {
			 int side_len = n;
			 int row = 0;
			 int col = 0;
			 int pos = 0;

			 char direction = 'r';
			 for (int i = num_elems; i > 0; i--) {
				 if (row == y && col == x) {
					 std::cout << i << ' ';
					 break;
				 }
				 ++pos;

				 if (pos == side_len) {

					 if (direction == 'r') direction = 'd';
					 else if (direction == 'd') direction = 'l';
					 else if (direction == 'l') direction = 'u';
					 else direction = 'r';

					 pos = 0;

					 if (direction == 'd' || direction == 'u') {
						 --side_len;
					 }
				 }

				 switch (direction) {
				 case 'r':
					 ++col;
					 break;
				 case 'd':
					 ++row;
					 break;
				 case 'l':
					 --col;
					 break;
				 case 'u':
					 --row;
					 break;
				 }
			 }
			 std::cout << '\n';
		 }
	 }
 }