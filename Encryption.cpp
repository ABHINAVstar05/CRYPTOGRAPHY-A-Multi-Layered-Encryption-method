#include <iostream>
#include <vector>
using namespace std ;
int main(){
   string str1 = "abcdefghijklmnopqrstuvwxyz" ;

   string plaintext ;
   cout<<"Enter your message from here : \n(NOTE : Press ENTER key to end your message.)\n\n";
   getline(cin, plaintext) ;
   int l = plaintext.length() ;
   
   char key ;                                //The key must be a lower-case alphabet only.....
   cout<<"\nEnter encryption key : " ;
   cin>>key ;

   //Arrangement of str1 according to key....
   int index ;
    for (int i=0; i<str1.length(); i++){
        if (key == str1[i]){
            index = i ;
        }
    }
    vector <char> code1 ;
    for (int i=index; i<str1.length(); i++){
        code1.push_back(str1[i]) ;
    }
    for (int i=0 ; i<index; i++){
        code1.push_back(str1[i]);
    }

    /*

    //Display str1 re - arrangement......
    
    cout<<"str1 re-arrangement : \n";
    for (int i=0; i<code1.size(); i++){
        cout<<code1[i]<<" ";
    }
    cout<<"\n" ;

    */

   //Fibonacci series.....
   vector<long long int> fib ;
   long long int f1 = 1, f2 = 2;
   fib.push_back(f1) ;
   fib.push_back(f2) ;
    for(int i=0; i<l - 2; i++){
        long long int f = f1 + f2 ;
        fib.push_back(f) ;
        f1 = f2 ;
        f2 = f ;
    }

    /*

    //Displaying Fibonacci......
    
    cout<<"Fibonacci : \n" ;
    for(int i=0; i<fib.size(); i++){
        cout<<fib[i]<<" ";
    }
    cout<<"\n" ;
    
    */

    //1st encryption layer --> Using indexing of code1 as per the fibonacci series to obtain cipher1.....
    vector<char> cipher1 ;
    for(int i=0; i<l; i++){
        long long int position = fib[i] ;
        if (position > code1.size()){
            position = position % code1.size() ;
        }
        cipher1.push_back(code1[position-1]) ;
    }

    /*

    //Display cipher1........
    
    cout<<"Cipher1 : \n" ;
    for (int i=0; i<cipher1.size(); i++){
        cout<<cipher1[i]<<" ";
    }
    cout<<"\n" ;

    */

    //2nd layer encryption --> ASCII values for ciphertext1.....
    vector<int> ascii ;
    int cipher2 ;
    vector<int> raw_ascii ;
    int raw_index = 0, raw_temp ;
    int index_c1 ;
    for (int j=0; j<cipher1.size(); j++){
        for (int i=0; i<str1.length(); i++){
            if (cipher1[j] == str1[i]){
                index_c1 = i ;
                
                if (index_c1 + 1 > 25){
                    raw_temp = (int)str1[index_c1-1] ;
                    raw_temp += (int)('{') ; 
                    raw_ascii.push_back(raw_temp) ;
                                    
                }
                else if (index_c1-1 < 0){               
                    raw_temp = (int)('}') + (int)str1[index_c1 + 1] ;
                    raw_ascii.push_back(raw_temp) ;
                    
                }
                else{
                    raw_temp = (int)str1[index_c1 - 1] + (int)str1[index_c1+1] ;
                    raw_ascii.push_back(raw_temp) ;
                }
            }
        }
    }

   for (int i=0 ; i<cipher1.size(); i++){
        cipher2 = (int)cipher1[i] + (int)plaintext[i] + raw_ascii[i] ;
        ascii.push_back(cipher2) ;
    }

    /*

    //Displaying ascii --> 2nd layer encryption.....
    
    cout<<"ASCII representation : \n" ;
    for(int i=0; i<ascii.size(); i++){
        cout<<ascii[i]<<" ";
    }
    cout<<"\n" ;
    cout<<"Size of ascii : "<<ascii.size()<<"\n" ;
    
    */

    //3rd encryption layer --> Decimal to hexadecimal conversion of ciphertext2...
    vector <char> hexa2 ;
    int temp ;
    int cipher3 ;
    for (int i=0; i<ascii.size(); i++){
        cipher3 = ascii[i] ;
        vector <char> hexa ;
        while (cipher3 != 0){
            
            temp = cipher3 % 16 ;
            if (temp < 10){
                hexa.push_back(temp + 48) ;
            }
            else{
                hexa.push_back(temp + 55) ;
            }
            cipher3 = cipher3 / 16 ;
        }
        for (int i=hexa.size()-1; i>=0; i--){
            hexa2.push_back(hexa[i]) ;
        }
    }

    //Display final encrypted cipher text......
    cout<<"Encrypted form of plaintext : ";
    for (int i=0; i<hexa2.size(); i++){
        cout<<hexa2[i] ;
    }
    cout<<"\n" ;
}
