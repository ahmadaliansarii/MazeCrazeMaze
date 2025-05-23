#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

class Maze {
public:
    char** maze;
    int row;
    int column;

    // constructor
    Maze() {
        setMazeParameters();
        importMaze();
    }

    // destructor
    ~Maze() {
        for (int i = 0; i < row; i++) {
            delete[] maze[i];
        }
        delete[] maze;
    }

    // function to read the maze parameters and allocate memory for the 2D char array
    void setMazeParameters() {
        ifstream infile("chosenFile.txt");
        string line;
        row = 0;
        column = 0;
        while (getline(infile, line)) {
            row++;
            column=line.length()+1;
        }
        column++;
        maze = new char*[row];
        for (int i = 0; i < row; i++) {
            maze[i] = new char[column];
        }
    }

    // function to import the maze from the text file into the 2D char array
    void importMaze() {
        ifstream infile("chosenFile.txt");
        string line;
        int r = 0;
        while (getline(infile, line)) {
            for (int c = 0; c < column; c++) {
                if (c < line.length()) {
                    maze[r][c] = line[c];
                } else {
                    maze[r][c] = ' ';
                }
            }
            r++;
        }
    }

    // function to print the maze
    void printMaze() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << maze[i][j];
            }
            cout << endl;
        }
    }
};

class Objects{	
public:
	int n,m;
	
	Objects(){
		n=0;
		m=0;
	}
};

class Portals : public Objects{
public:
	static int portalNumber;
	
	Portals() : Objects(){
		portalNumber++;
	}
};

int returnRandomIndexPosition(int arrSize){
	return rand() % arrSize;
}

int Portals::portalNumber=0;

class MovingObjects : public Objects{
public:
	char move;
	
	MovingObjects() : Objects(){
		move=' ';
	}
	
	void assignMove(){
	}
	
	void performMove(Maze& maze){
	}
};

class Hero : public MovingObjects{
private:
	bool gameOver;
	
public:
	int score=0;
	bool powerUpUsed;
	
	Hero() : MovingObjects(){
		powerUpUsed=false;
	}
	
	void assignMove(){
	    if (_kbhit()) {  // Check if a key has been pressed
	        move = _getch();
	    }
	}
	
	void findLocationInMaze(Maze& maze){
		for(n = 0; n < maze.row; n++){
	        for(m = 0; m < maze.column; m++){
	            if(maze.maze[n][m] == '@') {
	                break;
	            }
	        }
	        if(maze.maze[n][m] == '@') {
	            break;
	        }
	    }
	}
	
	void endGame(Maze& maze) {
    system("cls");
    for(int i = 0; i < maze.row; i++) {
        for(int j = 0; j < maze.column; j++) {
            if(i == n && j == m) {
                cout << "@";
                gameOver = true;  // Update the gameOver flag
            }
            else {
                maze.maze[i][j] = ' ';
                cout << maze.maze[i][j];
            }
        }
        cout << endl;
    }
}
    
    bool checkIfGameOver(){
    	if(gameOver==1){
    		cout << "\nScore : " << score << "\nGAME OVER!";
    		return 1;
		}else{
			return 0;
		}
	}
	
