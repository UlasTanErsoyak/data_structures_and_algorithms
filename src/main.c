#include "include/bmp_image.h"
int main() {
    struct bmp_image* x=read_img("../img/blackbuck.bmp");
    // write_img(x,"../out/blackbuck_output.bmp");

    // convert_to_bw(x);
    // write_img(x,"../out/blackbuck_bw.bmp");

    // convert_to_binary(x,120);
    // write_img(x,"../out/blackbuck_bn.bmp");

    // _add_padding(x,1);
    // write_img(x,"../out/blackbuck_add_padding_odd.bmp");

    // _add_padding(x,2);
    // write_img(x,"../out/blackbuck_add_padding_even.bmp");

    convolution(x,3,1,2);
    write_img(x,"../out/res4.bmp");

    return 0;
}