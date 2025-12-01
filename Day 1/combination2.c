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
            while (value > 0)
            {
                value--;
                dial--;
                if (dial < 0)
                {
                    dial = 99;
                }
                if (dial == 0)
                {
                    password++;
                }
            }
        }
        else
        {
            while (value < 0)
            {
                value--;
                dial++;
                if (dial > 99)
                {
                    dial = 0;
                }
                if (dial == 0)
                {
                    password++;
                }
            }
        }
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