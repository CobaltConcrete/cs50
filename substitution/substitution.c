// cipher an input plaintext based on input key

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int key;

    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
        return 1;
        }
        for (int j = i + 1; j < 26; j++)
        {
           if (argv[1][i] == argv[1][j])
           {
            printf("Usage: ./caesar key\n");
            return 1;
           }
        }
    }

    string s = argv[1];
    string plain = get_string("plaintext:  ");
    printf("ciphertext: ");

    for (int p = 0; p < strlen(plain); p++)
    {
        if (isupper(plain[p]))
        {
            printf("%c", toupper(argv[1][plain[p]-65]));
        }

        else if (islower(plain[p]))
        {
            printf("%c", tolower(argv[1][plain[p]-97]));
        }

        else
        {
            printf("%c", plain[p]);
        }
    }
    printf("\n");
    return 0;
}
