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
        printf("dial %d\npassword %d\n", dial, password);
        if (direction == 'L')
        {
            while (value > 99)
            {
                value -= 100;
                password++;
            }
            dial -= value;
            if (dial < 0)
            {
                dial += 100;
                password++;
            }
        }
        else
        {
            while (value < 0)
            {
                value -= 100;
                password++;
            }
            dial += value;
            if (dial > 99)
            {
                dial -= 100;
                password++;
            }
        }
        if (dial == 0)
        {
            password++;
        }
        printf("direction %c\nvalue %d\nnew dial %d\nnew password %d\n\n", direction, value, dial, password);
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