#include "include/bmp_image.h"
int main() {
    struct bmp_image* x = read_img("../img/blackbuck.bmp");
    convert_to_bw(x);
    convert_to_binary(x,125);
    write_img(x,"../img/test.bmp");

    return 0;
}
