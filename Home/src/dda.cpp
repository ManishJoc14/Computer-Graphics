#include <graphics.h>
#include <conio.h>
#include <math.h>

void printLineDda(int x1, int y1, int x2, int y2, int color, int delayInMs)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
    float x_inc = dx / (float)steps;
    float y_inc = dy / (float)steps;

    float x = x1, y = y1;
    for (int i = 0; i < steps; i++)
    {
        delay(delayInMs);
        putpixel(round(x), round(y), color);
        x += x_inc;
        y += y_inc;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // @prams - x1, y1, x2, y2, Color, delayInMs
    // AD
    printLineDda(10, 10, 10, 300, WHITE, 5);

    // AE
    printLineDda(10, 10, 150, 100, RED, 5);
    // BE
    printLineDda(10, 100, 150, 100, RED, 5);

    // BF
    printLineDda(10, 100, 150, 200, RED, 5);
    // CF
    printLineDda(10, 200, 150, 200, RED, 5);

    getch();
    closegraph(); // Close the graphics mode
    return 0;
}
