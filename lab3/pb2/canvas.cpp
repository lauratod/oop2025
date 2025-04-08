#include "canvas.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

canvas::canvas(int width, int height) {
    this->width = width;
    this->height = height;

    matrix = (char**)malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        matrix[i] = (char*)malloc(width * sizeof(char));
    }

    Clear();
}


canvas::~canvas() {
    for (int i = 0; i < height; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void canvas::DrawCircle(int x, int y, int ray, char ch)
{
    int i, j;
    for (i = y - ray; i <= y + ray; i++)
    {
        for ( j = x - ray; j <= x + ray; j++)
        {
            if (i >= 0 && i < height && j >= 0 && j < width) {
                int a = (i - y) * (i - y) + (j - x) * (j - x);
                if (a >= ray * (ray - 1) && a <= ray * (ray + 1))
                {
                    matrix[i][j] = ch;
                }
                else
                    matrix[i][j] = ' ';
            }
        }
    }
}

void canvas::FillCircle(int x, int y, int ray, char ch)
{
    int i, j;
    for (i = y - ray; i <= y + ray; i++)
    {
        for (j = x - ray; j <= x + ray; j++)
        {
            if (i >= 0 && i < height && j >= 0 && j < width) {
                int a = (i - y) * (i - y) + (j - x) * (j - x);
                if (a <=ray*ray)
                {
                    matrix[i][j] = ch;
                }
                else
                    matrix[i][j] = ' ';
            }
        }
    }
}

void canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = 0; i <= height - 1; i++)
    {
        for (int j = 0; j <= height - 1; j++)
        {
            if (i == top && j >= left && j <= right)
            {
                matrix[i][j] = ch;
            }
            else if (i == bottom && j >= left && j <= right)matrix[i][j] = ch;
            else if (j == left && i >= top && i <= bottom)matrix[i][j] = ch;
            else if (j == right && i >= top && i <= bottom)matrix[i][j] = ch;
            else matrix[i][j] = ' ';
        }
    }
}

void canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = 0; i <= height - 1; i++)
    {
        for (int j = 0; j <= height - 1; j++)
        {
            if (i >= top && i <= bottom && j >= left && j <= right)
            {
                matrix[i][j] = ch;
            }
            else matrix[i][j] = ' ';
        }
    }
}


void canvas::SetPoint(int x, int y, char ch)
{
    matrix[x][y] = ch;
}

void canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int error = dx + dy;
    while (true)
    {
        matrix[x1][y1] = ch;
        int e2 = 2 * error;
        if (e2 >= dy)
        {
            if (x1 == x2)break;
            error = error + dy;
            x1 = x1 + sx;
        }
        if (e2 <= dx)
        {
            if (y1 == y2)break;
            error = error + dx;
            y1 = y1 + sy;
        }
    }
}

void canvas::Print() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}
void canvas::Clear() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrix[i][j] = ' ';
        }
    }
}