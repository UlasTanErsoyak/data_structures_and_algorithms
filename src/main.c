#include "include/bmp_image.h"
int main() {
    struct bmp_image* x=read_img("../img/Lenna.bmp");
    write_img(x,"../out/none.bmp");

    // convert_to_bw(x);
    // write_img(x,"../out/blackbuck_bw.bmp");
    // blur(x);
    // write_img(x,"../out/blur.bmp");
    v_edge(x);
    write_img(x,"../out/vedge.bmp");

    // g_blur(x,3);
    // write_img(x,"../out/gblur.bmp");
    return 0;
}