# CS2 Semester Project: Sudoku Puzzle Generator and Solver

## Overview

As part of our CS 2 semester project, we implemented a Sudoku puzzle generator/solver. The main idea about the project was to generate valid Sudoku problem grids, erasing numbers selectively to create solvable puzzles of varied difficulty, and to solve the puzzles with two different algorithms — a simple backtracking solver and an improved solver utilizing the Minimum Remaining Value (MRV) heuristic to always choose the empty cell with the lowest number of possible valid numbers, in an effort to lower the number of incorrect guesses and solve faster. Both algorithms, simple backtracking and MRV solver were used to solve sudoku puzzles of different difficulty and were compared with each other by computing the average time elapsed for 1 solution. To our surprise, the time elapsed was more for the efficient solver than the simple solver and the reason behind it is revealed later in the report. The entire project also features two different operational modes: DEBUG and non-DEBUG, each designed for specific testing and execution environments.

One of the major challenges faced during development was understanding and implementing the efficient solver algorithm. Even though we implemented the efficient solver by simply following the given To Dos, we had hard time understanding the actual logic behind this algorithm but finally we have understood after proper research.

Even though the overall project structure was given to us, we had to complete the basic logic and ensure everything integrated with each other as required. This project helped us practice key programming concepts like recursion, backtracking, modular design, and optimization. It also gave us valuable experience in applying the foundational topics we learned during the semester to a larger real-world coding project. Additionally, we learned how to use CLion and its different features, specially the DEBUG mode- how we can check the flow or correctness of the program/algorithm without compiling the whole program, which we believe is going to be very useful in the future.

The collaborative aspect of the project enhanced our ability to work in a team with each of us being tasked with various modules like puzzle generation, input/output, and solver logic. Overall, this project was a valuable learning experience that helped us strengthen our understanding of key C++ concepts like recursion, memory management, and file handling, while also showing us how to apply coding skills to real-world problem solving.

## Flowchart for Sudoku Solver Execution (Non-DEBUG Mode)

