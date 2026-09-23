#include <algorithm>
#include <bit>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <numeric>

#include "board.h"

enum PieceType {
    blackPawn,
    blackKnight,
    blackBishop,
    blackRook,
    blackQueen,
    blackKing,
    whitePawn,
    whiteKnight,
    whiteBishop,
    whiteRook,
    whiteQueen,
    whiteKing
};

void Board::initBoard() {
    // white init
    bitboard[PieceType::whitePawn] = 0x000000000000FF00ULL;
    bitboard[PieceType::whiteKnight] = 0x0000000000000042ULL;
    bitboard[PieceType::whiteBishop] = 0x0000000000000024ULL;
    bitboard[PieceType::whiteRook] = 0x0000000000000081ULL;
    bitboard[PieceType::whiteQueen] = 0x0000000000000008ULL;
    bitboard[PieceType::whiteKing] = 0x0000000000000010ULL;

    whiteBitboard = std::accumulate(
        bitboard + PieceType::whitePawn, bitboard + PieceType::whiteKing, uint64_t{0},
        [](uint64_t initial, uint64_t piece) { return initial | piece; });

    // black init
    bitboard[PieceType::blackPawn] = 0x00FF000000000000ULL;
    bitboard[PieceType::blackKnight] = 0x4200000000000000ULL;
    bitboard[PieceType::blackBishop] = 0x2400000000000000ULL;
    bitboard[PieceType::blackRook] = 0x8100000000000000ULL;
    bitboard[PieceType::blackQueen] = 0x0800000000000000ULL;
    bitboard[PieceType::blackKing] = 0x1000000000000000ULL;

    blackBitboard = std::accumulate(
        bitboard + PieceType::blackPawn, bitboard + PieceType::blackKing, uint64_t{0},
        [](uint64_t initial, uint64_t piece) { return initial | piece; });

    std::cout << "Board initialized." << "\n";
}

void Board::printBoard() {
    char board[64];
    std::fill(std::begin(board), std::end(board), ' ');

    for (auto i{0}; i < 12; ++i) {
        uint64_t piece{bitboard[i]};

        while (piece) {
            int square{std::countr_zero(piece)};

            switch (i) {
            case 0:
                board[square] = 'P';
                break;
            case 1:
                board[square] = 'N';
                break;
            case 2:
                board[square] = 'B';
                break;
            case 3:
                board[square] = 'R';
                break;
            case 4:
                board[square] = 'Q';
                break;
            case 5:
                board[square] = 'K';
                break;
            case 6:
                board[square] = 'p';
                break;
            case 7:
                board[square] = 'n';
                break;
            case 8:
                board[square] = 'b';
                break;
            case 9:
                board[square] = 'r';
                break;
            case 10:
                board[square] = 'q';
                break;
            case 11:
                board[square] = 'k';
                break;
            default:
                board[square] = 'X';
                break;
            }

            piece &= (piece - 1);
        }
    }

    std::cout << "------------------------------------------------------" << "\n";

    for (auto i{0}; i < 64; ++i) {
        if (i % 8 == 0) {
            if (i == 0) {
                std::cout << "     |     |     |     |     |     |     |     |     |" << "\n";
                std::cout << "  " << (64 - i) / 8 << "  |";
            } else {
                std::cout << "\n" << "------------------------------------------------------";
                std::cout << "\n"
                          << "     |     |     |     |     |     |     |     |     |";
                std::cout << "\n" << "  " << (64 - i) / 8 << "  |";
            }
        }

        std::cout << "  " << board[i] << "  |";
    }

    std::cout << "\n" << "------------------------------------------------------" << "\n";
    std::cout << "     |  a  |  b  |  c  |  d  |  e  |  f  |  g  |  h  |" << "\n";
}
