//
// Created by Sivert Utne on 22/09/2020.
//

#include <iostream>
#include <memory>
#include <string>
#include <vector>


using namespace std;


class ChessBoard {
public:
    enum class Color {
        WHITE,
        BLACK
    };


    class Piece {
    public:
        explicit Piece(Color color) : color(color) {}

        virtual ~Piece() = default;

        Color color;

        std::string color_string() const {
            if(color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    };


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


    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for(auto &square_column : squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if(piece_from) {
            if(piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
                auto &piece_to = squares[to_x][to_y];
                if(piece_to) {
                    if(piece_from->color != piece_to->color) {
                        cout << piece_to->type() << " is being removed from " << to << endl;
                        if(auto king = dynamic_cast<King *>(piece_to.get()))
                            cout << king->color_string() << " lost the game" << endl;
                    } else {
                        // piece in the from square has the same color as the piece in the to square
                        cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                        return false;
                    }
                }
                piece_to = move(piece_from);
                return true;
            } else {
                cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                return false;
            }
        } else {
            cout << "no piece at " << from << endl;
            return false;
        }
    }
};


int main() {
    ChessBoard board;
    board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

    board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
    board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
    board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");
    cout << endl;

    cout << "A simulated game:" << endl;
    board.move_piece("e1", "e2");
    board.move_piece("g8", "h6");
    board.move_piece("b1", "c3");
    board.move_piece("h6", "g8");
    board.move_piece("c3", "d5");
    board.move_piece("g8", "h6");
    board.move_piece("d5", "f6");
    board.move_piece("h6", "g8");
    board.move_piece("f6", "e8");
}