	void performMove(Maze& maze, Portals*& portals,int realPortal) {
	    if (move == 'w') {  // move up
	        if (maze.maze[n - 1][m] == '#' || maze.maze[n - 1][m] == '-' || (maze.maze[n - 1][m] == '0' && ((n-1)!=portals[realPortal].n && (m)!=portals[realPortal].m))) {
	            // do nothing
	        }
	        else if (maze.maze[n - 1][m] == '0' && ((n-1)==portals[realPortal].n && (m)==portals[realPortal].m)) {
	            n--;
	            endGame(maze);
	        }
	        else {
	            if (maze.maze[n - 1][m] == '.') {
	                score++;
	            }
	            if (maze.maze[n - 1][m] == '+') {
	                powerUpUsed=true;
	            }
	            if (n > 0) {
	                maze.maze[n][m] = ' ';       // Clear the current position
					n--;                         // Update the new position
					maze.maze[n][m] = '@'; 
	            }
	        }
	    }
	    else if (move == 's') {  // move down
	        if (maze.maze[n + 1][m] == '#' || maze.maze[n + 1][m] == '-' || (maze.maze[n + 1][m] == '0' && ((n+1)!=portals[realPortal].n && (m)!=portals[realPortal].m))) {
	            // do nothing
	        }
	        else if (maze.maze[n + 1][m] == '0' && ((n+1)==portals[realPortal].n && (m)==portals[realPortal].m)) {
	            n++;
	            endGame(maze);
	        }
	        else {
	            if (maze.maze[n + 1][m] == '.') {
	                score++;
	            }
	            if (maze.maze[n + 1][m] == '+') {
	                powerUpUsed=true;
	            }
	            if (n < maze.row - 1) {
	                maze.maze[n][m] = ' ';
	                n++;
	                maze.maze[n][m] = '@';
	            }
	        }
	    }
	    else if (move == 'd') {  // move right
	        if (maze.maze[n][m + 1] == '#' || maze.maze[n][m + 1] == '-' || (maze.maze[n][m + 1] == '0' && ((n)!=portals[realPortal].n && (m + 1)!=portals[realPortal].m))) {
	            // do nothing
	        }
	        else if (maze.maze[n][m + 1] == '0' && ((n)==portals[realPortal].n && (m + 1)==portals[realPortal].m)) {
	            m++;
	            endGame(maze);
	        }
	        else {
	            if (maze.maze[n][m + 1] == '.') {
	                score++;
	            }
	            if (maze.maze[n][m + 1] == '+') {
	                powerUpUsed=true;
	            }
	            if (m < maze.column - 1) {
	                maze.maze[n][m] = ' ';
	                m++;
	                maze.maze[n][m] = '@';
	            }
	        }
	    }
	    else if (move == 'a') {  // move left
	        if (maze.maze[n][m - 1] == '#' || maze.maze[n][m - 1] == '-' || (maze.maze[n][m - 1] == '0' && ((n)!=portals[realPortal].n && (m - 1)!=portals[realPortal].m))) {
	            // do nothing
	        }
	        else if (maze.maze[n][m - 1] == '0' && ((n)==portals[realPortal].n && (m - 1)==portals[realPortal].m)) {
	            m--;
	            endGame(maze);
	        }
	        else {
	            if (maze.maze[n][m - 1] == '.') {
	                score++;
	            }
	            if (maze.maze[n][m - 1] == '+') {
	                powerUpUsed=true;
	            }
	            if (m > 0) {
	                maze.maze[n][m] = ' ';       
					m--;                         // Update the new position
					maze.maze[n][m] = '@'; 
	            }
	        }
	    }
	    move=' ';
	}
};

class Ghosts : public MovingObjects{
private:
	char past;
	
public:
//	bool shouldIMove;
	static int ghostNumber;
	
	Ghosts() : MovingObjects(){
		past='.';
		ghostNumber++;
//		shouldIMove=true;
	}
	
void assignMove(Hero& hero) {
    if (abs(n - hero.n) <= 2 && abs(m - hero.m) <= 2) {
        if (n > hero.n) {
            move = 'w';
        }
        else if (n < hero.n) {
            move = 's';
        }
        else if (m < hero.m) {
            move = 'd';
        }
        else if (m > hero.m) {
            move = 'a';
        }
    }
    else {
        // Assign a random move
        int randNum = rand() % 4;
        if (randNum == 0) {
            move = 'w';
        }
        else if (randNum == 1) {
            move = 's';
        }
        else if (randNum == 2) {
            move = 'd';
        }
        else if (randNum == 3) {
            move = 'a';
        }
    }
}
	
	void performMove(Maze& maze, Hero &hero){
//		if(shouldIMove==true){
			
			if(move == 'w') {  // move up
		        if(maze.maze[n-1][m] == '#' || maze.maze[n-1][m] == '-' || maze.maze[n-1][m] == '0'){
		            // do nothing
		        }
		        else{
		            if (maze.maze[n - 1][m] == '@') {
		                hero.endGame(maze);
		            }
		            maze.maze[n][m]=past;
		            past=maze.maze[n-1][m];
		            n--;
		        }
		    }
		    else if(move == 's') {  // move down
		        if(maze.maze[n+1][m] == '#' || maze.maze[n+1][m] == '-' || maze.maze[n+1][m] == '0'){
		            // do nothing
		        }
		        else{
		            if (maze.maze[n + 1][m] == '@') {
		                hero.endGame(maze);
		            }
		            maze.maze[n][m]=past;
		            past=maze.maze[n+1][m];
		            n++;
		        }
		    }
		    else if(move == 'd') {  // move right
		        if(maze.maze[n][m+1] == '#' || maze.maze[n][m+1] == '-' || maze.maze[n][m+1] == '0'){
		            // do nothing
		        }
		        else{
		            if (maze.maze[n][m + 1] == '@') {
		                hero.endGame(maze);
		            }
		            maze.maze[n][m]=past;
		            past=maze.maze[n][m+1];
		            m++;
		        }
		    }
		    else if(move == 'a') {  // move left
		        if(maze.maze[n][m-1] == '#' || maze.maze[n][m-1] == '-' || maze.maze[n][m-1] == '0'){
		            // do nothing
		        }
		        else{
		            if (maze.maze[n][m - 1] == '@') {
		                hero.endGame(maze);
		            }
		            maze.maze[n][m]=past;
		            past=maze.maze[n][m-1];
		            m--;
		        }
		    }
		    maze.maze[n][m] = 'G';
		    move=' ';
//		}
			
		}
};

