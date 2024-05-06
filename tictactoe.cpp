#include<iostream>
using namespace std;

bool win_game_row(char arr[3][3]){
	//Checks Horizontal Win
	for(int i=0;i<3;i++){
		bool res = true;
		char same = arr[i][0];
		if(same == '-'){
			continue; //This Row has empty spaces
		}
		for(int j=1;j<3;j++){
			if(arr[i][j] != same){
				res = false;
				break;
			}
		}
		if(res == true){
			return res;
		}
	}	
	return false;
}

bool win_game_col(char arr[3][3]){
	//Checks Vertical Win
	for(int i=0;i<3;i++){
		bool res = true;
		char same = arr[0][i];
		if(same == '-'){
			continue; //This Column has empty spaces
		}
		for(int j=1;j<3;j++){
			if(arr[j][i] != same){
				res = false;
				break;
			}
		}
		if(res == true){
			return res;
		}
	}	
	return false;
}

bool win_game_diag1(char arr[3][3]){
	//Checks Diagonal Win
	char same = arr[0][0];
	if(same == '-'){
		return false;
	}
	for(int i=1;i<3;i++){
		if(arr[i][i] != same){
			return false;
		}
	}
	return true;
}

bool win_game_diag2(char arr[3][3]){
	//Checks Diagonal Win
	char same = arr[0][2];
	if(same == '-'){
		return false;
	}
	for(int i=1;i<3;i++){
		if(arr[i][2-i] != same){
			return false;
		}
	}
	return true;
}

void display(char arr[3][3]){
	//Displays the complete board
	cout<<"\n";
	cout<<arr[0][0]<<" | "<<arr[0][1]<<" | "<<arr[0][2]<<endl;
	cout<<"---------\n";
	cout<<arr[1][0]<<" | "<<arr[1][1]<<" | "<<arr[1][2]<<endl;
	cout<<"---------\n";
	cout<<arr[2][0]<<" | "<<arr[2][1]<<" | "<<arr[2][2]<<endl;
}

bool completelyFilled(char arr[3][3]){
	bool res = true;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(arr[i][j] == '-'){
				res = false;
				return res;
			}
		}
	}
	return res;
}

void change(char arr[3][3],int row,int col,int turn){
	//Takes input from the user and changes the value at that position
	if(turn == 0){
		arr[row][col] = 'O';
	}
	else{
		arr[row][col] = 'X';
	}
}

bool filled(char arr[3][3],int row,int col){
	//Check whether the given position is already occupied or not
	return (arr[row][col] == 'X' || arr[row][col] == 'O');
}

int main(){
	begin: 
		char arr[3][3];
		fill_n(arr[0],3,'-');
		fill_n(arr[1],3,'-');
		fill_n(arr[2],3,'-');
		int turn = 1;
		string temp_turn = "a"; //Temporary variable to read input of turn from the user
		//Creating this will enable us to read all the characters without any segmentation fault
		
		cout<<"Player-1 will play with \'X\' \n"; //turn = 1
		cout<<"Player-2 will play with \'O\' \n"; //turn = 0
		cout<<"\n";
        cout<< "  1 | 2 | 3  " <<endl;;  
        cout<< "  ----------  " <<endl ;  
        cout<< "  4 | 5 | 6  " <<endl ;  
        cout<< "  ----------  "<<endl ;  
        cout<< "  7 | 8 | 9 " <<endl ;   
		cout<<endl;
		
		while(true){
			cout<<"Which Player will turn first (1 or 2): ";
			getline(cin,temp_turn);
	
			if(temp_turn == "1"){
				turn = 1; //0 represents Player-1 who plays with X
				break;
			}
			else if(temp_turn == "2"){
				turn = 0; //0 represents Player-2 who plays with O
				break;
			}
			else{
				cout<<"Wrong Input! Try Again\n\n";
			}
		}
		
		int row,col;
		while(true){
			while(true){ //Checking whether the place is already filled or not
				cout<<"\nEnter a row number (1 or 2 or 3): ";
				cin>>row;
				cout<<"Enter a column number (1 or 2 or 3): ";
				cin>>col;
				if(row<=0 || row>=4){
					cout<<"Invalid Row Number Input! Try Again\n";
				}
				else if(col<=0 || col>=4){
					cout<<"Invalid Column Number Input! Try Again\n";
				}
				else if(filled(arr,row-1,col-1)){
					cout<<"Place Already Filled! Try Again\n";
				}
				else{
					break;
				}
			}
			change(arr,row-1,col-1,turn); //Passing Player Input to TIC-TAC-TOE Board
			display(arr); //Displaying TIC-TAC-TOE Board
			if(win_game_col(arr) || win_game_row(arr) || win_game_diag1(arr) || win_game_diag2(arr)){
				cout<<(turn==0?"Player-2 won the game!\n":"Player-1 won the game!\n");
				break;
			}
			if(completelyFilled(arr)){
				cout<<"\n****It's a tie!!****\n";
				cout<<"Board has been completely filled\n";
				break;
			}
			turn = (turn+1)%2;
		}
		string choice;
		cout<<"\n\nDo you want to play again? (y/n) ";
		cout<<"\nPress any other key to exit: ";
		getline(cin,choice);
		getline(cin,choice);
		if(choice=="y"){
			cout<<endl;
			goto begin;	
		}
}