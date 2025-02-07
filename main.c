#include "grayscale.h"
#include <complex.h>

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
