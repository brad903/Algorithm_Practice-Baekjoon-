#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;

	while(getline(cin, s)){
			int lower = 0, upper = 0, number = 0, space = 0;

			for(char data : s){
				if (data >= 'a' && data <= 'z')
					lower++;
				else if (data >= 'A' && data <= 'Z')
					upper++;
				else if (data >= '0' && data <= '9')
					number++;
				else if (data == ' ')
					space++;
			}

			cout << lower << " " << upper << " " << number << " " << space << endl;
	}

	return 0;
}