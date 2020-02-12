#include <iostream>
#include <vector>
#include <utility>      // std::pair

struct node{
  int value;        // if value=0 healthy ，value=-1 border , 1 is infected   
  bool isChecked=false;   // checked or not

  node () {};
  node (int v) : value (v) {}    
};

class Pos{
  int x, y;
  public:
    Pos(){};
    Pos(int xValue, int yValue) : x(xValue), y(yValue) { } // default constructor
    int get_x(){
      return x;
    } 
    int get_y(){
      return y;
    } 
    void setValues(int xValue, int yValue){
      x = xValue;
      y = yValue;
    }
};

// Define 8 direction moves
std::vector<Pos> move(9, Pos());
void InitMove(){
  move[0].setValues(0, 0); //  origin
  move[1].setValues(1, 0); //  E
  move[2].setValues(1, 1); //  S-E
  move[3].setValues(0, 1); //  S
  move[4].setValues(-1, 1); //  S-W
  move[5].setValues(-1, 0); //  W
  move[6].setValues(-1, -1);; //  N-W
  move[7].setValues(0, -1); //  N
  move[8].setValues(1, -1); //  N-E
}

// Initialize the board 
std::vector<std::vector<node>> board(8, std::vector<node>(8, node()));
void InitBoard(std::vector<std::pair<int,int>>& infectedCells){
  for(int i=0; i<board.size(); i++){
    for(int j=0; j<board[0].size(); j++){
      // wall
      if(i == 0 || i == board.size()-1 || j == 0 || j == board[0].size()-1){
        board[i][j].value = -1;
      }else{
        board[i][j].value = 0;
      }
    }
  }

  // infected cells
  for(int i=0; i<infectedCells.size(); i++){
    board[infectedCells[i].first][infectedCells[i].second].value = 1;
  }
}

void checkInfection(int x, int y){
  if(board[x][y].value == -1 || board[x][y].value == 0 || board[x][y].isChecked == true){
    return;
  }
  board[x][y].isChecked = true;
  for(int i=0; i<move.size(); i++){
    if(x+move[i].get_x() >= 0 && x+move[i].get_x() < 8){
      if(y+move[i].get_y() >= 0 && y+move[i].get_y() < 8){  
        checkInfection(x+move[i].get_x(), y+move[i].get_y());
      }
    }
  }
}

void printInitBoard(){
  for(int i=0; i<board.size(); i++){
    for(int j=0; j<board[0].size(); j++){
      std::cout << board[i][j].value << '\t';
    }
    std::cout << '\n';
  }
}

void printInfectedBoard(){
  for(int i=0; i<board.size(); i++){
    for(int j=0; j<board[0].size(); j++){
      if(board[i][j].value == 1 && board[i][j].isChecked == true){
        std::cout << 2 << '\t';
      }else{
        std::cout << board[i][j].value << '\t';
      }
    }
    std::cout << '\n';
  }
}

int main(){
  std::vector<std::pair<int, int>> infectedCells{std::make_pair(1,1), std::make_pair(2,2), std::make_pair(3,3),
                                                 std::make_pair(3,4), std::make_pair(3,6), std::make_pair(4,4),
                                                 std::make_pair(4,3), std::make_pair(4,6), std::make_pair(5,1),
                                                 std::make_pair(5,3), std::make_pair(5,4), std::make_pair(5,6),
                                                 std::make_pair(6,1)};
  InitMove();    // Initialize move directions
  InitBoard(infectedCells); // Initialize infected cells
  printInitBoard(); // print initialized board
  
  std::cout << "-------------------------------------------\n";
  std::cout << "After Check\n";
  checkInfection(1,1);
  printInfectedBoard();

  return 0;
}
