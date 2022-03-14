#include "helper.h"

long int find_pid(char* program) {
    char* ptr;
    int temp;
    int uid = getuid();
    struct stat info;
    DIR* entry = opendir("/proc");
    struct dirent* dir;
    while ((dir = readdir(entry))) {
        // if dir is a number
        if (sscanf(dir->d_name, "%d", &temp) == 1) {
            char path[1024] = {0};
            char line[1024] = {0};
            // TODO 2: under each process dir, there is a file that
            // can help us find the program name. First, read /proc's man page and 
            // then create an absolute path (based on "/proc/%s/[file]" template) 
            // and store it in "path" variable:
            snprintf(path, 1024, "/proc/%s/%s", getpid(), program);

            // open the special file
            FILE* special_file = fopen(path, "r");
            if (special_file == NULL) {
                perror("TODO 3 is not fixed");
                return 0;
            }

            // TODO 3-1: populate info struct for the file (i.e. path).
            stat(path);

            if (fgets(line, 1024, special_file) != NULL) {

                // TODO 3-2: this if clause checks whether the content of the special file
                // matches the program name we are looking for. Since many students/users  
                // could be running the same program, add additional condition to find the 
                // program that was run under your account (i.e., compare its uid with getuid() value in line 14)
                if (strcmp(line, program) == 0) {
                    return strtol(dir->d_name, &ptr, 10);	
                }
            }
            fclose(special_file);
        }
    }
    closedir(entry);
    return 0;
}