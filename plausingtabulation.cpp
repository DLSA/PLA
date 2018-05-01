#include<iostream>
#include<vector>
#include<math.h>
#include<string>
using namespace std;
class tabulation
{
private:
int caldecimalbit;

    int minimum,repeat,combine1,combine2,difference,noofdecimals,possible;
    vector<vector<int> >binary;
 vector<int>temp1;
 vector<vector<int> >save;
 vector<vector<int> >uniques;
   vector<vector<int> >sorted;
   vector<char>output;

int reducedtable[99][99];
    int j,k,decimal,element,counter,count1;
vector<int>minterms;

    vector<int>minterm;
vector<vector<int> >isolated;
int miniprimetable[2][99];
vector<int>mins;

public:

int variables,i;
void tabulate()
{
    int term,noofmin;
    cout<<endl<<"Enter the no of minterms of function "<<i+1<< " to be implemented in PLA"<<endl;
    cin>>noofmin;
    cout<<"enter minterms"<<endl;
    for(j=0;j<noofmin;j++)
    {
        cin>>term;
        minterm.push_back(term);
    }
  mins=minterm;

}
public:
    vector<char> alloperations()
    {
        repeat=0;
        noofdecimals=0;
         minterms=minterm;
         mins=minterm;
    convertbinary();
    sortlist();
    iteration();
    recursion();
    uniqueprimes();
    //printprimeimplicant(save);
    essentialprimeimplicant();

    //printprimeimplicant(uniques);
    //printprimeimplicant(save);
   // printprimeimplicant(uniques);
    saveoutput();
    finaloutput();
    return output;
    }
    void convertbinary()
    {
    for(i=0;i<minterms.size();i++)
        {
            counter=0;
            decimal=minterms[i];
            vector<int>temp(variables+2);
            for(j=variables-1;j>=0;j--)

            {
                element=minterms[i]%2;
                minterms[i]=minterms[i]/2;
                temp[j]=element;
                if(element==1)
                {
                    counter++;
                }
            }

            temp[variables]=counter;
            temp[variables+1]=decimal;
            binary.push_back(temp);


            }

           /*  for(i=0;i<minterms.size();i++)
                {
                    for(j=0;j<variables+2;j++)
                    {
                    cout<<binary[i][j];
                    }
                cout<<endl;

                }   */

}

void sortlist()
{
   // cout<<endl<<endl;
   for(i=0;i<minterms.size();i++)
   {
      minimum=i;
    for(j=0;j<minterms.size();j++)
   {
      if(binary[minimum][variables]>binary[j][variables])
       minimum=j;

   }
       sorted.push_back(binary[minimum]);
       binary[minimum][variables]=9999;
   }

   binary.clear();
minimum=0;
   // cout<<endl<<endl;
   for(i=0;i<minterms.size();i++)
   {
       minimum=i;
    for(j=0;j<minterms.size();j++)
   {
      if((sorted[minimum][variables]==sorted[j][variables])&&(sorted[minimum][variables+1]>sorted[j][variables+1]))
       minimum=j;

   }
       binary.push_back(sorted[minimum]);
       sorted[minimum][variables+1]=9999;
   }

            /* for(i=0;i<minterms.size();i++)
                {
                    for(j=0;j<variables+2;j++)
                    {
                    cout<<binary[i][j];
                    }
                cout<<endl;

                }  */
                sorted.clear();
}

void iteration()
{
    int check=0;

     // cout<<endl<<endl;
 for(i=0;i<binary.size();i++)
 {
     check=0;
 for(j=i+1;j<binary.size();j++)
 {
          combine1=combinationpossible(binary[i][variables+1],binary[j][variables+1]);

 if((binary[i][variables]==(binary[j][variables]-1))&&combine1==1)
 {
     vector<int>temp1(binary[i].begin(),binary[i].end());

     temp1.push_back(binary[j][variables+1]);
     temp1.push_back(difference);
     sorted.push_back(temp1);
     temp1.clear();
     check++;

}

}

}
binary.clear();
           /* for(i=0;i<sorted.size();i++)
                {
                    for(j=0;j<variables+4;j++)
                    {
                        if(j>variables)
                        {
                            cout<<"\t";
                        }
                    cout<<sorted[i][j];
                    }
                cout<<endl;

                }  */
                noofdecimals++;
    if(repeat==0)
    {
        repeat=1;
    }
repeat=2*repeat;

}

void recursion()
{
int k;
// cout<<repeat;
     //  cout<<endl<<endl;
 for(i=0;i<sorted.size();i++)
 {

     vector<int>temp1(sorted[i].begin(),sorted[i].end()-1);
 for(j=i+1;j<sorted.size();j++)
 {
          combine1=combinationpossible(sorted[i][variables+1],sorted[j][variables+1]);
          combine2=decimaldifferencesame(sorted[i],sorted[j]);

 if((sorted[i][variables]==(sorted[j][variables]-1))&&(combine1==1)&&(combine2==1))
 {

//   cout<<"t"<<endl;
    for(k=1;k<=repeat;k++)
    {
     temp1.push_back(sorted[j][variables+k]);
    }
    sorted[j][variables+1]=999999;
    if((sorted[i][variables+repeat+1])<difference)
    {
        temp1.push_back(sorted[i][variables+repeat+1]);
        temp1.push_back(difference);
        }
        else
        {
        temp1.push_back(difference);
        temp1.push_back(sorted[i][variables+repeat+1]);
        }
        save.push_back(temp1);
     binary.push_back(temp1);
     temp1.clear();
     temp1.push_back(999999);
 }
 }
 if(temp1[0]!=999999&&temp1[variables+1]!=999999)
 {
    temp1.push_back(sorted[i][variables+repeat+noofdecimals]);
    save.push_back(temp1);
    temp1.clear();
 }
}
//   cout<<binary.size();
sorted.clear();
// cout<<endl<<endl;
noofdecimals++;
repeat=2*repeat;

         /*   for(i=0;i<binary.size();i++)
                {
                    for(j=0;j<=variables+repeat+noofdecimals;j++)
                    {
                        if(j>variables)
                        {
                            cout<<"\t";
                        }

                    cout<<binary[i][j];
                    }
                cout<<endl;

                }

                cout<<"Next recursion:";  */
sorted=binary;
binary.clear();
while(noofdecimals!=variables-1)
{
recursion();
}
}


int combinationpossible(int first,int second)
{
    int d,j;



    d=second-first;
     difference=d;
    for(j=1;j<variables;j++)
    {

    if((floor(log(d)/log(2)))==(log(d)/log(2))||difference==pow(2,j))
      {
        return 1;
      }


    }

        return 0;

}
int decimaldifferencesame(vector<int>table1,vector<int>table2)
{
    int i=0;
    for(i=variables+repeat+1;i<table1.size();i++)
    {

        if(table1[i]!=table2[i])
        {

table1.clear();
table2.clear();
            return 0;
        }


    }

    //cout<<endl;
table1.clear();
table2.clear();

    return 1;


}

void uniqueprimes()
{
    int check=0,same;
    for(i=0;i<save.size();i++)
{      check=0;
    for(j=i;j<save.size();j++)
    {
    same=ifsame(save[i],save[j]);
        if(i!=j&&same==1&&save[i][0]!=9999&&save[j][0]!=9999)
        {

          save[j][0]=9999;
          check=1;
        }
        else if(j==i&&check!=1&&save[i][0]!=9999&&save[j][0]!=9999)

          uniques.push_back(save[i]);

    }
}

save.clear();
save=uniques;
uniques.clear();
}


int ifsame(vector<int>vec1,vector<int>vec2)
{
    int k,n,count1=0;
    n=(vec1.size()-variables)/3;

for(k=1;k<=n;k++)
{
    if(vec1[variables+n*2+k]==vec2[variables+n*2+k])
  count1++;
}
    if(vec1[variables+1]==vec2[variables+1]&&count1==n)
        {return 1;}
        else
  return 0;
}


void printprimeimplicant(vector<vector<int> >print)
{
for(i=0;i<print.size();i++)
                {
                    for(j=0;j<print[i].size();j++)
                    {
                        if(j>variables)
                        {
                            cout<<"\t";
                        }
                    cout<<print[i][j];
                    }
                cout<<endl;

                }
}


void essentialprimeimplicant()
{
    int n,found=0;
for(i=0;i<mins.size();i++)
{
    miniprimetable[0][i]=mins[i];

    miniprimetable[1][i]=0;
}
/*
for(i=0;i<mins.size();i++)
{
    cout<<miniprimetable[0][i]<<endl;
cout<<miniprimetable[1][i];
}
cout<<endl;
*/
for(i=0;i<save.size();i++)
{

    n=(save[i].size()-variables)/3;
    // cout<<"\t"<<n;
    for(j=1;j<=n*2;j++)
    {
        for(k=0;k<mins.size();k++)
        {
            if(save[i][variables+j]==miniprimetable[0][k])
            {
                miniprimetable[1][k]++;
            }
        }
    }
}
//cout<<endl;
/*for(i=0;i<mins.size();i++)
{
    cout<<miniprimetable[0][i];
cout<<miniprimetable[1][i]<<endl;
}
cout<<endl;
*/
  temp1.clear();
for(i=0;i<mins.size();i++)
{
    if(miniprimetable[1][i]==1)
    {

        for(j=0;j<save.size();j++)
        {
            found=0;
            n=(save[j].size()-variables)/3;
                for(k=1;k<=n*2;k++)
                    {
                        if(save[j][variables+k]==miniprimetable[0][i])
                        {
                            uniques.push_back(save[j]);
                            save[j].clear();
                            found=1;
                            break;
                        }

                    }
                    if(found==1)
                    {
                        break;
                    }
      }
    }


  }
for(i=0;i<mins.size();i++)
{
            found=0;
        for(j=0;j<uniques.size();j++)
        {
            n=(uniques[j].size()-variables)/3;
                for(k=1;k<=n*2;k++)
                    {
                        if(uniques[j][variables+k]==miniprimetable[0][i])
                        {
                            found=1;
                        }
                    }
        }
        if(found==0)
        {
              temp1.push_back(miniprimetable[0][i]);
        }
}
/*
 for(i=0;i<temp1.size();i++)
    {
        cout<<endl<<"this"<<temp1[i];
    }  */
    if(temp1.capacity()!=0&&temp1.capacity()!=1)
    {
    allprimeimplicants();
    }
}

void allprimeimplicants()
{
    int n,countofones;
for(i=0;i<save.size();i++)
{
    countofones=0;
     for(j=0;j<temp1.size();j++)
        {
    n=(save[i].size()-variables)/3;
                for(k=1;k<=n*2;k++)
                    {
                        if(save[i][variables+k]==temp1[j])
                        {
                           // cout<<"d";
                        reducedtable[i][j]=1;
                        countofones++;
                        break;
                        }
                    }


            }
                        reducedtable[i][j]=countofones;
}




/*
for(i=0;i<save.size();i++)
{
for(j=0;j<=temp1.size();j++)
{
 cout<<reducedtable[i][j]<<"\t";
}
cout<<"\n";
}  */
possible=1;
count1=0;
     while(possible==1&&save.size()!=0&&temp1.size()!=0)
    {
    possible=pushbackremainingterms();
    }

}
int pushbackremainingterms()
{
    int maximum=0,maximumindex;
for(i=0;i<save.size();i++)
{
if(maximum<reducedtable[i][temp1.size()])
{     maximum=reducedtable[i][temp1.size()];
    maximumindex=i;
}
}
uniques.push_back(save[maximumindex]);
reducedtable[i][temp1.size()]=0;
count1=count1+maximum;
if(count1<maximum)
{
    return 1;
}
else
    return 0;
}

void saveoutput()
{
    char ch='A';
    int weight=pow(2,variables-1),n;
    for(i=0;i<uniques.size();i++)
    {
        ch='A';
        weight=pow(2,variables-1);
    for(j=0;j<variables;j++)
    {
        n=(uniques[i].size()-variables)/3;
        for(k=1;k<=n;k++)
        {
            if(weight==uniques[i][variables+n*2+k])
            {
                ch++;
                break;

            }
            else if(k==n)
            {
                if(uniques[i][j]==1)
                {
                output.push_back(ch);
                ch++;
                }
                else
                {
                output.push_back(ch+32);
                ch++;
                }
            }
        }

        weight=(weight)/2;

    }
if(i!=uniques.size()-1)
    output.push_back('+');
    }

    /*
cout<<endl<<endl;

    for(i=0;i<output.size();i++)
    {
        cout<<output[i];
    }

*/
}

void finaloutput()
{
    int n,count1;
    char ch='A';
    vector<int>rest;
    for(i=0;i<mins.size();i++)
    {
count1=0;
    for(j=0;j<uniques.size();j++)
    {

    n=(uniques[j].size()-variables)/3;
    for(k=1;k<=n*2;k++)
    {
        if(mins[i]==uniques[j][variables+k])
        {
            count1=1;
        }
    }

    }
    if(count1==0)
    {
        rest.push_back(mins[i]);
    }
}

    minterms.clear();
    minterms=rest;
    convertbinary();
       if(uniques.size()!=0&&minterms.size()!=0)
                        {
                        output.push_back('+');
                        }
     for(i=0;i<minterms.size();i++)
                {
                    ch='A';

                    for(j=0;j<variables;j++)
                    {
                    if(binary[i][j]==1)
                    {
                        output.push_back(ch);
                        ch++;
                    }
                    else
                        {
                            output.push_back(ch+32);
                           ch++;
                        }
                    }
                        if(i!=minterms.size()-1)
                        {
                        output.push_back('+');
                        }
                }
binary.clear();
}



vector<char> functionscompliment()
{
    int true1;
    mins.clear();
for(i=0;i<pow(2,variables);i++)
{
    true1=0;
    for(j=0;j<minterm.size();j++)
    {
        if(i==minterm[j])
        {
            true1=1;
        }
    }
    if(true1==0)
    {
        mins.push_back(i);
    }
}
minterm.clear();
minterm=mins;
tabulation ob;
ob.variables=variables;
ob.mins=mins;
ob.minterm=minterm;
return(ob.alloperations());

}
};







