#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include <math.h>

using namespace std;

const int MAX_FILE = 4; // 4 testbench (+ 1 hiden testbench)

class Chain;
class ChainNode
{
	friend class Chain;
	public:
		ChainNode(vector<int> c, vector<int> e, ChainNode *next){coef=c;exp=e;link=next;}
	private:
		vector<int> coef;
    	vector<int> exp;
    	ChainNode *link;
};
class Chain
{
	ChainNode *first;
    ChainNode *last;
	public:
		void Create(string coef[], string exp[], int count);
    	void Insert(vector<int> c, vector<int> e, ChainNode *x);
    	void Delete(ChainNode *x, ChainNode *y);
    	Chain BubbleSort(Chain PolyC);
    	Chain Total(Chain PolyC);
    	void GetCoef();
    	void GetExp();
		void MulBigNumber(ChainNode *a, ChainNode *b, int check);
		void Mul(Chain PolyA, Chain PolyB);
    	void Write(ofstream &fout);
};

void Chain::Create(string coef[], string exp[], int count) // create linked poly
{
	int *number_coef = new int[count+1];
	int *number_exp = new int[count+1];
	for(int i = 0; i < count+1; i++)
	{
		int *array_coef = new int[coef[i].length()];
		for(int j = 0; j < coef[i].length(); j++) array_coef[j] = atoi(coef[i].substr(j,1).c_str());
		int *array_exp = new int[exp[i].length()];
		for(int j = 0; j < exp[i].length(); j++) array_exp[j] = atoi(exp[i].substr(j,1).c_str());
		// store in to vector
		vector<int> vcoef(array_coef,array_coef+coef[i].length());
		vector<int> vexp(array_exp,array_exp+exp[i].length());
		// linked
		if(i == 0) 
		{
			first = new ChainNode(vcoef,vexp,0);
			last = first;
		}
		else
		{
			Insert(vcoef,vexp,last);
            last=last->link;
		}	
	}
}
void Chain::Insert(vector<int> c, vector<int> e, ChainNode *x)
{
    x->link = new ChainNode(c,e,x->link);
}
void Chain::Delete(ChainNode *x, ChainNode *y)
{
    if(x == first) first = first->link;
	else y->link = x->link;
    delete x;
}
Chain Chain::BubbleSort(Chain PolyC) // change the poly's exp from large to small
{
	ChainNode *a = PolyC.first;
    do
	{
		ChainNode *b;
		for(b = PolyC.first; b != last; b = b->link)
		{
			ChainNode *c = b->link;	
			if(b->exp.size() == c->exp.size())
			{
				if(b->exp[0] < c->exp[0]) // swap
       			{
       				vector<int> s1 = b->coef;
					vector<int> s2 = c->coef;
					vector<int> e1 = b->exp;
					vector<int> e2 = c->exp;
					b->coef = s2;
					c->coef = s1;
					b->exp = e2;
					c->exp = e1;
				}
				else
				{	
					// use sub of bignumber	
					int check = 0;
					int compare = (b->exp.size() > c->exp.size()) ? b->exp.size() : c->exp.size();
					vector<int> e1(compare,0);
					vector<int> e2(compare,0);
					if(b->exp.size() > c->exp.size())
					{
						for(int i = 0; i < b->exp.size(); i++) e1[i] = b->exp[i];
						for(int i = 0; i < c->exp.size(); i++) e2[compare-1-i] = c->exp[i];
					}
					else if(b->exp.size() < c->exp.size())
					{
						for(int i = 0; i < c->exp.size(); i++) e2[i] = c->exp[i];
						for(int i = 0; i < b->exp.size(); i++) e1[compare-1-i] = b->exp[i];
					}
					else
					{
						e1 = b->exp;
						e2 = c->exp;
					}
					vector<int> m2(compare,0);
					for(int i = 0; i < compare; i++) m2[compare-1-i] = e1[i]-e2[i];

    				vector<int> s2(compare,0);
					for(int i = compare-1; i >= 0; i--)  s2[compare-1-i] = m2[i];
					float judge = 0;
					for(int i = 0; i < compare; i++) judge += (s2[i]*pow(10,(compare-1-i)));
					// if judge < 0 => b->exp < c->exp
					if(judge < 0)  // swap
					{
						vector<int> s1 = b->coef;
						vector<int> s2 = c->coef;
						vector<int> e1 = b->exp;
						vector<int> e2 = c->exp;
						b->coef = s2;
						c->coef = s1;
						b->exp = e2;
						c->exp = e1;
					}
				}
			}
        	else if(b->exp.size() < c->exp.size()) //swap
        	{
        		vector<int> s1 = b->coef;
				vector<int> s2 = c->coef;
				vector<int> e1 = b->exp;
				vector<int> e2 = c->exp;
				b->coef = s2;
				c->coef = s1;
				b->exp = e2;
				c->exp = e1;
			}
        }
        a = a->link;
	}while(a != PolyC.last);
	return PolyC;
}
Chain Chain::Total(Chain PolyC) // add the coef from same exp
{
	ChainNode *a;
    ChainNode *b;
	first = 0;
    for(a = PolyC.first; a != PolyC.last; a = a->link)
	{
		for(b = a->link; b != last->link; b = b->link)
		{
			if(a->exp.size() == b->exp.size())
			{
				int check = 0;
				for(int i = 0; i < a->exp.size(); i++)
				{
					if(a->exp[i] == b->exp[i]) check++;
				}
				if(check == a->exp.size())
				{
					// use add of bignumber
					int compare = (a->coef.size() > b->coef.size()) ? a->coef.size() : b->coef.size();
					vector<int> e1(compare,0);
					vector<int> e2(compare,0);
					if(a->coef.size() > b->coef.size())
					{
						for(int i = 0; i < a->coef.size(); i++) e1[i] = a->coef[i];
						for(int i = 0; i < b->coef.size(); i++) e2[compare-1-i] = b->coef[i];
					}
					else if(a->coef.size() < b->coef.size())
					{
						for(int i = 0; i < b->coef.size(); i++) e2[i] = b->coef[i];
						for(int i = 0; i < a->coef.size(); i++) e1[compare-1-i] = a->coef[i];
					}
					else
					{
						e1 = a->coef;
						e2 = b->coef;
					}
					vector<int> m2(compare,0);
					for(int i = 0; i < compare; i++) m2[compare-1-i] = e1[i]+e2[i];
					for(int i = 0; i < compare-1; i++)  // judge carry
    				{
      					m2[i+1]+=m2[i]/10;
       					m2[i]=m2[i]%10;
    				}
    				vector<int> s2(compare,0);
					for(int i = compare-1; i >= 0; i--)  s2[compare-1-i] = m2[i];
    				// sum store in a->coef and delete b
    				a->coef = s2;
    				Delete(b,a);
				}
			}
		}
	}
	return PolyC;
}
void Chain::GetCoef() // examine poly's coef
{
    ChainNode *node;
    for(node=first;node!=last->link;node=node->link)
	{
    	for(int i = 0; i < node->coef.size(); i++) cout << node->coef[i];
    	cout << "   ";
    }
    cout << endl;
}
void Chain::GetExp() // examine poly's exp
{
    ChainNode *node;
    for(node=first;node!=last->link;node=node->link)
	{
    	for(int i = 0; i < node->exp.size(); i++) cout << node->exp[i];
    	cout << "   ";
    }
    cout << endl;
}
void Chain::MulBigNumber(ChainNode *a, ChainNode *b, int check) // to deal with bignumber
{
	vector<int> a1 = a->coef;
	vector<int> a2 = b->coef;
	vector<int> b1 = a->exp;
	vector<int> b2 = b->exp;
	// store in same length
	int compare = (b1.size() >= b2.size()) ? b1.size() : b2.size();
	vector<int> e1(compare,0);
	vector<int> e2(compare,0);
	if(b1.size() > b2.size())
	{
		for(int i = 0; i < b1.size(); i++) e1[i] = b1[i];
		for(int i = 0; i < b2.size(); i++) e2[compare-1-i] = b2[i];
	}
	else if(b1.size() < b2.size())
	{
		for(int i = 0; i < b2.size(); i++) e2[i] = b2[i];
		for(int i = 0; i < b1.size(); i++) e1[compare-1-i] = b1[i];
	}
	else
	{
		e1 = b1;
		e2 = b2;
	}
	// m1 => mul(coef); m2 => sum(exp)
	// store in reverse order
	vector<int> m1(a1.size()+a2.size(),0);
	vector<int> m2(compare,0);
	// coef
    for(int i = 0; i < a1.size(); i++)
    {
    	for(int j = 0; j < a2.size(); j++) m1[a1.size()+a2.size()-1-i-j] += a1[i]*a2[j];
	}
	for(int i = 0; i < a1.size()+a2.size()-1; i++)
    {
        m1[i+1] += m1[i]/10;
        m1[i] = m1[i]%10;
    }
	// exp
    for(int i = 0; i < compare; i++) m2[compare-1-i] = e1[i]+e2[i];
	for(int i = 0; i < compare-1; i++)  // judge carry
    {
      	m2[i+1]+=m2[i]/10;
       	m2[i]=m2[i]%10;
    }

	vector<int> s1(a1.size()+a2.size()-1,0);
	vector<int> s2(compare,0);
	// store in normal order
	for(int i = a1.size()+a2.size()-1; i > 0; i--) s1[a1.size()+a2.size()-1-i] = m1[i];	
	for(int i = compare-1; i >= 0; i--)  s2[compare-1-i] = m2[i];
	// linked
    if(check == 0) 
	{
		first = new ChainNode(s1,s2,0);
		last = first;
	}
	else 
	{
		Insert(s1,s2,last);
		last=last->link;
	}
}
void Chain::Mul(Chain PolyA, Chain PolyB) // Mul function
{
	ChainNode *a;
    ChainNode *b;
	first = 0;
	int i = 0;
    for(a = PolyA.first; a != PolyA.last->link; a = a->link)
	{
        for(b = PolyB.first; b!= PolyB.last->link; b = b->link) 
		{
			MulBigNumber(a,b,i);
			i++;
		}
    }
}
void Chain::Write(ofstream &fout) // output
{
        fout << "    C = A * B = ";
        ChainNode *c;

        for(c = first; c != last->link; c = c->link)
		{
            for(int i = 0; i < c->coef.size(); i++) fout << c->coef[i];
            if(c->exp[0] == 0) fout << " ";
            else if(c->exp[0] == 1 && c->exp.size() == 1) fout << " x ";
            else
			{
            	fout << " x ^ ";
            	for(int j = 0; j < c->exp.size(); j++) fout << c->exp[j];
            }
            if(c != last) fout << " + ";
        }
        fout << endl;
}

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
            string a1, a2, b1, b2, A, B;

            infile.getline(buffer,MAX);
            infile.getline(buffer,MAX);
            a1 = buffer;
            infile.getline(buffer,MAX);
            a2 = buffer;

            A = A.assign(a1,4,a1.length()); // poly A
            B = B.assign(a2,4,a2.length()); // poly B

			b1 = A, b2 = B;
			int count1 = 0, count2 = 0, start = 0, search1 = 0, search2 = 0;
			search1 = b1.find("+",start);
			while(search1 >= 0)
			{
				count1++;
				b1 = b1.assign(b1,b1.find("+",search1)+1,b1.length());
				search1 = b1.find("+",search1);
			}
			search2 = b2.find("+",start);
			while(search2 >= 0)
			{
				count2++;
				b2 = b2.assign(b2,b2.find("+",search2)+1,b2.length());
				search2 = b2.find("+",search2);
			}
			
			string *x = new string[count1+1]; // A has count1+1 items
			string *y = new string[count2+1]; // B has count2+1 items
			// store item in array
			b1 = A, b2 = B;
			search1 = 0, search2 = 0;
			for(int i = 0; i < count1+1; i++)
			{
				if(i != count1) 
				{
					x[i] = x[i].assign(b1,0,b1.find(" + ",0));
					b1 = b1.assign(b1,b1.find(" + ",search1)+3,b1.length());
					search1 = b1.find(" + ",search1);	
				}
				else x[i] = x[i].assign(b1,0,b1.length());
			}
			for(int i = 0; i < count2+1; i++)
			{
				if(i != count2) 
				{
					y[i] = y[i].assign(b2,0,b2.find(" + ",0));
					b2 = b2.assign(b2,b2.find(" + ",search2)+3,b2.length());
					search2 = b2.find(" + ",search2);	
				}
				else y[i] = y[i].assign(b2,0,b2.length());
			}
			
			string *coef1 = new string[count1+1]; // A coef
			string *exp1 = new string[count1+1]; // A exp
			string *coef2 = new string[count2+1]; // B coef
			string *exp2 = new string[count2+1]; // B exp
            for(int i = 0; i < count1+1; i++)
            {
            	int search_s1 = 0; // separate coef and exp
            	search_s1 = x[i].find(" x ^ ",0);
            	if(search_s1 >= 0) 
				{
					// exp > 1
					coef1[i] = coef1[i].assign(x[i],0,search_s1);
					exp1[i] = exp1[i].assign(x[i],search_s1+5,x[i].length());
				}
				else
				{
					int search_s2 = 0;
					search_s2 = x[i].find(" x",0);
					if(search_s2 >= 0) 
					{
						// exp = 1
						coef1[i] = coef1[i].assign(x[i],0,search_s2);
						exp1[i] = "1";
					}
					else
					{
						// exp = 0
						coef1[i] = coef1[i].assign(x[i],0,x[i].length());
						exp1[i] = "0";
					}
				}
			}
			for(int i = 0; i < count2+1; i++)
            {
            	int search_s1 = 0; // separate coef and exp
            	search_s1 = y[i].find(" x ^ ",0);
            	if(search_s1 >= 0)
				{
					// exp > 1
					coef2[i] = coef2[i].assign(y[i],0,search_s1);
					exp2[i] = exp2[i].assign(y[i],search_s1+5,y[i].length());
				}
				else
				{
					int search_s2 = 0;
					search_s2 = y[i].find(" x",0);
					if(search_s2 >= 0)
					{
						// exp = 1
						coef2[i] = coef2[i].assign(y[i],0,search_s2);
						exp2[i] = "1";
					}
					else
					{
						// exp = 0
						coef2[i] = coef2[i].assign(y[i],0,y[i].length());
						exp2[i] = "0";
					}
				}
			}
			
			// initial poly
			Chain PolyA, PolyB, PolyC;
			PolyA.Create(coef1,exp1,count1);	// create poly A
			PolyB.Create(coef2,exp2,count2);	// create poly B
			// output poly A and poly B
			fout << "Test" << n+1 << ":" << endl;
			fout << "    A = " << A << endl;
			fout << "    B = " << B << endl;
			PolyC.Mul(PolyA, PolyB);			// create poly C = PolyA * PolyB 
			PolyC = PolyC.BubbleSort(PolyC);	// use power down order
			PolyC = PolyC.Total(PolyC);			// if the coefs have same exp, add together 
			PolyC.Write(fout);					// output poly C
		}  
    }
    return 0;
}
