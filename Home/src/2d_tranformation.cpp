#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

#define n 3

void multiplyMatrix(float a[n][n], float b[n][n], float c[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void printMatrix(float matrix[n][n], int COLOR)
{
    setcolor(COLOR);
    line(matrix[0][0], matrix[1][0], matrix[0][1], matrix[1][1]);
    line(matrix[0][1], matrix[1][1], matrix[0][2], matrix[1][2]);
    line(matrix[0][2], matrix[1][2], matrix[0][0], matrix[1][0]);
}

void inputMatrix(float matrix[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("m[%d][%d]=", i, j);
            scanf("%f", &matrix[i][j]);
        }
        printf("\n");
    }
}

void translateMatrix(float Obj[n][n], float Img[n][n], float a, float b)
{
    float CM[n][n] = {
        {1, 0, a},
        {0, 1, b},
        {0, 0, 1}};

    multiplyMatrix(CM, Obj, Img);
}

void scaleMatrix(float Obj[n][n], float Img[n][n], float a, float b, float sx, float sy)
{
    float CM[n][n] = {
        {sx, 0, a * (1 - sx)},
        {0, sy, b * (1 - sy)},
        {0, 0, 1},
    };

    multiplyMatrix(CM, Obj, Img);
}

void rotateMatrix(float Obj[n][n], float Img[n][n], float p, float q, float thita)
{
    float CM[n][n] = {
        {cos(thita), sin(thita), p - p * cos(thita) - q * sin(thita)},
        {-sin(thita), cos(thita), q - q * cos(thita) + p * sin(thita)},
        {0, 0, 1},
    };

    multiplyMatrix(CM, Obj, Img);
}

int main()
{
    int gd = DETECT, gm;
    int choice;
    float Obj[n][n];
    float Img[n][n];

    // for translation
    float tx, ty;

    // for rotation
    float p, q, thita;

    // for scaling
    float a, b, sx, sy;
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);
    cleardevice();

    float xh = getmaxx();
    float yh = getmaxy();

    setcolor(BLACK);
    // print axis
    line(xh / 2, 0, xh / 2, yh);
    line(0, yh / 2, xh, yh / 2);

    do
    {

        printf("\n\n1. Translation  2. Rotation  3. Scaling 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("\n---------------Translation of matrix---------------\n");

            printf("Enter object matrix: \n");
            inputMatrix(Obj);

            printf("Enter new center coordinates: ");
            printf("\ntx= ");
            scanf("%f", &tx);
            printf("ty= ");
            scanf("%f", &ty);

            translateMatrix(Obj, Img, tx, ty);

            printMatrix(Obj, GREEN);
            printMatrix(Img, GREEN);
            break;

        case 2:
            printf("\n---------------Rotation of matrix---------------\n");

            printf("Enter object matrix: \n");
            inputMatrix(Obj);

            printf("Enter coordinates of fixed point: ");
            printf("\np= ");
            scanf("%f", &p);
            printf("q= ");
            scanf("%f", &q);

            printf("Enter angle thita in degrees: ");
            printf("\nThita= ");
            scanf("%f", &thita);
            thita = thita * M_PI / 180;

            rotateMatrix(Obj, Img, p, q, thita);
            printMatrix(Obj, BLUE);
            printMatrix(Img, BLUE);
            break;

        case 3:
            printf("\n---------------Scaling of matrix---------------\n");

            printf("Enter object matrix: \n");
            inputMatrix(Obj);

            printf("Enter coordinates of fixed point: ");
            printf("\na= ");
            scanf("%f", &a);
            printf("b= ");
            scanf("%f", &b);

            printf("Enter the scaling factor: ");
            printf("\nsx= ");
            scanf("%f", &sx);
            printf("sy= ");
            scanf("%f", &sy);

            scaleMatrix(Obj, Img, a, b, sx, sy);
            printMatrix(Img, DARKGRAY);
            printMatrix(Obj, DARKGRAY);
            break;

        case 4:
            return 0;

        default:
            printf("Wrong choice!!");
            return 0;
        };
    } while (choice >= 1 && choice <= 4);

    getch();
    closegraph();
    return 0;
}
