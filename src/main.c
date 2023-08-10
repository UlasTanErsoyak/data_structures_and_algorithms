#include "include/bmp_image.h"
int main() {
    struct bmp_image* x=read_img("../img/blackbuck.bmp");
    convolution(x,3,1,2);
    return 0;
}