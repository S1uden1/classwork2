#include <iostream>
int **make(int r,int l);
void output(const int *const* mtx, int r, int c);
void rm(int **mtx, int r);
void input(int **mtx,int r, int c);
int **convert(const int *t, size_t n, const size_t *lns, size_t rows);
int main(){
    int rows=0;
    int cols=0;
    std::cin>>rows>>cols;
    if(std::cin.fail()){
        return 1;
    }
    int **mtx=nullptr;
    try{
      mtx=make(rows,cols);
    }
    catch(const std::bad_alloc){
        return 2;
    }
    input(mtx,rows,cols);
    if(std::cin.fail()){
        rm(mtx,rows);
        return 1;
    }
    output(mtx,rows,cols);
    rm(mtx,rows);
}
void rm(int **mtx, int r){
  for(size_t i=0;i<r;++i){
    delete[] mtx[i];
  }
  delete[] mtx;
}
int **make(int r, int c){
    int **mtx=new int*[r];
    for(size_t i=0;i<r;++i){
        try{
            mtx[i]=new int[c];
        }
        catch(const std::bad_alloc){
            rm(mtx,i);
            throw;
        }
    }
    return mtx;
}
void input(int **mtx,int r, int c){
    for(size_t i=0; i<r;++i){
        for(size_t j=0;j<c;++j){
            std::cin>>mtx[i][j];
        }
    }
}
void output(const int *const* mtx, int r, int c){
    for(size_t i=0;i<r;++i){
        for(size_t j=0;j<c;++j){
          std::cout<<mtx[i][j];
        }
    }
}
int **convert(const int *t, size_t n, const size_t *lns, size_t rows){
    int **res = make(rows, *lns);
    size_t s=0, p=0;
    while(s<n){
        for(size_t i=0;i<lns[p];++i){
            res[p][i] = t[s+i];
        }
        s+=lns[p++];
    }
    return res;
}