#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<math.h>

using namespace std;

const int MAX_FILE = 4; // 4 testbench (+ 1 hiden testbench)
int n;
vector<bool> visit;
vector<int> vdigit1; 
vector<int> vdigit2; 
vector< vector<bool> > graph;
vector< vector<bool> > directgraph;

void DFS(int v)
{
	visit[v] = true;
	for (int w = 0; w < n; w++) 
	{ 
		if(graph[v][w])
		{
			if(!visit[w]) DFS(w);
		}
	}
}

int calculateVisit(int i)
{
	int calculate = 0;
	DFS(i);
	for(int j = 0; j < n; j++) if(visit[j]) calculate++;
	return calculate;
}

char letter(int i) // change number to letter
{
	char le;
	le = i+97;
	return le;
}

int main()
{
     // output file
     ofstream fout("result.txt");
     for (int g = 0; g < MAX_FILE; ++g)
    {
        const int MAX = 10000;
        char buffer[MAX];
        // read each file
        stringstream s;
        s << "testbench" << g+1 << ".txt";
        ifstream infile(s.str().c_str(), ifstream::in);

        // judge the file exists or doesn't exist
        if (!infile) cout << "Can't open file!\n";
        else
        {
            // read the number X and Y and store them into string
            string getText, GraphText, Text;

            infile.getline(buffer,MAX);
            infile.getline(buffer,MAX);
            getText = buffer;
            Text = Text.assign(getText,0,getText.length()); // graph
			GraphText = Text;
			
			int count1 = 0, start = 0, search1 = 0;
			search1 = GraphText.find(")",start);
			while(search1 >= 0) // calculate how many items
			{
				count1++;
				GraphText = GraphText.assign(GraphText,GraphText.find(")",search1),GraphText.length());
				search1 = GraphText.find(")",search1);
			}

			string *x = new string[count1]; // graph has count1 items
			// store item in array
			GraphText = Text;
			for(int i = 0; i < count1; i++)
			{
				x[i] = x[i].assign(GraphText,GraphText.find(",",0)-1,GraphText.find(")",0)-1);
				if(i != count1-1) GraphText = GraphText.assign(GraphText,GraphText.find(")",0)+4,GraphText.length());
			}
			
			char *coorX = new char[count1]; // coordinate x
			char *coorY = new char[count1]; // coordinate y
            for(int i = 0; i < count1; i++)
            {
            	int search_s1 = 0;
            	string coor1, coor2;
            	search_s1 = x[i].find(",",0);
            	if(search_s1 >= 0) 
				{
					coor1 = coor1.assign(x[i],0,search_s1);
					coorX[i] = coor1[0];
					coor2 = coor2.assign(x[i],search_s1+1,x[i].length());
					coorY[i] = coor2[0];
				}
			}
			// use integer to represent letters
			int *digit1 = new int[count1]; 
			int *digit2 = new int[count1];
			for(int i = 0; i < count1; i++)
			{
				digit1[i] = coorX[i]-97;
				digit2[i] = coorY[i]-97;
			}
			// store digit in vector
			vdigit1.assign(digit1,digit1+count1); 
			vdigit2.assign(digit2,digit2+count1); 
			
			//judge number of node
			int node = 0;
			vector<int> max1(count1,0); 
			vector<int> max2(count1,0); 
			while(node == 0)
			{
				int exam1,exam2;
				for(int i = 0; i < count1; i++)
				{
					for(int j = 0; j < count1; j++) if(vdigit1[i] >= vdigit1[j]) max1[i]++;
					for(int j = 0; j < count1; j++) if(vdigit2[i] >= vdigit2[j]) max2[i]++;
				}
				for(int i = 0; i < count1; i++)	if(max1[i] == count1) exam1 = vdigit1[i];
				for(int i = 0; i < count1; i++)	if(max2[i] == count1) exam2 = vdigit2[i];
				node = (exam1 > exam2) ? exam1+1 : exam2+1;
			}
	
			// adjacency matrix
			vector<bool> row(node,0);
			graph.assign(node,row);
			// judge a vertex and a vertex have edge or not --> draw graph
			for (int i = 0; i < count1; i++) graph[vdigit1[i]][vdigit2[i]] = 1;
			for (int i = 0; i < count1; i++) graph[vdigit2[i]][vdigit1[i]] = 1;

			n = node;	
			visit.assign(n,false);
			vector<bool> DFSrow(n,0);
			vector< vector<bool> > DFSgraph(n,row);
			// break one node and run DFS to see the graph is connected or not --> decide articulation points
			vector<bool> ap(n,0); 
			for(int i = 0; i < n; i++)
			{
				visit.assign(n,false); // clear visit state
				for(int j = 0; j < n; j++) 
				{
					if(graph[i][j] || graph[j][i])
					{
						DFSgraph[i][j] = DFSgraph[j][i] = 1;
						graph[i][j] = graph[j][i] = 0;
					}
				}
				if(i != 0) DFS(0);
				else DFS(1);
				int visited = 0;
				for(int j = 0; j < n; j++) if(visit[j]) visited++; // if all vertice (except one node we take off) are visited --> not an articulation point
				if(visited != n-1) ap[i] = 1;
				// restore the graph
				for(int j = 0; j < n; j++) if(DFSgraph[i][j]) graph[i][j] = 1;
				for(int j = 0; j < n; j++) if(DFSgraph[j][i]) graph[j][i] = 1;
				DFSgraph.assign(n,DFSrow); 
			}		
			
			vector<int> circle(n,0);
			for(int i = 0; i < n; i++)
			{
				if(ap[i]) 
				{
					for(int j = 0; j < n; j++) 
					{
						if(graph[i][j] || graph[j][i]) // break the edges that link to articulation points
						{
							DFSgraph[i][j] = DFSgraph[j][i] = 1;
							graph[i][j] = graph[j][i] = 0;
							if(ap[j]) circle[i] = circle[j] = 2; // if two or more articulation points linke together that circle==2
							else circle[j] = 1; // if a node (except articulation points) link to articulation points that circle==1 
						}
					}			
				}
			}	
		//	for(int i = 0; i < n; i++) cout <<  i+1 << ": " << circle[i] << endl; 
			vector<int> looprow(n,0);
			vector< vector<int> > loop(n,looprow);
			vector<int> artirow(n,0);
			vector< vector<int> > articulationlink(n,artirow);
			// judge biconnected graph
			for(int i = 0; i < n; i++) 
			{
				visit.assign(n,false);								
				// search vertex adjacent to articulation point
				if(circle[i]==1) 
				{
					int cal = calculateVisit(i);
					for(int j = 0; j < n; j++) 
					{
						if(ap[j]) 
						{
							if(DFSgraph[i][j] || DFSgraph[j][i]) 
							{
								visit[j] = 1;
								if(circle[j]==2)
								{
									for(int k = 0; k < n; k++)
									{
										if(circle[k]==2 && (DFSgraph[k][j] || DFSgraph[j][k]))
										{
											int checkcheck1 = 0, checkcheck2 = 0;
											for(int m = 0; m < n; m++)
											{
												if(circle[m]!= 2 && visit[m] && (DFSgraph[m][k] || DFSgraph[k][m])) visit[k] = 1;
												if(cal==1) 
												{
													if(DFSgraph[i][k] || DFSgraph[k][i])
													{
														if(j < k) articulationlink[j][k] = 0;
														else articulationlink[k][j] = 0;
														checkcheck1 = 1;
													}
													if(checkcheck1==0  && DFSgraph[i][k]==0 && DFSgraph[k][i]==0)
													{
														if(j < k) articulationlink[j][k] = 1;
														else articulationlink[k][j] = 1;
													}
												}
												else if(cal!=1)
												{
													if(circle[m] == 1 && visit[m])
													{		
														// cout << "i: " << i << ", j: " << j << ", k: " << k << ", m: " << m << ", cal: " << cal << endl;
														if(checkcheck2 == 0 && !(DFSgraph[m][k] || DFSgraph[k][m]))
														{
															if(j < k) articulationlink[j][k] = 1;
															else articulationlink[k][j] = 1;
														}
														if(DFSgraph[m][k] || DFSgraph[k][m])
														{
															if(j < k) articulationlink[j][k] = 0;
															else articulationlink[k][j] = 0;
															checkcheck2 = 1;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				for(int j = 0; j < n; j++) if(visit[j]) loop[i][j] = 1;	
			}
			// judge duplicate loop
			for(int i = 0; i < n; i++)
			{
				for(int j = i+1; j < n; j++)
				{
					vector<int> checkpoint(2,0);
					int checkpoint2 = 0;
					for(int k = 0; k < n; k++)
					{
						if(loop[i][k]==1) checkpoint[0]++;
						if(loop[j][k]==1) checkpoint[1]++;
					}
					if(checkpoint[0]==checkpoint[1])
					{
						for(int k = 0; k < n; k++)	if(loop[i][k]==loop[j][k]) checkpoint2++;
						if(checkpoint2==n) for(int k = 0; k < n; k++) loop[j][k] = 0;	
					}	
				}
			}
			vector<int> loopnumber(n,0);
			for(int i = 0; i < n; i++) // judge the number of the end of the loop
			{
				int co = 0;
				for(int j = 0; j < n; j++) if(loop[i][j]) co = j;
				loopnumber[i] = co;
			}
			fout << "Test" << g+1 << ":" << endl;
			fout << "articulation point:";
			for(int i = 0; i < n; i++) if(ap[i]) fout << " " << letter(i);
			fout << endl;
			fout << "biconnected components: ";
			for(int i = 0; i < n; i++) 
			{
				int co = 0;		
				for(int j = 0; j < n; j++) // print loop
				{
					if(loop[i][j]) 
					{
						if(co==0) fout << "{";
						fout << letter(j);
						if(j != loopnumber[i]) fout << ",";
						co = 1;
					}
				}
				if(co == 1) fout << "}";
			}
			for(int i = 0; i < n; i++) 
			{
				for(int j = 0; j < n; j++)
				{
					if(articulationlink[i][j]) 
					{
						int checkdouble = 0;
						for(int k = 0; k < n; k++) if(loop[k][i] && loop[k][j]) checkdouble = 1;
						if(checkdouble!=1) fout << "{" << letter(i) << "," << letter(j) << "}"; // print arti loop	
					}
				} 
			}
			fout << endl;
			fout << endl;
		/*	for(int i = 0; i < n; i++) if(ap[i]) cout << "�`�I: " << i+1 << endl;   // print articulation points			
			for(int i = 0; i < n; i++) // print loop
			{
				int co = 0;
				for(int j = 0; j < n; j++) 
				{
					if(loop[i][j]) 
					{
						cout << j << " ";	
						co = 1;
					}
				}
				if(co == 1) cout << endl;
			}
			for(int i = 0; i < n; i++) // print arti loop
			{
				for(int j = 0; j < n; j++) if(articulationlink[i][j]) cout << "articulationlink: (" << i << ", " << j << ")" << endl;
			}
			cout << endl;*/
		}  
    }
    return 0;
}

