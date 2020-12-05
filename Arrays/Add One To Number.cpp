// https://www.interviewbit.com/problems/add-one-to-number/

vector<int> Solution::plusOne(vector<int> &A) {
    bool flag = false;
    vector<int> C;
    for(int i=0;i<A.size();i++){    // removing prefix zeros
        if(A[i]!=0){
            flag = true;
        }
        if(flag){
            C.push_back(A[i]);
        }
    }
    
    if(C.size()==0){       // cases where all are 0
        C.push_back(1);
        return C;
    }
    
    int temp = A[A.size()-1];
    if(temp!=9){            // cases where last digit is not 9
        C.pop_back();
        C.push_back(temp+1);
        return C;
    }
    else{
        if(C.size()==1){    // case where only single 9
            C.pop_back();
            C.push_back(1);
            C.push_back(0);
            return C;
        }
        for(int i=C.size()-1;i>0;i--){   // cases with last digit as 9
            C[i] = 0;
            C[i-1] += 1;    // carry
            if(C[i-1]<10) break;
        }
        if(C[0]==10){           // handling cases where all digits are 9
            C[0] = 1;
            C.push_back(0);
        }
        return C;
    }
}
