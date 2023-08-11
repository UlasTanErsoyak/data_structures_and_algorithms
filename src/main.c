#include "include/bmp_image.h"
int main() {
    struct bmp_image* x=read_img("../img/blackbuck.bmp");
    write_img(x,"../out/res1.bmp");

    convert_to_bw(x);
    write_img(x,"../out/res2.bmp");

    convert_to_binary(x,120);
    write_img(x,"../out/res3.bmp");
    
    convolution(x,3,1,30);
    write_img(x,"../out/res4.bmp");
    return 0;
}