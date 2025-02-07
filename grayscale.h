#ifndef GRAYSCALE_H
#define GRAYSCALE_H

#include "pre.h"
#include "../stb_image.h"
#include "../stb_image_write.h"

#define R_GRAYSCALE 0.299
#define G_GRAYSCALE 0.587
#define B_GRAYSCALE 0.114

int grayscale(unsigned char *data, int width, int height, int channels, char *output_filename);

#endif