#include <iostream>
#include <string>
using namespace std;

bool isIPv4(string queryIP);
bool isIPv6(string queryIP);
	
int main(){
	bool flag1 = false;
    bool flag2 = false;
    for(int i=0; i<queryIP.length(); i++){
        if(queryIP[i] == '.'){
            flag1 = isIPv4(queryIP);
            break;
        }
        if(queryIP[i] == ':'){
            flag2 = isIPv6(queryIP);
            break;
        }
    }
    string ans;
    if(flag1){
        ans = "IPv4";
    }
    else if(flag2){
        ans = "IPv6";
    }
    else ans = "Neither";
}
