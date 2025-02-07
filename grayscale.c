#include "grayscale.h"

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