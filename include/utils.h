/**
 * @file utils.h
 * @brief Utility functions for Sudoku board management and file system operations.
 *
 * This header file provides utility functions to:
 * - Allocate and deallocate dynamic Sudoku boards.
 * - Manage folders for storing Sudoku puzzles and solutions.
 * - Generate formatted filenames for Sudoku puzzles.
 *
 * These utilities are designed to support file I/O operations, board memory management,
 * and folder structure initialization for Sudoku puzzle generation and solving projects.
 *
 * @date
 * February 8, 2025
 */

#ifndef SUDOKUPROJECT_UTILITY_H
#define SUDOKUPROJECT_UTILITY_H

#include <string>
using namespace std;

/**
  * @brief Deallocates memory for a dynamically allocated 2D Sudoku board.
  *
  * Safely frees each row array and then the array of row pointers.
  * After deletion, sets the BOARD pointer to nullptr to prevent dangling references.
  *
  * @param BOARD Pointer to the dynamically allocated 2D board (int**). Must be non-null.
  * @param rows  The number of rows in the board (typically 9 for a standard sudoku).
  */
void deallocateBoard(int** BOARD, const int& rows = 9);

/**
 * @brief Creates a folder at the specified path if it does not exist.
 *
 * Checks if the folder already exists and creates it if it doesn't. Logs
 * success or failure messages to the console.
 *
 * @param folderPath The path where the folder should be created.
 */
void createFolder(const string& folderPath);

/**
 * @brief Initializes the folder structure for Sudoku data storage.
 *
 * Creates a base `data/` directory along with `data/puzzles/` and
 * `data/solutions/` subdirectories for storing generated puzzles and their solutions.
 */
void initDataFolder();

/**
 * @brief Generates a formatted filename with zero-padded index.
 *
 * Constructs a filename using a zero-padded index, a destination path, and a prefix.
 * The filename follows the pattern: `destination/XXXXprefix.txt`, where `XXXX` is the
 * zero-padded index (e.g., `0001puzzle.txt`).
 *
 * @param index The numerical index to include in the filename.
 * @param destination The directory where the file will be saved.
 * @param prefix The filename prefix (e.g., "puzzle" or "solution").
 * @return A formatted string representing the complete file path.
 */
string getFileName(const int& index, const string& destination, const string& prefix);

#endif //SUDOKUPROJECT_UTILITY_H
