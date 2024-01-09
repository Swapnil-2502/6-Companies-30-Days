661. Image Smoother
Link: https://leetcode.com/problems/image-smoother/description/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        // int n = img.size();
        // int m = img[0].size();

        // vector<vector<int>> ans(n,vector<int>(m));

        // int deltaRow[] = {-1,-1,0,1,1,1,0,-1};
        // int deltaCol[] = {0,1,1,1,0,-1,-1,-1};

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         int sum=0;
        //         int count=0;

        //         for(int index=0;index<8;index++){
        //             int row = i+deltaRow[index];
        //             int col = j+deltaCol[index];

        //             if(row>=0 && row<n && col>=0 && col<m){
        //                 sum += img[row][col];
        //                 count++;
        //             }
        //         }
        //         sum += img[i][j];
        //         count++;
        //         ans[i][j] = sum/count;
        //     }
        // }
        // return ans;
 //Tc = O(9 * N*M);
//SC = O(N*M);

        int n = img.size();
        int m = img[0].size();
        vector<int> temp(n);
        vector<int> prevRow(n), curRow(n);

        for(int i=0;i<n;i++){
            curRow = img[i];
            for(int j=0;j<m;j++){
                int sum = 0, count = 0;

                //Bottom Elements;
                if(i+1<n){
                    if(j+1<m){
                        sum+= img[i+1][j+1];
                        count++;
                    }
                    sum += img[i+1][j];
                    count++;

                    if(j-1>=0){
                        sum+= img[i+1][j-1];
                        count++;
                    }
                }

                //Next Neighbour 
                if(j+1<m){
                    sum+= img[i][j+1];
                    count++;
                }

                //top Elements;
                if(i-1>=0){
                    if(j-1>=0){
                        sum+= prevRow[j-1];
                        count++;
                    }
                    sum+= prevRow[j];
                    count++;
                    
                    if(j+1<m){
                        sum+= prevRow[j+1];
                        count++;
                    }
                }

                //Prev Neighbours 
                if(j-1>=0){
                    sum+= curRow[j-1];
                    count++;
                }
                

                //(i,j)th element where we are standing
                sum+= img[i][j];
                count++;

                img[i][j] = sum/count;

            }
            prevRow = curRow;
        }

        return img;
        //TC = O(9*N*M);
        //SC = O(N*2);
    }

};

