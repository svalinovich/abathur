#ifndef BOARD_H
#define BOARD_H

#include <cstdint>

class Board {
  public:
    uint64_t bitboard[12] = {0};
    uint64_t whiteBitboard = 0;
    uint64_t blackBitboard = 0;

    void initBoard();
    void printBoard();
};

#endif
