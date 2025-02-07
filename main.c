#include <stdio.h>
#include <stdlib.h> 

#include "pre.h"
#include "../stb_image.h"
#include "../stb_image_write.h"

#define R_GRAYSCALE 0.299
#define G_GRAYSCALE 0.587
#define B_GRAYSCALE 0.114

int grayscale(unsigned char *data, int width, int height, int channels, char *output_filename) {
	if (channels < 3) {
		fprintf(stderr, "Image does not have enough color channels!\n");
		return 0;
	}
	
	unsigned char *new_image = (unsigned char *)malloc(width * height);
	if (!new_image) {
		fprintf(stderr,"Memory allocation for new image is failed!\n");
		return 0;
	}

	for (int i = 0; i < width * height; i++) {
		int r = data[i * channels + 0];
		int g = data[i * channels + 1];
		int b = data[i * channels + 2];

		new_image[i] = (unsigned char)(R_GRAYSCALE * r + G_GRAYSCALE * g + B_GRAYSCALE * b);
	}

	if (stbi_write_png(output_filename, width, height, 1, new_image, width * 1)) {
		printf("Output image saved as \"%s\"!\n", output_filename);
	} else {
		fprintf(stderr, "Failed to save image\n");
		free(new_image);
		return 0;
	}

	free(new_image);
	return 1;
}

int main(int argc, char **argv) {
	
	if (argc != 3) {
		fprintf(stderr, "Format is invalid! ::> ./m <input_name> <output_name>\n");
		return 1;
	}

	int width, height, channels;
	char *input_filename = argv[1];
	char *output_filename = argv[2];  
	
	unsigned char *data = stbi_load(input_filename, &width, &height, &channels, 0);

	if (!data) {
		fprintf(stderr, "Failed to load image!\n");
		return 1;
	}	
	printf("Loaded image with size %dx%d and %d channels\n", width, height, channels);

	int result = grayscale(data, width, height, channels, output_filename);
	if (result) printf("Grayscale image %s is generated!\n", output_filename);
	else fprintf(stderr, "Grayscale function failed!\n");
	
	stbi_image_free(data);
	return 0;
}
