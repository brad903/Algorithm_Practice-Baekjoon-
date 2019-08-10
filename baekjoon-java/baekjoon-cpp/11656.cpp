#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

void bubble_sorting(string *ps) {
	
}

int main() {
	string s;
	cin >> s;

	char *p = (char *)malloc(sizeof(char)*s.length());

	for (int i = 0; i < s.length()-1; i++) {
		char target = s[i];
		for (int j = i + 1; j < s.length(); j++) {
			if (s[j] < target){
				char temp;
				temp = target;
				target = s[j];
				s[j] = temp;
			}
		}
		*(p + i) = i;
	}
	*(p + (s.length() - 1)) = s[s.length() - 1];

	for (int i = 0; i < s.length(); i++)
		cout << *(p + i);

	free(p);
}