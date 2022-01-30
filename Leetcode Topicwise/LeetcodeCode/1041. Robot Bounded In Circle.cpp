class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<int> direction = {0, 1};
        vector<int> position = {0, 0};
        
        for(auto d : instructions){
            if(d == 'G'){
                position[0] += direction[0];
                position[1] += direction[1];
            }
            
            else if(d == 'L'){
                int temp = direction[0];
                direction[0] = -1 * direction[1];
                direction[1] = temp;
            }
            else{
                int temp = direction[1];
                direction[1] = -1 * direction[0];
                direction[0] = temp;
            }
        }
        return (position[0] == 0 && position[1] == 0) || (direction[0] != 0 || direction[1] != 1);
    }
};