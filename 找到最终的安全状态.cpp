#include <iostream>
#include <vector>
using namespace std;

int setflag(vector<vector<int>>& graph, vector<int>& flag, int i);

int main(){
	vector<vector<int>> graph;
	cin >> graph;
	
	int size = graph.size();
    vector<int> flag(size, 0);
    for(int i=0; i<size; i++){
        if(graph[i].size() == 0)
            flag[i] = 1;
    }
    
    vector<int> ans;
    for(int i=0; i<size; i++){
        int res = setflag(graph, flag, i);
        if(res == 1){
            ans.push_back(i);
        }
    }
    
    for(int i=0; i<ans.size(); i++){
    	cout << ans[i];
    	if(i != ans.size() - 1) cout << ",";
	}
	cout << endl;
	
	return 0;
}
