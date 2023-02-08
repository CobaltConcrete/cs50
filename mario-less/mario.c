// print ascending stairs with '#' based on input height

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h, r, space, brick;
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

        for (brick = 0; brick < r; brick++)
        {
            printf("#");
        }

        printf("\n");
    }
}
