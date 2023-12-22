#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    FILE *fp, *fs;

    char kword[10], lexeme[10], digits[10], c, d, f;
    fp = fopen("input.c", "r");
    fs = fopen("keywords.txt", "r");
    printf("Address   lexeme   token \n");
    printf("-------------------------");
    while (!feof(fp))
    {
        int i = 0;
        fflush(stdin);
        c = getc(fp);
        if (isalpha(c))
        {
            lexeme[i++] = c;
            f = 1;

            while (f)
            {
                d = getc(fp);
                if (isdigit(d) || isalpha(d) || d == '_')
                {
                    lexeme[i++] = d;
                    f = 1;
                }
                else
                {
                    lexeme[i] = '\0';
                    f = 0;
                    fseek(fp, -1, 1);
                }
            }

            int z;
            while (!feof(fs))
            {
                fscanf(fs, "%s", kword);
                z = strcmp(lexeme, kword);
                // printf("%s %s \n",lexeme,kword);
                if (z == 0)
                {
                    printf("\n%d  %s    keyword ", &lexeme, lexeme);
                    rewind(fs);
                    break;
                }
            }
            if (z != 0)
            {
                printf("\n%d  %s     identifier", &lexeme, lexeme);
                rewind(fs);
            }
        }
        if (isdigit(c))
        {
            i = 0;
            digits[i++] = c;
            while (isdigit(c = getc(fp)))
            {
                digits[i++] = c;
            }
            digits[i] = '\0';
            printf("\n%d  %s      digit", &digits, digits);
        }
    }
    fclose(fp);
    fclose(fs);
}
