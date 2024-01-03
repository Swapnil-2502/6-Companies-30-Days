// Q: Find Missing And Repeating
// Link: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        
        unordered_map<int,int> mp;
        
        vector<int> ans;
        
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i]) != mp.end()){
                ans.push_back(arr[i]);
            } 
            
            mp[arr[i]] = 1;
        }
        
        for(int i=1;i<=n;i++){
            if(mp.find(i) == mp.end()){
                ans.push_back(i);
                break;
            } 
        }
        
        return ans;
    }
};
