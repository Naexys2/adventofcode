#include <stdio.h>
#include <math.h>

int taille_nombre(long long int nombre)
{
    int taille = 0;
    while (nombre > 1)
    {
        nombre = nombre / 10;
        taille++;
    }
    return taille;
}

long long int add_invalid(char *fichier)
{
    long long int password = 0;
    FILE *input = fopen(fichier, "r");
    long long int start;
    long long int stop;
    while (fscanf(input, "%lld-%lld,", &start, &stop) != EOF)
    {
        printf("\ninterval : %lld | %lld\n", start, stop);
        for (long long int i = start; i <= stop; i++)
        {
            if (taille_nombre(i) % 2 == 0)
            {
                long long int part1 = i / pow(10, taille_nombre(i) / 2);
                long long int part2 = i - part1 * pow(10, taille_nombre(i) / 2);
                if (part1 == part2)
                {
                    // printf("%d | %d\n", part1, part2);
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
    long long int password = add_invalid("input.txt");
    printf("Solution : %lld\n", password);
    return 0;
}