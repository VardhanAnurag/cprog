// NxN tic-tac-toes
#include <iostream>
using namespace std;

// The following 3 functions are helper functions to convert
// between 1D and 2D array indices.  The grid itself is stored
// as a 1D array.  However, for printing, checking who won,
// etc. it may be easier to write loops that generate separate
// row/column indices (i.e. treating the array like a 2D array).
// The functions below should be written using the hints in the
// writeup for performing the appropriate arithmetic conversion
// between 1D- and 2D-indices, and can then be called in any
// of the other functions when you find yourself wanting to 
// convert one to the other.

/**
 * Helper function - Given the grid array and its dimension
 *    as well as a particular row (r) and column (c), this
 *    function performs the arithmetic to convert r and c
 *    to a 1D index and returns that character in the grid.
 *    For example, for dim = 3 and r = 2, c = 1, this function
 *    should compute the corresponding index: 7 and return
 *    grid[7].
 *
 * Use this function wherever you generate, row/column
 *    indices and want to access that element in the grid.
 *    Pass the row/column indices as r and c, respectively.
 *
 */
char getEntryAtRC(char grid[], int dim, int r, int c);

/**
 * Helper function - Given a 1D index returns the row
 * that corresponds to this 1D index.  Use this in
 * conjunction with idxToCol() anytime you have a 1D index
 * and want to convert to 2D indices.
 */
int idxToRow(int idx, int dim);

/**
 * Helper function - Given a 1D index returns the column
 * that corresponds to this 1D index.  Use this in
 * conjunction with idxToRow() anytime you have a 1D index
 * and want to convert to 2D indices.
 */
int idxToCol(int idx, int dim);


/** Should print the tic-tac-toe board in a nice grid
 *  format as shown below:
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O'
 *         (the letter oh), or '?'.
 */
void printTTT(char grid[], int dim);

/** 
 * Should check if any player has won the game yet.
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O', or '?'
 *
 * Return value:
 *   Should return 1 if 'X' has won, 2 if 'O' has won, or 0 (zero)
 *   if the game is still undecided.
 * 
 */
int checkForWinner(char grid[], int dim);


/** 
 * Should check if there is no possible way any player can win.
 * More specifically, if there does not exist a row, column,
 * or diagonal that can still have 3 of a kind, then the game
 * will be a draw.
 * 
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O', or '?'
 *
 * Return value:
 *   Return true if no player can win given the current 
 *   game state, false otherwise.
 */
bool checkForDraw(char grid[], int dim);
 

/**********************************************************
 *  Write your implementations for each function prototyped
 *  above in the space below
 **********************************************************/

char getEntryAtRC(char grid[], int dim, int r, int c)
{
    return grid[r*dim+c];
}

int idxToRow(int idx, int dim)
{
    return idx/dim;
}

int idxToCol(int idx, int dim)
{
    return idx % dim;
}

void printTTT(char grid[], int dim)
{
  for (int i = 0; i< dim*dim; i++)
  {
    if (i % dim == dim-1 && i!= dim*dim-1)
    {
      cout << grid[i] << endl;
      for (int j = 0; j< 2*dim-1; j++)
      {
        cout << '-';
      }
      cout << endl;
    }
    else if (i == dim*dim-1)
    {
      cout << grid[i] << endl;
    }
    else
    {
      cout << grid[i] << '|';
    }
  }
}

int checkForWinner(char grid[], int dim)
{
  static int* stuff = numberGrid(&grid[0], dim);
  int count[6] = {0, 0, 0, 0, 0, 0};
  string names[6] = {"Top Row", "Bottom Row", "Left Column", "Right Column", 
  "Downwards Diagonal", "Upwards Diagonal"}; 
  for (int i = 0; i< dim*dim; i++)
  {
    int r = idxToRow(i, dim);
    int c = idxToCol(i, dim);
    if (r == 0) // top row
    {
      count[0]+= *(stuff+i);
    }
    if (r == dim-1) // bottom row;
    {
      count[1] += *(stuff+i);
    }
    if (c == 0) //left column
    {
      count[2] += *(stuff+i);
    }
    if (c == dim-1) //right column
    {
      count[3] += *(stuff+i);
    }
    if (r == c) //downwards diagonal
    {
      count[4] += *(stuff+i);
    }
    if (r + c == dim-1) //upwards diagonal
    {
      count[5] += *(stuff+i);
    }
  }
  for (int it = 0; it< 6; it++)
  {
      if (count[it] == dim)
      {
        cout << "Player 'X' has won, " << names[it] << endl;
        return 1;
      } 
      if (count[it] == -dim)
      {
        cout << "Player 'O' has won, " << names[it] << endl;
        return -1;
      } 
  }
  return 0;
}