```text
main()
│
├── initDataFolder()
│   ├── createFolder("data/")
│   │   └── if “data/” doesn’t exist → filesystem::create_directories("data/")
│   ├── createFolder("data/puzzles/")
│   └── createFolder("data/solutions/")
│
├── createAndSaveNPuzzles(NUM_PUZZLE_TO_GENERATE, COMPLEXITY_EMPTY_BOXES, PATH_TO_PUZZLES, PUZZLE_PREFIX)
│   │
│   └── Loop i = 0 … NUM_PUZZLE_TO_GENERATE − 1
│       │
│       ├── generateBoard(COMPLEXITY_EMPTY_BOXES)
│       │   │
│       │   ├── getEmptyBoard()
│       │   │   ├── Allocate `int** BOARD = new int*[9]`
│       │   │   ├── For row = 0 … 8:
│       │   │   │   ├── BOARD[row] = new int[9]
│       │   │   │   └── For col = 0 … 8: BOARD[row][col] = 0
│       │   │   └── return BOARD
│       │   │
│       │   ├── fillBoardWithIndependentBox(BOARD)
│       │   │   ├── fillDiagonalMatrix(BOARD,0,0)
│       │   │   │   ├──for k = 0 → 6 step 3
|       |   |   |   |  |
|       |   |   |   |  |─ v = getShuffledVector()
|       |   |   |   |  |      |
|       |   |   |   |  |      |- vector v = 1 to 9       
|       |   |   |   |  |      |- random device g       
|       |   |   |   |  |      |- shuffle(v.begin(),v.end(),g)
|       |   |   |   |  |      |- return v 
|       |   |   |   |  |           
|       |   |   |   |  |-- for i = 0 → 2
|       |   |   |   |  |   └─ for j = 0 → 2
|       |   |   |   |  |      └─ BOARD[i+k][j+k] = v.back(); v.pop_back()
|       |   |   |   |
|       |   |   |   |---return BOARD
│       │   │   └── return BOARD
│       │   │
│       │   ├── solveBoard(BOARD, 0, 0)
│       │   │   └── Recursive backtracking:
│       │   │       • If r == 9 → return true
│       │   │       • Else if c == 9 → return solveBoard(BOARD, r + 1, 0)
│       │   │       • Else if BOARD[r][c] ≠ 0 → return solveBoard(BOARD, r, c + 1)
│       │   │       • Else:
│       │   │           – For k = 1…9:
│       │   │               * isValid(BOARD, r, c, k)?
│       │   │                   ├─ Check row i=0…8: if BOARD[r][i] == k → false
│       │   │                   ├─ Check col i=0…8: if BOARD[i][c] == k → false
│       │   │                   ├─ startRow = 3*(r/3), startCol = 3*(c/3)
│       │   │                   └─ Check subgrid rows startRow…+2, cols startCol…+2:
│       │   │                       if any == k → false
│       │   │                   └─ else → true
│       │   │               * If valid:
│       │   │                   – BOARD[r][c] = k
│       │   │                   – If solveBoard(BOARD, r, c + 1) → return true
│       │   │                   – Else → BOARD[r][c] = 0  ← backtrack
│       │   │           – End for
│       │   │       • Return false  ← no k works, backtrack
│       │   │
│       │   └── deleteRandomItems(BOARD, COMPLEXITY_EMPTY_BOXES)
│       │       │
|       |       |─ if (BOARD == nullptr OR n < 1 OR n > 81)
│       |       |     └─ return
│       |       |
|       |       |─ rd   = random_device()
|       |       |─ gen  = mt19937(rd)
|       |       |─ dist = uniform_int_distribution(0, 8)
│       |       |
|       |       |─ remaining = n
│       |       |
|       |       |─ while (remaining > 0)
|       |       |   │
|       |       |   ├─ row = dist(gen)
|       |       |   ├─ col = dist(gen)
|       |       |   │
|       |       |   ├─ if (BOARD[row][col] != 0)
|       |       |   │     ├─ BOARD[row][col] = 0
|       |       |   │     └─ remaining--
|       |       |   │
|       |       |   └─ else
|       |       |         (loop continues)
│       │
│       ├── filename = getFileName(i, PATH_TO_PUZZLES, PUZZLE_PREFIX)
│       │   ├── idx = to_string(i)
│       │   ├── pad = string(4−idx.length(), '0')
│       │   └── filename = destination + pad + idx + prefix + ".txt"
│       │
│       ├── writeSudokuToFile(BOARD, filename)
│       │   ├── ofstream fout(filename)
│       │   ├── For r = 0…8:
│       │   │   ├── For c = 0…8:
│       │   │   │   ├── If BOARD[r][c]==0 → fout<<'-'
│       │   │   │   └── Else → fout<<BOARD[r][c]
│       │   │   └── fout<<'\n'
│       │   └── fout.close()
│       │
│       └── deallocateBoard(BOARD)
│           ├── For row = 0…8: delete[] BOARD[row]
│           └── delete[] BOARD
│
├── solveAndSaveNPuzzles(NUM_PUZZLE_TO_GENERATE, PATH_TO_PUZZLES, PATH_TO_SOLUTIONS, SOLUTION_PREFIX)
│   │
│   ├── path_list = getAllSudokuInFolder(PATH_TO_PUZZLES)
│   │   ├── vector<string> sudokus
│   │   ├── For each entry in filesystem::directory_iterator(folderPath):
│   │   │   └── If entry.is_regular_file(): sudokus.push_back(entry.path().string())
│   │   ├── print sudokus.size() & list
│   │   └── return sudokus
│   │
│   └── Loop i = 0 … path_list.size() − 1
│       │
│       ├── sudoku = readSudokuFromFile(path_list[i])
│       │   ├── Allocate `int** BOARD = new int*[9]`, vector<int> numbers
│       │   ├── Read file into string s
│       │   ├── replaceCharacter(s, '-', '0'):
│       │   │   └── For each char in s: if char=='-' → char='0'
│       │   ├── extractNumbers(s, numbers):
│       │   │   └── For each char in s: if isdigit → numbers.push_back(char−'0')
│       │   ├── fillBoard(numbers, BOARD):
│       │   │   └── For idx=0…80: r=idx/9, c=idx%9; BOARD[r][c]=numbers[idx]
│       │   └── return BOARD
│       │
│       ├── if solve(sudoku, false)  ← calls solveBoard(BOARD, 0, 0) as above
│       │
│       ├── if checkIfSolutionIsValid(sudoku)
│       │   ├── For r=0…8: ensure each 1…9 appears once in row
│       │   ├── For c=0…8: ensure each 1…9 appears once in column
│       │   └── For each subgrid origin (0,0),(0,3),…:
│       │       └── ensure each 1…9 appears once in 3×3 block
│       │
│       ├── filename = getFileName(i, PATH_TO_SOLUTIONS, SOLUTION_PREFIX)
│       ├── writeSudokuToFile(sudoku, filename)  (as above)
│       └── deallocateBoard(sudoku)
│
├── compareSudokuSolvers(experiment_size, COMPLEXITY_EMPTY_BOXES)
│   │
│   └── Loop t = 1 … experiment_size
│   |   │
│   |   ├── board1 = generateBoard(COMPLEXITY_EMPTY_BOXES)  (as above)
│   |   ├── board2 = deepCopyBoard(board1)
│   |   │   ├── Allocate `int** B2 = new int*[9]`
│   |   │   ├── For r=0…8: B2[r]=new int[9]; For c=0…8: B2[r][c]=board1[r][c]
│   |   │   └── return B2
│   |   │
│   |   ├── start timer
│   |   ├── solvedEff = solve(board1, true)
│   |   │   └── solve() → solveBoardEfficient(BOARD)
│   |   │       ├── findNextCell(BOARD)
│   |   │       │   ├── bestOpts=10, bestR=bestC=-1
│   |   │       │   ├── For r=0…8, c=0…8 if BOARD[r][c]==0:
│   |   │       │   │   └── count valid k by isValid()
│   |   │       │   └── return (bestR, bestC, bestOpts) or (-1,-1,0)
├   |   |       |-─ if (row == -1)
│   |   |       |   └─ return true
│   |   |       |
├   |   |       |-─ for k = 1 → 9
│   |   |       |   │
│   |   |       |   ├─ if isValid(BOARD, row, col, k)
│   |   |       |   │   ├─ BOARD[row][col] = k
│   |   |       |   │   ├─ if solveBoardEfficient(BOARD)
│   |   |       |   │   │   └─ return true
│   |   |       |   │   └─ else BOARD[row][col] = 0
│   |   |       |
└   |   |       |-─ return false       
|   |   ├── stop timer → accumulate efficient stats
│   |   │
│   |   ├── start timer
│   |   ├── solvedBasic = solve(board2, false)
│   |   │   └── solve() → solveBoard(BOARD, 0, 0) (basic backtracking as above)
│   |   ├── stop timer → accumulate basic stats
│   |   │
│   |   ├── deallocateBoard(board1)
│   |   └── deallocateBoard(board2)
│   │
│   └── print average timings & success counts
│
└── return 0
```

