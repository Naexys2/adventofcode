#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int taille_nombre(long long int nombre)
{
    int taille = 0;
    while (nombre >= 1)
    {
        nombre = nombre / 10;
        taille++;
    }
    return taille;
}

int est_diviseur(int a, int b)
{
    if (b % a == 0)
    {
        return 1;
    }
    return 0;
}

int is_invalid(long long int nb)
{
    int t_nb = taille_nombre(nb);
    for (int i = 2; i <= t_nb; i++)
    {
        if (est_diviseur(i, t_nb))
        {
            long long int *split = malloc(i * (sizeof(long long int)));
            for (int j = 0; j < i; j++)
            {
                long long int part = nb / pow(10, (t_nb / i) * (i - j - 1));
                split[j] = part;
                nb -= part * pow(10, (t_nb / i) * (i - j - 1));
            }
            for (int j = 0; j < i - 1; j++)
            {
                if (split[j] != split[j+1])
                {
                    return 0;
                }
            }
            free(split);
            return 1;
        }
    }
    return 0;
}

long long int add_invalid(char *fichier)
{
    long long int password = 0;
    FILE *input = fopen(fichier, "r");
    long long int start;
    long long int stop;
    while (fscanf(input, "%lld-%lld,", &start, &stop) != EOF)
    {
        for (long long int i = start; i <= stop; i++)
        {

            if (is_invalid(i))
            {
                password += i;
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