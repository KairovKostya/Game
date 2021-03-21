enum class Direction {
    LEFT, RIGHT, UP, DOWN, NONE
};

class Keyboard {
public:
    char GetKey();
    Direction SetDirection(char key);
};

