#include <iostream>

#include "chess/board.h"

int main() {
    std::cout << "Perfection goal that changes. Never stops moving. Can chase, cannot catch."
              << "\n";

    Board board;
    board.initBoard();
    board.printBoard();
}
