#ifndef BOARD_H
#define BOARD_H

#include "position.h"

class Board {
  public:
    Position m_currentPosition{}; // TODO: this should probably be a pointer for easy position switching
    void printBoard();
};

#endif