## Contribution by Group Members

- **Yugesh** focused mainly on working in `.cpp` files (except for `generator.cpp`), solving logic for efficient solver at initial phase. He also developed the flowchart and helped write the answers for the report.
- **Ritiz** worked on implementing the board generation functions (`generator.cpp`) and helped with testing the generated puzzles for correctness.
- **Aashish** was responsible for organising the project work, guiding task distribution, and preparing the project report. He also contributed by working on solver testing and performance comparison using both the basic and efficient solving methods.
- **Abhinav** debugged the whole program after the `.cpp` files were complete, handled all errors and made sure there were none. He also worked on all the `.h` header files.

All four of us worked together to complete this project. We shared ideas, discussed our individual parts, and helped review and organize the report to make sure it clearly reflected our work. Everyone was involved in each other’s tasks and contributed their thought process even though the tasks were divided.

## Closing Thoughts

The project experience is really going to be one of the memorable ones. Even though we participated in it for a short time, we learned several things from technical aspects like dynamic memory allocation, recursion, and backtracking to social aspects like teamwork. It helped us understand the importance of time management and working in a team. The project got little intimidation at times, but this was a good learning experience and really tested our skills. It also helped us understand the topics we need to work on if we want to successfully carry out larger projects in the future. The project as a whole provides good practice to implement the topics we learned in our CS2 class. 

Finally, this project has helped to build a team, and we plan to work on more projects together in the future. We would like to thank **Prof. Dr. Keshav Bhandari** and **TA Syed Tousiful Haque** for this engaging opportunity to learn and grow in a team.
