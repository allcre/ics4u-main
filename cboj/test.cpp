#include <iostream> 

int main(){ 
    int X, Y, A, B, C = 0; 
    std::cin >> X >> Y >> A >> B; 
    int P[X][Y]; 
    for(int i = 0; i < X; i++) 
        for(int j = 0; j < Y; j++) 
        std::cin >> P[i][j]; 
    
    for(int i = 0; i < X; i++) { 
        for(int j = 0; j < Y; j++) { 
            std::cout << P[i][j] << " "; 
            C++; 
            if(C == B) { 
                std::cout << std::endl; 
                C = 0; 
            } 
        } 
    } 
    return 0; 
}