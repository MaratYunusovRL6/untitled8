#include <iostream>
#include <string>
#include<cstdio>
#include<cstring>
using namespace std;
class WorkWithFile{
private:
    char* dataOfFile;
public:
    WorkWithFile(const char* fileName){
        FILE*res=fopen(fileName,"r");
        fseek(res,0,SEEK_END);
        int size=ftell(res);
        dataOfFile=new char[size];
    }
    ~WorkWithFile(){
        delete[] dataOfFile;
    }
    void check(){
        for(int i=0;i<sizeof(dataOfFile);i++){
            cout<<dataOfFile[i];
        }
    }
    void readFromFile(const char* fileName){
        FILE *res=fopen(fileName,"r");
        char buf;
        int k=0;
        while((fscanf(res,"%c",&buf)!=EOF)){
            dataOfFile[k]=buf;
            k++;
        }
        dataOfFile[k]='\0';
        fclose(res);
    }
    void writeToFile(const char* fileName){
        FILE*res=fopen(fileName,"w");
        fprintf(res,"%s",dataOfFile);
        fclose(res);
    }
    int fileSize(const char* fileName){
        FILE*res=fopen(fileName,"r");
        fseek(res,0,SEEK_END);
        int size=ftell(res);
        return(size);
    }
};
int main() {
    WorkWithFile a("1.txt");
    a.readFromFile("1.txt");
    a.writeToFile("2.txt");
    cout<< endl <<a.fileSize("1.txt")<<"\t"<<a.fileSize("2.txt")<<endl;
}
