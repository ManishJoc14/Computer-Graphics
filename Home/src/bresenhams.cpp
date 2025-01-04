#include <graphics.h>
#include <conio.h>
#include <math.h>

void printLineBresenhams(int x1, int y1, int x2, int y2, int color, int delayInMs)
{
    int p, steps;
    int dx = fabs(x2 - x1);
    int dy = fabs(y2 - y1);

    int x_inc = x2 > x1 ? 1 : -1;
    int y_inc = y2 > y1 ? 1 : -1;

    if (dx > dy)
    {
        p = 2 * dy - dx;
        steps = dx;

        for (int i = 0; i < steps; i++)
        {
            if (p < 0)
            {
                x1 += x_inc;
                y1 = y1;
                p += 2 * dy;
            }
            else
            {
                x1 += x_inc;
                y1 += y_inc;
                p += 2 * dy - 2 * dx;
            }
            delay(delayInMs);
            putpixel(x1, y1, color);
        }
    }
    else
    {
        steps = dy;
        p = 2 * dx - dy;

        for (int i = 0; i < steps; i++)
        {
            if (p < 0)
            {
                x1 = x1;
                y1 += y_inc;
                p += 2 * dx;
            }
            else
            {
                x1 += x_inc;
                y1 += y_inc;
                p += 2 * dx - 2 * dy;
            }
            delay(delayInMs);
            putpixel(x1, y1, color);
        }
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // @prams - x1, y1, x2, y2, Color, delayInMs

    // AD
    printLineBresenhams(10, 10, 10, 300, WHITE, 5);

    // AE
    printLineBresenhams(10, 10, 150, 100, RED, 5);
    // BE
    printLineBresenhams(10, 100, 150, 100, RED, 5);

    // BF
    printLineBresenhams(10, 100, 150, 200, RED, 5);
    // CF
    printLineBresenhams(10, 200, 150, 200, RED, 5);

    getch();
    closegraph(); // Close the graphics mode
    return 0;
}
