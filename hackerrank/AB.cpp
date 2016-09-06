#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string convert_to_binary(char x){
    //cout<<"x="<<x<<endl;
    int n;
    if(x>=65){
        n=x-55;
    }
    else{
        n=x-'0';
    }
    // now convert the given string to binary
    string s="0000";
    int i=3;
    //cout<<"n="<<n<<endl;
    while(n>0){
        s[i]=n%2+48;
        n/=2;
        --i;
    }
    //cout<<"s="<<s<<endl;
    return s;

}
char binary_hexa(string s){
    int x=0;
    int i=3;
    int j=0;
    int ans=0;
    while(i>=0){
        if(s[i]=='1'){
            x+=pow(2,j);
        }
        ++j;
        --i;
    }
    if(x<=9){
        return char(x+48);
    }


        return char((x-10)+65);



}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin>>q;
    for(int a=0;a<q;++a){
        bool flag=1;
        int k;
        cin>>k;
        string A,B,C;
        string new_A,new_B,new_C;
        cin>>A>>B>>C;
        new_A=A;
        new_B=B;
        new_C=C;
        //now check which has the max length between the numbers and add padding to the left hand side if needed
        int l_a=A.length();
        int l_b=B.length();
        int l_c=C.length();
        int maxi=max(l_a,max(l_b,l_c));
        while(l_a<maxi){
            A='0'+A;
            ++l_a;
        }
        while(l_b<maxi){
            B='0'+B;
            ++l_b;
        }
        while(l_c<maxi){
            C='0'+C;
            ++l_c;
        }
        //cout<<A<<endl;cout<<B<<endl;cout<<C<<endl;
        // now lets convert the given numbers into binary representation
        string binary_A,binary_B,binary_C;
        // now lets process each hexadecimal digit by converting them to firts binary strings
        for(int i=0;i<maxi;++i){
            char b_A=A[i];
            char b_B=B[i];
            char b_C=C[i];
            // now convert each character into a binary string of 4 characters
            binary_A=convert_to_binary(b_A);
           // cout<<binary_A<<endl;
            binary_B=convert_to_binary(b_B);
           // cout<<binary_B<<endl;
            binary_C=convert_to_binary(b_C);
           // cout<<binary_C<<endl;
            // now we have the binary representation lets do the processing
                for(int z=0;z<4;++z){
                    //cout<<"hello"<<endl;
                    if(binary_C[z]=='1' && binary_B[z]=='0' && binary_A[z]=='0'){
                        binary_B[z]='1';
                        --k;
                    }
                    else if(binary_C[z]=='0' && binary_B[z]=='1' && binary_A[z]=='1'){
                        binary_B[z]='0';
                        binary_A[z]='0';k-=2;
                    }
                    else if(binary_C[z]=='0' && binary_B[z]=='0' && binary_A[z]=='1'){
                        binary_A[z]='0';--k;
                    }
                    else if(binary_C[z]=='0' && binary_B[z]=='1' && binary_A[z]=='0'){
                        binary_B[z]='0';--k;
                    }
                }
            if(k<0){
                flag=0;
                cout<<-1<<endl;
                break;
            }
            else{
                // convert the binary represented form to the actual form
                //cout<<binary_A<<endl;
                //cout<<binary_B<<endl;
                //cout<<binary_C<<endl;
                new_A[i]=binary_hexa(binary_A);
                new_B[i]=binary_hexa(binary_B);
                //new_C[i]=binary_hexa(binary_C);


            }


        }
        // now if we have some remaining k with us lets try to minimise the value of A and B further

            //first we will try new_A
            for(int jj=0;jj<maxi && k>0;++jj){
                 binary_A=convert_to_binary(new_A[jj]);
               // cout<<binary_A<<endl;
                binary_B=convert_to_binary(new_B[jj]);
               // cout<<binary_B<<endl;
                binary_C=convert_to_binary(C[jj]);
                 for(int z=0;z<4 && k>0;++z){
                     if(binary_C[z]=='1' && binary_B[z]=='0' && binary_A[z]=='1' && k>=2){
                        binary_B[z]='1';
                        binary_A[z]='0';
                         k-=2;
                    }
                     else if(binary_C[z]=='1' && binary_B[z]=='1' && binary_A[z]=='1' && k>=0){
                         binary_A[z]='0';--k;
                     }

                 }
                new_A[jj]=binary_hexa(binary_A);
                new_B[jj]=binary_hexa(binary_B);

            }

            // now we will try to minimise new_B






       // cout<<"k="<<k<<endl;

        if(flag==1){
            //cout<<"n="<<new_A<<endl;
            int jj=0;
            while(new_A[jj]=='0'){
                ++jj;
            }
            string temp="";
            for(jj;jj<new_A.length();++jj){
                temp+=new_A[jj];
            }
            new_A="";
            new_A=temp;
            if(temp==""){
                new_A="0";
            }
            jj=0;
            while(new_B[jj]=='0'){
                ++jj;
            }
            temp="";
            for(jj;jj<new_B.length();++jj){
                temp+=new_B[jj];
            }

            new_B="";
            new_B=temp;
            if(temp=="0"){
                new_B="0";
            }
            cout<<new_A<<endl;
            cout<<new_B<<endl;

        }



    }
    return 0;
}
