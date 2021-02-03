/*
 * Author: Owen Li 
 * E-mail: gz_li@outlook.com
 * 
 * This file is for exercise audio/video process
 */  
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//char[128] OUTPUT_PATH = "/opt/avbasic/output/";

void yuv420p_split(char* url, int w, int h)
{
    FILE* fpInput = fopen(url, "rb+");
    
    mkdir("/opt/avbasic/output/yuv420p", 0777);
    FILE* fpOutputY = fopen("/opt/avbasic/output/yuv420p/yuv420_y.y", "wb+");
    FILE* fpOutputU = fopen("/opt/avbasic/output/yuv420p/yuv420_u.y", "wb+");
    FILE* fpOutputV = fopen("/opt/avbasic/output/yuv420p/yuv420_v.y", "wb+");

    unsigned char* pic = (unsigned char*)malloc((w*h*3)/2);

    fread(pic, 1, (w*h*3)/2, fpInput);
    fwrite(pic, 1, w*h, fpOutputY);
    fwrite(pic+w*h, 1, (w*h)/4, fpOutputU);
    fwrite(pic+(w*h*5)/4, 1, (w*h)/4, fpOutputV);
    
    fclose(fpOutputV);
    fclose(fpOutputU);
    fclose(fpOutputY);
    fclose(fpInput);
    free(pic);
}



void yuv444p_split(char* url, int w, int h)
{
    FILE* fpInput = fopen(url, "rb+");

    mkdir("/opt/avbasic/output/yuv444p", 0777);
    FILE* fpOutputY = fopen("/opt/avbasic/output/yuv444p/yuv444p_y.y", "wb+");
    FILE* fpOutputU = fopen("/opt/avbasic/output/yuv444p/yuv444p_u.y", "wb+");
    FILE* fpOutputV = fopen("/opt/avbasic/output/yuv444p/yuv444p_v.y", "wb+");

    unsigned char* pic = (unsigned char*)malloc(w*h*3);

    fread(pic, 1, w*h*3, fpInput);
    fwrite(pic, 1, w*h, fpOutputY);
    fwrite(pic+w*h, 1, w*h, fpOutputU);
    fwrite(pic+w*h*2, 1, w*h, fpOutputV);

    fclose(fpOutputV);
    fclose(fpOutputU);
    fclose(fpOutputY);
    fclose(fpInput);
    free(pic);

}

void yuv420p_gray(char* url, int w, int h)
{
    FILE* fpInput = fopen(url, "rb+");

    mkdir("/opt/avbasic/output/yuv420p_gray", 0777);
    FILE* fpOutputY = fopen("/opt/avbasic/output/yuv420p_gray/yuv420pgray_y.y", "wb+");
    //FILE* fpOutputU = fopen("/opt/avbasic/output/yuv420p_gray/yuv420pgray_u.y", "wb+");
    //FILE* fpOutputV = fopen("/opt/avbasic/output/yuv420p_gray/yuv420pgray_v.y", "wb+");

    unsigned char* pic = (unsigned char*)malloc((w*h*3)>>1);

    fread(pic, 1, (w*h*3)>>1, fpInput);
    memset(pic+w*h, 128, (w*h)>>1);
    fwrite(pic, 1, (w*h*3)>>1, fpOutputY);
    //fwrite(pic+w*h, 1, w*h, fpOutputU);
    //fwrite(pic+w*h*2, 1, w*h, fpOutputV);

    //fclose(fpOutputV);
    //fclose(fpOutputU);
    fclose(fpOutputY);
    fclose(fpInput);
    free(pic);

}

void yuv420p_harfy(char* url, int w, int h)
{
    FILE* fpInput = fopen(url, "rb+");

    mkdir("/opt/avbasic/output/yuv420p_harfy", 0777);
    FILE* fpOutputY = fopen("/opt/avbasic/output/yuv420p_harfy/yuv420pharfy_y.y", "wb+");

    unsigned char* pic = (unsigned char*)malloc((w*h*3)>>1);

    fread(pic, 1, (w*h*3)>>1, fpInput);

    int i;
    unsigned char* temp = pic;
    for(i = 0; i < w*h; i++){
        *temp = (*temp)>>1;
         temp++;
    }
    fwrite(pic, 1, (w*h*3)>>1, fpOutputY);

    fclose(fpOutputY);
    fclose(fpInput);
    free(pic);

}

void yuv420p_border(char* url, int w, int h, int border)
{
    FILE* fpInput = fopen(url, "rb+");

    mkdir("/opt/avbasic/output/yuv420p_border", 0777);
    FILE* fpOutputY = fopen("/opt/avbasic/output/yuv420p_border/yuv420pborder_y.y", "wb+");

    unsigned char* pic = (unsigned char*)malloc((w*h*3)>>1);

    fread(pic, 1, (w*h*3)>>1, fpInput);

    int i, j;
    unsigned char* temp = pic;
    for(i = 0; i < h; i++){
        for(j =0; j< w; j++){
            if( (j<border) || (j>(w-border)) || (i<border) || (i>(h-border)))
            {
 	        pic[i*h+j] = 0;
            }      
        }
    }
    fwrite(pic, 1, (w*h*3)>>1, fpOutputY);

    fclose(fpOutputY);
    fclose(fpInput);
    free(pic);
}


void yuv420p_graybar(int w, int h, int ymin, int ymax, int barnum)
{

    mkdir("/opt/avbasic/output/yuv420p_graybar", 0777);
    FILE* fpOutput = fopen("/opt/avbasic/output/yuv420p_graybar/yuv420p_graybar.yuv", "wb+");

    unsigned char* pic = (unsigned char*)malloc((w*h*3)>>1);

    unsigned int ybar[barnum];
    memset(ybar, 0, sizeof(ybar));

    int k;
    unsigned int step = (ymax-ymin)/barnum;
    for(k = 0; k < barnum; k++)
    {
        ybar[k] = step*k;
        printf("ybar-%d: %d\n",k, ybar[k]);
    }

    
    int i, j;
    unsigned char* temp = pic;
    unsigned int w_step = w/barnum;

    for(i = 0; i < barnum; i++){
        for(j = 0; j< h; j++){
            memset(pic+w*j+w_step*i, ybar[i], w_step);
            //printf("barnum=%d, y=%d, pic=%d\n", i, ybar[i], *(pic+w*j+w_step*i));
        }
    }
/*
    for(i =0; i < h; i++)
    {
        for(j = 0; j < w; j++)
        {
	    printf("%d-", *(pic+i*w+j));
        }
        printf("\n");
    }
*/
    memset(pic+w*h, 64, (w*h)>>1);
    fwrite(pic, 1, (w*h*3)>>1, fpOutput);

    fclose(fpOutput);
    free(pic);
}


void rgb24_split(char* url, int w, int h)
{
    FILE* fpInput = fopen(url, "rb+");

    mkdir("/opt/avbasic/output/rgb24_split", 0777);
    FILE* fpOutputR = fopen("/opt/avbasic/output/rgb24_split/r.y", "wb+");
    FILE* fpOutputG = fopen("/opt/avbasic/output/rgb24_split/g.y", "wb+");
    FILE* fpOutputB = fopen("/opt/avbasic/output/rgb24_split/b.y", "wb+");

    unsigned char* pic = (unsigned char*)malloc(w*h*3);
    fread(pic, 1, w*h*3, fpInput);
    int i, j;
    for(i =0; i < h; i++)
    {
        for(j =0; j < w; j+=3)
        {
            fwrite(pic+i*w+j, 1, 1, fpOutputR);
	    fwrite(pic+i*w+j+1, 1, 1, fpOutputG);
            fwrite(pic+i*w+j+2, 1, 1, fpOutputB);
        }
    }

    fclose(fpOutputR);
    fclose(fpOutputG);
    fclose(fpOutputB);
    fclose(fpInput);
    free(pic);
}


