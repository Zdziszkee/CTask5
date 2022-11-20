#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 3)return 69;

    char *firstNumber = argv[1];
    char *secondNumber = argv[2];

    int firstSize = strlen(firstNumber);
    int secondSize = strlen(secondNumber);

    char resultNumber[firstSize + secondSize];

    for (int i = 0; i < sizeof(resultNumber) / sizeof(resultNumber[0]); ++i) {
        resultNumber[i] = 0;
    }
    int resultCursor = firstSize + secondSize - 1;
    for (int i = (firstSize - 1); i >= 0; i--) {
        char a = firstNumber[i] - '0';
        int resultIndex = resultCursor;
        for (int j = (secondSize - 1); j >= 0; j--) {
            char b = secondNumber[j] - '0';
            char result = ((a * b) + resultNumber[resultIndex]) ;
            resultNumber[resultIndex] = result%10;
            resultNumber[resultIndex - 1] += result/10 ;
            resultIndex--;
        }
        resultCursor--;
    }
    for (int i = 0; i < sizeof(resultNumber) / sizeof(resultNumber[0]); ++i){
        printf("%d",resultNumber[i]);
    }
    printf("\n-----");
    return 0;
}
