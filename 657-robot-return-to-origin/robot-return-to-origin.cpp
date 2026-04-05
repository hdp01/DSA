class Solution {
public:
    bool judgeCircle(string moves) {
        int xCoordinate = 0;
        int yCoordinate = 0;
        for (char move : moves) {
            switch (move) {
                case 'U':  
                    yCoordinate++;
                    break;
                case 'D':  
                    yCoordinate--;
                    break;
                case 'L':  
                    xCoordinate--;
                    break;
                case 'R':
                    xCoordinate++;
                    break;
            }
        }
        return (xCoordinate == 0 && yCoordinate == 0);
    }
};