#include <iostream>

#include "board.h"
#include "move.h"

int main() {
    std::cout << "Perfection goal that changes. Never stops moving. Can chase, cannot catch."
              << "\n";

    Board board;
    board.printBoard();

    Move::makeMove(board.m_currentPosition, Move::convertMove("e2e4"));
    std::cout << "\n";
    board.printBoard();
    Move::makeMove(board.m_currentPosition, Move::convertMove("d7d5"));
    std::cout << "\n";
    board.printBoard();

    return 0;
}
