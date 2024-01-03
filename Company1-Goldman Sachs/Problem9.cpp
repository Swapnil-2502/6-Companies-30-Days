// Number following a pattern
// Link: https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1

// Gist: if I then -> 1.push in stack 2.increase curr 3.add to ans string(empty stack)
// if D then -> 1.push in stack 2.increase curr
// After the Iteration
// if last element is I then -> 1.add to ans from remaining elem from stack 2.add curr to ans
// if last element is D then -> 1.add curr to ans 2.add all elements from stack to ans

class Solution{   
public:
    string printMinNumberForPattern(string S){
        stack<int> st;
        int curr = 1;
        
        string ans = "";
        
        for(int i=0;i<S.size();i++){
            
            if(S[i] == 'I'){
                st.push(curr);
                curr++;
                
                while(!st.empty()){
                    int ele = st.top();
                    st.pop();
                    
                    ans = ans + to_string(ele);
                }
            }
            
            else{
                st.push(curr);
                curr++;
            }
        }
        
        int n = S.size();
        
        if(S[n-1] == 'I'){
            while(!st.empty()){
                    int ele = st.top();
                    st.pop();
                    
                    ans = ans + to_string(ele);
            }
            ans = ans + to_string(curr);
            return ans;
        }
        else{
            ans = ans + to_string(curr);
            while(!st.empty()){
                    int ele = st.top();
                    st.pop();
                    
                    ans = ans + to_string(ele);
            }
            return ans;
        }
    }
};

//Tc = O(N);
//SC = O(stack space);