// Chess 
#include "Chess.h"
#include "Board.h"

int main()
{
	//string board = "R######R################################################r######r"; 
	Board real_board;
	string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"; 
//	string board = "##########K###############################R#############r#r#####";
	Chess a(board);
	int codeResponse = 0;
	string res = a.getInput();
	while (res != "exit")
	{


		/**/ 
		{ // put your code here instead that code
			codeResponse=real_board.move(res[0] - 'a'  , res[1] - '0', res[2] - 'a',  res[3] - '0');
			cout <<  codeResponse << endl;
		}
		/**/
		a.setCodeResponse(codeResponse);
		res = a.getInput(); 
	}

	cout << endl << "Exiting " << endl; 
	return 0;
}