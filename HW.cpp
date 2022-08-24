#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
string ArrayStr[500];
//keyword={"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"}
string Keywords[]={"auto","break","case","char","const","continue","default",
							"do","else","enum","extern","for","goto",
							"if","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while","endl","cout","cin"};



string symbols[]={"\t","\n",";",":","<>","(",")","{","}","[","]","\""};

string operators[]={"+","-","*","/","==","!=","<",">","<=",">=","<=>","<<",">>","="};

string DataType[]={"int","float","string","char","double"};

string Variable[]={"a","b","Answer","Ans"};

string Constant[]={"0","1","2","3","4","5","6","7","8","9"};

vector<string> Keywords_;
vector<string> symbols_;
vector<string> operator_;
vector<string> DataType_;
vector<string> Variable_;
vector<string> Constant_;

int Count_Value=0;


void KeepString(string str){
    
    

    ///Keep Every word in a string array
    string word = "";
    for (int i=0;i<str.length();i++) 
    {
        if (str[i] == ' ')
        {
            ArrayStr[Count_Value]=word;
            Count_Value++;
            word = "";
        }
        else {
            word = word + str[i];
        }
    }
    ArrayStr[Count_Value]=word;





   // cout<<"Print Array String(Every specific word):\n\n "<<endl;
    for(int i=0;i<=Count_Value;i++){
    // cout<<"\n"<<ArrayStr[i]<<" ";

      //Check Data Type
      for(int d=0;d<5;d++){
        if(ArrayStr[i]==DataType[d]){

            DataType_.push_back(ArrayStr[i]);
           // cout<<" is a DataType"<<endl;
        }
      }

      //Check Operator
       for(int o=0;o<14;o++){
        if(ArrayStr[i]==operators[o]){
            operator_.push_back(ArrayStr[i]);
           // cout<<" is a Operator"<<endl;
        }
      }

      //Check Variabble
      for(int v=0;v<4;v++){
        if(ArrayStr[i]==Variable[v]){
            Variable_.push_back(ArrayStr[i]);
           // cout<<" is a Variable"<<endl;
        }
      }

       //Check Symbol
      for(int s=0;s<12;s++){
        if(ArrayStr[i]==symbols[s]){
            symbols_.push_back(ArrayStr[i]);
           // cout<<" is a Symbol"<<endl;
        }
      }

       //Check Keywords
      for(int k=0;k<32;k++){
        if(ArrayStr[i]==Keywords[k]){
            Keywords_.push_back(ArrayStr[i]);
           // cout<<" is a Keyword"<<endl;
        }
      }

      //Check Constant
      for(int c=0;c<10;c++){
        if(ArrayStr[i]==Constant[c]){
            Constant_.push_back(ArrayStr[i]);
        }
      }

    }
}

string RemoveDoubleSlashComment(string Text){

    int count=0;
    bool CheckQuot;

    for(int i=0;i<Text.length();i++){       //something right
        if(Text[i]=='"'){
            count++;
            continue;
        }
        
        if(count==0 || count%2==0){
        if(Text[i]=='/' && Text[i+1]=='/'){
             Text= Text.substr(0, i-1);
             break;
        }
        }
    }
    return Text;
}

