1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(auto it:edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for(int i=0;i<n;i++) dist[i][i] = 0;

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int countCity = n;
        int cityNo = -1;

        for(int city = 0; city<n; city++){
            int count = 0;
            for(int adjCity=0; adjCity<n; adjCity++){
                if(dist[city][adjCity] <= distanceThreshold) count++;

            }
            if(count<=countCity){
                countCity = count;
                cityNo = city;
            }
        }

        return cityNo;
    }
};

//TC = O(N^3);
//SC = O(N^2);