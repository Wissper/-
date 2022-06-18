#include <iostream>
#include <string>
using namespace std;

bool isIPv4(string queryIP);
bool isIPv6(string queryIP);
	
int main(){
	bool flag1 = false;
    bool flag2 = false;
    string queryIP;
    cin >> queryIP;
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
    
    cout << ans << endl;
}

bool isIPv4(string queryIP){
    int num = 0;
    int firstZero = 0;
    int numOfPoint = 0;
    int conseqNum = 0;
    for(int i=0; i<queryIP.size(); i++){
        if(queryIP[i] == '.'){
            if(conseqNum == 0) return false;
            num = 0;
            conseqNum = 0;
            firstZero = 0;
            numOfPoint++;
            continue;
        }
        if(queryIP[i] > '9' || queryIP[i] <'0') return false;
        if(firstZero == 1) return false;
        conseqNum++;
        num = num * 10 + queryIP[i] - '0';
        if(num > 255) return false;
        if(queryIP[i] == '0'){
            if(firstZero == 0) firstZero = 1;
        }
        else firstZero = -1;
    }
    if(numOfPoint != 3) return false;
    if(queryIP[queryIP.length()-1] == '.') return false;
    return true;
}


bool isIPv6(string queryIP){
    int conseqNum = 0;
    int num = 0;
    for(int i=0; i<queryIP.length(); i++){
        if(queryIP[i] == ':'){
            num++;
            if(conseqNum == 0) return false;
            conseqNum = 0;
            continue;
        }
        if((queryIP[i]>='0' && queryIP[i]<='9') || (queryIP[i]>='a' && queryIP[i]<='f') || 
        (queryIP[i]>='A' && queryIP[i]<='F')){
            conseqNum++;
        }
        else{
            return false;
        }
        if(conseqNum > 4) return false;
    }
    if(queryIP[queryIP.length()-1] == ':') return false;
    if (num != 7) return false;
    return true;
}

