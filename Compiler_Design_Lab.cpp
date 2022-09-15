#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
string ArrayStr[500];
int Count_Value = 0;

// keyword={"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"}
string Keywords[] = {"auto", "break", "case", "char", "const", "continue", "default",
                     "do", "else", "enum", "extern", "for", "goto",
                     "if", "long", "register", "return", "short", "signed",
                     "sizeof", "static", "struct", "switch", "typedef", "union",
                     "unsigned", "void", "volatile", "while", "endl", "cout", "cin"};

string symbols[] = {"\t", "\n", ";", ":", "<>", "(", ")", "{", "}", "[", "]", "\"", ","};

string operators[] = {"+", "-", "*", "/", "==", "!=", "<", ">", "<=", ">=", "<=>", "<<", ">>", "="};

string DataType[] = {"int", "float", "string", "char", "double"};

string Variable[] = {"a", "b", "Answer", "Ans"};

string Constant[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

string Built_it[1000];
int Builtin = 0;
vector<string> UnConditional;

vector<string> Keywords_;
vector<string> symbols_;
vector<string> operator_;
vector<string> DataType_;
vector<string> Variable_;
vector<string> Constant_;

set<string> Keywords_s;
set<string> symbols_s;
set<string> operator_s;
set<string> DataType_s;
set<string> Variable_s;
set<string> Constant_s;

void KeepString(string str)
{
   /// Keep Every word in a string array
   string word = "";
   for (int i = 0; i < str.length(); i++)
   {
      if (str[i] == ' ')
      {
         ArrayStr[Count_Value] = word;
         Count_Value++;
         word = "";
      }
      else
      {
         word = word + str[i];   //Actually Charater
      }
   }
   ArrayStr[Count_Value] = word;

   // cout<<"Print Array String(Every specific word):\n\n "<<endl;
   for (int i = 0; i <= Count_Value; i++)
   {
      // cout<<"\n"<<ArrayStr[i]<<" ";

      // Check Data Type
      for (int d = 0; d < 5; d++)
      {
         if (ArrayStr[i] == DataType[d])
         {

            DataType_s.insert(ArrayStr[i]);
            // cout<<" is a DataType"<<endl;
         }
      }

      // Check Operator
      for (int o = 0; o < 14; o++)
      {
         if (ArrayStr[i] == operators[o])
         {
            operator_s.insert(ArrayStr[i]);
            // cout<<" is a Operator"<<endl;
         }
      }

      // Check Variabble
      for (int v = 0; v < 4; v++)
      {
         if (ArrayStr[i] == Variable[v])
         {
            Variable_s.insert(ArrayStr[i]);
            // cout<<" is a Variable"<<endl;
         }
      }

      // Check Symbol
      for (int s = 0; s < 13; s++)
      {
         if (ArrayStr[i] == symbols[s])
         {
            symbols_s.insert(ArrayStr[i]);
            // cout<<" is a Symbol"<<endl;
         }
      }

      // Check Keywords
      for (int k = 0; k < 32; k++)
      {
         if (ArrayStr[i] == Keywords[k])
         {
            Keywords_s.insert(ArrayStr[i]);
            // cout<<" is a Keyword"<<endl;
         }
      }

      // Check Constant
      for (int c = 0; c < 10; c++)
      {
         if (ArrayStr[i] == Constant[c])
         {
            Constant_s.insert(ArrayStr[i]);
         }
      }
   }
}

string RemoveDoubleSlashComment(string Text)
{

   int count = 0;
   bool CheckQuot;

   for (int i = 0; i < Text.length(); i++)
   { // something right
      if (Text[i] == '"')
      {
         count++;
         continue;
      }

      if (count == 0 || count % 2 == 0)
      {
         if (Text[i] == '/' && Text[i + 1] == '/')
         {
            Text = Text.substr(0, i - 1);
            break;
         }
      }
   }
   return Text;
}

void symbolTable()
{
   cout << "\n\n\n\nSymbol Table:" << endl;
  

   cout << "Datatype: ";
   for (auto itr=DataType_s.begin();itr!=DataType_s.end();itr++)
   {
      cout << *itr << "  ";
      Built_it[Builtin] = *itr;
      DataType_.push_back(*itr);
      Builtin++;
   }
   cout << "\nVariable: ";
   for (auto itr=Variable_s.begin();itr!=Variable_s.end();itr++)
   {
      cout << *itr << "  ";
      Built_it[Builtin] = *itr;
      Variable_.push_back(*itr);
      Builtin++;
   }
   cout << "\nKeyword: ";
   for (auto itr=Keywords_s.begin();itr!=Keywords_s.end();itr++)
   {
      cout << *itr << "  ";
      Built_it[Builtin] = *itr;
      Keywords_.push_back(*itr);
      Builtin++;
   }

   cout << "\nSymbol: ";
   for (auto itr=symbols_s.begin();itr!=symbols_s.end();itr++)
   {
      cout << *itr << "  ";
      Built_it[Builtin] = *itr;
      symbols_.push_back(*itr);
      Builtin++;
   }
   cout << "\nOperators: ";
   for (auto itr=operator_s.begin();itr!=operator_s.end();itr++)
   {
      cout << *itr << "  ";
      Built_it[Builtin] = *itr;
      operator_.push_back(*itr);
      Builtin++;
   }
   cout << "\nConstant: ";
   for (auto itr=Constant_s.begin();itr!=Constant_s.end();itr++)
   {
      cout << *itr << "  ";
      Built_it[Builtin] = *itr;
      Constant_.push_back(*itr);
      Builtin++;
   }



   /// Show in Table
   cout << "\nSymbol Table:" << endl;
   cout << "========================================================================================" << endl;
   cout << "Data Type\tVariable\tKeyword\t\tSymbol\t\tOperaator\tConstant" << endl;
   for (int i = 0; i < symbols_.size(); i++)
   {
      // DataType
      if (i >= DataType_.size())
      {
         cout << "|| "
              << "\t\t";
      }
      else
      {
         cout << "|" << DataType_.at(i) << "\t\t";
      }

      // VAriable
      if (i >= Variable_.size())
      {
         cout << " "
              << "\t\t";
      }
      else
      {
         cout << Variable_.at(i) << "\t\t";
      }

      // Keyword
      if (i >= Keywords_.size())
      {
         cout << " "
              << "\t\t";
      }
      else
      {
         cout << Keywords_.at(i) << "\t\t";
      }

      // Symbol
      if (i >= symbols_.size())
      {
         cout << " "
              << "\t\t";
      }
      else
      {
         cout << symbols_.at(i) << "\t\t";
      }

      // Operator
      if (i >= operator_.size())
      {
         cout << " "
              << "\t\t";
      }
      else
      {
         cout << operator_.at(i) << "\t\t";
      }

      // Constant
      if (i >= Constant_.size())
      {
         cout << " ||" << endl;
         ;
      }
      else
      {
         cout << Constant_.at(i) << "||" << endl;
      }
   }
   cout << "========================================================================================" << endl;
}

void FindError(string str)
{
   cout << "\n\n\nHere Will be found error" << endl;
   // cout<<"\nString with space"<<str<<endl;
   // cout<<"\nString without space"<<Allstr<<endl;
   int Parentheses_1 = 0;
   int Parentheses_2 = 0;
   int Braces_1 = 0;
   int Braces_2 = 0;
   int Bracket_1 = 0;
   int Bracket_2 = 0;

   for (int i = 0; i < str.length(); i++)
   {
      if (str[i] == '(')
      {
         Parentheses_1++;
      }
      if (str[i] == ')')
      {
         Parentheses_2++;
      }
      if (str[i] == '{')
      {
         Braces_1++;
      }
      if (str[i] == '}')
      {
         Braces_2++;
      }
      if (str[i] == '[')
      {
         Bracket_1++;
      }
      if (str[i] == ']')
      {
         Bracket_2++;
      }
   }
   if (Parentheses_1 == Parentheses_2)
   {
      cout << "No Error in Parentheses->()" << endl;
   }
   else
   {
      cout << "Here obtain Parentheses error ->()" << endl;
   }
   if (Braces_1 == Braces_2)
   {
      cout << "No Error in Braces ->{}" << endl;
   }
   else
   {
      cout << "Here obtain Parentheses error ->{}" << endl;
   }
   if (Bracket_1 == Bracket_2)
   {
      cout << "No Error in Bracket ->[]" << endl;
   }
   else
   {
      cout << "Here obtain Bracket error ->[]" << endl;
   }

   // cout<<"\""<<endl;

   ///=================================//
   int Similar = 0;
   int Help_Error = 0;
   int Error = 0;
   int count = 0;
   int FindError = 0;
    string HelpString="";
   //   cout<<"All Word May be: ";
   for (int i = 0; i < Count_Value; i++)
   { // something right
     // cout << "ArrayStr[" << i << "]: " << ArrayStr[i] << endl;
      if (ArrayStr[i] == "\"")
      {
         count++;
         continue;
      }

      if (count == 0 || count % 2 == 0)
      {
         //=================

         Similar = 0;
         for (int j = 0; j < Builtin; j++)
         {
            if (ArrayStr[i] == Built_it[j])
            {
               Similar++;
              // cout << "Which is Similar: " << ArrayStr[i] << endl;
            }
         }

         if (Similar == 0)
         {
           // cout << "Which is not similar: " << ArrayStr[i] << endl;
             HelpString = ArrayStr[i];
            if (HelpString == "main()" || HelpString == " " || HelpString == "")
            {
               //cout << "Which is not similar_: " << HelpString << endl;
            }
            else
            {
               Error++;
               cout << "Which is Unconditional: " << HelpString << endl;
               UnConditional.push_back(HelpString);
            }
         }

         //===================
      }
   }

   if (Error > 0)
   {
      cout << "There have error "<<endl;
      cout << "Number of Error: " << Error << endl;
      cout<<"Errors are___:"<<endl;
       for (string &er : UnConditional) {
       cout << er << ",  ";
       }
   }
   else
   {
      cout << "No Error" << endl;
   }

   //cout << "\nAllBuiltin: " << endl;
   for (int i = 0; i < Builtin; i++)
   {
      //// cout<<Built_it[i]<<" ";
   }

  // cout << "\n\n All ArrauStr[]: " << endl;
   for (int i = 0; i < Count_Value; i++)
   {
      ////  cout<<i<<". "<<ArrayStr[i]<<endl;
   }
}

int main()
{
   string Text_ = "";
   string NewString = "";
   string WithoutSpace = "";

   ifstream MyReadFile("D:\\xyz.txt");

   while (getline(MyReadFile, Text_))
   {
      string Text = RemoveDoubleSlashComment(Text_);
      cout << Text << endl;
      NewString += Text;
      Text = "";
   }
   MyReadFile.close();

   // All String in One Line
   cout << "\nNew String in One Line: " << NewString << endl;

   /// All Word and Symble keep in one Array String
   /// Here will be create Symbol Table:

   string ErrorString = NewString;

   // Remove Space between two words
   // NewString.erase(remove(NewString.begin(), NewString.end(), ' '), NewString.end());
   // cout<<"\nNew String without space: \n"<<NewString<<endl;

   // Remove /* */ Comment
   int Check = 0;
   int x_count = 0;
   for (int i = 0; NewString[i] != '\0'; i++)
   {
      if (NewString[i] == '"')
      {
         Check++;
         continue;
      }

      if (Check == 0 || Check % 2 == 0)
      {
         if (NewString[i] == '/' && NewString[i + 1] == '*')
         {
            for (int j = i + 2; NewString[j] != '\0'; j++)
            {
               x_count++;
               if (NewString[j] == '*' && NewString[j + 1] == '/')
               {
                  NewString.erase(i, x_count + 3);
                  x_count = 0;
                  break;
               }
            }
         }
      }
   }

   cout << "\nWithout /* */ Comment: =========\n"
        << NewString << endl;
   KeepString(NewString);
   symbolTable();
   FindError(NewString);

   return 0;
}