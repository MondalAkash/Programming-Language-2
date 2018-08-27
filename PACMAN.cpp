/********************************************************
               HEADERFILES USED IN PROJECT
/********************************************************/
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <conio.h>
using namespace std;   /**Standerd Namespace*/
char tmp_map[25][51];  /**2D Array*/
char map[25][51] = {                                   /**map*/
	"|***********************************************|",
	"|         |                    |                |",
	"|+++  +++      +=+=+=+=+=+=+        +++ +++     |",
	"|         _-_#                #_-_           _-_|",
	"|  ====   #    +=+=+=+=+=+=+      #   ====      |",
	"|                                               |",
	"|+++  +++ |     _-_-_-_-_      |    +++  +++    |",
	"|                                               |",
	"|  +  +++      =+=+=+=+=+=+=        +++  +++    |",
	"|        #_-_                 #_-_           _-_|",
	"|  ====     #  +=+=+=+=+=+=+      #   ====      |",
	"|+++  ++             |              +++  +++    |",
	"|          |                    |               |",
	"|  +  +++      =+=+=+=+=+=+=        +++  +++    |",
	"|         #_-_                #_-_           _-_|",
	"|  ====     #  +=+=+=+=+=+=+       #   ====     |",
	"|+++  ++             |               +++  +++   |",
	"|          |                    |               |",
	"|  +  +++      =+=+=+=+=+=+=        +++  +++    |",
	"|         #_-_                #_-_           _-_|",
	"|  ====      # +=+=+=+=+=+=+      #   ====      |",
	"|                                               |",
	"|***********************************************|"
	};

void Map()         /**For Showing Map*/
{
	for(int q = 0; q < 25; q++) {
		cout<<map[q]<<endl;
	}
}

void gotoxy( short int x, short int y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;                    /**My Position*/

    SetConsoleCursorPosition( hStdout, position ) ; /**Enemy Position*/
}


struct Walk {          /**Structure Named WALK*/
	short int walk_count;
	short int x;
	short int y;
	short int b1;
};

struct Target {     /**Structure Named TARGET*/
	short int x;
	short int y;
};

vector<Target> walk_queue; /**Vector Next Position*/

vector<Walk> Barr;  /**Vector Current Position & Count*/

void AddArray( int x, int y, int wc , int b1 ){    /**To Count Position*/
	if( tmp_map[y][x] == ' ' || tmp_map[y][x] == '.' ){
		tmp_map[y][x] = '+';
		Walk tmp;   /**Structure Variable*/
		tmp.x = x;  /**Variable Calling Throw Structure Variable*/
		tmp.y = y;  /**Variable Calling Throw Structure Variable*/
		tmp.walk_count = wc;/**Variable Calling Throw Structure Variable*/
		tmp.b1 = b1; /**Variable Calling Throw Structure Variable*/
		Barr.push_back( tmp );/**Push Back Function From Vector*/
	}
}

void FindPath( int sx, int sy, int x, int y ){ /**Move According To Direction*/
	memcpy( tmp_map, map, sizeof(map) );  /**Copies the values of Map bytes from the location pointed to by Source Map
	                                       directly to the memory block pointed to by Temp_MAp.*/
    Barr.clear();/**To Avoid Map Overlaping*/
	Walk tmp;   /**Structure Variable*/
	tmp.x = sx;/**Variable Calling Throw Structure Variable*/
	tmp.y = sy;/**Variable Calling Throw Structure Variable*/
	tmp.walk_count =0; /**Variable Calling Throw Structure Variable*/
	tmp.b1 ;
	Barr.push_back( tmp );

	int i = 0;
	while( i < Barr.size() ){
		if( Barr[i].x == x && Barr[i].y == y ){
			walk_queue.clear(); /**Clear Memory*/
			Target tmp2;
			while( Barr[i].walk_count != 0 ){
				tmp2.x = Barr[i].x;
				tmp2.y = Barr[i].y;
				walk_queue.push_back( tmp2 );

				i = Barr[i].b1;
			}

			break;
		}

		AddArray( Barr[i].x+1, Barr[i].y, Barr[i].walk_count+1, i );/**Position chng*/
		AddArray( Barr[i].x-1, Barr[i].y, Barr[i].walk_count+1, i );/**Position chng*/
		AddArray( Barr[i].x, Barr[i].y+1, Barr[i].walk_count+1, i );/**Position chng*/
		AddArray( Barr[i].x, Barr[i].y-1, Barr[i].walk_count+1, i );/**Position chng*/
		i++;
	}

	Barr.clear(); /**Clear Array*/
}


