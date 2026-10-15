#include <iostream>
#include <span>

#include "board.h"

void Board::printBoard() {
    char board[64];
    std::fill(std::begin(board), std::end(board), ' ');

    for (auto i{0}; i < 12; ++i) {
        std::uint64_t piece{m_currentPosition.m_bitboard[i]};

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

    for (auto i{0}; i < 8; ++i) {
        std::cout << "------------------------------------------------------" << "\n";
        std::cout << "     |     |     |     |     |     |     |     |     |" << "\n";
        std::cout << "  " << 8 - i << "  |";
        std::span<char> row = std::span<char>(board).subspan(63 - 7 - (8 * i), 8);

        for (char pieceSymbol : row) {
            std::cout << "  " << pieceSymbol << "  |";
        }

        std::cout << "\n";
    }

    std::cout << "------------------------------------------------------" << "\n";
    std::cout << "     |  a  |  b  |  c  |  d  |  e  |  f  |  g  |  h  |" << "\n";
}
