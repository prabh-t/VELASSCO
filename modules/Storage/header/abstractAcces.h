#ifndef abstractAcces_H
#define abstractAcces_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
class abstractAcces
{
public:
     int create(char *path, char *filename, char *data) = 0;
     const char* cat(char *path, char *filename) = 0;
     const char* grep(char *path, char *filename, char *dataToFind) = 0;
    
     const char* GetResultOnVerticesId(
                                  char* session_Id,
                                  char* model_Id,
                                  char* analysis_Id,
                                  double timeStep,
                                  char* result_Id,
                                  vector<int> vertices
                                  ) = 0;
    
    void CheckIfAllVerticesArePresent();
private:
    
    
};

#endif