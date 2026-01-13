#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 30
#define PI 3.14159265358979323846

typedef struct turtle turtle;
struct turtle{
    char*** matrix;
    int xpos;
    int ypos;
    double facing;
};

/*Turtle initilizing at pos x,y facing north defined as 0 deg*/
turtle* init(int x,int y)
{
    turtle* t;
    t = calloc(1,sizeof(turtle));
    t->xpos = x;
    t->ypos = y;
    t->facing = 0;
    t->matrix = malloc((HEIGHT+1)*sizeof(char**));
    for(int row = 0;row<=HEIGHT;row++){
        t->matrix[row] = malloc((WIDTH+1)*sizeof(char*));
        for(int col = 0;col<=WIDTH;col++)
            t->matrix[row][col] = " ";
    }
    return t;
}

void rotate(turtle* t,double deg)
{
    t->facing += deg;
}

void setheading(turtle* t,double deg)
{
    t->facing = deg;
}

void freeturtle(turtle* t)
{
    for(int i = 0;i<=HEIGHT;i++)
        free(t->matrix[i]);
    
    free(t->matrix);
    free(t);
}

void putbotline(turtle* t,int x, int y)
{
    t->matrix[y][x] = "_";
}
void puttopline(turtle* t,int x,int y)
{
    t->matrix[y][x] = "‾";
}

void puthorline(turtle* t,int x,int y)
{
    t->matrix[y][x] = "―";
}
void putvertline(turtle* t,int x, int y)
{
    t->matrix[y][x] = "|";
}

void putwdiagonalline(turtle* t, int x,int y)
{
    t->matrix[y][x] = "\\";
}

void putediagonalline(turtle* t, int x,int y)
{
    t->matrix[y][x] = "/";
}

/*Applies Bresenham's Line algortihm to put down horizontal lines*/
void bresenhams(turtle* t,int x0,int y0,int x1,int y1)
{
    int dx,dy,stepx,stepy,er,e2;
    bool changey,changex;
    dx = abs(x1-x0);
    dy = -abs(y1-y0);
    stepx = (x1>x0) ? 1 : -1;
    stepy = (y1>y0) ? 1 : -1;
    er = dx+dy;

    
    while(1){
        changex,changey = false;
        if(x0==x1 && y0==y1) 
            break;

        e2 = 2*er;
        if(e2>=dy){
            changex = true;
            er += dy;
            x0 += stepx;
        }
        if(e2<=dx){
            changey = true;
            er += dx;
            y0 += stepy;
        }
        
        if(changey && changex){
            if(stepx *stepy == 1)
                putediagonalline(t,x0,y0);
            else
                putwdiagonalline(t,x0,y0);
        }
        else if(changex)
            if(stepy == 1)
                puttopline(t,x0,y0);
            else
                putbotline(t,x0,y0);
        else
            putvertline(t,x0,y0); 
    }
    t->xpos=x1+stepx;
    t->ypos=y1+stepy;

}

/*Puts line from turtle initial position to position which it faces with rounded length*/
void forward(turtle* t,int length)
{
    int x0 = t->xpos;
    int y0 = t->ypos;
    int deltax = length*sin(t->facing*PI/180);
    int deltay = length*cos(t->facing*PI/180);
    int x1 = x0 + deltax;
    int y1 = y0 + deltay;

    if(deltay == 0){
        int step = (deltax <0) ? -1: 1;
        for(int x = x0;x != x1;x += step)
            puthorline(t,x,y0);
        
        t->xpos = x1;
        return;
    }
    if(deltax == 0){
        int step = (deltay <0) ? -1: 1;
        for(int y = y0;y != y1;y += step)
            putvertline(t,x0,y);

        t->ypos = y1;
        return;
    }
    bresenhams(t,x0,y0,x1,y1);
}
/*Draws the ASCII board in the terminal*/
void draw(turtle* t)
{
    for(int i = HEIGHT;i>=0;i--){
        for(int k = 0;k<=WIDTH;k++)
            printf("%s",t->matrix[i][k]);
        
        printf("\n");
    }
}
void main()
{
    turtle* t1 = init(10,10);
    rotate(t1,30);
    forward(t1,10);
    draw(t1);
    freeturtle(t1);
}