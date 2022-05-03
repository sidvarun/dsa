
// Very good explaination
https://leetcode.com/problems/robot-room-cleaner/discuss/1028277/C%2B%2B-Algorithm-walk-through-and-code-with-detailed-comments.

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
struct hashFunction
{
  size_t operator()(const pair<int , 
                    int> &x) const
  {
    return x.first ^ x.second;
  }
};

class Solution {
public:
    unordered_set<pair<int, int>, hashFunction> visited;
    vector<vector<int>> directions;
    int m;
    int n;
    void goBack(Robot &robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    void dfs(int i, int j, int d, Robot &robot){

        
        visited.insert({i, j});
        robot.clean();
        
        for(int k = 0; k<4; k++){
            int newDir = (d + k) % 4;
            int x = i + directions[newDir][0];
            int y = j + directions[newDir][1];
        
            if(visited.find({x, y}) == visited.end()){
                if(robot.move()){
                    dfs(x, y, newDir, robot);
                    goBack(robot);
                }
            }            
            
            robot.turnRight();
        }
    }
    void cleanRoom(Robot& robot) {
        directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        dfs(0, 0, 0, robot);
    }
};