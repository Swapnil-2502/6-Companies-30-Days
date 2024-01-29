1030. Matrix Cells in Distance Order
Link: https://leetcode.com/problems/matrix-cells-in-distance-order/description/


class Solution {
public:

    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        

        vector<vector<int>> vis(rows,vector<int>(cols,0));
        vis[rCenter][cCenter] = 1;

        queue<pair<int,pair<int,int>>> q; //{dist,{r,c}};
        q.push({0,{rCenter,cCenter}});

        int deltax[4] = {-1,0,1,0};
        int deltay[4] = {0,1,0,-1};

        vector<pair<int,pair<int,int>>> res; //{dist,{r,c}};

        while(!q.empty()){
            auto it = q.front();
            int dist = it.first;
            int xcoord = it.second.first;
            int ycoord = it.second.second;
            q.pop();

            res.push_back({dist,{xcoord,ycoord}});

            for(int i=0;i<4;i++){
                int newr = deltax[i] + xcoord;
                int newc = deltay[i] + ycoord;
                
                if(newr>=0 && newr<rows && newc>=0 && newc<cols && vis[newr][newc]!=1){
                    q.push({dist+1,{newr,newc}});
                    vis[newr][newc] = 1;
                }
            }
        }

        sort(res.begin(),res.end());

        vector<vector<int>> ans;
        for(int i=0;i<res.size();i++){
            vector<int>temp(2,0);
            temp[0] = res[i].second.first;
            temp[1] = res[i].second.second;
            ans.push_back(temp);
        }

        return ans;

    }
};

//TC = O(rows*cols*4 + nlogn);
//SC = O(rows*cols)