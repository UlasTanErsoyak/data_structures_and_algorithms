#include "include/bmp_image.h"

int main() {
    struct bmp_image* x = read_img("../img/bmp_24.bmp");
    for(int i=0;i<x->header.width*x->header.height;i++){
        printf("%d %d %d\n",x->pixels[i].red,x->pixels[i].green,x->pixels[i].blue);
    }
    return 0;
}