bool checkForDraw(char grid[], int dim)
{
}

int* numberGrid(char grid[], int dim)
{
  int size = dim*dim;
  static int numbers[121];
  for(int i = 0; i< size; i++)
  {
    if (grid[i] == 'X')
    {
      numbers[i] = 1;
    }
    else if (grid[i] == '?' )
    {
      numbers[i] = 0;
    }
    else
    {
      numbers[i] = -1;
    }
  }
  return &numbers[0];
}


/**********************************************************
 *  Complete the indicated parts of main(), below. 
 **********************************************************/
int main()
{
  // This array holds the actual board/grid of X and Os. It is sized 
  // for the biggest possible case (11x11), but you should only 
  // use dim^2 entries (i.e. if dim=3, only use 9 entries: 0 to 8)
  char tttdata[121];
    
  // dim stands for dimension and is the side length of the 
  // tic-tac-toe board i.e. dim x dim (3x3 or 5x5). 
  int dim;
  // Get the dimension from the user
  cout << "Please enter tic-tac-toe dimension: " << endl;
  cin >> dim;
    
  int dim_sq = dim*dim;

  for(int i=0; i < dim_sq; i++){
    tttdata[i] = '?';
  }

  // Print one of these messages when the game is over
  // and before you quit
  const char xwins_msg[] = "X player wins!";
  const char owins_msg[] = "O player wins!";
  const char draw_msg[] =  "Draw...game over!";
  const char roster[] = {'X', 'O'};

  bool done = false;
  int turn = 0;
  // Show the initial starting board
  printTTT(tttdata, dim);

  while(!done){

    //**********************************************************
    // Get the current player's input (i.e. the location they want to
    // choose to place their mark [X or O]) and update the tttdata array.
    // Be sure to follow the requirements defined in the guide/writeup
    // for quitting immediately if the user input is out-of-bounds 
    // (i.e. not in the range 0 to dim_sq-1) as well as continuing to 
    // prompt for an input if the user chooses locations that have already
    // been chosen (already marked with an X or O).
    //**********************************************************

    // Add your code here for getting input
    int pos;
    cout << "Player " << roster[turn] << " enter your square choice [0-" << dim*dim << "]: " << endl;
    cin >> pos;
    if (pos > dim*dim)
    {
      break;
    }
    char entry = getEntryAtRC(tttdata, dim, idxToRow(dim, pos), idxToCol(dim, pos));
    if (entry == 'X' || entry == 'O')
    {
      continue;
    }
    tttdata[pos] = roster[turn];
    // Show the updated board if the user eventually chose a valid location
    // (i.e. you should have quit the loop and program by now without any 
    //  other output message if the user chosen an out-of-bounds input).
    printTTT(tttdata, dim);
    //**********************************************************
    // Complete the body of the while loop to process the input that was just
    //  received to check for a winner or draw and update other status, as 
    //  needed. 
    // 
    // To match our automated checkers' expected output, you must output 
    // one of the messages defined above using *one* of the cout commands 
    // (under the appropriate condition) below:
    //   cout << xwins_msg << endl;  OR
    //   cout << owins_msg << endl;  OR
    //   cout << draw_msg << endl;
    //
    // Note: Our automated checkers will examine a specific number of lines
    //  at the end of the program's output and expect to see the updated board
    //  and game status message.  You may certainly add some debug print  
    //  statements during development but they will need to be removed to 
    //  pass the automated checks.
    //**********************************************************
    int winner = checkForWinner(tttdata, dim);
    if (winner == 1 || winner == -1) done = true;
    
    turn = 1-turn;






  } // end while
  return 0;
}