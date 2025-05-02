struct Point {
    int x;
    int y;
    
    Point(int xC, int yC) : x(xC), y(yC) {}

    // Define comparison operator for ordering in the set
    bool operator<(const Point& other) const {
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }

    //  Add equality operator for erase
    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }
};
