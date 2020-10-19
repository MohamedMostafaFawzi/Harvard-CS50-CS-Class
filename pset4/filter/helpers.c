#include "helpers.h"
#include <cs50.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
}





// Round any color degree above 255 to 255
int max255(int degree);

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];

            int originalRed = pixel.rgbtRed;
            int originalGreen = pixel.rgbtGreen;
            int originalBlue = pixel.rgbtBlue;

            image[i][j].rgbtRed = max255(round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue));
            image[i][j].rgbtGreen = max255(round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue));
            image[i][j].rgbtBlue = max255(round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue));
        }
    }
}





// exchange the pixle with the oppisite one to do thge reflect filter
void exchange(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            exchange(&image[i][j], &image[i][width - 1 - j]);
        }
    }
}


// Check if it's a valid pixel
bool isvalid(int i, int j, int height, int width);

// Blur the pixel
RGBTRIPLE blur_image(int i, int j, int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blurred_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            blurred_image[i][j] = blur_image(i, j, height, width, image);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = blurred_image[i][j] ;
        }
    }

}




// MARK:- Helper Funcs

// Round any color degree above 255 to 255
int max255(int degree)
{
    // this is called ternary operator and it's just a simplification of the if statement
    return degree > 255 ? 255 : degree;
}

// Exchange the pixle with the oppisite one to do thge reflect filter
void exchange(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}

bool isvalid(int i, int j, int height, int width)
{
    return i >= 0 && i < height && j >= 0 && j < width;
}

// Blur the pixel
RGBTRIPLE blur_image(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int red_degree = 0;
    int blue_degree = 0;
    int green_degree = 0;

    int number_valid_pixels = 0;

    for (int xi = -1; xi <= 1; xi++)
    {
        for (int xj = -1; xj <= 1; xj++)
        {
            int new_i = i + xi;
            int new_j = j + xj;

            if (isvalid(new_i, new_j, height, width))
            {
                number_valid_pixels++;
                red_degree += image[new_i][new_j].rgbtRed;
                blue_degree += image[new_i][new_j].rgbtBlue;
                green_degree += image[new_i][new_j].rgbtGreen;
            }
        }
    }
    RGBTRIPLE blur_pixel;

    blur_pixel.rgbtRed = round((float) red_degree / number_valid_pixels);
    blur_pixel.rgbtGreen = round((float) green_degree / number_valid_pixels);
    blur_pixel.rgbtBlue = round((float) blue_degree / number_valid_pixels);

    return blur_pixel;
}
