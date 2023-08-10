#include "include/bmp_image.h"
int main() {
    struct bmp_image* x=read_img("../img/bmp_24.bmp");
    // convert_to_bw(x);
    // convert_to_binary(x,90);
    _add_padding(x,10);
    write_img(x,"../img/test.bmp");
    return 0;
}
