#ifndef MOVE_H
#define MOVE_H

#include "position.h"
#include <cstdint>
#include <string_view>
#include <vector>

namespace Move {
std::uint16_t convertMove(const std::string_view stringInput);
void makeMove(Position &position, const std::uint16_t move);
std::vector<std::uint16_t> generateMoves(const Position &position, std::uint64_t piece);
bool isLegal(const Position &position, const std::uint16_t move);
} // namespace Move

#endif
