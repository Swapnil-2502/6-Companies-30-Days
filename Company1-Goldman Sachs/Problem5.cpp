// 519. Random Flip Matrix
// Link: https://leetcode.com/problems/random-flip-matrix/description/


class Solution {
public:
    set<pair<int, int>> st;
    int n,m;
    Solution(int nn, int mm){
        n = nn;
        m = mm;
    }
    
    vector<int> flip() {
        int row, col;
        do{
            row = random()%n;
            col = random()%m;
        }while(st.count({row, col}));

        st.insert({row, col});
        return {row, col};
    }
    
    void reset() {
        st.clear();
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */