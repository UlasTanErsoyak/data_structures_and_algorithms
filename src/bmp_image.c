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
    }    return header;
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
            int luminosity=0.21*image->pixels[i][j].red+0.72*image->pixels[i][j].green+0.07*image->pixels[i][j].blue;
            luminosity=(luminosity<0)?0:(luminosity>255)?255:luminosity;
            image->pixels[i][j].red=luminosity;
            image->pixels[i][j].green=luminosity;
            image->pixels[i][j].blue=luminosity;
        }
    }
}
void convert_to_binary(struct bmp_image* image,const int8_t threshold){
    for(int i=0;i<image->header.height;i++){
        for(int j=0;j<image->header.width;j++){
            uint8_t avg=(image->pixels[i][j].red+image->pixels[i][j].green+image->pixels[i][j].blue)/3;
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
static void _add_padding(struct bmp_image* image){
    int new_width=image->header.width+2*PADDING_OFFSET;
    int new_height = image->header.height+2*PADDING_OFFSET;
    struct pixel** output_pixels=(struct pixel**)malloc(new_height*sizeof(struct pixel*));
    for (int i=0;i<new_height;i++){
        output_pixels[i]=(struct pixel*)calloc(new_width,sizeof(struct pixel));
    }
    for (int i=PADDING_OFFSET;i<image->header.height+PADDING_OFFSET;i++){
        for (int j=PADDING_OFFSET;j<image->header.width+PADDING_OFFSET;j++){
            output_pixels[i][j]=image->pixels[i-PADDING_OFFSET][j-PADDING_OFFSET];
        }
    }
    for (int i=0;i<image->header.height;i++){
        free(image->pixels[i]);
    }
    free(image->pixels);
    image->pixels=output_pixels;
}
void convolution(struct bmp_image* image){
    struct pixel** output_pixels=(struct pixel**)malloc(image->header.height*sizeof(struct pixel*));
    for (int i=0;i<image->header.height;i++){
        output_pixels[i]=(struct pixel*)malloc(image->header.width*sizeof(struct pixel));
    }
    _add_padding(image);
    int kernel[3][3]={{1,1,1},{1,1,1},{1,1,1}};
    int r_sum=0;
    int g_sum=0;
    int b_sum=0;
    for (int i=PADDING_OFFSET;i<image->header.height+PADDING_OFFSET;i++){
        for (int j=PADDING_OFFSET;j<image->header.width+PADDING_OFFSET;j++){
            r_sum=0;
            g_sum=0;
            b_sum=0;
            for(int ki=-1;ki<2;ki++){
                for(int kj=-1;kj<2;kj++){
                    int x_idx=i+ki;
                    int y_idx=j+kj;
                    r_sum+=kernel[ki+1][kj+1]*(image->pixels[x_idx][y_idx].red);
                    b_sum+=kernel[ki+1][kj+1]*(image->pixels[x_idx][y_idx].blue);
                    g_sum+=kernel[ki+1][kj+1]*(image->pixels[x_idx][y_idx].green);
                }
            }
            output_pixels[i-PADDING_OFFSET][j-PADDING_OFFSET].red=(int)r_sum/9;
            output_pixels[i-PADDING_OFFSET][j-PADDING_OFFSET].green=(int)g_sum/9;
            output_pixels[i-PADDING_OFFSET][j-PADDING_OFFSET].blue=(int)b_sum/9;
        }
    }
    for (int i=0;i<image->header.height;i++){
        free(image->pixels[i]);
    }
    free(image->pixels);
    image->pixels=output_pixels;
    // _normalize_img(image);
}
static void _normalize_img(struct bmp_image* image){
    int r_max_value=0;
    int g_max_value=0;
    int b_max_value=0;
    int r_min_value=255;
    int g_min_value=255;
    int b_min_value=255;
    for (int i=0;i<image->header.height;i++) {
        for (int j=0;j<image->header.width;j++) {
            r_max_value=max(r_max_value,image->pixels[i][j].red);
            g_max_value=max(g_max_value,image->pixels[i][j].green);
            b_max_value=max(b_max_value,image->pixels[i][j].blue);
            r_min_value=min(r_min_value,image->pixels[i][j].red);
            g_min_value=min(g_min_value,image->pixels[i][j].green);
            b_min_value=min(b_min_value,image->pixels[i][j].blue);
        }
    }
    for (int i=0;i<image->header.height;i++) {
        for (int j=0;j<image->header.width;j++) {
            image->pixels[i][j].red=(int)(((double)(image->pixels[i][j].red-r_min_value)/(r_max_value-r_min_value))*255);
            image->pixels[i][j].green=(int)(((double)(image->pixels[i][j].green-g_min_value)/(g_max_value-g_min_value))*255);
            image->pixels[i][j].blue=(int)(((double)(image->pixels[i][j].blue-b_min_value)/(b_max_value-b_min_value))*255);
        }
    }
}

void blur(struct bmp_image* image){
    //TODO
}