class pla
{
private:
    vector<vector<int> >binarylist;
    vector<vector<char> >functions;
    vector<vector<char> >functionscompliment;
    vector<vector<char> >functionpla;

        vector<int>orinput;
    int i,j,k,m,element,similarity,static1;
    public:
        int terms;
        vector<int>input;
    void binary()
    {
         static1=0;
        for(i=0;i<pow(2,terms);i++)
        {
            k=i;
            vector<int>temp(terms+1);
            for(j=terms-1;j>=0;j--)
            {
                element=k%2;
                k=k/2;
                temp[j]=element;
            }
            binarylist.push_back(temp);
        }

    }
    void functionminimumterms(vector<vector<char> >funcs,vector<vector<char> >funcscomp)
    {
        int maxm=0,maxindex=0;
        functions=funcs;
        functionscompliment=funcscomp;

        for(i=0;i<pow(2,terms);i++)
        {
            vector<vector<char> >temp1;
        for(j=0;j<terms;j++)
        {
         if(binarylist[i][j]==1)
         {
            temp1.push_back(functions[j]);
         }

        else
            temp1.push_back(functionscompliment[j]);

        }
        similarity=compare(temp1);

        binarylist[i].push_back(similarity);
        }

for(i=0;i<pow(2,terms);i++)
{
    if(maxm<binarylist[i][terms+1])
   {
       maxm=binarylist[i][terms+1];
    maxindex=i;
   }
}
// cout<<maxindex<<endl<<endl;
if(maxm!=0)
{
for(i=0;i<terms;i++)
{
    if(binarylist[maxindex][i]==1)
    {
        functionpla.push_back(functions[i]);
    }
    else
    {
        functionscompliment[i].push_back('-');
        functionpla.push_back(functionscompliment[i]);
    }
}
}
else
{
for(i=0;i<terms;i++)
{

        functionpla.push_back(functions[i]);
}
}
cout<<endl<<"  THE functions or their compliments leading to minimum  AND gates in PLA are: \n"<<endl;
 for(i=0;i<functionpla.size();i++)
    {
        cout<<"\t\t\t";
    for(j=0;j<functionpla[i].size();j++)
    {

        cout<<functionpla[i][j];
    }
    cout<<endl;
    }

cout<<"  (NOTE:  '-' at the end of a function  depits that function is in compliments form"<<endl;


    }

