class CountSquares {
    unordered_map<int, unordered_map<int, int>> points;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
         int x = point[0], y = point[1];
        points[x][y]++;
    }
    
    int count(vector<int> point) {
         int x = point[0], y = point[1];
        int result = 0;

        // iterate same x (vertical line)
        for (auto &[y2, cnt] : points[x]) {
            if (y2 == y) continue;

            int d = y2 - y;

            // Right side square
            result += cnt *
                      points[x + d][y] *
                      points[x + d][y2];

            // Left side square
            result += cnt *
                      points[x - d][y] *
                      points[x - d][y2];
        }

        return result;
    }
};
