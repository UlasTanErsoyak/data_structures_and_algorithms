#include "include/bmp_image.h"
int main() {
    struct bmp_image* x=read_img("../img/blackbuck.bmp");
    write_img(x,"../out/test1.bmp");
    _add_padding(x,15);
    write_img(x,"../out/test3.bmp");
    return 0;
}