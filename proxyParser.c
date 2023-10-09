#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define FILE_SIZE 100

typedef struct{
    char* IP;
    unsigned int Port;
    char* Protocol;
    int Latency;
   
    char* Country;  
    char* Anonymity;

    char* User;         //NOT USED
    char* Password;     //NOT USED

}ProxySettings;

FILE* parseFile(FILE* input, int NoLines){
    FILE* output = fopen("OutputFile.txt", "a");
    ProxySettings *Proxydata;
    
    char line[512];
    while(fgets(line, sizeof(line), input)){
        sscanf( line,"%[0-9.] %[1-9]", Proxydata->IP, Proxydata->Port,Proxydata->Protocol,Proxydata->Country);
        
        
        
        printf("%s",line);
    }
    
    
    return output;
};

char **split(char **argv, int *argc, const char *str, const char *delimiter, int allowempty)
{
    char *string = malloc(strlen(str + 1));
    strcpy(string, str);
    *argc = 0;
    do
    {
        if(*string && (!strchr(delimiter, *string) || allowempty))
        {
            argv[(*argc)++] = string;
        }
        while(*string && !strchr(delimiter, *string)) string++;
        if(*string) *string++ = 0;
        if(!allowempty) 
            while(*string && strchr(delimiter, *string)) string++;
    }while(*string);

    for(int arg = 3; arg < *argc - 5 - 1; arg++)
    {
        argv[3][strlen(argv[3])] = ' ';
        memmove(&argv[4], &argv[arg + 2], sizeof(*argv) * (*argc - 4));
        *argc -= 1;
    }
    return argv;
}

int main(int argc,char* argv[]){

    char* DataFile = NULL;
    int num;
    if (argc <= 2) {
        printf("Enter file for parsing (relative or absolute): ");
        size_t bufsize = FILE_SIZE;
        DataFile = (char*)malloc(bufsize);

        if (DataFile == NULL) {
            perror("Not enough free memory"); 
            return EXIT_FAILURE;
        }

        if (fgets(DataFile, bufsize, stdin) == NULL) {
            perror("Error reading input");
            free(DataFile);
            return EXIT_FAILURE;
        }
        
        DataFile[strlen(DataFile)-1] = 0;
        
    } else {
        DataFile = argv[1];
    }

    char* end;
    int ChangeOutputSequence = strtol(argv[2], &end, 10 );
    if (ChangeOutputSequence == 1 && argc == 3){
        printf("Enter custom output sequence:\n"
        "1.IP\n2.Port\n3.Protocol\n4.Latency'\n"
        "5.Country\n6.Anonymity\n7.User\n8.Password\n");
    }


    FILE* fd = fopen(DataFile, "r");
    if (fd == NULL) {
        perror("Cannot open input file");
        free(DataFile); 
        exit(EXIT_FAILURE);
    } else {
        printf("Opened input file\n");
    }

  
    // FILE* OutputFile = parseFile(fd, NoLines);
    

    // fclose(OutputFile);
    fclose(fd);
   
    if (argc < 2){
        free(DataFile);
    };

    return 0;
}