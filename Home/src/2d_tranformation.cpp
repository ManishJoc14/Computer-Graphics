#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

#define n 3

void addMatrix(float a[n][n], float b[n][n], float c[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

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

void printMatrix(float matrix[n][n])
{

    putpixel(matrix[0][0], matrix[1][0], WHITE);

    putpixel(matrix[0][1], matrix[1][1], WHITE);

    putpixel(matrix[0][2], matrix[1][2], WHITE);
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
    // translation
    float tx, ty;

    // rotation
    float p, q, thita;

    // scaling
    float a, b, sx, sy;
    initgraph(&gd, &gm, NULL);

restart:
    printf("\n\n1. Translation  2. Rotation  3. Scaling\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:

        printf("\n---------------Translation of matrix---------------\n");

        printf("Enter object matrix: \n");
        inputMatrix(Obj);

        printf("Enter new center coordinates: ");
        printf("\na= ");
        scanf("%f", &a);
        printf("b= ");

        scanf("%f", &b);

        translateMatrix(Obj, Img, tx, ty);
        printMatrix(Img);
        goto restart;
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

        printf("Enter andle thita: ");
        printf("\nThita= ");
        scanf("%f", &thita);

        rotateMatrix(Obj, Img, p, q, thita);
        printMatrix(Img);
        goto restart;
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
        printMatrix(Img);
        goto restart;
        break;

    default:
        printf("Wrong choice!!");
        goto restart;
        break;
    };

    getch();
    closegraph();
    return 0;
}
