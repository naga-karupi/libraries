//これから書きます

#include<array>
#include<vector>


namespace matrix{//クラスにしようそうしよう

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
                    C_Matrix[i][j] += A_Matrix[k][j] + B_Matrix[i][k];
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

    template<typename T>
    constexpr auto Inverse_Matrix(T A_Matrix){
        T A_Inverse_Matrix;
        constexpr int sqr_Matrix_Size = A_Matrix.size();

        for(int i = 0; i < sqr_Matrix_Size; i++){
            A_Inverse_Matrix[i][i] = 1;
        }

        //掃き出し
        for(int i = 0; i < sqr_Matrix_Size; i++){
            for(int j = 0; j < sqr_Matrix_Size; j++){
                for(int k = 0; k < sqr_Matrix_Size; k++){
                    if(i != j || i != k){
                        A_Inverse_Matrix[k][j] = -A_Matrix[i][j]/A_Matrix[i][i]*A_Matrix[k][j];
                        A_Matrix[k][j] = -A_Matrix[i][j]/A_Matrix[i][i]*A_Matrix[k][j];
                    }
                }
            }
        }
        
        //掃き出し続き
        for(int i = 0; i < sqr_Matrix_Size; i++){
            for(int j = 0; j < sqr_Matrix_Size; j++){
                A_Inverse_Matrix[i][j] = A_Inverse_Matrix[i][j] / A_Matrix[i][i];
            }
        }

        return A_Inverse_Matrix;
    }

    template<typename T, typename T2>
    constexpr auto Generalized_Inverse_Matrix(T A_Matrix){
        constexpr int sqr_Matrix_Size = A_Matrix[0].size();
        T A_Generalized_Inverse_Matrix;
        std::array<std::array<T2, sqr_Matrix_Size>, sqr_Matrix_Size> A_sqr_Matrix, A_sqr_Inverse_Matrix;

        //Aの転置行列とAの積
        for(int i = 0; i < sqr_Matrix_Size; i++){
            for(int j = 0; j < sqr_Matrix_Size || i > j; j++){
                for(int k = 0; k < A_Matrix.size(); k++){
                    A_sqr_Matrix[i][j] = A_sqr_Matrix[j][i] 
                        = A_Matrix[k][j] * A_Matrix[i][k];
                }
            }
        }

        A_sqr_Inverse_Matrix = Inverse_Matrix(A_sqr_Matrix);

        for(int i = 0; i < ){}
    }

    
}