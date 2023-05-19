void sudoku_v1();
void sudoku_v2();
void sudoku_v3();
void sudoku_final();

//Stylization Function
void line();
void line1();
void verticalBorder();
void grid(int j);
void grid1(int j);

// Functions for version 2
void randomPreset(int sudokuBlock[3][3]);
void sudokuGrid(int sudokuBlock[3][3]);
void partialSudokuBlock(int sudokuBlock[3][3]);
void userInput(int sudokuBlock[3][3]);
void completeSudokuBlock(int sudokuBlock[3][3]);
void removeFill(int sudokuBlock[3][3]);

// Functions for version 3
void randomPreset1(int result[]);
void randomPosition(int result[], int sudokuBlock[3][3]);
void printSudokuBlock(int sudokuBlock[3][3], int row, int col);
void replaceZerosWithInputs(int sudokuBlock[3][3], int input[3]);
void userInput1(int sudokuBlock[3][3]);
void printTimeTaken(time_t start, time_t end);

// Functions for the final version
void printPositionBlock();
void userInput2(int sudokuBlock[3][3]);