    int compare(vector<vector<char> >temp2)
    {
        similarity=0;
        int i,j,k,l,m;
        vector<char>string1;
        vector<char>string2;
        for(i=0;i<temp2.size();i++)
        {
            temp2[i].push_back('+');
        }


        for(i=0;i<temp2.size();i++)
        {
            for(j=i+1;j<temp2.size();j++)
            {

            for(k=0;k<temp2[i].size();k++)
            {
                if(temp2[i][k]!='+')
                {

                 string1.push_back(temp2[i][k]);

                }
                else if(temp2[i][k]=='+')
                    {
                    for(l=0;l<temp2[j].size();l++)

                    {
                        if(temp2[j][l]!='+')
                        {

                    string2.push_back(temp2[j][l]);

                        }
                        else if(temp2[j][l]=='+')
                        {
                         if(string1==string2)
                            {
                              similarity++;

                                }
                            string2.erase(string2.begin(),string2.end());
                        }

                   }

        string1.erase(string1.begin(),string1.end());

                            string2.erase(string2.begin(),string2.end());
           }

            }
        }
     return  similarity;
    }

    }
void applyinputstothepla(vector<int>input3)
{

    int andoutput;
    int output;
    static1++;
        vector<char>string1;
        if(static1==1)
    {
     for(i=0;i<functionpla.size();i++)
        {
            functionpla[i].push_back('+');
        }
    }

    for(i=0;i<functionpla.size();i++)
    {
        string1.clear();
        for(j=0;j<functionpla[i].size();j++)
        {
        if(functionpla[i][j]!='+'&&functionpla[i][j]!='-')
        {
            string1.push_back(functionpla[i][j]);
        }
       else  if(functionpla[i][j]=='+'||functionpla[i][j]=='-')
       {
           cout<<endl;
           if(string1.size()!=0)
            {
           andoutput=(anding(input3,string1));
           orinput.push_back(andoutput);
           string1.clear();
            }

            string1.clear();

       }

        }

        output=oring(orinput);

        if(functionpla[i][functionpla[i].size()-2]=='-')
        {
            if(output==1)
            {
            output=0;
            }
            else
            {
            output=1;
            }
        cout<<"OUTPUT of function "<<i+1<<" is\n\t\tPLA OUTPUT "<<i+1<<" :"<<output<<endl;
        string1.clear();

        orinput.clear();
        }
        else
        {
       cout<<"OUTPUT of function "<<i+1<<" is\n\t\tPLA OUTPUT "<<i+1<<" :"<<output<<endl;
        string1.clear();

        orinput.clear();

        }
    }


    }