typedef  struct  tagBITMAPFILEHEADER  
{   
//unsigned char  bfType[2];       //位图文件的类型，必须为BM   
unsigned int       bfSize;       //文件大小，以字节为单位  
unsigned short int  bfReserverd1; //位图文件保留字，必须为0   
unsigned short int  bfReserverd2; //位图文件保留字，必须为0   
unsigned int       bfbfOffBits;  //位图文件头到数据的偏移量，以字节为单位  
}FileHeader;  
 
typedef  struct  tagBITMAPINFOHEADER   
{   
int biSize;                        //该结构大小，字节为单位  
int  biWidth;                     //图形宽度以象素为单位  
int  biHeight;                     //图形高度以象素为单位  
short int  biPlanes;               //目标设备的级别，必须为1   
short int  biBitcount;             //颜色深度，每个象素所需要的位数  
int   biCompression;        //位图的压缩类型  
int  biSizeImage;              //位图的大小，以字节为单位  
unsigned int  biXPelsPermeter;       //位图水平分辨率，每米像素数  
unsigned int  biYPelsPermeter;       //位图垂直分辨率，每米像素数  
int  biClrUsed;            //位图实际使用的颜色表中的颜色数  
int  biClrImportant;       //位图显示过程中重要的颜色数  
}InfoHeader;  


void rgb24_to_bmp(char* url, int w, int h)
{
    FILE* fpInput = fopen(url, "rb+");

    mkdir("/opt/avbasic/output/rgb24_to_bmp", 0777);
    FILE* fpOutput = fopen("/opt/avbasic/output/rgb24_to_bmp/output.bmp", "wb+");

    unsigned char* pic = (unsigned char*)malloc(w*h*3);
    fread(pic, 1, w*h*3, fpInput);
    

    FileHeader* fileheader = (FileHeader*)malloc(sizeof(FileHeader));
    InfoHeader* infoheader = (InfoHeader*)malloc(sizeof(InfoHeader));
    
    int  head_size = sizeof(FileHeader) + sizeof(InfoHeader);
    unsigned char bfType[2]={'B','M'};
    
    //strncpy(fileheader->bfType, bfType, 2);
    //fileheader->bfType ={'B', 'M'};
    fileheader->bfSize = head_size + w*h*3;
    fileheader->bfReserverd1 = 0;
    fileheader->bfReserverd2 = 0;
    fileheader->bfbfOffBits = head_size;

    infoheader->biSize = sizeof(InfoHeader);
    infoheader->biWidth = w;
    infoheader->biHeight = -h;
    infoheader->biPlanes = 1;
    infoheader->biBitcount = 24;
    infoheader->biCompression = 3;
    infoheader->biSizeImage = w*h*3;
    //infoheader->biXPelsPermeter = w;
    //infoheader->biYPelsPermeter = h;

    fwrite(bfType, 1, sizeof(bfType), fpOutput);
    fwrite(fileheader, 1, sizeof(FileHeader), fpOutput);
    fwrite(infoheader, 1, sizeof(InfoHeader), fpOutput); 
    
    printf("fileheader->bfSize =%d\n", fileheader->bfSize);
    printf("fileheader->bfReserverd1 =%d\n", fileheader->bfReserverd1);
    printf("fileheader->bfReserverd2 =%d\n", fileheader->bfReserverd2);    
    printf("fileheader->bfbfOffBits =%d\n", fileheader->bfbfOffBits);

    printf("before\n");
    int i, j;
    for(i =10; i < 11; i++)
    {
        for(j =0; j < 3*w; j+=3)
        {
            printf("%d-%d-%d***", pic[i*w+j], pic[i*w+j+1], pic[i*w+j+2]);
        }
        printf("\n");
    }
    

    for(i =0; i < h; i++)
    {   
        for(j =0; j < w*3; j+=3)
        {
            //printf("Line-%d, Piexl-%d\n", i, j);
            unsigned char temp = pic[i*w*3+j];
            pic[i*w*3+j] = pic[i*w*3+j+2];
            pic[i*w*3+j+2] = temp;
        }
    }
    printf("after\n");
    for(i =10; i < 11; i++)
    {
        for(j =0; j < 3*w; j+=3)
        {
            printf("%d-%d-%d***", pic[i*w+j], pic[i*w+j+1], pic[i*w+j+2]);
        }
        printf("\n");
    }

    fwrite(pic, 1, w*h*3, fpOutput);

    fclose(fpOutput);
    fclose(fpInput);
    free(pic);
}


