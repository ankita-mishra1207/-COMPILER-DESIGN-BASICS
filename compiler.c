#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[32][10] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"
};

// Check if a word is a keyword
int isKeyword(char *word) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>');
}

int main() {
    char code[] = "int main() { int x = 10; float y = x + 5; }";
    char buffer[100];
    int i = 0;

    printf("Source code: %s\n\n", code);
    printf("Tokens found:\n");

    for (int j = 0; code[j] != '\0'; j++) {
        char ch = code[j];

        if (isOperator(ch)) {
            printf("Operator: %c\n", ch);
        } else if (isalnum(ch)) {
            buffer[i++] = ch;
        } else if ((ch == ' ' || ch == '\n' || ch == '\t' || ch == ';' || ch == '(' || ch == ')' || ch == '{' || ch == '}') && i != 0) {
            buffer[i] = '\0';
            i = 0;

            if (isKeyword(buffer))
                printf("Keyword: %s\n", buffer);
            else if (isdigit(buffer[0]))
                printf("Number: %s\n", buffer);
            else
                printf("Identifier: %s\n", buffer);
        }
    }

    return 0;
}
