#include <iostream>
int **make(int r,int l);
void output(const int *const* mtx);
void rm(int **mtx, int r, int c);
int main(){
    int rows=0;
    int cols=0;
    std::cin>>rows>>cols;
    if(std::cin.fail()){
        return 1;
    }
    int **mtx=nullptr;
    mtx=make(rows,cols);
    output(mtx);
    rm(mtx);
}
void rm(int **mtx, int r, int c){
  for(size_t i=0;i<r;++i){
    delete[] mtx[i];
  }
  delete[] mtx;
}