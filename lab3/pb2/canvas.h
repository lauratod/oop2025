#pragma once
//#include <stdlib.h>
//#include <stdio.h>

class canvas
{
    // add private data members
    int width, height;
    char** matrix;
public:
    canvas(int width, int height);
    ~canvas();
    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void Print(); // shows what was printed
    void Clear(); // clears the canvas
};

