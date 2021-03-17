#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    char imageBuf[10000];
    int fSize;
    FILE *fin, *fout;

    fin = fopen("./cross.jpg", "rb");
    fout = fopen("./test.jpg", "wb");

    fseek(fin, 0, SEEK_END); 

    fSize=ftell(fin); 

    fseek(fin, 0, SEEK_SET);

    fread(imageBuf, 1, fSize, fin);
    fclose(fin);

    int randPos = rand() % fSize;
    imageBuf[randPos] = rand() % 256;

    fwrite(imageBuf, 1, fSize, fout);

    fclose(fout);

    int status, ret, retCode;
    int crashNum = 0;
    char fileName[20]; 
    char commandBuf[200];
    sprintf(commandBuf, "./jpg2bmp test.jpg temp.bmp");
    ret = system(commandBuf);
    wait(&status);
    retCode = WEXITSTATUS(ret);
    if (retCode == 128 + 1 || retCode == 128 + 2 || retCode == 128 + 3 || retCode == 128 + 4 || retCode == 128 +  5 || retCode == 128 + 6 || retCode == 128 + 7 || retCode == 128 + 8);
    
        sprint(stderr, "file %s is generated\n", fileName)
        
     
     {
    crashNum ++;
    sprintf(fileName, "./crashed-%d.jpg", crashNum);
    fout = fopen(fileName, "wb");
    fwrite(imageBuf, 1, fSize, fout);
    fclose(fout);
     }

}