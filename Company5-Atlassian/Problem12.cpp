2211. Count Collisions on a Road
linK: https://leetcode.com/problems/count-collisions-on-a-road/description/


class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int notCollide = 0;

        //Count no of cars from 0th index which are going only left
        for(int i=0;i<n;i++){
            if(directions[i] != 'L') break;

            notCollide++;
        }

        //Count no of cars from n-1 th index which are going only right
        for(int i=0;i<n;i++){
            if(directions[i] != 'R') break;

            notCollide++;
        }

        //Count no of cars from 0th index which is stationary
        for(int i=0;i<n;i++){
            if(directions[i] != 'S') break;

            notCollide++;
        }

        return n - notCollide;
    }
};
//TC = O(n);
//SC = O(1);