int main()
{
    bool run = true;
	int x = 15; /**My Position*/
	int y = 16; /**My POsition*/
	int old_x;
	int old_y;
    int ex = 1; /**Enemy Position*/
	int ey = 1; /**Enemy Position*/
    int points = 0;
	char d;
	int spm;
	system("color 0a");
 cout<<"\n\t\t\t\t"<<"      PACMAN \n\n";
 cout<<"\n\n\n\t\t\t\tPlease wait while loading\n\n";
 char a=177, b=219;
 cout<<"\t\t\t\t";
 for (int i=0;i<=23;i++)
 cout<<a;
 cout<<"\r";
 cout<<"\t\t\t\t";
 for (int i=0;i<=23;i++)
 {
  cout<<b;
  for (int j=0;j<=1e8;j++);
 }
 cout<<endl;
 system("cls");
    cout<<"\t\t\tWELCOME TO OUR PROJECT"<<endl<<endl;
    cout<<"Group Members: "<<endl<<"\n\t1.Akash Mondal"<<endl<<"\t2.Noushin Jannat"<<endl<<"\t3.M.Tanzeeb Rubaiat Haque"<<endl<<endl;
    cout<<"\nSubmitted To:\n\tMD HASIBUL HASAN\n\tDept. Of CSE\n\tAIUB"<<endl;
    cout<<"\n\t\t\tProject Topic: PACMAN"<<endl;
    char c;
    cout<<"\n\nPress <I> To See The Instructions Of The Game"<<endl<<endl<<"Input: ";
    cin>>c;
    if(c=='i'||c=='I')
    {
        system("cls");
        cout<<"Instructions To Play This Game: "<<endl<<endl<<endl;
        cout<<"\t\t1. Press Arrow Keys To Move Your Object\n\n\n\t\t2. Eat The Dots Produced By The Enemy To Gain Poins\n\n\n\t\t3. Don't Get Caught By The Enemy\n\n"<<endl;
    }
    char l;
    cout<<"Press <L> To Select The Difficulties Of The Game"<<endl<<endl<<"Input: ";
    cin>>l;
    if(l=='l'||l=='L')
    {
        system("cls");
        cout<<"Difficulties:\n\n\tE -> Easy\n\n\tN -> Normal\n\n\tH -> Hard\n\nInput : ";
    }

	cin >> d;

	if( d == 'N'||d=='n' ){
		spm = 2;
	}else if( d == 'H'||d=='h' ){
		spm = 1;
	}
	else if (d=='e'||d=='E')
    {
        spm=3;
    }
    else{
        cout<<"You Entered Wrong Keyword"<<endl;

    }
    system("cls");
    Map();
    gotoxy(x,y);cout<<"$";

	int frm = 0;

	FindPath( ex,ey,x,y );

	while( run ){
		gotoxy( x, y ); cout << " ";

		old_x = x; /**Replace New Value*/
		old_y = y; /**Replace New Value*/

		if ( GetAsyncKeyState( VK_UP ) ){
			if( map[y-1][x] == '.' ){ y--; points++; } else
			if( map[y-1][x] == ' ' ) y--;
		}
		if ( GetAsyncKeyState( VK_DOWN ) ){
			if( map[y+1][x] == '.' ){ y++; points++; } else
			if( map[y+1][x] == ' ' ) y++;
		}
		if ( GetAsyncKeyState( VK_LEFT ) ){
			if( map[y][x-1] == '.' ){ x--; points++; } else
			if( map[y][x-1] == ' ' ) x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) ){
			if( map[y][x+1] == '.' ){ x++; points++; } else
			if( map[y][x+1] == ' ' ) x++;
		}

		if( old_x != x || old_y != y ){
			FindPath( ex,ey,x,y );
		}


    gotoxy( x,y ); cout << "$";
		map[ey][ex] = '.';
		gotoxy( ex, ey ); cout << ".";

		if( frm%spm == 0 && walk_queue.size() != 0 ){
			ex = walk_queue.back().x;
			ey = walk_queue.back().y;
			walk_queue.pop_back();
		}

		gotoxy( ex, ey ); cout << "@";

		if( ex == x && ey == y ){
                cout<<"\a";
			break;
		}

        gotoxy(51,25);
		gotoxy( 51, 12 ); cout <<"Score: "<< points;
		Sleep( 100 );
		frm++;
	}

	system("cls");
	cout<<"You Lose and Your Score Is : "<<points<<"\tLevel: ";
	cin.get();
	cin.get();
	getch();
	system("cls");
	cout<<"\n\n\nThank You For Enjoying Our Game!! ^_^ \a"<<endl<<endl<<endl;
    cin.get();
    cin.get();
	return 0;
}
/**Some Functions Are Copied From Websites & The Links Are Given Below:

/**void gotoxy( short int x, short int y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ; //
    COORD position = { x, y } ; //My Position

    SetConsoleCursorPosition( hStdout, position ) ; //Enemy Position
}
Link: http://www.cplusplus.com/forum/beginner/68765/

For MemoryCoppy:
Link: http://www.cplusplus.com/reference/cstring/memcpy/
Link: https://msdn.microsoft.com/en-us/library/windows/desktop/ms646293(v=vs.85).aspx
*/

