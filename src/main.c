#include "include/bmp_image.h"
int main() {
    struct bmp_image* x=read_img("../img/Lenna.bmp");
    convolution(x,3,1,1);
    write_img(x,"../out/res1.bmp");
    return 0;
}