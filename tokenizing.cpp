#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readData(char[]);
void tokenize(char[]);
bool isIdentifier(char[]);
bool isReserved(char[]);
string isSpecial(char[]);
bool isInt(char[]);
bool isReal(char[]);

int main()
{
    char input[100]="";
    readData(input);
    tokenize(input);

    return 0;
}

void readData(char input[])
{
    string text;
    ifstream inData;
    inData.open("data.txt");
    while(getline(inData, text))
    {
        strcat(input, text.c_str());
        strcat(input, " ");
    }
    inData.close();
}

void tokenize(char input[])
{
    cout<<isSpecial(input);
    char * args;

    args=strtok(input, " =,;");

    while(args!=NULL)
    {
        if(isReserved(args))
        {
            cout<<args<<"\tRESERVED WORD\n";
        }
        else if(isIdentifier(args))
        {
            cout<<args<<"\tIDENTIFIER\n";
        }
        else if(isInt(args))
        {
            cout<<args<<"\tINTEGER NUMBER\n";
        }
        else if(isReal(args))
        {
            cout<<args<<"\tREAL NUMBER\n";
        }
        else
        {
            cout<<args<<"\tINVALID TOKEN\n";
        }
        
        args=strtok(NULL, " =,;");
    }
}

bool isIdentifier(char input[])
{
    int i=0;
    if(isalpha(input[i]))
    {
        while(input[i++])
        {
            if(ispunct(input[i]))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool isReserved(char input[])
{
    if(strcmp(input, "int")==0)
    {
        return true;
    }
    else if(strcmp(input, "float")==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isInt(char input[])
{
    int i=0;
    while(input[i])
    {
        if(!isdigit(input[i]))
        {
            return false;
        }
        i++;
    }
    return true;
}

bool isReal(char input[])
{
    int i=0, count=0;

    if(isdigit(input[i]))
    {
        while(input[i++])
        {
            if(input[i]=='.')
            {
                count++;
            }
        }
        if(count==1)
        return true;
    }
    return false;
}

string isSpecial(char input[])
{
    int i=0;
    while(input[i])
    {
        if(input[i]==',')
        {
            return(",\tSPECIAL CHARACTER\n");
        }
        else if(input[i]==';')
        {
            return(";\tSPECIAL CHARACTER\n");
        }
        i++;
    }
    return "";
}
