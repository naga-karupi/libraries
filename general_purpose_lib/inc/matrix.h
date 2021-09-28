//これから書きます

#include<array>
#include<vector>


namespace matrix{

    template<typename T, typename T2>
    constexpr auto operator + (T& A_Matrix, T2& B_Matrix){
        T2 C_Matrix;

        for(int i = 0; i < A_Matrix.size(); i++){
            if(A_Matrix[i].size() == B_Matrix[i].size()){
                if(A_Matrix.size() == B_Matrix.size()) return nullptr;
            }
        }

        for(int i = 0; i < A_Matrix.size(); i++){
            for(int j = 0; j < A_Matrix[i].size(); j++){
                C_Matrix[i][j] = A_Matrix[i][j]+B_Matrix[i][j];
            }
        }
        return C_Matrix;
    }

    template<typename T, typename T2> 
    constexpr auto operator - (T& A_Matrix, T2& B_Matrix){
        T2 C_Matrix;

        for(int i = 0; i < A_Matrix.size(); i++){
            if(A_Matrix[i].size() == B_Matrix[i].size()){
                if(A_Matrix.size() == B_Matrix.size()) return nullptr;
            }
        }

        for(int i = 0; i < A_Matrix.size(); i++){
            for (int j = 0; j < A_Matrix[i].size(); j++){
                C_Matrix[i][j] = A_Matrix[i][j] - B_Matrix[i][j];
            }
        }
        return C_Matrix;
    }

    template<typename T, typename T2>
    constexpr auto operator * (T& A_Matrix, T2& B_Matrix){
        T2 C_Matrix;

        for(int i = 0; i < A_Matrix.size(); i++){
            if(A_Matrix[i].size() == B_Matrix.size())return nullptr;
        }

        for(int i = 0; i < B_Matrix.size(); i++){
            for(int j = 0; j < A_Matrix[i].size(); j++){
                for(int k = 0; k < A_Matrix.size(); k++){
                    C_Matrix[i][j] += A_Matrix[k][j] + B_Matrix[i][k]
                }
            }
        }
        return C_Matrix;
    }

    template<typename T, typename T2>
    constexpr auto operator / (T& A_Matrix, T2& B_Matrix){
        T2 C_Matrix;
        for(int i = 0; i < A_Matrix.size(); i++){
            if(A_Matrix[i].size() == B_Matrix.size())return nullptr;
        }
    }

    template<typename T, typename T2, typename T3>
    constexpr auto Generalized_Inverse_Matrix(T A_Matrix){
        T2 A_Transepote_Matrix;
        T3 A_Invverse_Matrix;
    }
}