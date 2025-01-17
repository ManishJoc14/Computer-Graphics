#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawCircle(int h, int k, int r)
{
    // initial center point
    int x = 0, y = r;

    // initial decision parameter
    int p = 1 - r;

    do
    {
        if (p < 0)
        {
            x++;
            p += 2 * x + 1;
        }
        else
        {
            x++;
            y--;
            p += 2 * x - 2 * y + 5;
        }

        // translate the circle to the center (h, k)
        putpixel(h + x, y + k, BLACK);
        putpixel(h + y, k + x, BLACK);
        putpixel(h + y, k - x, BLACK);
        putpixel(h + x, k - y, BLACK);

        putpixel(h - x, k - y, BLACK);
        putpixel(h - y, k - x, BLACK);
        putpixel(h - y, k + x, BLACK);
        putpixel(h - x, k + y, BLACK);

    } while (x <= y);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);
    cleardevice();

    // Question 1. circle with radius 50 and centre at (200,200)
    // drawCircle(200, 200, 50);

    // Question 2. concentric circular pattern
    // drawCircle(200, 200, 25);
    // drawCircle(200, 200, 50);
    // drawCircle(200, 200, 75);

    // Question 3. multiple circle pattern
    int H = 200, K = 200, R = 150; // for big circle
    int N = 12;                    // no. of circles
    int r = round((M_PI / N) * R); // radius of small circle

    drawCircle(H, K, R); // big circle

    for (int i = 1; i <= N; i++)
    {
        float angle = 2 * i * M_PI / N;
        int h = H + R * cos(angle),
            k = K + R * sin(angle);

        drawCircle(h, k, r); // small circle
        delay(50);
    }

    getch();
    closegraph();
    return 0;
}
