#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(void) {
	string s;
	cin >> s;

	int len = s.length();
	vector<string> ans;

	//若输入字符串长度小于4或大于12，则必不存在合理的ip地址
	if (len < 4 || len > 12) {
		return 0;
	}


}
