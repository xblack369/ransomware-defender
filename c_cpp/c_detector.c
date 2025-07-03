#include <stdio.h>
#include <string.h>
#include <math.h>

double calculate_entropy(const unsigned char *buffer, size_t length);

int detect_encryption(const char* file_path) {
    FILE* file = fopen(file_path, "rb");
    if (!file) return 0;

    unsigned char buffer[4096];
    size_t bytes_read = fread(buffer, 1, 4096, file);
    fclose(file);

    double entropy = calculate_entropy(buffer, bytes_read);

    if (memcmp(buffer, "GANDCRAB", 8) == 0 || 
        memcmp(buffer, "WANNACRY", 7) == 0) {
        return 1;
    }

    return entropy > 7.5 ? 1 : 0;
}