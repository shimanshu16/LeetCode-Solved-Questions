class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int r1=0,r2=0,i1=0,i2=0;
        int a=0,b=0;
        for (int i=0;i<num1.size();++i){
            if (num1[i]=='+'){
                r1=stoi(num1.substr(0,i));
                a=i;
            }
            if (num1[i]=='i'){
                i1=stoi(num1.substr(a+1,i-a-1));
            }
        }
        for (int i=0;i<num2.size();++i){
            if (num2[i]=='+'){
                r2=stoi(num2.substr(0,i));
                b=i;
            }
            if (num2[i]=='i'){
                i2=stoi(num2.substr(b+1,i-b-1));
            }
        }
        
        string ans="";
        int real=r1*r2-i1*i2;
        int img= r1*i2 + r2*i1;
        cout<<real<<" "<<img<<endl;
        ans+=to_string(real);
        ans+="+";
        
        ans+=to_string(img);
        ans+="i";
        return ans;

    }
};