#include <stdio.h>

int main()
{
    FILE *fp;
    char buffer[1024];
    scanf("%s", buffer);
    fp =fopen("order", "w");
    
    fwrite(buffer, sizeof(char),sizeof(buffer),fp);
    fclose(fp);
    return 0 ;
}