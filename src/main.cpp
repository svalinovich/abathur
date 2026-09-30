#include <iostream>

#include "chess/board.h"
#include "chess/move.h"

int main() {
    std::cout << "Perfection goal that changes. Never stops moving. Can chase, cannot catch."
              << "\n";

    Board board;
    board.initBoard();
    board.printBoard();

    Move::makeMove(board, Move::convertMove("e2e4"));
    std::cout << "\n";
    board.printBoard();
    Move::makeMove(board, Move::convertMove("d7d5"));
    std::cout << "\n";
    board.printBoard();

    return 0;
}
