2126. Destroying Asteroids
Link: https://leetcode.com/problems/destroying-asteroids/description/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        long newMass = mass;
        stack<int> st;

        for(auto it : asteroids){
            st.push(it);

            while(!st.empty() && st.top() <= newMass){
                newMass += st.top();
                st.pop();
            }
        }

        return st.empty();
    }
};

//TC = O(N);
//SC = O(N);