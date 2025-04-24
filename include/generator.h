/**
* @file generator.h
 * @brief Function prototypes for generating random solvable Sudoku boards.
 *
 * This header defines functions to:
 * - Create empty Sudoku boards.
 * - Fill independent diagonal boxes.
 * - Solve and generate a complete Sudoku board.
 * - Randomly delete cells to create a solvable puzzle.
 * - Generate a complete Sudoku puzzle with a specific number of empty cells.
 *
 * Detailed function descriptions and parameters are provided below.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>




/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  *
  * @brief Creates and returns a new empty 9×9 Sudoku board.
  *
  * Dynamically allocates a 9×9 grid of integers on the heap and
  * initializes every cell to 0, representing an empty Sudoku board.
  *
  * @return A pointer to the newly allocated 2D array (int**), where
  *         each of the 9 rows points to an array of 9 integers.
  */

int** getEmptyBoard();





/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  * @brief Generates a randomized sequence of the digits 1 through 9.
  *
  * Constructs a std::vector containing the values 1 to 9 in ascending order,
  * then uses std::shuffle with a std::mt19937 engine seeded by std::random_device
  * to produce a random permutation.
  *
  * @return A std::vector<int> of length 9, containing the numbers 1–9 in shuffled order.
  */

std::vector<int> getShuffledVector();



/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  *@brief Populates the three diagonal 3×3 subgrids of the Sudoku board with random numbers.
  *
  * Targets the independent boxes at positions (0,0), (3,3), and (6,6) on the 9×9 board.
  * For each diagonal box, it generates a shuffled sequence of 1–9 and fills the 3×3 cell block
  * All other cells in the board remain unchanged.
  *
  * @param BOARD A pointer to the 9×9 Sudoku board (int**), already allocated and initialized.
  *
  */
void fillBoardWithIndependentBox(int** BOARD);


/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  *
  *@brief Removes a specified number of entries from the Sudoku board at random.
  *
  * Validates the board pointer and the requested count, then selects `n` unique
  * filled cells uniformly at random and sets them to 0 to create the puzzle.
  * Ensures each selected cell is only cleared once.
  *
  * @param BOARD A pointer to the 9×9 Sudoku board (int**). Must be non-null.
  * @param n The number of cells to delete; must be between 1 and 81 inclusive.
  */
void deleteRandomItems(int** BOARD, const int& n);


/**
  * @brief Generates a complete and playable Sudoku puzzle board.
  *
  * Initializes an empty 9×9 board, fills the three diagonal 3×3 subgrids,
  * solves the full board to produce a valid completed puzzle, then removes
  * the specified number of cells to create the final playable puzzle.
  *
  * @param empty_boxes The number of cells to clear (set to 0) in the completed board; must be between 1 and 81.
  * @return A pointer to the dynamically allocated 9×9 Sudoku board (int**), containing a solvable puzzle.
  */
int** generateBoard(const int& empty_boxes);
#endif // GENERATOR_H
