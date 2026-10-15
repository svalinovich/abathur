#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

#include "position.h"

enum PieceType {
    whitePawn,
    whiteKnight,
    whiteBishop,
    whiteRook,
    whiteQueen,
    whiteKing,
    blackPawn,
    blackKnight,
    blackBishop,
    blackRook,
    blackQueen,
    blackKing
};

/*
 * @brief Default constructor. Sets up initial chessboard position.
 */

Position::Position() {
    // white init
    m_bitboard[PieceType::whitePawn] = 0x000000000000FF00ULL;
    m_bitboard[PieceType::whiteKnight] = 0x0000000000000042ULL;
    m_bitboard[PieceType::whiteBishop] = 0x0000000000000024ULL;
    m_bitboard[PieceType::whiteRook] = 0x0000000000000081ULL;
    m_bitboard[PieceType::whiteQueen] = 0x0000000000000008ULL;
    m_bitboard[PieceType::whiteKing] = 0x0000000000000010ULL;

    m_whiteBitboard =
        std::accumulate(m_bitboard + PieceType::whitePawn, m_bitboard + PieceType::whiteKing, std::uint64_t{0},
                        [](std::uint64_t initial, std::uint64_t piece) { return initial | piece; });

    // black init
    m_bitboard[PieceType::blackPawn] = 0x00FF000000000000ULL;
    m_bitboard[PieceType::blackKnight] = 0x4200000000000000ULL;
    m_bitboard[PieceType::blackBishop] = 0x2400000000000000ULL;
    m_bitboard[PieceType::blackRook] = 0x8100000000000000ULL;
    m_bitboard[PieceType::blackQueen] = 0x0800000000000000ULL;
    m_bitboard[PieceType::blackKing] = 0x1000000000000000ULL;

    m_blackBitboard =
        std::accumulate(m_bitboard + PieceType::blackPawn, m_bitboard + PieceType::blackKing, std::uint64_t{0},
                        [](std::uint64_t initial, std::uint64_t piece) { return initial | piece; });

    std::cout << "Initial position loaded." << "\n";
}

/*
 * @brief Constructor from a given position.
 *
 * @details Constructs a position from a given position represented as an array of 12 bitboards. After copying the
 * array, it also updates m_whiteBitboard and m_blackBitboard.
 *
 * @param bitboard Represents the board as an array of 12 bitboards, one for each piece type and color.
 */

Position::Position(const std::uint64_t (&bitboard)[12]) {
    std::copy(std::begin(bitboard), std::end(bitboard), m_bitboard);

    m_whiteBitboard =
        std::accumulate(m_bitboard + PieceType::whitePawn, m_bitboard + PieceType::whiteKing, std::uint64_t{0},
                        [](std::uint64_t initial, std::uint64_t piece) { return initial | piece; });
    m_blackBitboard =
        std::accumulate(m_bitboard + PieceType::blackPawn, m_bitboard + PieceType::blackKing, std::uint64_t{0},
                        [](std::uint64_t initial, std::uint64_t piece) { return initial | piece; });
}
