#include <stdio.h>


void showMap(int map[50][50], int r, int c)
{
    int i, j;
    printf("\nArea Map:\n");
    printf("(0 = Safe, 1 = Danger)\n\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}


void scanArea(int map[50][50], int r, int c)
{
    int i, j;
    int dangerCount = 0;

    printf("\nScanning Area...\n");
    printf("-----------------------------\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (map[i][j] == 1)
            {
                printf("Danger detected at -> Row %d, Column %d\n", i + 1, j + 1);
                dangerCount++;
            }
        }
    }

    printf("\n-----------------------------\n");
    if (dangerCount == 0)
    {
        printf("Result: No danger zones found. Area is completely safe.\n");
    }
    else
    {
        printf("Result: %d danger zone(s) detected in the area.\n", dangerCount);
    }
}

int main()
{
    int rows, cols;
    int area[50][50];
    int i, j;

    printf("====================================\n");
    printf("   DANGER ZONE DETECTION SYSTEM\n");
    printf("====================================\n");

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0 || rows > 50 || cols > 50)
    {
        printf("Invalid size! Please enter values between 1 and 50.\n");
        return 0;
    }

    printf("\nEnter area data (Only 0 or 1 allowed):\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Cell [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &area[i][j]);

            if (area[i][j] != 0 && area[i][j] != 1)
            {
                printf("Invalid input! Only 0 or 1 is allowed.\n");
                j--; // re-enter same cell
            }
        }
    }

    showMap(area, rows, cols);
    scanArea(area, rows, cols);

    printf("\nSystem Execution Finished.\n");
    return 0;
}