void rgb24_to_yuv420p(char* url, int w, int h)
{
    FILE* fpInput = fopen(url, "rb+");

    mkdir("/opt/avbasic/output/rgb24_to_yuv420p", 0777);
    FILE* fpOutput = fopen("/opt/avbasic/output/rgb24_to_yuv420p/rgb24_to_yuv420p.yuv", "wb+");

    unsigned char* rgbBuffer = (unsigned char*)malloc(w*h*3+1);
    unsigned char* yuvBuffer = (unsigned char*)malloc(((w*h*3)>>1)+1);
    unsigned char* yBuffer = (unsigned char*)malloc(w*h);
    unsigned char* uBuffer =(unsigned char*)malloc(((w*h)>>2)+1); 
    unsigned char* vBuffer =(unsigned char*)malloc(((w*h)>>2)+1);
/*
    rgbBuffer[sizeof(*rgbBuffer)-1] = '\0';
    yuvBuffer[sizeof(*yuvBuffer)-1] = '\0';
    yBuffer[sizeof(*yBuffer)-1] = '\0';
    uBuffer[sizeof(*uBuffer)-1] = '\0';
    vBuffer[sizeof(*vBuffer)-1] = '\0';
*/

    unsigned char* rgbBufferPos = rgbBuffer;
    unsigned char* yBufferPos = yBuffer;
    unsigned char* uBufferPos = uBuffer;
    unsigned char* vBufferPos = vBuffer;

    fread(rgbBuffer, 1, w*h*3, fpInput);

    int i, j;
    unsigned char r, g, b, y, u, v;
    for(i = 0; i < h; i++){

        printf("\nLine: %d\n", i);

        for(j = 0; j < w*3; j+=3)
        {
            r = *(rgbBufferPos++);
            g = *(rgbBufferPos++);
            b = *(rgbBufferPos++);
            //printf("r=%d, g=%d, b=%d", r, g, b);
            *(yBufferPos++) = (unsigned char)( ( 66 * r + 129 * g +  25 * b + 128) >> 8) + 16;
            
	    if((i%2 == 0) && ((j/3)%2 == 0)){
                *(uBufferPos++) = (unsigned char)( ( -38 * r -  74 * g + 112 * b + 128) >> 8) + 128;
                *(vBufferPos++) = (unsigned char)( ( 112 * r -  94 * g -  18 * b + 128) >> 8) + 128; 
            }
 
            if(i < 4){

                //printf("Line: %d\n", i);
                printf("Point(%d, %d): r=%d, g=%d, b=%d, y=%d\n", i, j/3, r, g, b, *(yBufferPos-1));
                if((i%2 == 0) && ((j/3)%2 == 0)){
                    printf("Point(%d, %d): u=%d, v=%d\n", i, j/3, *(uBufferPos-1), *(vBufferPos-1));
                }
            }

        }
      
    }
    yBufferPos+=1003;
    yBufferPos++;
    printf("yBufferPos=%d\n", *(++yBufferPos));
    strcat(yuvBuffer, yBuffer);
    strcat(yuvBuffer, uBuffer);
    strcat(yuvBuffer, vBuffer);

    fwrite(yuvBuffer, 1, (w*h*3)>>1, fpOutput);

    fclose(fpOutput);
    fclose(fpInput);

    free(yBuffer);
    free(uBuffer);
    free(vBuffer);
    free(rgbBuffer);
    free(yuvBuffer); 

}

