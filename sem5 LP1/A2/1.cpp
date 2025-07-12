#include<bits/stdc++.h>
using namespace std;

struct optab
{
    string opcode;
    string opclass;
    string opmnemonics;
};

struct optab OT[18]=
{
    {"STOP","IS","00"},
    {"ADD","IS","01"},
    {"SUB","IS","02"},
    {"MULT","IS","03"},
    {"MOVER","IS","04"},
    {"MOVEM","IS","05"},
    {"COMP","IS","06"},
    {"BC","IS","07"},
    {"DIV","IS","08"},
    {"READ","IS","09"},
    {"PRINT","IS","10"},
    {"START","AD","01"},
    {"END","AD","02"},
    {"ORIGIN","AD","03"},
    {"EQU","AD","04"},
    {"LTORG","AD","05"},
    {"DC","DL","01"},
    {"DS","DL","02"}
};

int getoptabID(string s)
{
    for(int i=0;i<18;i++)
    {
        if(OT[i].opcode==s)
            return i;
    }
    return -1;
}

int getregisterID(string s)
{
    if(s=="AREG")
        return 1;
    else if(s=="BREG")
        return 2;
    else if(s=="CREG")
        return 3;
    else if(s=="DREG")
        return 4;
    else   
        return -1; 
}

int getconditionID(string s)
{
    if(s=="LT")
        return 1;
    else if(s=="LE")
        return 2;
    else if(s=="EQ")
        return 3;
    else if(s=="GT")
        return 4;
    else if(s=="GE")
        return 5;
    else if(s=="ANY")
        return 6;
    else
        return -1;
}

struct symboltable
{
    int no;
    string sname;
    string saddress;
};

struct symboltable ST[10];

bool symbolpresent(string s)
{
    for(int i=0;i<10;i++)
    {
        if(ST[i].sname==s)
            return true;
    }
    return false;
}

int getsymbolID(string s)
{
    for(int i=0;i<10;i++)
    {
        if(ST[i].sname==s)
            return i;
    }
    return -1;
}

struct literaltable
{
    int no;
    string lname;
    string laddress;
};

struct literaltable LT[10];

bool literalpresent(string s)
{
    for(int i=0;i<10;i++)
    {
        if(LT[i].lname==s)
            return true;
    }
    return false;
}

int getliteralID(string s)
{
    for(int i=0;i<10;i++)
    {
        if(LT[i].lname==s)
            return i;
    }
    return -1;
}

int main()
{
    ifstream in1;
    in1.open("input.txt");

    ofstream ic,st,lt;
    ic.open("ic.txt");
    st.open("symtable.txt");
    lt.open("littable.txt");

    string label,opcode,op1,op2;
    int scnt=0,lcnt=0,nlcnr=0,LC=0;

    cout<<"-----ASSEMBLY PASS-1 CODE-----"<<endl;
    cout<<"LABEL\t OPCODE\t OP1\t OP2\t LC\t INTERMEDIATE CODE"<<endl;

    while(!in1.eof())
    {
        in1>>label>>opcode>>op1>>op2;
        string IC,lc;
        int id;

        id=getoptabID(opcode);
        IC="("+OT[id].opclass+","+OT[id].opmnemonics+")";

        if(opcode=="START")
        {
            lc="---";
            if(op1!="NAN")
            {
                LC=stoi(op1);
                IC+="(C,"+op1+")    NAN";
            }
        }

        if(opcode=="END")
        {
            lc="---";
            IC+="NAN    NAN";
        }
        if (opcode=="ORIGIN")
        {
            string token1,token2,op;
            stringstream ss(op1);
            int found=op1.find('+');
            if(found!=string::npos)
                op='+';
            else:
                op='-';
            getline(ss,token1,op);
            getline(ss,token2,op);
            lc="---";
            if(op=='+')
            {
                LC=stoi(ST[getsymbolID(token1)].saddress)+stoi(token2);
                IC+="(S,"+to_string(ST[getsymbolID(token1)].no)+")+"+token2+"NAN";
            }
            else
            {
                LC=stoi(ST[getsymbolID(token1)].saddress)-stoi(token2);
                IC+="(S,"+to_string(ST[getsymbolID(token1)].no)+")-"+token2+"NAN";
            }
        }

    }
}