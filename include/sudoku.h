/**
 * @file sudoku.h
 * @brief Core Sudoku solving and board generation functions.
 *
 * This header file declares functions essential for solving Sudoku puzzles
 * and validating board states. It includes:
 * - A backtracking Sudoku solver.
 * - A cell validation function to ensure valid number placement.
 * - A board generation stub for creating Sudoku puzzles.
 *
 * All functions operate on dynamically allocated 9x9 Sudoku boards
 * represented as `int**`, where empty cells are denoted by 0.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#ifndef SUDOKUPROJECT_SUDOKU_H
#define SUDOKUPROJECT_SUDOKU_H

#include <iostream>

/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  * @brief Determines if placing a number in a specific cell respects Sudoku rules.
  *
  * Checks that the candidate number `k` does not already appear in the same row `r`,
  * column `c`, or the corresponding 3×3 subgrid of the 9×9 board.
  *
  * @param BOARD A pointer to the 9×9 Sudoku board (int**).
  * @param r The zero-based row index (0–8) of the target cell.
  * @param c The zero-based column index (0–8) of the target cell.
  * @param k The value (1–9) to validate for placement at BOARD[r][c].
  * @return `true` if `k` can be legally placed at the specified position; `false` otherwise.
  */
bool isValid(int** BOARD, const int& r, const int& c, const int& k);



/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  *
  * @brief Attempts to solve the Sudoku board using recursive backtracking.
  *
  * Recursively fills empty cells (denoted by 0) starting at position (r, c).
  * Advances through the board row by row, column by column. For each empty cell,
  * it tries values 1–9 and uses `isValid` to check legality. If a placement leads
  * to a dead end, it backtracks by resetting the cell to 0 and trying the next value.
  *
  * @param BOARD A pointer to the 9×9 Sudoku board (int**), where empty cells are 0.
  * @param r The current zero-based row index (0–8) to attempt filling.
  * @param c The current zero-based column index (0–8) to attempt filling.
  * @return `true` if the board is successfully solved; `false` if no valid configuration exists
  *    from this state.
  */
bool solveBoard(int** BOARD, const int& r=0, const int& c=0);

// ========================= Efficient Solutions ==========================


/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  *
  * @brief Finds the next empty cell that’s hardest to fill using the MRV heuristic.
  *
  * Scans all empty cells (value 0) on the 9×9 board, counts how many numbers (1–9)
  * can legally go in each via `isValid()`, and selects the cell with the fewest options.
  * If any cell has only one possible value, returns it immediately for efficiency.
  *
  * @param BOARD A 9×9 Sudoku board (int**), where empty cells are represented by 0.
  * @return A std::tuple<int, int, int> containing:
  *         - The row index (0–8) of the chosen cell, or -1 if none remain.
  *         - The column index (0–8) of the chosen cell, or -1 if none remain.
  *         - The count of valid options for that cell, or INT_MAX if the board is full.
  */

std::tuple<int, int, int> findNextCell(int** BOARD);


/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  *  @brief Solves the Sudoku board using recursive backtracking with the MRV heuristic.
  *
  * Uses `findNextCell()` to pick the empty cell with the fewest legal options (Minimum Remaining Value),
  * then attempts each valid number in turn. Recursively continues until the board is complete or no
  * solution is found, backtracking by resetting the cell to 0 on failure.
  *
  * @param BOARD A pointer to the 9×9 Sudoku board (int**), where empty cells are represented by 0.
  * @return `true` if the board is successfully solved; `false` if no valid completion exists.
  */
bool solveBoardEfficient(int** BOARD);

/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  * @brief Chooses and runs the Sudoku solver based on the efficiency flag.
  *
  * If `efficient` is true, uses the MRV‐based backtracking solver (`solveBoardEfficient`),
  * otherwise falls back to the basic row‐by‐row backtracking solver (`solveBoard`).
  *
  * @param board A pointer to the 9×9 Sudoku board (int**), where empty cells are 0.
  * @param efficient If true, uses the optimized solver; if false, uses the basic solver.
  * @return `true` if the board is successfully solved by the chosen algorithm; `false` otherwise.
  */
bool solve(int** board, const bool& efficient = false);

#endif //SUDOKUPROJECT_SUDOKU_H