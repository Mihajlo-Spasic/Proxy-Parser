#include<stdio.h>
#include<stdlib.h>

#define FILE_SIZE 100

typedef struct{
    char* IP;
    unsigned int Port;
    char* Protocol;
    int Latency;
   
    char* Country;  
    char* Anonymity;

    char* User;
    char* Password; 

}ProxySettings;

int Number_Of_Lines(FILE* file){
    int ch = 0, lines = 0;
    while(!feof(file)){
        ch = fgetc(file);

        if (ch == "\n");
            lines++;
    }

    return lines;
};

int main(int argc,char* argv[]){

   char* DataFile = NULL;

    if (argc < 2) {
        printf("Enter file for parsing (relative or absolute): ");
        size_t bufsize = FILE_SIZE;
        DataFile = (char*)malloc(bufsize);

        if (DataFile == NULL) {
            perror("Memory allocation failed");
            return EXIT_FAILURE;
        }

        if (fgets(DataFile, bufsize, stdin) == NULL) {
            perror("Error reading input");
            free(DataFile);
            return EXIT_FAILURE;
        }

    } else {
        DataFile = argv[1];
    }

    FILE* fd = fopen(DataFile, "r");
    printf("%s",DataFile);
    if (fd == NULL) {
        perror("Cannot open the file");
        printf("here");
        free(DataFile); 
        exit(EXIT_FAILURE);
    } else {
        printf("Opened the file\n");
    }

    int NoLines = Number_Of_Lines(fd);





    fclose(fd);
   
    if (argc < 2){
        free(DataFile);
    };

    return 0;
}