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
        putpixel(h + x, y + k, WHITE);
        putpixel(h + y, k + x, WHITE);
        putpixel(h + y, k - x, WHITE);
        putpixel(h + x, k - y, WHITE);

        putpixel(h - x, k - y, WHITE);
        putpixel(h - y, k - x, WHITE);
        putpixel(h - y, k + x, WHITE);
        putpixel(h - x, k + y, WHITE);

    } while (x <= y);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // 1. circle with radius 50 and centre at (200,200)
    // drawCircle(200, 200, 50);

    // 2. concentric circular pattern
    // drawCircle(200, 200, 25);
    // drawCircle(200, 200, 50);
    // drawCircle(200, 200, 75);

    //3. multiple circle pattern
    float PIE = 3.1415;
    int H = 200, K = 200, R = 150;    // for big circle
    int N = 12;                       // no. of circles
    int r = round((PIE / N) * R);     // radius of small circle
    float angle = (2 * r) / (float)R; // angle substended by one circle

    drawCircle(H, K, R); // big circle

    for (int i = 1; i <= 12; i++)
    {

        int h = H + R * cos(i * angle),
            k = K + R * sin(i * angle);

        drawCircle(h, k, r); // small circle
        delay(50);
    }

    getch();
    closegraph();
    return 0;
}
