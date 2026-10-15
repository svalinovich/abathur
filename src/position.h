#ifndef POSITION_H
#define POSITION_H

#include <cstdint>

class Position {
  public:
    std::uint64_t m_bitboard[12]{0};
    std::uint64_t m_whiteBitboard{0};
    std::uint64_t m_blackBitboard{0};

    Position();
    Position(const std::uint64_t (&bitboard)[12]);
};

#endif
