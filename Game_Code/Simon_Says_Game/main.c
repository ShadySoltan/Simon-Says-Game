#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CHAR_SET "RGBYPCW"
#define CHAR_SET_SIZE (sizeof(CHAR_SET) - 1) // Exclude the null terminator

// Function to generate a random string of a given length
void generateRandomString(char *str, size_t length)
{
    if (str == NULL || length == 0)
    {
        return;
    }

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    size_t i;
    for (i = 0; i < length; i++)
    {
        str[i] = CHAR_SET[rand() % CHAR_SET_SIZE];
    }
    str[length] = '\0'; // Null-terminate the string
}

int main()
{
    size_t length = 5;                               // Change this to your desired length
    char *randomString = (char *)malloc(length + 1); // +1 for the null terminator

    if (randomString == NULL)
    {
        perror("Unable to allocate memory");
        return 1;
    }

    generateRandomString(randomString, length);
    printf("Generated string: %s\n", randomString);

    free(randomString);
    return 0;
}
