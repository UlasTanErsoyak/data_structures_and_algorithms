#include "include/bmp_image.h"
int main() {
    struct bmp_image* x=read_img("../img/blackbuck.bmp");
    write_img(x,"../out/blackbuck_output.bmp");

    // convert_to_bw(x);
    // write_img(x,"../out/blackbuck_bw.bmp");

    // convert_to_binary(x,120);
    // write_img(x,"../out/blackbuck_bn.bmp");
    convolution(x);
    write_img(x,"../out/blackbuck_convolved.bmp");
    return 0;
}