#ifndef MOVE_H
#define MOVE_H

#include "chess/board.h"
#include <string_view>

uint16_t convertMove(const std::string_view stringInput);

void makeMove(Board &board, const uint16_t move);

#endif
