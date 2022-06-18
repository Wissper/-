#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> parse(string s, int step);

int main(void) {
	string s;
	cin >> s;

	int len = s.length();
	vector<string> ans;

	//若输入字符串长度小于4或大于12，则必不存在合理的ip地址
	if (len < 4 || len > 12) {
		return 0;
	}

	ans = parse(s, 1);
	
	cout << "[";
    
    for(int i=0; i<ans.size(); i++){
    	cout << ans[i];
    	if(i != ans.size()-1) cout << ", ";
	}
	
	cout << "]" << endl;
	
	return 0;
}


vector<string> parse(string s, int step){
    vector<string> ans;
    if(s.length() == 0) return ans;
    if(step == 4){
        if(s.length() > 3 || (s[0]=='0' && s.length() > 1)){
            return ans;
        }
        else{
            ans.push_back(s);
            return ans;
        }
    }
    string pref = "";
    int pre = 0;
    for(int i=0; i<3; i++){
        if(s.length() == 0) return ans;
        pref += s[0];
        pre = pre * 10 + s[0] - '0';
        if(pre > 255) break;
        s.erase(s.begin());
        vector<string>res = parse(s, step + 1);
        for(int j=0; j<res.size(); j++){
            ans.push_back(pref+"."+res[j]);
        }
        if(pre == 0) break;
    }
    return ans;
}

