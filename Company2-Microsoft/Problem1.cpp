1401. Circle and Rectangle Overlapping
Link: https://leetcode.com/problems/circle-and-rectangle-overlapping/description/

class Solution 
{
 public:
     bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
         // Calculate the closest point on the rectangle to the center of the circle.
        int closestX = max(x1,min(xCenter,x2));
        int closestY = max(y1,min(yCenter,y2));
        // Calculate the distance between the center of the circle and the closest point.
        int dist = (closestX-xCenter) * (closestX-xCenter) +
                   (closestY-yCenter) * (closestY-yCenter);
        
        // Check if the distance is less than or equal to the radius squared.
        return radius * radius >= dist;
    }
};