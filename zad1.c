#include <stdio.h>

int countCharacterOccurrences(const char* filePath, char character) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Błąd przy otwieraniu pliku.\n");
        return -1;
    }

    int count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == character) {
            count++;
        }
    }

    fclose(file);
    return count;
}

int main() {
    printf("Podaj ścieżkę do pliku: ");
    char plik[100];
    scanf("%s", plik);

    printf("Podaj szukany znak:");
    char znak;
    scanf("%s", &znak);

    int occurrences = countCharacterOccurrences(plik, znak);
    printf("Znak '%c' występuje %d razu w pliku.\n", znak, occurrences);

    return 0;
}