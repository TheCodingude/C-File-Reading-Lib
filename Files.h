#define FILES_IMPLEMENTATION
#ifndef FILES_H_
#define FILES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* read_file(const char* filepath);
char* read_from_stream(FILE *stream);
void write_file(char* filepath, char* data);
void write_stream(FILE *file, char* data);

#endif  // FILES_H_
#ifdef FILES_IMPLEMENTATION

char* read_file(const char* filepath){
    FILE *file = fopen(filepath, "r");

    if (file == NULL){
        return NULL;
    }

    char* final_str;
    char buffer[1024];
    
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        strcat(final_str, buffer);   
    }

    fclose(file);

    return final_str;
}

char* read_from_stream(FILE *stream){
    
    char* final_str;
    char buffer[1024];
    
    while (fgets(buffer, sizeof(buffer), stream) != NULL)
    {
        strcat(final_str, buffer);   
    }

    fclose(stream);

    return final_str;
}

char** read_file_by_lines(char* filename){

    char* final[1024];
    int len;
    char buffer[1024]; // buffer for lines
 
    FILE* file = fopen(filename, "r");

    char uwu; // yes this is the variable name 
    int i = 0; // index for the array :)b



    while(1){

        len = strlen(buffer);

        if(feof(file)){
            break;
        }
        uwu = fgetc(file);
        if (uwu == '\n'){
            buffer[len + 1] = '\0';
            final[i] = buffer;
        }else{
            buffer[len] = uwu;
        }
    }

    return final;

}

void write_file(char* filepath, char* data){
    FILE *file = fopen(filepath, "w");
    fprintf(file, data);
    fclose(file);
}

void write_to_stream(FILE *file, char* data){
    fprintf(file, data);
    fclose(file);
}



#endif
