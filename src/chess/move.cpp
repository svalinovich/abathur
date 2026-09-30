#include "move.h"
#include "chess/board.h"
#include <cstdint>

/*
 * @brief Converts a string representation of a move to a 16-bit move.
 *
 * @details In order to be UCI compliant, input must be parsed to be used by the engine efficiently.
 * This function takes in input such as "e2e4", and packs it as a 16-bit unsigned short compatible
 * with the rest of the architecture. Special moves such as promotions are specially encoded in the
 * flag bits listed below.
 *
 * @param stringInput Represents a selected move like "e2e5" which should move from e2 to e4.
 *
 * @return Move represented as a 16-bit unsigned short.
 *
 * move => [ special = 2 bits | promotion = 2 bits | to = 6 bits | from = 6 bits ]
 * special: 00 - nothing, 01 - castling, 10 - en passant, 11 - promotion
 * promotion: 00 - knight, 01 - bishop, 10 - rook, 11 - queen
 */

uint16_t Move::convertMove(const std::string_view stringInput) {
    std::string_view source{stringInput.substr(0, 2)};
    std::string_view destination{stringInput.substr(2, 2)};
    uint16_t convertedMove{0};

    uint8_t convertedSource{static_cast<uint8_t>((source[0] - 'a') + (8 * (source[1] - '1')))};
    uint8_t convertedDestination{static_cast<uint8_t>((destination[0] - 'a') + (8 * (destination[1] - '1')))};

    // in case of promotion, the input can be "a7a8q" which represents promotion to queen
    // if (stringInput.length() == 5) {
    // }

    convertedMove |= convertedDestination;
    convertedMove <<= 6;
    convertedMove |= convertedSource;

    return convertedMove;
}

/*
 * @brief Makes a move.
 *
 * @details Makes a chess move by detecting which bitboard contains a piece. The encoded move is
 * unpacked then the selected bitboard is XOR-ed so that the old piece position is deleted, and the
 * new one added.
 *
 * @param board reference to the board in order to change its state
 * @param move 16-bit integer which encodes each move
 *
 * move => [ special = 2 bits | promotion = 2 bits | to = 6 bits | from = 6 bits ]
 * promotion: 00 - knight, 01 - bishop, 10 - rook, 11 - queen
 * special: 00 - nothing, 01 - castling, 10 - en passant, 11 - promotion
 *
 * @note This will not work for capturing pieces.
 */

void Move::makeMove(Board &board, const uint16_t move) {
    // unpacking commands from move
    uint8_t from{static_cast<uint8_t>(move & 0x003FULL)};
    uint8_t to{static_cast<uint8_t>((move >> 6) & 0x003FULL)};
    // TODO: uint8_t flags{static_cast<uint8_t>((move & 0xF000) >> 12)};

    uint64_t fromMask{0x1ULL << from};
    uint64_t toMask{0x1ULL << to};

    for (uint64_t &pieces : board.bitboard) {
        if (pieces & toMask) {
            // delete piece if captured
            pieces &= ~toMask;
        }

        if (pieces & fromMask) {
            // deletes piece on position "from", and adds on position "to"
            pieces ^= fromMask | toMask;
        }
    }
}
