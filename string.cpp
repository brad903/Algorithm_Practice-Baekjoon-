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
	string s7 = "abcdefg";  // ���� ���� ����ϴ� ���

	cout << s1 << "\n";
	cout << s2 << "\n";
	cout << s3 << "\n";
	cout << s4 << "\n";
	cout << s5 << "\n";
	cout << s6 << "\n";
	cout << s7 << "\n";

	cout << "-----------------------------------------------------------------\n";

	string s = "abc";
	printf("%s\n", s.c_str());  // string�� c��� ��Ÿ�Ϸ� ��� �����ϰ���

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
	// size()�� unsigned int�� ����ϱ� ������ -1�ϸ� ���� �ڷ� �Ѿ
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

	// ���� ������ �ռ����� �ƴ��� �Ǵ�. �ڷ� ������ �� ū ���� ����
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
	sss.insert(0, "H");  // "He" 0��° ��ġ�� �߰�
	cout << sss << '\n';
	sss.insert(2, "o");  // "Heo" 2��° ��ġ�� �߰�
	cout << sss << '\n';
	sss.insert(2, 2, 'l').append(" ");  // "Hello " 2��° ��ġ�� l�� 2�� �߰�
	cout << sss << '\n';
	string world = "Half the World Away";
	sss.insert(6, world, 9, 5).push_back('!'); // "Hello World" 6��° ��ġ�� world�� 9��°���� 5���� �߰�
	cout << sss << '\n';

	cout << "-----------------------------------------------------------------\n";
	
	string str = "10";
	int number = stoi(str);
	print(str, number);

	number = stoi(str, 0, 2);  // 0��° ���ں��� 2������ �ٲ�
	print(str, number);

	str = "ffff";
	number = stoi(str, 0, 16);
	print(str, number);

	str = "21 Guns";
	number = stoi(str);  // ���ڶ� ���ڶ� �����ִ� ��� ���ڸ� ������
	print(str, number);

	str = "3.141592";
	number = stoi(str);  // �Ǽ��� ��� ���� �κи� ������ �ٲ�
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