

int main() {
    FILE* bmpFile = fopen("../blackbuck.bmp", "rb");
    if (bmpFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    struct BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(struct BMPHeader), 1, bmpFile);

    if (bmpHeader.signature != 0x4D42) {
        printf("Not a valid BMP file\n");
        fclose(bmpFile);
        return 1;
    }

    // Calculate the size of the pixel data
    int pixelDataSize = bmpHeader.fileSize - bmpHeader.dataOffset;

    // Allocate memory for the entire BMP content (header + pixel data)
    uint8_t* bmpContent = (uint8_t*)malloc(bmpHeader.fileSize);
    if (bmpContent == NULL) {
        perror("Memory allocation failed");
        fclose(bmpFile);
        return 1;
    }

    // Copy the BMP header into the allocated memory
    memcpy(bmpContent, &bmpHeader, sizeof(struct BMPHeader));

    // Read the remaining pixel data into the allocated memory
    fread(bmpContent + sizeof(struct BMPHeader), 1, pixelDataSize, bmpFile);

    int width = bmpHeader.width;
    int height = bmpHeader.height;

    printf("Image Width: %d\n", width);
    printf("Image Height: %d\n", height);

    fclose(bmpFile);

    return 0;
}
