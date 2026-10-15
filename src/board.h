#ifndef BOARD_H
#define BOARD_H

#include "position.h"

class Board {
  public:
    Position m_currentPosition{};
    void printBoard();
};

#endif
