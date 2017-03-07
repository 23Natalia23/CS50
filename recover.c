#include <stdio.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./copy name\n");
        return 1;
    }
    
    // open file, check file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fclose(file);
        fprintf(stderr, "Could not open file.\n");
        return 2;
    }
    
    // a buffer of 512 bytes
    BYTE buffer[512];
    
    char found_jpeg[50];
    
    // set count when jpeg begins
    int count_jpeg = 0;
    
    // file output
    FILE *image = NULL;

    while (fread(buffer, sizeof(buffer), 1, file))
    {
        // check first couple of sequence of the jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8
        && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // close the file if it is opened
            if (image != NULL)
            {
                fclose(image);
            }
            
            sprintf(found_jpeg, "%03i.jpg", count_jpeg);
            
            // open new JPEG file for writing
            image = fopen(found_jpeg, "w");
            
            count_jpeg++;
        }
        if (image != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, image);
        }
    }
    // close files
    if (image != NULL)
    {
        fclose(image);
    }
    fclose(file);
    
    // success
    return 0;
}