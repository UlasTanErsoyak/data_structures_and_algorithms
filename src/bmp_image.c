#include "include/bmp_image.h"
struct bmp_header _read_header(const char* file_path){
    FILE* bmp_file=fopen(file_path,"rb");
    if(bmp_file==NULL){
        printf("error [bmp_image:_read_header]->couldn't open file %s",file_path);
        exit(1);
    }
    struct bmp_header header;
    fread(&header,sizeof(struct bmp_header),1,bmp_file);
    if(header.signature!=0x4D42){
        printf("erorr [bmp_image:_read_header]->unvalid signature from %s.expected 0X4D41 got %04Xd",file_path,header.signature);
        fclose(bmp_file);
        exit(1);
    }
    uint8_t* bmp_content=(uint8_t*)malloc(header.file_size);
    if(bmp_content==NULL) {
        printf("error [bmp_image:_read_header]->memory allocation failed for %s",file_path);
        fclose(bmp_file);
        exit(1);
    }
    return header;
}
struct pixel* _read_pixels(const struct bmp_header* header){
    struct pixel* pixels=(struct pixel*)malloc(header->height*header->width*sizeof(struct pixel));
    if(pixels==NULL){
        printf("error [bmp_image:_read_pixels]->memory allocation failed for pixels");
        exit(1);
    }
    
}
struct bmp_image read_img(const char* file_path){
    struct bmp_header header=_read_header(file_path);
}