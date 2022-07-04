class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<vector<int> > flag(grid);
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(flag[i][j]){
                    for(int x=0; x<grid[i].size(); x++){
                        if(grid[i][x] == 1 && x != j){
                            if(flag[i][j]){
                                flag[i][j] = 0;
                                ans++;
                            }
                            if(flag[i][x]){
                                flag[i][x] = 0;
                                ans++;
                            }
                        }
                        if(grid[x][j] == 1 && x != i){
                            if(flag[i][j]){
                                flag[i][j] = 0;
                                ans++;
                            }
                            if(flag[x][j]){
                                flag[x][j] = 0;
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
