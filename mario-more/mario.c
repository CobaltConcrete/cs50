// print ascending and descending stairs with '#' based on input height

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h, r, space, brick1, brick2;
    do
    {
        h = get_int("Height (1 to 8): ");
    }
    while (h < 1 || h > 8);

    for (r = 1; r <= h; r++)
    {
        for (space = 0; space < h - r; space++)
        {
            printf(" ");
        }

        for (brick1 = 0; brick1 < r; brick1++)
        {
            printf("#");
        }

        printf("  ");

         for (brick2 = 0; brick2 < r; brick2++)
        {
            printf("#");
        }

        printf("\n");
    }
}
