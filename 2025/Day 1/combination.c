#include <stdio.h>

int calculate(char *fichier)
{
    int dial = 50;
    int password = 0;
    FILE *input = fopen(fichier, "r");
    char direction;
    int value;
    while (fscanf(input, "%c%d\n", &direction, &value) != EOF)
    {
        if (direction == 'L')
        {
            dial -= value;
            dial = dial % 100;
        }
        else
        {
            dial += value;
            dial = dial % 100;
        }
        if (dial == 0)
        {
            password++;
        }
        printf("dial, %d\npassword %d\nlast direction %c\nlast value %d\n\n", dial, password, direction, value);
    }
    fclose(input);
    return password;
}

int main()
{
    int password = calculate("input.txt");
    printf("Le mot de passe est %d\n", password);
    return 0;
}