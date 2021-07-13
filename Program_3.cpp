#include<iostream>
#include<vector>

#define MAX_ADJACENT 8
using namespace std;

bool is_valid(int row, int col,int r,int c) { 
    return (row >= 0) && (row < r) && (col >= 0) && (col < c); 
}

bool is_mine (int row, int col,const vector<vector<char>> &board) { 
    if (board[row][col] == 'M') 
        return true; 
    
    return false; 
} 

int count_adjacent_mines(int row, int col, const vector<vector<char>> &real_board){

	int row_delta[MAX_ADJACENT] = {-1,-1,-1,0,0,1,1,1};
	int col_delta[MAX_ADJACENT] = {-1,0,1,-1,1,-1,0,1};
	int count = 0;

	for(int i = 0;i < MAX_ADJACENT;i ++ ){

		int new_row = row + row_delta[i];
        int new_col = col + col_delta[i];

		if(is_valid(new_row,new_col,real_board.size(),real_board[0].size()))
			if(is_mine(new_row,new_col,real_board))
				count++;
	}
	return count;
}

void print_board(const vector<vector<char>> &my_board) {
    for (int row = 0; row < my_board.size(); row++) {
        for (int col = 0; col < my_board[0].size(); col++)
            cout << my_board[row][col];
        cout << endl;
    }
}

bool play_minesweeper(int row, int col,vector<vector<char>> &my_board, const vector<vector<char>> &real_board ) { 
  
     if (my_board[row][col] != '*') 
         return false; 
  
    int count = count_adjacent_mines(row,col,real_board); 
    my_board[row][col] = count + '0'; 
  
    if (!count) { 

    	int row_delta[MAX_ADJACENT] = {-1,-1,-1,0,0,1,1,1};
	    int col_delta[MAX_ADJACENT] = {-1,0,1,-1,1,-1,0,1};
	    int r = sizeof(real_board) / sizeof(real_board[0]);

    	for(int i = 0;i < MAX_ADJACENT;i ++ ){
		int new_row = row + row_delta[i];
        int new_col = col + col_delta[i];
        // print_board(my_board);

		if(is_valid(new_row,new_col,real_board.size(),real_board[0].size()))
			if(is_mine(row,col,real_board) == false)
				play_minesweeper(new_row,new_col,my_board,real_board);
				
		}
    } 
  
    return false; 
     
}

int main(){
	int x,y,r,c;
	do{cin>>r>>c>>x>>y;}
	while(r <= 0 || c <= 0 || x <= 0 || y <= 0);
	vector<vector<char>> real_board(r,vector<char>(c));
	vector<vector<char>> my_board(r,vector<char>(c,'*'));


	// TRY TO IMPLEMENT CORRECTELY
	for(int i = 0;i < r;i ++){
		for(int j = 0;j < c;j ++){
			cin>> real_board[i][j];
		}
	}
	play_minesweeper(y - 1,x - 1,my_board,real_board);
    print_board(my_board);


}