         int anding(vector<int>input1,vector<char>temp)
    {

        int i,j;
       char ch='A';
          int mul=1;
        for(i=0,j=0;i<input1.size();i++)
        {
            if(temp[j]==ch)
                {
                    mul=mul*input1[i];
                    j++;
                }

            else if(temp[j]==ch+32)
            {
                j++;
              if(input1[i]==1)
              {
                  mul=mul*0;
              }
              else
              {
                mul=mul*1;
              }
            }
            ch++;
        }
        return(mul);
    }

 int oring(vector<int>input2)
    {
        int i,j;

        int sum=0;
        for(i=0;i<input2.size();i++)
        {
           sum=sum+input2[i];
        }


        if(sum==0)
        {
        return(sum);
        }
        else
            return 1;
    }


} ;




int main()
{
    int variables,i,j,noofplaoutputs;
    vector<char>temp;
    int k,l;
    cout<<"How many inputs does the PLA must have"<<endl;
    cin>>variables;

    cout<<endl<<"For how many functions the PLA should be programmed "<<endl;
    cin>>noofplaoutputs;
    vector<vector<char> >functions;
    vector<vector<char> >functionscompliment;
    
    tabulation ob[noofplaoutputs];
 for(i=0;i<noofplaoutputs;i++)
{
    ob[i].i=i;
    ob[i].variables=variables;
    ob[i].tabulate();
    temp=ob[i].alloperations();
    functions.push_back(temp);
    temp.clear();
    temp=ob[i].functionscompliment();
    functionscompliment.push_back(temp);
    temp.clear();
}


    cout<<endl<<"\tMinimized expression for each function (in order): "<<endl;

    for(k=0;k<functions.size();k++)
    {
        cout<<"\t\t\t";
    for(l=0;l<functions[k].size();l++)
    {
        cout<<functions[k][l];
    }

    cout<<endl;
    }

    cout<<endl<<"\tCorresponding compliments of the functions (in order) are :"<<endl;
    for(k=0;k<functionscompliment.size();k++)
    {

        cout<<"\t\t\t";
    for(l=0;l<functionscompliment[k].size();l++)
    {
        cout<<functionscompliment[k][l];
    }

    cout<<endl;
    }
    cout<<endl<<endl;
    pla ob1;
    ob1.terms=noofplaoutputs;
ob1.binary();
ob1.functionminimumterms(functions,functionscompliment);
cout<<"\n\n\n\tThe pla have been programmed according to the provided information "<<endl;
cout<<"\nGive the inputs to the PLA"<<endl;
while(1)
{
vector<int>input(variables);
for(i=0;i<variables;i++)
{
cin>>input[i];
}
ob1.applyinputstothepla(input);
input.clear();

}
return 0;
}
