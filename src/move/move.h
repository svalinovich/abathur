#ifndef MOVE_H
#define MOVE_H

#include "board/board.h"
#include <cstdint>
#include <string_view>
#include <vector>

namespace Move {
uint16_t convertMove(const std::string_view stringInput);
void makeMove(Board &board, const uint16_t move);
std::vector<uint16_t> generateLegalMoves(uint64_t piece);
bool isLegal(const Board &board, const uint16_t move);
} // namespace Move

#endif