void symbolTable(){
    cout<<"\n\n\n\nSymbol Table:"<<endl;
   // cout<<"Keyword\t\t\tSymbol\tOperator\tDatatype\tVariable"<<endl;
    
    //  for (auto i =symbols_.begin(); i != symbols_.end(); ++i){
    //     cout << *i <<endl;
    //  }

    //  for (string i : Keywords_,symbols_) {
    //    cout << i << endl;
    // }

    // for(int k=0,s=0,o=0,d=0,v=0; k < Keywords_.size(),s<symbols_.size(),o<operator_.size(),d<DataType_.size(),v<Variable_.size(); k++,s++,o++,d++,v++){
    //     cout << Keywords_.at(k)<<"\t\t\t"<<symbols_.at(s)<<"\t"<<operator_.at(o)<<"\t\t"<<DataType_.at(d)<<"\t\t"<<Variable_.at(v) <<endl;
    // }

    // for(int i=0; i<symbols_.size();i++){
    //     cout <<symbols_.at(i)<<"\t\t"<< Keywords_.at(i)<<"\t\t\t"<<symbols_.at(i)<<"\t"<<operator_.at(i)<<"\t\t"<<DataType_.at(i)<<"\t\t"<<Variable_.at(i) <<endl;
    // }

    cout<<"Datatype: ";
    for (string i : DataType_) {
       cout << i <<"  ";
    }
   cout<<"\nVariable: ";
   for(string i :Variable_) {
       cout << i <<"  ";
    }
    cout<<"\nKeyword: ";
    for (string i : Keywords_) {
       cout << i <<"  ";
    }
    cout<<"\nSymbol: ";
    for (string i : symbols_) {
       cout << i <<"  ";
    }
    cout<<"\nOperators: ";
    for (string i : operator_) {
       cout << i <<"  ";
    }
    cout<<"\nConstant: ";
    for (string i : Constant_) {
       cout << i <<"  ";
    }
}

void FindError(string str,string Allstr){
    cout<<"\n\n\nHere Will be finded error"<<endl;
   // cout<<"\nString with space"<<str<<endl;
   // cout<<"\nString without space"<<Allstr<<endl;
   int Parentheses_1=0;
   int Parentheses_2=0;
   int Braces_1=0;
   int Braces_2=0;
   int Bracket_1=0;
   int Bracket_2=0;

   for(int i=0;i<Allstr.length();i++){
     if(Allstr[i]=='('){
        Parentheses_1++;
     } 
     if(Allstr[i]==')'){
        Parentheses_2++;
     }  
     if(Allstr[i]=='{'){
        Braces_1++;
     }  
     if(Allstr[i]=='}'){
        Braces_2++;
     }  
     if(Allstr[i]=='['){
        Bracket_1++;
     }  
     if(Allstr[i]==']'){
        Bracket_2++;
     }   

   }
      if(Parentheses_1==Parentheses_2){
        cout<<"No Error in Parentheses->()"<<endl;
     }else{
        cout<<"Here obtain Parentheses error ->()"<<endl;
     }
     if(Braces_1==Braces_2){
        cout<<"No Error in Braces ->{}"<<endl;
     }else{
        cout<<"Here obtain Parentheses error ->{}"<<endl;
     }
     if(Bracket_1==Bracket_2){
        cout<<"No Error in Bracket ->[]"<<endl;
     }else{
        cout<<"Here obtain Bracket error ->[]"<<endl;
     }

     cout<<"\""<<endl;


     ///=================================//
    int count=0;
    int FindError=0;

}

int main(){
    string Text_="";
    string NewString="";
    string WithoutSpace="";


    ifstream MyReadFile("D:\\xyz.txt");

    while (getline(MyReadFile,Text_))
    {
        string Text= RemoveDoubleSlashComment(Text_);
        cout<<Text<<endl;
        NewString+=Text;
        Text="";
    }
    MyReadFile.close();

    //All String in One Line
    cout<<"\nNew String in One Line: "<<NewString<<endl;

    ///All Word and Symble keep in one Array String
    ///Here will be create Symbol Table:
    KeepString(NewString);
    string ErrorString=NewString;

    //Remove Space between two words
    NewString.erase(remove(NewString.begin(), NewString.end(), ' '), NewString.end());
    cout<<"\nNew String without space: \n"<<NewString<<endl;

    //Remove /* */ Comment 
    int Check=0;
    int x_count=0;
    for(int i=0; NewString[i]!='\0'; i++) {
         if(NewString[i]=='"'){
            Check++;
            continue;
        }
        
        if(Check==0 || Check%2==0){
            if(NewString[i]=='/' && NewString[i+1]=='*'){
                for(int j=i+2;NewString[j]!='\0';j++){
                    x_count++;
                    if(NewString[j]=='*' && NewString[j+1]=='/'){
                         NewString.erase(i,x_count+3);
                         x_count=0;
                         break;
                     }
               }
           }
        }
     }

    cout<<"\nWithout /* */ Comment: =========\n"<<NewString<<endl;
    
    symbolTable();
    FindError(ErrorString,NewString);

    return 0;
    
}