#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>


int main(int argc, string argv[])
{
    // check for valid number of command line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY.\n");
        return 1;
    }
    
    // check for valid key
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    for (int i = 0; i <= strlen(argv[1]); i++)
    {
        for (int j = i + 1; j <= strlen(argv[1]); j++)
        {
            if (isdigit(argv[1][i]))
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // ask for input from user
    string plaintext = get_string("plaintext: ");

    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    printf("ciphertext: ");
    
    for (int m = 0; m < strlen(plaintext); m++)
    {
        
        // ciphertext in case of uppercase letters
        if (isalpha(plaintext[m]) && isupper(plaintext[m]))
        {
            char *e = strchr(ALPHA, plaintext[m]);
            int index1 = (e - ALPHA);
            
            plaintext[m] = toupper(argv[1][index1]);
            printf("%c", plaintext[m]);
        }
        
        // ciphertext in case of lowercase letters
        else if (isalpha(plaintext[m]) && islower(plaintext[m]))
        {
            char *f = strchr(alpha, plaintext[m]);
            int index2 = (f - alpha);
            
            plaintext[m] = tolower(argv[1][index2]);
            printf("%c", plaintext[m]);
        }
        
        // ciphertext in case of any other character
        else
        {
            printf("%c", plaintext[m]);
        }
    }
    // print new line after ciphertext
    printf("\n");
    return 0;
}

