void rgb24_to_colorbar(int w, int h)
{
    
    mkdir("/opt/avbasic/output/rgb24_to_colorbar", 0777);
    FILE* fpOutput = fopen("/opt/avbasic/output/rgb24_to_colorbar/rgb24_to_colorbar.rgb", "wb+");

    unsigned char* rgbBuffer = (unsigned char*)malloc(w*h*3+1);

    int i, j, barnum;
    int barwidth = w/8;
    for(i = 0; i < h; i++){

        printf("\nLine: %d\n", i);
               
        for(j = 0; j < w*3; j+=3)
        {
            barnum = j / (3*barwidth);
            //printf("barnum=%d \n", barnum);
            switch(barnum){
                case 0:
                    rgbBuffer[i*w*3+j+0] = 255;
                    rgbBuffer[i*w*3+j+1] = 255;
                    rgbBuffer[i*w*3+j+2] = 255;
                    break;
                case 1:
                    rgbBuffer[i*w*3+j+0] = 255;
                    rgbBuffer[i*w*3+j+1] = 255;
                    rgbBuffer[i*w*3+j+2] = 0;
                    break;
                case 2:
                    rgbBuffer[i*w*3+j+0] = 0;
                    rgbBuffer[i*w*3+j+1] = 255;
                    rgbBuffer[i*w*3+j+2] = 255;
                    break;
                case 3:
                    rgbBuffer[i*w*3+j+0] = 0;
                    rgbBuffer[i*w*3+j+1] = 255;
                    rgbBuffer[i*w*3+j+2] = 0;
                    break;
                case 4:
                    rgbBuffer[i*w*3+j+0] = 255;
                    rgbBuffer[i*w*3+j+1] = 0;
                    rgbBuffer[i*w*3+j+2] = 255;
                    break;
                case 5:
                    rgbBuffer[i*w*3+j+0] = 255;
                    rgbBuffer[i*w*3+j+1] = 0;
                    rgbBuffer[i*w*3+j+2] = 0;
                    break;
                case 6:
                    rgbBuffer[i*w*3+j+0] = 0;
                    rgbBuffer[i*w*3+j+1] = 0;
                    rgbBuffer[i*w*3+j+2] = 255;
                    break;
                case 7:
                    rgbBuffer[i*w*3+j+0] = 0;
                    rgbBuffer[i*w*3+j+1] = 0;
                    rgbBuffer[i*w*3+j+2] = 0;
                    break;
                default:
                    break;

           }
           
        }
    }


    fwrite(rgbBuffer, 1, w*h*3, fpOutput);
    fclose(fpOutput);
    free(rgbBuffer);
}


/***********************************************************************************/
/* PCM samples start*/
/***********************************************************************************/
void pcm16le_split(char*url){

    if(url == NULL){
        return;
    }

    mkdir("/opt/avbasic/output/pcm16le_split", 0777);
    FILE* fpInput = fopen(url, "rb");
    
    FILE* fpOutputLeft = fopen("/opt/avbasic/output/pcm16le_split/pcm16le_split_left.pcm", "wb+");
    FILE* fpOutputRight = fopen("/opt/avbasic/output/pcm16le_split/pcm16le_split_right.pcm", "wb+");

    char* buff = (char* )malloc(4);
    while(!feof(fpInput)){
        fread(buff, 1, 4, fpInput);
        fwrite(buff, 1, 2, fpOutputLeft);
        fwrite(buff+2, 1, 2, fpOutputRight);
    }
    
    free(buff);
    fclose(fpOutputRight);
    fclose(fpOutputLeft);
    fclose(fpInput);
}

