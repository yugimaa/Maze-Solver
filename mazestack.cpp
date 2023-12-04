#include<iostream>
#include<stack>
using namespace std;


class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    stack<Coord> coordStack; //create stack of coord elements

    Coord start(sr, sc); //create start cordinate
    Coord end(er, ec);

    coordStack.push(start); //push start onto the stack

    //stack 
    //start

    maze[sr][sc] = 'S'; //set start as S

    while (!coordStack.empty())
    {
        Coord current = coordStack.top(); //current is set as start
        coordStack.pop(); //pops top item

        if (current.r() == end.r() && current.c() == end.c()) //if current == end (maze is solved)
        {
            return true;
        }
        else
        {
            if (maze[current.r()+1][current.c()] == '.') //if moving South is possible
            {
                //push South cordinate to 
                coordStack.push(Coord(current.r() + 1, current.c()));
                maze[current.r() + 1][current.c()] = 'P';
            }
            if (maze[current.r()][current.c()+1] == '.') //if moving East is possible
            {
                //push East cordinate to 
                coordStack.push(Coord(current.r(), current.c()+1));
                maze[current.r()][current.c() + 1] = 'P';
            }
            if (maze[current.r()-1][current.c()] == '.') //if moving North is possible
            {
                //push North cordinate to 
                coordStack.push(Coord(current.r()-1, current.c()));
                maze[current.r() - 1][current.c()] = 'P';

            }
            if (maze[current.r()][current.c()-1] == '.') //if moving West is possible
            {
                //push West cordinate to 
                coordStack.push(Coord(current.r(), current.c()-1));
                maze[current.r()][current.c() - 1] = 'P';
            }
        }
    }
    return false;
}
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise

int main()
{
    char maze[10][10] = {
        { 'X','X','X','X','X','X','X','X','X','X' },
        { 'X','.','.','.','X','.','.','.','.','X' },
        { 'X','.','.','X','X','.','X','X','.','X' },
        { 'X','.','X','.','.','.','.','X','X','X' },
        { 'X','X','X','X','.','X','X','X','.','X' },
        { 'X','.','.','X','.','.','.','X','.','X' },
        { 'X','.','.','X','.','X','.','.','.','X' },
        { 'X','X','.','X','.','X','X','X','X','X' },
        { 'X','.','.','.','.','.','.','.','.','X' },
        { 'X','X','X','X','X','X','X','X','X','X' }
    };

    if (pathExists(maze, 3, 4, 8, 1))
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout <<  " " << maze[i][j];
            }
            cout << endl;
        }
        cout << "Solvable!" << endl;

    }
   
   

    else
        cout << "Out of luck!" << endl;
}