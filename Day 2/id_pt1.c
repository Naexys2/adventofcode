#include <stdio.h>
#include <math.h>

int taille_nombre(int nombre)
{
    int taille = 0;
    while (nombre > 1)
    {
        nombre = nombre / 10;
        taille++;
    }
    return taille;
}

int add_invalid(char *fichier)
{
    int password = 0;
    FILE *input = fopen(fichier, "r");
    int start;
    int stop;
    while (fscanf(input, "%d-%d,", &start, &stop) != EOF)
    {
        for (int i = start; i <= stop; i++)
        {
            if (taille_nombre(i) % 2 == 0)
            {
                int part1 = i / pow(10, taille_nombre(i) / 2);
                int part2 = i - part1 * pow(10, taille_nombre(i) / 2);
                if (part1 == part2)
                {
                    printf("%d | %d\n", part1, part2);
                    password += i;
                }
            }
        }
    }
    fclose(input);
    return password;
}

int main()
{
    int password = add_invalid("input.txt");
    printf("Solution : %d\n", password);
    return 0;
}