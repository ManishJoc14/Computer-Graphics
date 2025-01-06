#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawEllipse(int h, int k, int rx, int ry)
{

    // first point on an ellipse
    int x = 0, y = ry;

    // initial decision parameter
    int p1 = pow(ry, 2) - pow(rx, 2) * ry + 0.25 * pow(rx, 2);

    do
    {
        if (p1 < 0)
        {
            x++;
            p1 += 2 * pow(ry, 2) * x + pow(ry, 2);
        }

        if (p1 > 0)
        {
            x++;
            y--;
            p1 += 2 * pow(ry, 2) * x - 2 * pow(rx, 2) * y + pow(ry, 2);
        }

        if (p1 == 0)
        {
            x++;
            y = y - 0.5;
        }

        putpixel(h + x, k + y, WHITE);
        putpixel(h + x, k - y, WHITE);
        putpixel(h - x, k - y, WHITE);
        putpixel(h - x, k + y, WHITE);
        delay(5);
    } while (2 * pow(ry, 2) * x <= 2 * pow(rx, 2) * y);

    // initial decision parameter  for region2
    int p2 = pow(ry, 2) * pow((x + 0.5), 2) + pow(rx, 2) * pow((y - 1), 2) - pow(rx, 2) * pow(ry, 2);

    do
    {

        putpixel(h + x, k + y, WHITE);
        putpixel(h + x, k - y, WHITE);
        putpixel(h - x, k - y, WHITE);
        putpixel(h - x, k + y, WHITE);

        if (p2 > 0)
        {
            y--;
            p2 += -2 * pow(rx, 2) * y + pow(rx, 2);
        }

        if (p2 < 0)
        {
            x++;
            y--;
            p2 += +2 * pow(ry, 2) * x - 2 * pow(rx, 2) * y + pow(rx, 2);
        }

        if (p2 == 0)
        {
            x++;
            y = y - 0.5;
        }

        delay(5);

    } while (y >= 0);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // drawEllipse(200, 200, 160, 120);

    int H = 300, K = 300, Rx = 140, Ry = 170; // for big ellipse
    int N = 12;                               // no. of ellipses

    int rx = round((M_PI / N) * Rx); // radius of small ellipse
    int ry = round((M_PI / N) * Ry); // radius of small ellipse

    drawEllipse(H, K, Rx, Ry); // big ellipse

    for (int i = 1; i <= N; i++)
    {
        float angle = 2 * i * M_PI / N;

        int h = H + Rx * sin(angle),
            k = K + Ry * cos(angle);

        drawEllipse(h, k, rx, ry); // small ellipse
    }

    getch();
    closegraph();
    return 0;
}