int Ghosts::ghostNumber=0;

void findGhostsAndPortals(Maze& maze, Ghosts*& ghosts, Portals*& portals) {
    int totalNumberOfGhosts = 0;
	int totalNumberOfPortals = 0;
	   
    for (int n = 0; n < maze.row; n++) {
        for (int m = 0; m < maze.column; m++) {
            if (maze.maze[n][m] == 'G') {
                totalNumberOfGhosts++;
            }
            if (maze.maze[n][m] == '+') {
                totalNumberOfPortals++;
            }
        }
    }
    
    ghosts = new Ghosts[totalNumberOfGhosts];
    portals = new Portals[totalNumberOfGhosts];
    
    int ghostIndex = 0;
    int portalIndex = 0;
    
    for (int n = 0; n < maze.row; n++) {
        for (int m = 0; m < maze.column; m++) {
            if (maze.maze[n][m] == 'G') {
                ghosts[ghostIndex].n = n;
                ghosts[ghostIndex].m = m;
                ghostIndex++;
            }
            if (maze.maze[n][m] == '0') {
                portals[portalIndex].n = n;
                portals[portalIndex].m = m;
                portalIndex++;
            }
        }
    }
}

void animateText(const string& text, int delay) {
    for (char c : text) {
        cout << c;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

void startWindow(){
	string message = "Welcome to MAZE CRAZE MAZE!\n\nCreators:\nJaswant Lal(22K-4473)\nAhmad Ali Ansari(22K-4385)\n\n[Press any key to start]\n";
    
    animateText(message, 50);
    char userInput=_getch();
    
    animateText("\nStarting the game...",50);
    this_thread::sleep_for(chrono::milliseconds(500));
    
    system("cls");
}

void changeFileName(string old, string updated){
    rename(old.c_str(), updated.c_str());
}

char choice=' ';

void chooseLevel(){
	animateText("Choose level:\n1-Easy\n2-Medium\n3-Hard\n...",50);
	while(1){
		choice=_getch();
		if(choice=='1' || choice=='2' || choice=='3') break;
	}
	
	if(choice=='1'){
		changeFileName("easy.txt","chosenFile.txt");
	}else if(choice=='2'){
		changeFileName("medium.txt","chosenFile.txt");
	}else{
		changeFileName("hard.txt","chosenFile.txt");
	}
	
	system("cls");
}

void revertFileName(){
	if(choice=='1'){
		changeFileName("chosenFile.txt","easy.txt");
	}else if(choice=='2'){
		changeFileName("chosenFile.txt","medium.txt");
	}else{
		changeFileName("chosenFile.txt","hard.txt");
	}
	choice=' ';
}

void mainGame(){
	Maze maze;
    Hero hero;
    Ghosts* ghosts = nullptr;
    Portals* portals = nullptr;
    int tickCounterPowerUp=0;
    const int durationOfPowerUp=10;//in term of ticks
    hero.findLocationInMaze(maze);
    findGhostsAndPortals(maze, ghosts, portals);
    
    int gameDuration = 60;  // Duration of the game in seconds
    int tickRate = 4;       // Number of ticks per second
    int ticks = gameDuration * tickRate;

    auto tickDuration = chrono::milliseconds(1000 / tickRate);  // Duration between ticks in milliseconds

    for (int i = 0,j=0; i < ticks; i++,j++){
        system("cls");
        
        maze.printMaze();
        cout << "\nTime left : " << double(gameDuration) - (i*(1.0/double(tickRate))) << "s";

        hero.assignMove();
        hero.performMove(maze,portals,returnRandomIndexPosition(int(portals[0].portalNumber)));
        
        if(hero.powerUpUsed==true){
        	tickCounterPowerUp=i+(durationOfPowerUp*tickRate);//5 second powerup period
        	hero.powerUpUsed=false;
			j=0;
		}
        
        if(i>=tickCounterPowerUp){
	        for (int i = 0; i < Ghosts::ghostNumber; i++) {
	            ghosts[i].assignMove(hero);
	            ghosts[i].performMove(maze, hero);
	        }	
		}else{
			cout << "\nGhosts freezed for " << double(durationOfPowerUp) - (j*(1.0/double(tickRate))) << "s";
			if (hero.checkIfGameOver()) {
            break;
        }
		}

        if (hero.checkIfGameOver()) {
            break;
        }

        this_thread::sleep_for(tickDuration);
    }

    delete[] ghosts;
}

int main(){
    startWindow();
    
    chooseLevel();
    
    mainGame();
    
    revertFileName();
    
    return 0;
}
