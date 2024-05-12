#include<iostream>
using namespace std;

class pattern {
    int n;
public:
    
    pattern(int height) {
        n = 5;
    }
    

    void square() {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "*";
            }
            cout << endl;
        }
    }

    void triangle(){

        for(int i=0 ; i< n; i++){
            for(int j=0 ; j< i+1 ; j++){
                cout<<"*";
            }
            cout<<endl;
        }
    }

    void number_triangle() {
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                cout << j + 1;
            }
            cout << endl;
        }
    }

    void number_triangle2() {
        
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i + 1; j++) {
                cout << i + 1;
            }
            cout << endl;
        }
    }

    void reverse_triangle() {
        
        for (int i = n; i > 0; i--) {
            for (int j = i; j >0; j--) {
                cout << "*";
                
            }
            cout << endl;
        }
    }

    void reverse_triangle2() {

        for(int i =0 ; i < n ; i++){
            for(int j = 0 ; j <n - i  ; j++){
                cout<<"*";
                
            }
                 
            cout<< endl;
        }
    }

    void reverse_triangle_withno() {

        for(int i =0 ; i < n ; i++){
            for(int j = 0 ; j <n - i  ; j++){
                cout<<j+1;
                
            }
                 
            cout<< endl;
        }
    }

    void star_pyramid() {

        for(int i =0 ; i < n ; i++){
            for(int j = 0 ; j <n - i -1  ; j++){
                cout<<" ";
            }
            for(int k = 0 ; k < 2*i + 1 ; k++){
                cout<<"*";
            }
            for(int l = 0 ; l< n -i -1 ; l++){
                cout<<" ";
            }
                 
            cout<< endl;
        }
    }

    void reverse_star_pyramid() {

        for(int i =0 ; i < n ; i++){
            for(int j = 0 ; j <i ; j++){
                cout<<" ";
            }
            for(int k = 0 ; k < 2*n - (2*i + 1) ; k++){
                cout<<"*";
            }
            for(int l = 0 ; l< i ; l++){
                cout<<" ";
            }
                 
            cout<< endl;
        }
    }

    void diamond_star(){
        
        star_pyramid();
        reverse_star_pyramid();
        
        cout<<endl;
    }
    
    void half_diamond_star(){

        for(int i=0 ; i< n; i++){
            for(int j=0 ; j< i+1 ; j++){
                cout<<"*";
            }
            cout<<endl;
        }

        for(int i =0 ; i < n-1 ; i++){
            for(int j = 0 ; j <n - i - 1 ; j++){
                cout<<"*";
                
            }
                 
            cout<< endl;
        }

    }

    void binary_triangle(){

        int start = 1;
        for(int i= 0 ; i< n; i++){
            if(i%2 ==0)     start= 1;
            else
            start =0;
            for(int j=0 ; j<=i ; j++){
                cout<<start<<" ";
                start = 1 - start;
            }
            cout<<endl;
        }

    }

    void number_crown(){
        int space =2*(n-1);
        for(int i=0 ; i<n ;i++){
            
            for(int j = 0 ; j<= i ; j++){
                cout<<j+1;
            }
            for(int j =0 ; j<space  ; j++){
                cout <<" ";
                
            }
            for(int j = i ; j>=0 ; j--){
                cout<<j+1;
            }

            cout<<endl;

            space-=2;
        }
    }

    void increasing_number_triangle(){

        int sum=1;
        for(int i=0 ; i< n; i++){
            for(int j=0 ; j< i+1 ; j++){
                cout<<sum<<" ";
                sum++;
            }
            cout<<endl;
        }
    }

    void increasing_letter_triangle(){

        char sum='a';
        for(int i=0 ; i< n; i++){
            for(int j=0 ; j< i+1 ; j++){
                cout<<sum<<" ";
                sum++;
            }
            cout<<endl;
            sum='a';

            //or
        //     for(char ch = 'A'; ch<='A'+i;ch++){
        //       cout<<ch<<" ";
              
        //   }
        //   cout<<endl;
        }
    }

    void symmetric_void_pattern(){
            int space =0;
        for(int i=0 ; i<n ;i++){
            
            for(int j = 0 ; j< n -i ; j++){
                cout<<"*";
            }
            for(int j =0 ; j<space  ; j++){
                cout <<" ";
                
            }
            for(int j = 0 ; j< n- i; j++){
                cout<<"*";
            }

            cout<<endl;

            space+=2;
        }

         space =2*(n-1);
        for(int i=0 ; i<n ;i++){
            
            for(int j = 0 ; j<= i ; j++){
                cout<<"*";
            }
            for(int j =0 ; j<space  ; j++){
                cout <<" ";
                
            }
            for(int j = i ; j>=0 ; j--){
                cout<<"*";
            }

            cout<<endl;

            space-=2;
        }

    }

    void symmetric_butterfly_pattern(){
        // initialising the spaces.
      int spaces = 2*n-2;
      
      // Outer loop for printing row.
      for(int i = 1;i<=2*n-1;i++){
          
          // stars for first half
          int stars = i;
          
          // stars for the second half.
          if(i>n) stars = 2*n - i;
          
          //for printing the stars
          for(int j=1;j<=stars;j++){
              cout<<"*";
          }
          
          //for printing the spaces
          for(int j = 1;j<=spaces;j++){
              cout<<" ";
          }
          
          //for printing the stars
          for(int j = 1;j<=stars;j++){
              cout<<"*";
          }
          
          // As soon as the stars for each iteration are printed, we move to the
          // next row and give a line break otherwise all stars
          // would get printed in 1 line.
          cout<<endl;
          if(i<n) spaces -=2;
          else spaces +=2;
      }
        
    }

    void hollow_triangle(){

        for(int i=0 ; i< n ; i++){
            for(int j=0 ; j<n ; j++){
                if(i==0 || j==0 || i==n-1 || j==n-1)
                cout<<"*";
                else
                cout<<" ";
            }
            cout<<endl;
        }
    }

    void number_pattern(){
         // Outer loop for no. of rows
     for(int i=0;i<2*n-1;i++){
         
         // inner loop for no. of columns.
         for(int j=0;j<2*n-1;j++){
             
             // Initialising the top, down, left and right indices of a cell.
             int top = i;
             int bottom = j;
             int right = (2*n - 2) - j;
             int left = (2*n - 2) - i;
             
             // Min of 4 directions and then we subtract from n
             // because previously we would get a pattern whose border
             // has 0's, but we want with border N's and then decreasing inside.
             cout<<(n- min(min(top,bottom), min(left,right)))<<" ";
         }
         
         // As soon as the numbers for each iteration are printed, we move to the
         // next row and give a line break otherwise all numbers
         // would get printed in 1 line.
         cout<<endl;

         //c:\Users\sneha\OneDrive\Pictures\Screenshots\Screenshot 2024-05-13 013549.png
     }
    }


};

int main() {
    int height;
    cout<<"height of pattern :";
    cin>>height;

    pattern a(height);
    a.number_pattern(); 
    return 0; 
}
