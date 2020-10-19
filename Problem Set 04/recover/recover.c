#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;

#define BLOCK_SIZE 512
#define FILE_NAME_SIZE 8

bool is_new_jpeg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    // Prints usage image to the user if the argument not equal to 2
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open inupt file in read mode
    FILE *infile = fopen(argv[1], "r");

    // Prints that the file do not exist if there's not input file
    if (infile == NULL)
    {
        printf("File do not exist\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];

    // hold the count of the pictures
    int file_count = 0;

    // check if the first jpeg is found
    bool is_first_jpeg_exist = false;

    FILE *outfile;

    while (fread(buffer, BLOCK_SIZE, 1, infile))
    {
        // check if there's a new jpeg
        if (is_new_jpeg(buffer))
        {
            if (!is_first_jpeg_exist)
            {
                is_first_jpeg_exist = true;
            }
            else
            {
                // close the outfile
                fclose(outfile);
            }

            char filename[FILE_NAME_SIZE];

            sprintf(filename, "%03i.jpg", file_count++);

            outfile = fopen(filename, "w");

            if (outfile == NULL)
            {
                return 1;
            }

            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
        else if (is_first_jpeg_exist)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }

    }

    fclose(outfile);
    fclose(infile);

}


// MARK:- Helper Funcs

// check if there's a new jpeg
bool is_new_jpeg(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}
