#include <stdio.h>

void calculateStatistics(int matrix[100][100], int rows, int cols) {
    int sum[100] = {0};
    float average[100] = {0};

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            sum[j] += matrix[i][j];
        }
        average[j] = (float)sum[j] / rows;
    }

    printf("Suma:");
    for (int j = 0; j < cols; j++) {
        printf(" %d", sum[j]);
    }
    printf("\n");

    printf("Srednia:");
    for (int j = 0; j < cols; j++) {
        printf(" %.1f", average[j]);
    }
    printf("\n");
}

int main() {
    int matrix[100][100];
    int rows = 0, cols = 0;

    printf("Podaj ścieżkę do pliku: ");
    char plik[100];
    scanf("%s", plik);
    printf("\n");

    FILE *file = fopen(plik, "r");
    if (file == NULL) {
        printf("Nie udalo sie otworzyc pliku.\n");
        return 1;
    }

    int j = 0;
    int num;
    char ch;
    while (!feof(file)) {
        if (fscanf(file, "%d", &num) == 1) {
            matrix[rows][j] = num;
            j++;
        }
        if ((ch = fgetc(file)) == '\n' || ch == EOF) {
            if (j > cols) cols = j;
            j = 0;
            rows++;
        }
    }

    fclose(file);

    calculateStatistics(matrix, rows, cols);

    return 0;
}