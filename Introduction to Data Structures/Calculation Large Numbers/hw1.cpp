#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>

using namespace std;

const int MAX_FILE = 4; // 4 testbench (+ 1 hiden testbench)

int main()
{
     // output file
     ofstream fout("result.txt");
     for (int n = 0; n < MAX_FILE; ++n)
     {
        const int MAX = 10000;
        char buffer[MAX];
        // read each file
        stringstream s;
        s << "testbench" << n+1 << ".txt";
        ifstream infile(s.str().c_str(), ifstream::in);

        // judge the file exists or doesn't exist
        if (!infile) cout << "Can't open file!\n";
        else
        {
            // read the number X and Y and store them into string
            string a1, a2, b1, b2;

            infile.getline(buffer,MAX);
            infile.getline(buffer,MAX);
            infile.getline(buffer,MAX);
            a1 = buffer;
            infile.getline(buffer,MAX);
            a2 = buffer;

            // select integer
            b1 = b1.assign(a1,2,a1.length());   // string x = b1
            b2 = b2.assign(a2,2,a2.length());   // string y = b2

            // initialize
            int *number_x = new int[b1.length()];
            int *number_y = new int[b2.length()];
            int *sum = new int[b1.length()];
            for(int i = 0; i < b1.length(); i++) sum[i] = 0;
            int *sub = new int[b1.length()];
            for(int i = 0; i < b1.length(); i++) sub[i] = 0;
            int *mul = new int[b1.length()+b2.length()];
            for(int i = 0; i < b1.length()+b2.length(); i++) mul[i] = 0;
            int div = 0;

            // string to int[]
            for(int i = 0; i < b1.length(); i++) number_x[i] = atoi(b1.substr(i,1).c_str());
            for(int i = 0; i < b2.length(); i++) number_y[i] = atoi(b2.substr(i,1).c_str());

            if(1) // ADD
            {
                int i = 0;
                for(i = 0; i < b1.length(); i++) sum[b1.length()-1-i] = number_x[i]+number_y[i];
                for(i = 0; i < b1.length()-1; i++)  // judge carry
                {
                    sum[i+1]+=sum[i]/10;
                    sum[i]=sum[i]%10;
                }
                for(i = b1.length()-1; i >= 0; i--)  fout << sum[i];
                fout << endl;
            }

            if(1) // SUB
            {
                int i = 0, check = 0;
                for(i = 0; i < b1.length(); i++) sub[b1.length()-1-i] = number_x[i]-number_y[i];
                do
                {
                    check = 0;
                    for(i = 0; i < b1.length()-1; i++)
                    {
                        if(sub[i] < 0)
                        {
                            sub[i+1]--;
                            sub[i] += 10;
                        }
                    }
                    for(i = 0; i < b1.length(); i++)
                        if(sub[i] < 0) check = 1;
                }while(check == 1);
                for(i = b1.length()-1; i >= 0; i--)  fout << sub[i];
                fout << endl;
            }

            if(1) // MUL
            {
                int i = 0, j = 0;
                for(i = 0; i < b1.length(); i++)
                    for(j = 0; j < b2.length(); j++) mul[b1.length()+b2.length()-1-i-j] += number_x[i]*number_y[j];
                for(i = 0; i < b1.length()+b2.length()-1; i++)
                {
                    mul[i+1] += mul[i]/10;
                    mul[i] = mul[i]%10;
                }
                for(i = b1.length()+b2.length()-1; i > 0; i--) fout << mul[i];
                fout << endl;
            }

            if(1) // DIV
            {
                int i = 0, check = 0, check1 = 0, check2 = 0;
                for(i = 0; i < b1.length(); i++) sub[i] = number_x[i]-number_y[i];
                div++;
                do
                {
                    check = 0;
                    for(i = 0; i < b1.length()-1; i++)
                    {
                        if(sub[i+1] < 0)
                        {
                            sub[i]--;
                            sub[i+1] += 10;
                        }
                    }
                    for(i = 0; i < b1.length(); i++)
                        if(sub[i] < 0) check = 1;
                }while(check == 1);
                for(i = 0; i < b1.length(); i++)
                {
                    if(sub[i] == 0) check1++;
                    if(sub[i] >= 0) check2++;
                }
                while(check2 == b1.length() && check1 != b1.length())
                {
                    check1 = 0;
                    check2 = 0;
                    for(i = 0; i < b1.length(); i++) sub[i] -= number_y[i];
                    for(i = 0; i < b1.length()-1; i++)
                    {
                        if(sub[i+1] < 0)
                        {
                            sub[i]--;
                            sub[i+1] += 10;
                        }
                    }
                    for(i = 0; i < b1.length()-1; i++)
                    {
                        if(sub[i+1] < 0)
                        {
                            sub[i]--;
                            sub[i+1] += 10;
                        }
                    }
                    for(i = 0; i < b1.length(); i++)
                    {
                        if(sub[i] == 0) check1++;
                        if(sub[i] >= 0) check2++;
                    }
                    if(check2 == b1.length()) div++;
                }
                fout << div;
                fout << "\n" << endl;
            }
        }
    }
    return 0;
}