void pcm16le_halfleft(char*url){

    if(url == NULL){
        return;
    }

    mkdir("/opt/avbasic/output/pcm16le_halfleft", 0777);
    FILE* fpInput = fopen(url, "rb");

    FILE* fpOutputLeft = fopen("/opt/avbasic/output/pcm16le_halfleft/pcm16le_halfleft.pcm", "wb+");
    //FILE* fpOutputRight = fopen("/opt/avbasic/output/pcm16le_split/pcm16le_split_right.pcm", "wb+");

    char* buff = (char* )malloc(4);
    short* buffLeft;
    while(!feof(fpInput)){
        fread(buff, 1, 4, fpInput);
        buffLeft = (short*)buff;
        *buffLeft = *buffLeft / 2;
         
        fwrite((char*)buff, 1, 2, fpOutputLeft);
        fwrite(buff+2, 1, 2, fpOutputLeft);
    }

    free(buff);
    //fclose(fpOutputRight);
    fclose(fpOutputLeft);
    fclose(fpInput);
}
void pcm16le_doublespeed(char*url){

    if(url == NULL){
        return;
    }

    mkdir("/opt/avbasic/output/pcm16le_doublespeed", 0777);
    FILE* fpInput = fopen(url, "rb");

    FILE* fpOutput = fopen("/opt/avbasic/output/pcm16le_doublespeed/pcm16le_doublespeed.pcm", "wb+");

    char* buff = (char*)malloc(4);
    int cnt = 0;
    while(!feof(fpInput)){
        
        fread(buff, 1, 8, fpInput);
        fwrite(buff, 1, 4, fpOutput);
    }

    free(buff);
    fclose(fpOutput);
    fclose(fpInput);
}

void pcm16le_16to8(char*url) {


    if(url == NULL){
        return;
    }

    mkdir("/opt/avbasic/output/pcm16le_16to8", 0777);
    FILE* fpInput = fopen(url, "rb");

    FILE* fpOutput = fopen("/opt/avbasic/output/pcm16le_16to8/pcm16le_16to8.pcm", "wb+");

    char* buff = (char*)malloc(4);
    //short* left, *right;
    //unsigned char* left_u, * right_u;
    while(!feof(fpInput)){
      
        short* left, *right;
        unsigned char* left_u, * right_u;

        fread(buff, 1, 4, fpInput);
        left = (short*)buff;
        right = (short*)(buff + 2);
        
        *left = (*left)>>8;
        //*left_u = *left + 127;
        
        *right = (*right)>>8;
        //*right_u = *right + 127;

        fwrite(left, 1, 1, fpOutput);
        fwrite(right, 1, 1, fpOutput);
    }

    free(buff);
    fclose(fpOutput);
    fclose(fpInput);

}

/***********************************************************************************/
/* PCM samples end*/
/***********************************************************************************/

int main(int argc,  char** argv)
{
    mkdir("/opt/avbasic/output", 0777);
    //yuv420p_split("/opt/avbasic/res/lena_256x256_yuv420p.yuv", 256, 256);
    //yuv444p_split("/opt/avbasic/res/lena_256x256_yuv444p.yuv", 256, 256);
    //yuv420p_gray("/opt/avbasic/res/lena_256x256_yuv420p.yuv", 256, 256);
    //yuv420p_harfy("/opt/avbasic/res/lena_256x256_yuv420p.yuv", 256, 256);
    //yuv420p_border("/opt/avbasic/res/lena_256x256_yuv420p.yuv", 256, 256, 20); 
    //yuv420p_graybar(640, 320, 0, 255, 10);
    //rgb24_split("/opt/avbasic/res/cie1931_500x500.rgb", 500, 500);    
    //rgb24_to_bmp("/opt/avbasic/res/lena_256x256_rgb24.rgb", 256, 256);
    //rgb24_to_yuv420p("/opt/avbasic/res/lena_256x256_rgb24.rgb", 256, 256);
    //rgb24_to_colorbar(352, 288);

    //pcm16le_split("/opt/avbasic/res/NocturneNo2inEflat_44.1k_s16le.pcm");
    //pcm16le_halfleft("/opt/avbasic/res/NocturneNo2inEflat_44.1k_s16le.pcm");
    //pcm16le_doublespeed("/opt/avbasic/res/NocturneNo2inEflat_44.1k_s16le.pcm");
    pcm16le_16to8("/opt/avbasic/res/NocturneNo2inEflat_44.1k_s16le.pcm");
   


    return 0;

}
