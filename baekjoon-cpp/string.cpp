#include <string>
#include <iostream>
using namespace std;

void print(string s, int number) {
	cout << s << " -> " << number << '\n';
}

int main() {
	string s1;

	char c[] = "c string";
	string s2(c);
	string s3 = c;

	c[1] = '\0';

	string s4(c);
	string s5 = c;

	string s6(10, '!');
	string s7 = "abcdefg";  // 제일 많이 사용하는 방법

	cout << s1 << "\n";
	cout << s2 << "\n";
	cout << s3 << "\n";
	cout << s4 << "\n";
	cout << s5 << "\n";
	cout << s6 << "\n";
	cout << s7 << "\n";

	cout << "-----------------------------------------------------------------\n";

	string s = "abc";
	printf("%s\n", s.c_str());  // string을 c언어 스타일로 출력 가능하게함

	s += "def";
	printf("%s\n", s.c_str());

	s = "";
	printf("%s\n", s.c_str());

	s = "abcdefgdkfjkjkfjskfjskz";
	printf("%s\n", s.c_str());

	cout << "-----------------------------------------------------------------\n";

	string ss = "book";
	cout << ss << ": " << ss.size() << '\n';
	cout << ss << ": " << ss.length() << '\n';
	cout << ss << "empty: " << ss.empty() << '\n';

	ss = "";
	cout << ss << ": " << ss.size() << '\n';
	// size()가 unsigned int를 사용하기 때문에 -1하면 제일 뒤로 넘어감
	cout << ss << ": " << ss.size()-1 << '\n'; 
	cout << ss << "empty: " << ss.empty() << '\n';

	cout << "-----------------------------------------------------------------\n";

	string ss1 = "string";
	string ss2 = "stirng";

	if (ss1 == ss2) {
		cout << "ss1 == ss2" << '\n';
	}
	else if (ss1 != ss2) {
		cout << "ss1 != ss2" << '\n';
	}

	// 사전 순으로 앞서는지 아닌지 판단. 뒤로 갈수록 더 큰 수로 가짐
	if (ss1 < ss2) {
		cout << "ss1 < ss2" << '\n';
	}
	else if (ss1 > ss2) {
		cout << "ss1 > ss2" << '\n';
	}

	cout << "-----------------------------------------------------------------\n";

	string a = "Hello";
	string b = "World";

	string hello_world = a + " " + b;
	hello_world += "!";

	cout << hello_world << '\n';
	
	string ccc = "Hello";
	string d = "World";

	string hello_world2 = ccc + ' ' + d;
	hello_world2.push_back('!');

	cout << hello_world2 << '\n';

	cout << "-----------------------------------------------------------------\n";

	string aa = "He";
	aa.append(2, 'l'); // "Hell"
	aa.append("o").append(1, ' '); // "Hello "

	string bb = "";
	const char *cc = "World";
	bb.append(cc); // "World"

	string hello_world3 = aa;
	hello_world3.append(bb); // "Hello World"
	hello_world3.push_back('!'); // "Hello World!"

	cout << hello_world3 << '\n';

	cout << "-----------------------------------------------------------------\n";

	string sss = "e";  // "e"
	sss.insert(0, "H");  // "He" 0번째 위치에 추가
	cout << sss << '\n';
	sss.insert(2, "o");  // "Heo" 2번째 위치에 추가
	cout << sss << '\n';
	sss.insert(2, 2, 'l').append(" ");  // "Hello " 2번째 위치에 l을 2개 추가
	cout << sss << '\n';
	string world = "Half the World Away";
	sss.insert(6, world, 9, 5).push_back('!'); // "Hello World" 6번째 위치에 world의 9번째부터 5개를 추가
	cout << sss << '\n';

	cout << "-----------------------------------------------------------------\n";
	
	string str = "10";
	int number = stoi(str);
	print(str, number);

	number = stoi(str, 0, 2);  // 0번째 문자부터 2진수로 바꿈
	print(str, number);

	str = "ffff";
	number = stoi(str, 0, 16);
	print(str, number);

	str = "21 Guns";
	number = stoi(str);  // 숫자랑 문자랑 섞여있는 경우 숫자만 정수로
	print(str, number);

	str = "3.141592";
	number = stoi(str);  // 실수인 경우 정수 부분만 정수로 바꿈
	print(str, number);

	cout << "-----------------------------------------------------------------\n";

	int n1 = 1;
	int n2 = 2;

	string sss1 = to_string(n1);
	string sss2 = to_string(n2);

	cout << sss1 + ' ' + sss2 << '\n';

	int l1 = 2147483647;
	int l2 = 2147483647;

	string sss3 = to_string(l1);
	string sss4 = to_string(l2);

	cout << sss3 + ' ' + sss4 << '\n';

	double dddd = 3.141592;
	float ffff = 653583979.0;

	string sss5 = to_string(dddd);
	string sss6 = to_string(ffff);

	cout << sss5 + ' ' + sss6 << '\n';

	return 0;
}