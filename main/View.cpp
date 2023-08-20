#include "View.h"

View :: View()
: size(11),scale(2),origin(Point2D())
{

}


bool View :: GetSubscripts(int& out_x, int& out_y, Point2D location)
{
    out_x = (location.x)/2;
    out_y = (location.y)/2;

    if( location.x < 0 || location.x > 20  || location.y < 0 || location.y > 20 ) //Check to see if a object is out of bounds
    {
        cout << "An object is outside the display" << endl;
        return false;
    }
    return true;
}


void View :: Clear()
{
    for (int i = 0; i < view_maxsize; i++)
    {
        for(int j =0; j < view_maxsize; j++)
        {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }

}

void View :: Plot(GameObject* ptr)
{
    int x, y;
    if(GetSubscripts(x,y,ptr->GetLocation()))
    {
        if(grid[x][y][0] == '.') //Check to see if two objects coincide
        {
            ptr->DrawSelf(grid[x][y]);
        }
        else
        {
            *(grid[x][y]) = '*';
            *(grid[x][y]+1) = ' ';
        }
    }
}

void View::Draw() 
{
    for (int j = size-1; j >= -1; j--) 
    {
        for (int i = -1; i <= size-1; i++) 
        {
            //grid axis
            if (i == -1 && j%2 == 0) 
            {
                cout << j*2;
                if (j/5 == 0) 
                {
                    cout << " ";
                }
            }
            else if (i == -1 && j%2 != 0) 
            {
                cout << "  ";
            }
            else if (j == -1 && i%2 == 0) 
            {
                cout << i*2;
                if (i/5 == 0) 
                {
                    cout << " ";
                }
                cout << "  ";
            }
            //draw objects
            if (i >= 0 && j >=0) 
            {
                cout << grid[i][j][0] << grid[i][j][1];
            }
        }
        cout << endl;
    }
}

