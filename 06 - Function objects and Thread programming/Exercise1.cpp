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

        /// Return symbol to display piece on board
        virtual std::string symbol() const = 0;

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

        /// Return symbol to display piece on board
        std::string symbol() const override {
            if(color == Color::WHITE)
                return "♚";
            else
                return "♔";
        }

        /// Returns true if the given chess piece move is valid
        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            int x_movement = abs(to_x - from_x);
            int y_movement = abs(to_y - from_y);
            // King can only move one spot in either or both directions
            if(x_movement + y_movement == 1) return true;
            if(x_movement == 1 && y_movement == 1) return true;
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

        /// Return symbol to display piece on board
        std::string symbol() const override {
            if(color == Color::WHITE)
                return "♞";
            else
                return "♘";
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

    /// Function objects for handling feedback after a player makes a move
    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move;
    function<void(const Piece &piece, const string &square)> on_removing_piece;
    function<void(const Color &color)> on_check_mate;
    function<void(const Piece &piece, const string &from, const string &to)> on_invalid_piece_move;
    function<void(const string &square)> on_missing_piece;

    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    // Rearranging the code to make it easier to understand the flow
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        // Checking if piece exists
        auto &piece_from = squares[from_x][from_y];
        if(!piece_from) {
            if(on_missing_piece) on_missing_piece(from);
            return false;
        }
        // making sure this is a valid move for that piece
        if(!piece_from->valid_move(from_x, from_y, to_x, to_y)) {
            if(on_invalid_piece_move) on_invalid_piece_move(*piece_from, from, to);
            return false;
        }

        // check if a piece is in the way
        auto &piece_to = squares[to_x][to_y];
        if(piece_to) {
            // make sure the piece isn't friendly
            if(piece_from->color == piece_to->color) {
                // piece in the from square has the same color as the piece in the to square
                if(on_invalid_piece_move) on_invalid_piece_move(*piece_from, from, to);
                return false;
            }

            // Did you just kill the king and win the game?
            if(auto king = dynamic_cast<King *>(piece_to.get())) {
                if(on_removing_piece) on_removing_piece(*piece_to, to);
                piece_to = move(piece_from);
                if(on_piece_move) on_piece_move(*piece_to, from, to);
                if(on_check_mate) on_check_mate(king->color);
                return true;
            }

            // Remove opponents piece
            if(on_removing_piece) on_removing_piece(*piece_to, to);
        }
        piece_to = move(piece_from);
        if(on_piece_move) on_piece_move(*piece_to, from, to);
        return true;
    }


};


class ChessBoardPrint {
private:
    ChessBoard& board;
    function<void(ChessBoard &board)> printBoard;

public:
    explicit ChessBoardPrint(ChessBoard &board) : board(board) {
        // setting function object to print entire board
        printBoard = [](ChessBoard &board) {
            char letters[] = "abcdefgh";
            for(int i = 7; i >= 0; i--) {
                cout << letters[i];
                for(int j = 0; j < 8; j++) {
                    cout << "|";
                    auto &piece = board.squares[i][j];
                    if(piece) {
                        cout << piece->symbol();
                    } else {
                        cout << " ";
                    }
                }
                cout << "|" << endl;
            }
            cout << "  1 2 3 4 5 6 7 8" << endl;
        };

        // Assigning the function objects for the board
        board.on_piece_move = [this](const ChessBoard::Piece &piece, const string &from, const string &to) {
            cout << piece.type() << " is moving from " << from << " to " << to << endl;
            printBoard(this->board);
        };
        board.on_removing_piece = [](const ChessBoard::Piece &piece, const string &square) {
            cout << piece.type() << " is being removed from " << square << endl;
        };
        board.on_check_mate = [](ChessBoard::Color losingColor) {
            if(losingColor == ChessBoard::Color::WHITE)
                cout << "Black";
            else
                cout << "White";
            cout << " won the game!" << endl;
        };
        board.on_invalid_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
            cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
        };
        board.on_missing_piece = [](const string &square) {
            cout << "no piece at " << square << endl;
        };
    }
};


int main() {
    ChessBoard board;
    ChessBoardPrint print(board);

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
