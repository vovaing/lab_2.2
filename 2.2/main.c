#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для реверса строки
void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main(int argc, char *argv[]) {
    // Проверка наличия аргумента командной строки
    if (argc < 2) {
        printf("Использование: %s <имя_файла>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file;

    // 1. Заполнение файла словами с клавиатуры
    printf("Введите слова (для завершения введите 'end'):\n");
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка открытия файла для записи.\n");
        return 1;
    }

    char word[100];
    while (1) {
        scanf("%s", word);
        if (strcmp(word, "end") == 0) {
            break;
        }
        fprintf(file, "%s\n", word);
    }
    fclose(file);

    // Вывод содержимого файла на экран
    printf("\nСодержимое файла:\n");
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла для чтения.\n");
        return 1;
    }

    while (fscanf(file, "%s", word) != EOF) {
        printf("%s\n", word);
    }
    fclose(file);

    // 2. Подсчёт количества слов в файле
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла для чтения.\n");
        return 1;
    }

    int wordCount = 0;
    while (fscanf(file, "%s", word) != EOF) {
        wordCount++;
    }
    fclose(file);

    printf("\nКоличество слов в файле: %d\n", wordCount);

    // 3. Реверс самого длинного слова в файле
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла для чтения.\n");
        return 1;
    }

    char longestWord[100] = "";
    while (fscanf(file, "%s", word) != EOF) {
        if (strlen(word) > strlen(longestWord)) {
            strcpy(longestWord, word);
        }
    }
    fclose(file);

    reverseString(longestWord);
    printf("\nСамое длинное слово после реверса: %s\n", longestWord);

    return 0;
}
