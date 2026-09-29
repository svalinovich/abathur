#include <iostream>
#include <string>

#include "chess/board.h"
#include "chess/move.h"

int main() {
    std::cout << "Perfection goal that changes. Never stops moving. Can chase, cannot catch."
              << "\n";

    Board board;
    board.initBoard();
    board.printBoard();

    // makeMove(board, convertMove());
    std::cout << "\n";
    board.printBoard();

    return 0;
}
