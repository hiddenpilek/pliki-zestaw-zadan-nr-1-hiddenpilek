#include <stdio.h>
#include <string.h>

void convert_with_numbers(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Błąd przy otwieraniu pliku.\n");
        return;
    }

    int counts[10] = {0};
    char line[256];
    char newLines[1000][256];
    int lineCount = 0;

    while (fgets(line, sizeof(line), file)) {
        int level = 0;
        while (line[level] == '*') level++;
        counts[level - 1]++;
        memset(counts + level, 0, sizeof(int) * (10 - level));
        char newLine[256] = "";
        for (int i = 0; i < level - 1; i++) strcat(newLine, "\t");
        for (int i = 0; i < level; i++) {
            char count[10];
            sprintf(count, "%d", counts[i]);
            strcat(newLine, count);
            strcat(newLine, ".");
        }
        strcat(newLine, " ");
        strcat(newLine, line + level + 1);
        strcpy(newLines[lineCount++], newLine);
    }

    fclose(file);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Błąd przy otwieraniu pliku.\n");
        return;
    }

    for (int i = 0; i < lineCount; i++) {
        fputs(newLines[i], file);
    }

    fclose(file);
}

void convert_with_letters_and_numbers(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int counts[10] = {0};
    char line[256];
    char newLines[1000][256];
    int lineCount = 0;

    while (fgets(line, sizeof(line), file)) {
        int level = 0;
        while (line[level] == '*') level++;
        counts[level]++;
        memset(counts + level + 1, 0, sizeof(int) * (10 - level - 1));
        char newLine[256] = "";
        for (int i = 0; i < level; i++) strcat(newLine, "\t");
        char count[10];
        if ((level - 1) % 4 == 0) {
            sprintf(count, "%c.", 'A' + counts[level] - 1);
        } else if ((level - 1) % 4 == 1) {
            sprintf(count, "%d.", counts[level]);
        } else if ((level - 1) % 4 == 2) {
            sprintf(count, "%c.", 'a' + counts[level] - 1);    
        } else if ((level - 1) % 4 == 3) {
            sprintf(count, "(%d)", counts[level]);
        } else {
            sprintf(count, "(%c)", 'a' + counts[level] - 1);
        }
        strcat(newLine, count);
        strcat(newLine, " ");
        strcat(newLine, line + level + 1);
        strcpy(newLines[lineCount++], newLine);
    }

    fclose(file);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < lineCount; i++) {
        fputs(newLines[i], file);
    }

    fclose(file);
}

int main() {
    printf("Podaj ścieżkę do pliku: ");
    char plik[100];
    scanf("%s", plik);
    printf("\n");

    printf("1. Konwersja z cyframi\n2. Konwersja z cyframi i literami\nWybierz typ konwersji: ");
    int typ;
    scanf("%d", &typ);

    if (typ == 1) convert_with_numbers(plik);
    else if (typ == 2) convert_with_letters_and_numbers(plik);
    else printf("Niepoprawny typ konwersji.\n");

    convert_with_numbers(plik);
    return 0;
}