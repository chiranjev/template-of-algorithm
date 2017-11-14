#include <iostream>
using namespace std;

int n;
int ans = 0, DONE;

int getPosition(int n){   // gives position of queen placed eg for 0100 return 2
    int ans=0;
    while(n>0){
        ans++;
        n = n >>1;
    }
    return ans-1;
}

int board[100][100] = {0};

void solve(int rowMask,int ld,int rd,int row){   // rowmask denotes position where queen is placed, ld and rd denote which positions are safe and unsafe

    if(rowMask==DONE)
    {  // if all queens are placed

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        ans++;
        return;
    }

    int safe = DONE & (~(rowMask|ld|rd));    // safe will give us the safe positions

    while(safe){
        int p = safe & (-safe); // p will give the first safe postion
        int col = getPosition(p);  //col will give the position where queen is placed
        board[row][col] = 1;

        safe = safe - p;  // removing pth queen from board and marking it unsafe i.e if initially it was 1111 now it will be 1110
        solve(rowMask|p, (ld|p)<<1,(rd|p)>>1,row+1);
        board[row][col] = 0;  // backtracking step
    }
}

int main() {

   cin>>n;
   DONE = ((1<<n)) - 1; //it is the mask when all queens are placed

   solve(0,0,0,0); // (rowmask,ld,rd,rowno)
   cout<<ans<<endl;
}
