#include "include/bmp_image.h"
static struct bmp_header _read_header(FILE* bmp_file,char* file_path){
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
static struct pixel** _read_pixels(FILE* bmp_file,char* file_path,struct bmp_header* header){
    struct pixel** pixels=(struct pixel**)malloc(header->height*sizeof(struct pixel*));
    for (int i=0;i<header->height;i++) {
        pixels[i]=(struct pixel*)malloc(header->width*sizeof(struct pixel));
    }
    if(pixels==NULL){
        printf("error [bmp_image:_read_pixels]->memory allocation failed for %s",file_path);
        exit(1);
    }
    fseek(bmp_file,header->data_offset,SEEK_SET);
    for (int i=0;i<header->height; i++) {
        fread(pixels[i],sizeof(struct pixel),header->width,bmp_file);
    }
    return pixels;
}
/*reads the file on the given path.returns a struct pointer that has the header info,all pixels as an array and file_path as fields.*/
struct bmp_image* read_img(char* file_path){
    FILE* bmp_file=fopen(file_path,"rb");
    if(bmp_file==NULL){
        printf("error [bmp_image:read_img]->couldn't open file %s",file_path);
        exit(1);
    }
    struct bmp_header header=_read_header(bmp_file,file_path);
    struct pixel** pixels=_read_pixels(bmp_file,file_path,&header);
    struct bmp_image* image=(struct bmp_image*)malloc(sizeof(struct bmp_image));
    image->file_path=file_path;
    image->header=header;
    image->pixels=pixels;
    fclose(bmp_file);
    return image;
}
void write_img(struct bmp_image* image,char* file_name){
    FILE* bmp_file=fopen(file_name,"wb");
    if (bmp_file==NULL) {
        printf("error [bmp_image:write_img]->couldn't open file %s\n", file_name);
        exit(1);
    }
    fwrite(&image->header,sizeof(struct bmp_header),1,bmp_file);
    for (int i=0;i<image->header.height;i++) {
        fwrite(image->pixels[i],sizeof(struct pixel),image->header.width,bmp_file);
    }
    fclose(bmp_file);
}
void convert_to_bw(struct bmp_image* image){
    for (int i=0;i<image->header.height;i++) {
        for(int j=0;j<image->header.width;j++){
            int avg=(image->pixels[i][j].red+image->pixels[i][j].green+image->pixels[i][j].blue)/3;
            image->pixels[i][j].red=avg;
            image->pixels[i][j].green=avg;
            image->pixels[i][j].blue=avg;
        }
    }
}
void convert_to_binary(struct bmp_image* image,int8_t threshold){
    for(int i=0;i<image->header.height;i++){
        for(int j=0;j<image->header.width;j++){
            int avg=(image->pixels[i][j].red+image->pixels[i][j].green+image->pixels[i][j].blue)/3;
            if(avg<threshold){
                image->pixels[i][j].red=0;
                image->pixels[i][j].green=0;
                image->pixels[i][j].blue=0;
            }else{
                image->pixels[i][j].red=255;
                image->pixels[i][j].green=255;
                image->pixels[i][j].blue=255;
            }
        }
    }
}
static void _add_padding(struct bmp_image* image,int padding){
    //construct new images resolution with added padding.
    int new_height=image->header.height+padding*2;
    int new_width=image->header.width+padding*2;
    //allocate new image to the memory.
    struct pixel** pixels=(struct pixel**)malloc(new_height*sizeof(struct pixel*));
    for(int i=0;i<new_height;i++) {
        pixels[i]=malloc(new_width*sizeof(struct pixel));
    }
    //initialize new image with all zeros.
    for(int i=0;i<new_height; i++){
        memset(pixels[i],0,new_width*sizeof(struct pixel));
    }
    //wtf
    for(int i=padding;i<image->header.height+padding;i++){
        memcpy(pixels[i]+padding,image->pixels[i-padding],image->header.width*sizeof(struct pixel));
    }
    image->header.height=new_height;
    image->header.width=new_width;
    for(int i=0;i<image->header.height-2*padding;i++){
        free(image->pixels[i]);
    }
    free(image->pixels);
    image->pixels=pixels;
}
static void convolution(struct bmp_image* image,int** kernel,uint8_t kernel_size,uint8_t stride,uint8_t padding){
    if(padding>0){
        _add_padding(image,padding);
    }
    int new_height=(image->header.height-kernel_size+2*padding)/stride+1;
    int new_width=(image->header.width-kernel_size+2*padding)/stride+1;
    struct pixel** pixels =(struct pixel**)malloc(new_height*sizeof(struct pixel*));
    for (int i=0;i<new_height;i++){
        pixels[i]=malloc(new_width*sizeof(struct pixel));
    }


}
