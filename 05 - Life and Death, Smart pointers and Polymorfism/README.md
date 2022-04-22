# Life and Death, Smart pointers and Polymorfism
## Exercise 1
Complete the code for `// missing implementations`.

### Result
Code asked to be implemented:
```c++
class King : public Piece {
    // missing implementations
};


class Knight : public Piece {
    // missing implementations
};
```
I implemented the classes like this:
```c++
class King : public Piece {
public:
    explicit King(Color color) : Piece(color) {}

    /// Return color and type of the chess piece
    std::string type() const override {
        return color_string() + " King";
    }

    /// Returns true if the given chess piece move is valid
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
        int x_movement = abs(to_x - from_x);
        int y_movement = abs(to_y - from_y);
        // King can only move one spot in either or both directions
        if(x_movement == 1 && y_movement <= 1) return true;
        if(y_movement == 1 && x_movement <= 1) return true;
        // Any other moves are illegal
        return false;
        return false;
    }
};


class Knight : public Piece {
public:
    explicit Knight(Color color) : Piece(color) {}

    /// Return color and type of the chess piece
    std::string type() const override {
        return color_string() + " Knight";
    }

    /// Returns true if the given chess piece move is valid
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
        int x_movement = abs(to_x - from_x);
        int y_movement = abs(to_y - from_y);
        // Knight can only move two steps in one direction, and one in the other
        if((x_movement == 2 || y_movement == 2) && (x_movement == 1 || y_movement == 1)) return true;
        // if it isn't, it is an illegal move
        return false;
    }
};
```

Which yields the following result after execution:
```console
Invalid moves:
no piece at e3
can not move white King from e1 to e3
can not move whiteKnight from b1 to b2

A simulated game:
white King is moving from e1 to e2
blackKnight is moving from g8 to h6
whiteKnight is moving from b1 to c3
blackKnight is moving from h6 to g8
whiteKnight is moving from c3 to d5
blackKnight is moving from g8 to h6
whiteKnight is moving from d5 to f6
blackKnight is moving from h6 to g8
whiteKnight is moving from f6 to e8
black King is being removed from e8
black lost the game
```

## Exercise 2
Lag en tekstutskrift av sjakkbrettet som viser rutene og hvilke brikker som eventuelt er i de ulike brikkene etter hvert trekk. Den tekstlige representasjonen av sjakkbrikkene bør her være svært kort. Utvid Piece, King og Knight klassene for å få til dette.

### Result
I am making the following additions to the code:   
**`Piece`**
```c++
/// Return symbol to display piece on board
virtual std::string symbol() const = 0;
```

**`King`**
```c++
std::string symbol() const override {
    if(color == Color::WHITE)
        return "♚";
    else
        return "♔";
}
```

**`Knight`**
```c++
std::string symbol() const override {
    if(color == Color::WHITE)
        return "♞";
    else
        return "♘";
}
```
And then finally creating a method to print the board:
```c++
void printBoard() {
    char letters[] = "abcdefgh";
    for(int i = 7; i >= 0; i--) {
        cout << letters[i];
        for(int j = 0; j < 8; j++) {
            auto &piece = squares[i][j];
            cout << "|";
            if(piece) {
                cout << piece->symbol();
            } else {
                cout << " ";
            }
        }
        cout << "|" << endl;
    }
    cout << "  1 2 3 4 5 6 7 8" << endl;
}
```

#### Final result
```console
...

h| | | | | |♘| | |
g|♞| | | | | | | |
f| | | | | |♞| | |
e| |♚| | | | | |♔|
d| | | | | | | | |
c| | | | | | | | |
b| | | | | | | |♘|
a| | | | | | | | |
  1 2 3 4 5 6 7 8
black Knight is moving from h6 to g8
h| | | | | | | | |
g|♞| | | | | | |♘|
f| | | | | |♞| | |
e| |♚| | | | | |♔|
d| | | | | | | | |
c| | | | | | | | |
b| | | | | | | |♘|
a| | | | | | | | |
  1 2 3 4 5 6 7 8
white Knight is moving from f6 to e8
black King is being removed from e8
h| | | | | | | | |
g|♞| | | | | | |♘|
f| | | | | | | | |
e| |♚| | | | | |♞|
d| | | | | | | | |
c| | | | | | | | |
b| | | | | | | |♘|
a| | | | | | | | |
  1 2 3 4 5 6 7 8
black lost the game
```
