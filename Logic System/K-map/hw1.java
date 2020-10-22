import java.util.*;
import java.io.*;
import java.lang.*;
public class hw1
{
	public static void main(String[] args)
	{
		try 
		{
			// initialize
			Scanner cin = new Scanner(System.in);
			int f;
			int value[] = new int[16];
			int min[] = new int[16];
			char kmap[][] = new char[4][4];
		
			System.out.print("Please input a filename of minterm: ");
			String input1 = cin.nextLine();
			
			// judge the minterm
			Scanner reader = new Scanner(new FileInputStream(input1));
			f = Integer.parseInt(reader.nextLine());
			String str1;
			int i1 = 0;
			if(reader.hasNextLine())
			{
				str1 = reader.nextLine();
				i1 = str1.indexOf(",");
						
				for(int j = 0; i1 > 0 && j < 16; j++)
				{
					int k = Integer.parseInt(str1.substring(0,i1));
					value[k] = k;
					min[k] = 1;
					str1 = str1.substring(i1+1,str1.length());
					i1 = str1.indexOf(",");	
				}
				int i3 = str1.lastIndexOf(",");
				int last1 = Integer.parseInt(str1.substring(i3+1,str1.length()));
				value[last1] = last1;
				min[last1] = 1;
			}
			
			System.out.print("Please input a filename of don't care: ");
			String input2 = cin.nextLine();
		
			// judge the don't care
			Scanner reader2 = new Scanner(new FileInputStream(input2));
			int f2 = Integer.parseInt(reader2.nextLine());
			String str2;
			int i2 = 0;

			if(reader2.hasNextLine())
			{
				str2 = reader2.nextLine();
				i2 = str2.indexOf(",");
							
				for(int j = 0; i2 > 0 && j < 16; j++)
				{
					int k = Integer.parseInt(str2.substring(0,i2));
					value[k] = k;
					min[k] = 2;
					str2 = str2.substring(i2+1,str2.length());
					i2 = str2.indexOf(",");
				}
				int i4 = str2.lastIndexOf(",");
				int last2 = Integer.parseInt(str2.substring(i4+1,str2.length()));
				value[last2] = last2;
				min[last2] = 2;
			}
			
			for (int i = 0; i < 4; i++)  // set kmap=0
			{
				for (int j = 0; j < 4; j++)
				{
					kmap[i][j] = '0';
				}
			}
			for (int k = 0; k < 16; k++) // set kmap depend what we are input
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (min[i*4+j] == 1)  kmap[i][j] = '1';
						if (min[i*4+j] == 2)  kmap[i][j] = 'x';
					}
				}
			}
			// initialize the judge sentence
			String mm1 = "-";
			int count[] = new int[16];
			int m[] = new int[16];
			for(int j = 0; j < 16; j++) m[j] = min[j];
			String m1[][] = new String[16][18];
			for(int j = 0; j < 16; j++) 
			{
				for(int k = 0; k < 18; k++) m1[j][k] = "3";
			}
			String m2[][][][] = new String[16][18][16][18];
			String m3[][][][] = new String[16][18][16][18];
			for(int j = 0; j < 16; j++) 
				{
					for(int k = 0; k < 18; k++) 
					{
						for(int o = 0; o < 16; o++) 
						{
							for(int q = 0; q < 18; q++) m2[j][k][o][q] = "4";
						}
					}
				}
				for(int j = 0; j < 16; j++) 
				{
					for(int k = 0; k < 18; k++) 
					{
						for(int o = 0; o < 16; o++) 
						{
							for(int q = 0; q < 18; q++) m3[j][k][o][q] = "-";
						}
					}	
				}
			// judge if the variable is 2,3 or 4
			if(f == 2)
			{
				// judge whether the minterm can compare to the other minterm or not
				if((min[0] == 1 && min[1] == 1) || (min[0] == 2 && min[1] == 1) || (min[0] == 1 && min[1] == 2)) 
				{
					m[0] = 0;
					m[1] = 0;
					m1[0][1] = "06"; 
				}
				if((min[0] == 1 && min[2] == 1) || (min[0] == 2 && min[2] == 1) || (min[0] == 1 && min[2] == 2)) 
				{
					m[0] = 0;
					m[2] = 0;
					m1[0][2] = "50";
				}
				if((min[1] == 1 && min[3] == 1) || (min[1] == 2 && min[3] == 1) || (min[1] == 1 && min[3] == 2)) 
				{
					m[1] = 0;
					m[3] = 0;
					m1[1][3] = "51";
				}
				if((min[2] == 1 && min[3] == 1) || (min[2] == 2 && min[3] == 1) || (min[2] == 1 && min[3] == 2))
				{
					m[2] = 0;
					m[3] = 0;
					m1[2][3] = "16";
				}					

				if(m1[0][1].length() == 2 && m1[2][3].length() == 2)
				{
					
					m1[0][1] = "9";
					m1[2][3] = "9";	
					mm1 = "56";
				}
			}
			else if(f == 3)
			{
				// judge whether the minterm can compare to the other minterm or not
				if((min[0] == 1 && min[1] == 1) || (min[0] == 2 && min[1] == 1) || (min[0] == 1 && min[1] == 2)) 
				{
					m[0] = 0;
					m[1] = 0;
					m1[0][1] = "007"; 
				}
				if((min[0] == 1 && min[2] == 1) || (min[0] == 2 && min[2] == 1) || (min[0] == 1 && min[2] == 2)) 
				{
					m[0] = 0;
					m[2] = 0;
					m1[0][2] = "060";
				}
				if((min[0] == 1 && min[4] == 1) || (min[0] == 2 && min[4] == 1) || (min[0] == 1 && min[4] == 2)) 
				{
					m[0] = 0;
					m[4] = 0;
					m1[0][4] = "500";
				}
				if((min[1] == 1 && min[3] == 1) || (min[1] == 2 && min[3] == 1) || (min[1] == 1 && min[3] == 2))
				{
					m[1] = 0;
					m[3] = 0;
					m1[1][3] = "061";
				}	
				if((min[1] == 1 && min[5] == 1) || (min[1] == 2 && min[5] == 1) || (min[1] == 1 && min[5] == 2)) 
				{
					m[1] = 0;
					m[5] = 0;
					m1[1][5] = "501"; 
				}
				if((min[2] == 1 && min[3] == 1) || (min[2] == 2 && min[3] == 1) || (min[2] == 1 && min[3] == 2)) 
				{
					m[2] = 0;
					m[3] = 0;
					m1[2][3] = "017";
				}
				if((min[2] == 1 && min[6] == 1) || (min[2] == 2 && min[6] == 1) || (min[2] == 1 && min[6] == 2)) 
				{
					m[2] = 0;
					m[6] = 0;
					m1[2][6] = "510";
				}
				if((min[4] == 1 && min[5] == 1) || (min[4] == 2 && min[5] == 1) || (min[4] == 1 && min[5] == 2))
				{
					m[4] = 0;
					m[5] = 0;
					m1[4][5] = "107";
				}		
				if((min[4] == 1 && min[6] == 1) || (min[4] == 2 && min[6] == 1) || (min[4] == 1 && min[6] == 2)) 
				{
					m[4] = 0;
					m[6] = 0;
					m1[4][6] = "160"; 
				}
				if((min[3] == 1 && min[7] == 1) || (min[3] == 2 && min[7] == 1) || (min[3] == 1 && min[7] == 2)) 
				{
					m[3] = 0;
					m[7] = 0;
					m1[3][7] = "511";
				}
				if((min[5] == 1 && min[7] == 1) || (min[5] == 2 && min[7] == 1) || (min[5] == 1 && min[7] == 2)) 
				{
					m[5] = 0;
					m[7] = 0;
					m1[5][7] = "161";
				}
				if((min[6] == 1 && min[7] == 1) || (min[6] == 2 && min[7] == 1) || (min[6] == 1 && min[7] == 2))
				{
					m[6] = 0;
					m[7] = 0;
					m1[6][7] = "117";
				}		
				// judge whether m1 can compare to the other m1 or not
				if(m1[0][1].length() == 3 && m1[2][3].length() == 3)
				{
					m1[0][1] = "9";
					m1[2][3] = "9";	
					m2[0][1][2][3] = "067";
				}
				if(m1[0][1].length() == 3 && m1[4][5].length() == 3)
				{
					m1[0][1] = "9";
					m1[4][5] = "9";	
					m2[0][1][4][5] = "507";
				}
				if(m1[0][2].length() == 3 && m1[4][6].length() == 3)
				{
					m1[0][2] = "9";
					m1[4][6] = "9";	
					m2[0][2][4][6] = "560";
				}
				if(m1[1][3].length() == 3 && m1[5][7].length() == 3)
				{
					m1[1][3] = "9";
					m1[5][7] = "9";	
					m2[1][3][5][7] = "561";
				}
				if(m1[2][3].length() == 3 && m1[6][7].length() == 3)
				{
					m1[2][3] = "9";
					m1[6][7] = "9";	
					m2[2][3][6][7] = "517";
				}
				if(m1[4][5].length() == 3 && m1[6][7].length() == 3)
				{
					m1[4][5] = "9";
					m1[6][7] = "9";	
					m2[4][5][6][7] = "167";
				}
				
				int time = 0;
				for(int j = 0; j < 8; j++)
				{
					if(min[j] == 1 || min[j] == 2) time++;
				}
				if(time == 7) 
				{
					mm1 = "567"; 
					for(int j = 0; j < 8; j++) count[j]++;
				}
				
				for(int j = 0; j < 8; j++)
				{
					if(m[j] == 0) count[j]++;
					for(int k = 0; k < 16; k++) 
					{
						if(m1[j][k].substring(0,1) == "9")
						{
							count[j]++;
							count[k]++;
						}
					}
				}		
			}
			else if(f == 4)
			{
				// judge whether the minterm can compare to the other minterm or not
				if((min[0] == 1 && min[1] == 1) || (min[0] == 2 && min[1] == 1) || (min[0] == 1 && min[1] == 2)) 
				{
					m[0] = 0;
					m[1] = 0;
					m1[0][1] = "0008"; 
				}
				if((min[0] == 1 && min[2] == 1) || (min[0] == 2 && min[2] == 1) || (min[0] == 1 && min[2] == 2)) 
				{
					m[0] = 0;
					m[2] = 0;
					m1[0][2] = "0070";
				}
				if((min[0] == 1 && min[4] == 1) || (min[0] == 2 && min[4] == 1) || (min[0] == 1 && min[4] == 2)) 
				{
					m[0] = 0;
					m[4] = 0;
					m1[0][4] = "0600";
				}
				if((min[0] == 1 && min[8] == 1) || (min[0] == 2 && min[8] == 1) || (min[0] == 1 && min[8] == 2)) 
				{
					m[0] = 0;
					m[8] = 0;
					m1[0][8] = "5000"; 
				}
				if((min[1] == 1 && min[3] == 1) || (min[1] == 2 && min[3] == 1) || (min[1] == 1 && min[3] == 2))
				{
					m[1] = 0;
					m[3] = 0;
					m1[1][3] = "0070";
				}	
				if((min[1] == 1 && min[5] == 1) || (min[1] == 2 && min[5] == 1) || (min[1] == 1 && min[5] == 2)) 
				{
					m[1] = 0;
					m[5] = 0;
					m1[1][5] = "0601"; 
				}
				if((min[1] == 1 && min[9] == 1) || (min[1] == 2 && min[9] == 1) || (min[1] == 1 && min[9] == 2)) 
				{
					m[1] = 0;
					m[9] = 0;
					m1[1][9] = "5001"; 
				}
				if((min[2] == 1 && min[3] == 1) || (min[2] == 2 && min[3] == 1) || (min[2] == 1 && min[3] == 2)) 
				{
					m[2] = 0;
					m[3] = 0;
					m1[2][3] = "0018";
				}
				if((min[2] == 1 && min[6] == 1) || (min[2] == 2 && min[6] == 1) || (min[2] == 1 && min[6] == 2)) 
				{
					m[2] = 0;
					m[6] = 0;
					m1[2][6] = "0610";
				}
				if((min[2] == 1 && min[10] == 1) || (min[2] == 2 && min[10] == 1) || (min[2] == 1 && min[10] == 2)) 
				{
					m[2] = 0;
					m[10] = 0;
					m1[2][10] = "5010";
				}
				if((min[4] == 1 && min[5] == 1) || (min[4] == 2 && min[5] == 1) || (min[4] == 1 && min[5] == 2))
				{
					m[4] = 0;
					m[5] = 0;
					m1[4][5] = "0108";
				}		
				if((min[4] == 1 && min[6] == 1) || (min[4] == 2 && min[6] == 1) || (min[4] == 1 && min[6] == 2)) 
				{
					m[4] = 0;
					m[6] = 0;
					m1[4][6] = "0170"; 
				}
				if((min[4] == 1 && min[12] == 1) || (min[4] == 2 && min[12] == 1) || (min[4] == 1 && min[12] == 2)) 
				{
					m[4] = 0;
					m[12] = 0;
					m1[4][12] = "5100"; 
				}
				if((min[8] == 1 && min[9] == 1) || (min[8] == 2 && min[9] == 1) || (min[8] == 1 && min[9] == 2)) 
				{
					m[8] = 0;
					m[9] = 0;
					m1[8][9] = "1008"; 
				}
				if((min[8] == 1 && min[10] == 1) || (min[8] == 2 && min[10] == 1) || (min[8] == 1 && min[10] == 2)) 
				{
					m[8] = 0;
					m[10] = 0;
					m1[8][10] = "1070"; 
				}
				if((min[8] == 1 && min[12] == 1) || (min[8] == 2 && min[12] == 1) || (min[8] == 1 && min[12] == 2)) 
				{
					m[8] = 0;
					m[12] = 0;
					m1[8][12] = "1600"; 
				}
				if((min[3] == 1 && min[7] == 1) || (min[3] == 2 && min[7] == 1) || (min[3] == 1 && min[7] == 2)) 
				{
					m[3] = 0;
					m[7] = 0;
					m1[3][7] = "0611";
				}
				if((min[3] == 1 && min[11] == 1) || (min[3] == 2 && min[11] == 1) || (min[3] == 1 && min[11] == 2)) 
				{
					m[3] = 0;
					m[11] = 0;
					m1[3][11] = "5011";
				}
				if((min[5] == 1 && min[7] == 1) || (min[5] == 2 && min[7] == 1) || (min[5] == 1 && min[7] == 2)) 
				{
					m[5] = 0;
					m[7] = 0;
					m1[5][7] = "0171";
				}
				if((min[5] == 1 && min[13] == 1) || (min[5] == 2 && min[13] == 1) || (min[5] == 1 && min[13] == 2)) 
				{
					m[5] = 0;
					m[13] = 0;
					m1[5][13] = "5101";
				}
				if((min[6] == 1 && min[7] == 1) || (min[6] == 2 && min[7] == 1) || (min[6] == 1 && min[7] == 2))
				{
					m[6] = 0;
					m[7] = 0;
					m1[6][7] = "0118";
				}
				if((min[6] == 1 && min[14] == 1) || (min[6] == 2 && min[14] == 1) || (min[6] == 1 && min[14] == 2))
				{
					m[6] = 0;
					m[14] = 0;
					m1[6][14] = "5110";
				}
				if((min[9] == 1 && min[11] == 1) || (min[9] == 2 && min[11] == 1) || (min[9] == 1 && min[11] == 2)) 
				{
					m[9] = 0;
					m[11] = 0;
					m1[9][11] = "1071"; 
				}
				if((min[9] == 1 && min[13] == 1) || (min[9] == 2 && min[13] == 1) || (min[9] == 1 && min[13] == 2)) 
				{
					m[9] = 0;
					m[13] = 0;
					m1[9][13] = "1601"; 
				}
				if((min[10] == 1 && min[11] == 1) || (min[10] == 2 && min[11] == 1) || (min[10] == 1 && min[11] == 2)) 
				{
					m[10] = 0;
					m[11] = 0;
					m1[10][11] = "1018";
				}
				if((min[10] == 1 && min[14] == 1) || (min[10] == 2 && min[14] == 1) || (min[10] == 1 && min[14] == 2)) 
				{
					m[10] = 0;
					m[14] = 0;
					m1[10][14] = "1610";
				}
				if((min[12] == 1 && min[13] == 1) || (min[12] == 2 && min[13] == 1) || (min[12] == 1 && min[13] == 2))
				{
					m[12] = 0;
					m[13] = 0;
					m1[12][13] = "1108";
				}	
				if((min[12] == 1 && min[14] == 1) || (min[12] == 2 && min[14] == 1) || (min[12] == 1 && min[14] == 2)) 
				{
					m[12] = 0;
					m[14] = 0;
					m1[12][14] = "1170"; 
				}
				if((min[7] == 1 && min[15] == 1) || (min[7] == 2 && min[15] == 1) || (min[7] == 1 && min[15] == 2))
				{
					m[7] = 0;
					m[15] = 0;
					m1[7][15] = "5111";
				}	
				if((min[11] == 1 && min[15] == 1) || (min[11] == 2 && min[15] == 1) || (min[11] == 1 && min[15] == 2))
				{
					m[11] = 0;
					m[15] = 0;
					m1[11][15] = "1611";
				}	
				if((min[13] == 1 && min[15] == 1) || (min[13] == 2 && min[15] == 1) || (min[13] == 1 && min[15] == 2))
				{
					m[13] = 0;
					m[15] = 0;
					m1[13][15] = "1171";
				}	
				if((min[14] == 1 && min[15] == 1) || (min[14] == 2 && min[15] == 1) || (min[14] == 1 && min[15] == 2))
				{
					m[14] = 0;
					m[15] = 0;
					m1[14][15] = "1118";
				}	
				// judge whether the m1 can compare to the other m1 or not
				if(m1[0][1].length() == 4 && m1[2][3].length() == 4)
				{
					m1[0][1] = "9";
					m1[2][3] = "9";	
					m2[0][1][2][3] = "0078";
				}				
				if(m1[0][1].length() == 4 && m1[4][5].length() == 4)
				{
					m1[0][1] = "9";
					m1[4][5] = "9";	
					m2[0][1][4][5] = "0608";
				}
				if(m1[0][1].length() == 4 && m1[8][9].length() == 4)
				{
					m1[0][1] = "9";
					m1[8][9] = "9";	
					m2[0][1][8][9] = "5008";
				}
				if(m1[0][2].length() == 4 && m1[4][6].length() == 4)
				{
					m1[0][2] = "9";
					m1[4][6] = "9";	
					m2[0][2][4][6] = "0670";
				}
				if(m1[0][2].length() == 4 && m1[8][10].length() == 4)
				{
					m1[0][2] = "9";
					m1[8][10] = "9";	
					m2[0][2][8][10] = "5070";
				}
				if(m1[0][4].length() == 4 && m1[8][12].length() == 4)
				{
					m1[0][4] = "9";
					m1[8][12] = "9";	
					m2[0][4][8][12] = "5600";
				}
				if(m1[1][3].length() == 4 && m1[5][7].length() == 4)
				{
					m1[1][3] = "9";
					m1[5][7] = "9";	
					m2[1][3][5][7] = "0671";
				}
				if(m1[1][3].length() == 4 && m1[9][11].length() == 4)
				{
					m1[1][3] = "9";
					m1[9][11] = "9";	
					m2[1][3][9][11] = "5071";
				}
				if(m1[1][5].length() == 4 && m1[9][13].length() == 4)
				{
					m1[1][5] = "9";
					m1[9][13] = "9";	
					m2[1][5][9][13] = "5601";
				}
				if(m1[2][3].length() == 4 && m1[6][7].length() == 4)
				{
					m1[2][3] = "9";
					m1[6][7] = "9";	
					m2[2][3][6][7] = "0618";
				}
				if(m1[2][3].length() == 4 && m1[10][11].length() == 4)
				{
					m1[2][3] = "9";
					m1[10][11] = "9";	
					m2[2][3][10][11] = "5018";
				}
				if(m1[2][6].length() == 4 && m1[10][14].length() == 4)
				{
					m1[2][6] = "9";
					m1[10][14] = "9";	
					m2[2][6][10][14] = "5610";
				}
				if(m1[4][5].length() == 4 && m1[6][7].length() == 4)
				{
					m1[4][5] = "9";
					m1[6][7] = "9";	
					m2[4][5][6][7] = "0178";
				}
				if(m1[4][5].length() == 4 && m1[12][13].length() == 4)
				{
					m1[4][5] = "9";
					m1[12][13] = "9";	
					m2[4][5][12][13] = "5108";
				}
				if(m1[4][6].length() == 4 && m1[12][14].length() == 4)
				{
					m1[4][6] = "9";
					m1[12][14] = "9";	
					m2[4][6][12][14] = "5170";
				}
				if(m1[8][9].length() == 4 && m1[10][11].length() == 4)
				{
					m1[8][9] = "9";
					m1[10][11] = "9";	
					m2[8][9][10][11] = "1078";
				}
				if(m1[8][9].length() == 4 && m1[12][13].length() == 4)
				{
					m1[8][9] = "9";
					m1[12][13] = "9";	
					m2[8][9][12][13] = "1608";
				}
				if(m1[8][10].length() == 4 && m1[12][14].length() == 4)
				{
					m1[8][10] = "9";
					m1[12][14] = "9";	
					m2[8][10][12][14] = "1670";
				}
				if(m1[3][7].length() == 4 && m1[11][15].length() == 4)
				{
					m1[3][7] = "9";
					m1[11][15] = "9";	
					m2[3][7][11][15] = "5611";
				}
				if(m1[5][7].length() == 4 && m1[13][15].length() == 4)
				{
					m1[5][7] = "9";
					m1[13][15] = "9";	
					m2[5][7][13][15] = "5171";
				}
				if(m1[6][7].length() == 4 && m1[14][15].length() == 4)
				{
					m1[6][7] = "9";
					m1[14][15] = "9";	
					m2[6][7][14][15] = "5118";
				}
				if(m1[9][11].length() == 4 && m1[13][15].length() == 4)
				{
					m1[9][11] = "9";
					m1[13][15] = "9";	
					m2[9][11][13][15] = "1671";
				}
				if(m1[10][11].length() == 4 && m1[14][15].length() == 4)
				{
					m1[10][11] = "9";
					m1[14][15] = "9";	
					m2[10][11][14][15] = "1618";
				}
				if(m1[12][13].length() == 4 && m1[14][15].length() == 4)
				{
					m1[12][13] = "9";
					m1[14][15] = "9";	
					m2[12][13][14][15] = "1178";
				}
				// judge whether the m2 can compare to the other m2 or not
				if(m2[0][1][2][3].length() == 4 && m2[4][5][6][7].length() == 4)
				{
					m2[0][1][2][3] = "9";
					m2[4][5][6][7] = "9";	
					m3[4][5][6][7]  = "0678";
				}
				if(m2[0][1][2][3].length() == 4 && m2[8][9][10][11].length() == 4)
				{
					m2[0][1][2][3] = "9";
					m2[8][9][10][11] = "9";	
					m3[8][9][10][11] = "5078";
				}
				if(m2[0][1][4][5].length() == 4 && m2[8][9][12][13].length() == 4)
				{
					m2[0][1][4][5] = "9";
					m2[8][9][12][13] = "9";	
					m3[8][9][12][13] = "5608";
				}
				if(m2[0][2][4][6].length() == 4 && m2[8][10][12][14].length() == 4)
				{
					m2[0][2][4][6] = "9";
					m2[8][10][12][14] = "9";	
					m3[8][10][12][14] = "5670";
				}
				if(m2[1][3][5][7].length() == 4 && m2[9][11][13][15].length() == 4)
				{
					m2[1][3][5][7] = "9";
					m2[9][11][13][15] = "9";	
					m3[9][11][13][15] = "5671";
				}
				if(m2[2][3][6][7].length() == 4 && m2[10][11][14][15].length() == 4)
				{
					m2[2][3][6][7] = "9";
					m2[10][11][14][15] = "9";	
					m3[10][11][14][15] = "5618";
				}
				if(m2[4][5][6][7].length() == 4 && m2[12][13][14][15].length() == 4)
				{
					m2[4][5][6][7] = "9";
					m2[12][13][14][15] = "9";	
					m3[12][13][14][15]= "5178";
				}
				if(m2[8][9][12][13].length() == 4 && m2[10][14][11][15].length() == 4)
				{
					m2[8][9][12][13] = "9";
					m2[10][14][11][15] = "9";	
					m3[10][14][11][15] = "1678";
				}
				
				int time = 0;
				for(int j = 0; j < 16; j++)
				{
					if(min[j] == 1 || min[j] == 2) time++;
				}
				if(time == 15) 
				{
					mm1 = "5678"; 
					for(int j = 0; j < 16; j++) count[j]++;
				}
				// calculate the minterms have or haven't been circle
				for(int j = 0; j < 16; j++)
				{
					if(m[j] == 0) count[j]++;
					for(int k = 0; k < 16; k++) 
					{
						if(m1[j][k].substring(0,1) == "9")
						{
							count[j]++;
							count[k]++;
						}
						for(int o = 0; o < 16; o++)
						{
							for(int q = 0; q < 16; q++)
							{
								if(m2[j][k][o][q].substring(0,1) == "9")
								{
									count[j]++;
									count[k]++;
									count[o]++;
									count[q]++;
								}
							}
						}
					}
				}		
			}
			// output function
			PrintWriter writer = new PrintWriter(new FileOutputStream("output.txt"));
			if(f == 2)
			{
				// print the kmap
				writer.println("====K Map====");
				writer.println(" \\A |");
				writer.println("C \\ | 0   1  ");
				writer.println("----+---+----");
				writer.println("  0 | " + kmap[0][0] + " | " + kmap[0][2] + " | ");
				writer.println("----+---+----");
				writer.println("  1 | " + kmap[0][1] + " | " + kmap[0][3] + " | ");
				writer.println("----+---+----");
				
				String p = "-";
				String p1[][] = new String[4][4];
				for(int j = 0; j < 4; j++) 
				{	
					for(int k = 0; k < 4; k++) p1[j][k] = "-";
				}
				String p2[] = new String[4];
				for(int j = 0; j < 4; j++) p2[j] = "-";
				// judge what's the prime implicant
				for(int j = 0; j < 4; j++)
				{
					for(int k = 0; k < 4; k++)
					{
						if(mm1.equals("56")) p = "1";
						else if(!m1[j][k].equals("3") && m1[j][k].length() == 2)
						{
							if(m1[j][k].substring(0,1).equals("1")) p1[j][k] = "A";
							else if(m1[j][k].substring(0,1).equals("0")) p1[j][k] = "A'";
							if(m1[j][k].substring(1,2).equals("1")) p1[j][k] = "C";
							else if(m1[j][k].substring(1,2).equals("0")) p1[j][k] = "C'";
						}
						else if(m[0] == 1) p2[0] = "A'C'";
						else if(m[1] == 1) p2[1] = "A'C";
						else if(m[2] == 1) p2[2] = "AC'";
						else if(m[3] == 1) p2[3] = "AC";
					}
				}
				writer.print("prime implicant: ");
				if(!p.equals("-")) writer.print(p + " ");
				for(int j = 0; j < 4; j++) 
				{
					for(int k = 0; k < 4; k++) 
					{
						if(!p1[j][k].equals("-")) writer.print(p1[j][k] + ", ");
					}
					if(!p2[j].equals("-")) writer.print(p2[j] + ", ");
				}
				writer.println(" ");
				writer.print("essential prime implicant: ");
				if(!p.equals("-")) writer.print(p + " ");
				// judge what's the essential prime implicant
				for(int j = 0; j < 4; j++) 
				{
					for(int k = 0; k < 4; k++) 
					{
						if(!p1[j][k].equals("-")) writer.print(p1[j][k] + ", ");
					}
					if(!p2[j].equals("-")) writer.print(p2[j] + ", ");
				}
				writer.println(" ");
				writer.print("F(A,C)= ");
				if(!p.equals("-")) writer.print(p + " ");
				for(int j = 0; j < 4; j++) 
				{
					for(int k = 0; k < 4; k++) 
					{
						if(!p1[j][k].equals("-")) writer.print(p1[j][k] + "+ ");
					}
					if(!p2[j].equals("-")) writer.print(p2[j] + "+ ");
				}
				writer.println(" ");
			}
			else if(f == 3)
			{
				// print the kmap
				writer.println("=========K Map=========");
				writer.println("  \\AB|");
				writer.println(" C \\ | 00  01  11  10");
				writer.println("-----+---+---+---+-----");
				writer.println("  0  | " + kmap[0][0] + " | " + kmap[0][2] + " | " + kmap[1][2] + " | " + kmap[1][0] + " | ");
				writer.println("-----+---+---+---+-----");
				writer.println("  1  | " + kmap[0][1] + " | " + kmap[0][3] + " | " + kmap[1][3] + " | " + kmap[1][1] + " | ");
				writer.println("-----+---+---+---+-----");
				
				String p = "-";
				String p1[][] = new String[8][10];
				for(int j = 0; j < 8; j++) 
				{	
					for(int k = 0; k < 10; k++) p1[j][k] = "-";
				}
				String p2[][][][] = new String[8][8][8][8];
				for(int j = 0; j < 8; j++)
				{	
					for(int k = 0; k < 8; k++)
					{	
						for(int o = 0; o < 8; o++)
						{	
							for(int q = 0; q < 8; q++) p2[j][k][o][q] = "-";
						}
					}
				}
				String p3[] = new String[8];
				for(int j = 0; j < 8; j++) p3[j] = "-";
				// judge what's the prime implicant
				writer.print("prime implicant: ");
				for(int j = 0; j < 8; j++)
				{
					for(int k = 0; k < 10; k++)
					{
						for(int o = 0; o < 8; o++)
						{	
							for(int q = 0; q < 8; q++) 
							{
								if(mm1.equals("567")) p = "1";
								else if(Integer.parseInt(m2[j][k][o][q]) != 4 && m2[j][k][o][q].length() == 3)
								{
									if(m2[j][k][o][q].substring(0,1).equals("1")) p2[j][k][o][q] = "A";
									else if(m2[j][k][o][q].substring(0,1).equals("0")) p2[j][k][o][q] = "A'";
									if(m2[j][k][o][q].substring(1,2).equals("1")) p2[j][k][o][q] = "B";
									else if(m2[j][k][o][q].substring(1,2).equals("0")) p2[j][k][o][q] = "B'";
									if(m2[j][k][o][q].substring(2,3).equals("1")) p2[j][k][o][q] = "C";
									else if(m2[j][k][o][q].substring(2,3).equals("0")) p2[j][k][o][q] = "C'";
									if(!p2[j][k][o][q].equals("-") && value[k] == k) writer.print(p2[j][k][o][q] + ", ");
								}
								else if(!m1[j][k].equals("3") && m1[j][k].length() == 3 && m2[j][k][o][q].length() != 3)
								{
									if(m1[j][k].substring(0,1).equals("1"))
									{
										if(m1[j][k].substring(1,2).equals("1")) p1[j][k+1] = "B";
										else if(m1[j][k].substring(1,2).equals("0")) p1[j][k+1] = "B'";
										if(m1[j][k].substring(2,3).equals("1")) p1[j][k+1] = "C";
										else if(m1[j][k].substring(2,3).equals("0")) p1[j][k+1] = "C'";
										p1[j][k] = "A" + p1[j][k+1];
									}
									else if(m1[j][k].substring(0,1).equals("0"))
									{
										if(m1[j][k].substring(1,2).equals("1")) p1[j][k+1] = "B";
										else if(m1[j][k].substring(1,2).equals("0")) p1[j][k+1] = "B'";
										if(m1[j][k].substring(2,3).equals("1")) p1[j][k+1] = "C";
										else if(m1[j][k].substring(2,3).equals("0")) p1[j][k+1] = "C'";
										p1[j][k] = "A'" + p1[j][k+1];
									}
									else if(m1[j][k].substring(0,1).equals("5"))
									{
										if(m1[j][k].substring(1,2).equals("1"))
										{
											if(m1[j][k].substring(2,3).equals("1")) p1[j][k+1] = "C";
											else if(m1[j][k].substring(2,3).equals("0")) p1[j][k+1] = "C'";
											p1[j][k] = "B" + p1[j][k+1];
										}
										else if(m1[j][k].substring(1,2).equals("0"))
										{
											if(m1[j][k].substring(2,3).equals("1")) p1[j][k+1] = "C";
											else if(m1[j][k].substring(2,3).equals("0")) p1[j][k+1] = "C'";
											p1[j][k] = "B'" + p1[j][k+1];
										}
									}
								}
								else if(m[0] == 1) p3[0] = "A'B'C'";
								else if(m[1] == 1) p3[1] = "A'B'C";
								else if(m[2] == 1) p3[2] = "A'BC'";
								else if(m[3] == 1) p3[3] = "AB'C'";
								else if(m[4] == 1) p3[4] = "A'BC";
								else if(m[5] == 1) p3[5] = "AB'C";
								else if(m[6] == 1) p3[6] = "ABC'";
								else if(m[7] == 1) p3[7] = "ABC";
								
							}
						}
						if(!p1[j][k].equals("-") && m1[j][k].length() == 3) writer.print(p1[j][k] + ", ");
					}
					if(!p3[j].equals("-")) writer.print(p3[j] + ", ");
				}
				
				if(!p.equals("-")) writer.print(p + " ");
				writer.println(" ");
				writer.print("essential prime implicant: ");
				String e1[] = new String[12]; 
				for(int j = 0; j < 12; j++) e1[j] = "-";
				String e2[] = new String[12]; 
				for(int j = 0; j < 12; j++) e2[j] = "-";
				String e3[] = new String[12]; 
				for(int j = 0; j < 12; j++) e3[j] = "-";
				String e4[] = new String[12]; 
				for(int j = 0; j < 12; j++) e4[j] = "-";
				String e5[] = new String[12]; 
				for(int j = 0; j < 12; j++) e5[j] = "-";
				String e6[] = new String[12]; 
				for(int j = 0; j < 12; j++) e6[j] = "-";
				// judge what's the essential prime implicant
				for(int j = 0; j < 8; j++)
				{	
					for(int k = 1; k < 8; k++)
					{	
						for(int o = 2; o < 8; o++)
						{	
							for(int q = 3; q < 8; q++) 
							{
								if(count[j] == 1)
								{
									if(!p2[j][k][o][q].equals("-") && m2[j][k][o][q].length() == 3) e1[j+k] = p2[j][k][o][q];
									else if(!p1[j][k].equals("-") &&  m1[j][k].length() == 3) e2[j+k] = p1[j][k];
									else if(!p3[j].equals("-")) e3[j+k] = p3[j];
								}
								else // judge what's the F
								{
									if(!p2[j][k][o][q].equals("-")&& m2[j][k][o][q].length() == 3) e4[j+k] = p2[j][k][o][q];
									else if(!p1[j][k].equals("-") &&  m1[j][k].length() == 3) e5[j+k] = p1[j][k];
									else if(!p3[j].equals("-")) e6[j+k] = p3[j];
								}
							}
						}
					}
				}
				for(int j = 0; j < 12; j++) if(!e1[j].equals("-")) writer.print(e1[j] + ", ");
				for(int j = 0; j < 12; j++) if(!e2[j].equals("-")) writer.print(e2[j] + ", ");
				for(int j = 0; j < 12; j++) if(!e3[j].equals("-")) writer.print(e3[j] + ", ");
				writer.println(" ");
				writer.print("F(A,B,C)= ");
				for(int j = 0; j < 12; j++) if(!e1[j].equals("-")) writer.print(e1[j] + "+ ");
				for(int j = 0; j < 12; j++) if(!e2[j].equals("-")) writer.print(e2[j] + "+ ");
				for(int j = 0; j < 12; j++) if(!e3[j].equals("-")) writer.print(e3[j] + "+ ");
				for(int j = 0; j < 12; j++) if(!e4[j].equals("-")) writer.print(e4[j] + "+ ");
				for(int j = 0; j < 12; j++) if(!e5[j].equals("-")) writer.print(e5[j] + "+ ");
				for(int j = 0; j < 12; j++) if(!e6[j].equals("-")) writer.print(e6[j] + "+ ");
			}
			else if(f == 4)
			{
				// print kmap
				writer.println("=========K Map=========");
				writer.println("  \\AB|");
				writer.println("CD \\ | 00  01  11  10");
				writer.println("-----+---+---+---+-----");
				writer.println("  00 | " + kmap[0][0] + " | " + kmap[1][0] + " | " + kmap[3][0] + " | " + kmap[2][0] + " | ");
				writer.println("-----+---+---+---+-----");
				writer.println("  01 | " + kmap[0][1] + " | " + kmap[1][1] + " | " + kmap[3][1] + " | " + kmap[2][1] + " | ");
				writer.println("-----+---+---+---+-----");
				writer.println("  11 | " + kmap[0][3] + " | " + kmap[1][3] + " | " + kmap[3][3] + " | " + kmap[2][3] + " | ");
				writer.println("-----+---+---+---+-----");
				writer.println("  10 | " + kmap[0][2] + " | " + kmap[1][2] + " | " + kmap[3][2] + " | " + kmap[2][2] + " | ");
				writer.println("-----+---+---+---+-----");
				
				String p = "-";
				String p1[][] = new String[16][18];
				for(int j = 0; j < 16; j++) 
				{	
					for(int k = 0; k < 18; k++) p1[j][k] = "-";
				}
				String p2[][][][] = new String[16][18][16][18];
				for(int j = 0; j < 16; j++)
				{	
					for(int k = 0; k < 18; k++)
					{	
						for(int o = 0; o < 16; o++)
						{	
							for(int q = 0; q < 18; q++) p2[j][k][o][q] = "-";
						}
					}
				}
				String p3[][][][] = new String[16][18][16][18];
				for(int j = 0; j < 16; j++) 
				{
					for(int k = 0; k < 18; k++) 
					{
						for(int o = 0; o < 16; o++) 
						{
							for(int q = 0; q < 18; q++) p3[j][k][o][q] = "-";
						}
					}	
				}
				String p4[] = new String[18];
				for(int j = 0; j < 18; j++) p4[j] = "-";
				// judge what's the prime implicant
				writer.print("prime implicant: ");
				for(int j = 0; j < 16; j++)
				{
					for(int k = 0; k < 18; k++)
					{
						for(int o = 0; o < 16; o++)
						{	
							for(int q = 0; q < 18 ; q++) 
							{
								if(mm1.equals("5678")) p = "1";
								else if(!m3[j][k][o][q].substring(0,1).equals("-") && m3[j][k][o][q].length() == 4)
								{
									if(m3[j][k][o][q].substring(0,1).equals("1")) p3[j][k][o][q] = "A";
									else if(m3[j][k][o][q].substring(0,1).equals("0")) p3[j][k][o][q] = "A'";
									else if(m3[j][k][o][q].substring(1,2).equals("1")) p3[j][k][o][q] = "B";
									else if(m3[j][k][o][q].substring(1,2).equals("0")) p3[j][k][o][q] = "B'";
									else if(m3[j][k][o][q].substring(2,3).equals("1")) p3[j][k][o][q] = "C";
									else if(m3[j][k][o][q].substring(2,3).equals("0")) p3[j][k][o][q] = "C'";
									else if(m3[j][k][o][q].substring(3,4).equals("1")) p3[j][k][o][q] = "D";
									else if(m3[j][k][o][q].substring(3,4).equals("0")) p3[j][k][o][q] = "D'";	
									
								}
								else if(!m2[j][k][o][q].substring(0,1).equals("4") && m2[j][k][o][q].length() == 4 && m3[j][k][o][q].length() != 4)
								{
									if(m2[j][k][o][q].substring(0,1).equals("1"))
									{
										if(m2[j][k][o][q].substring(1,2).equals("1")) p2[j][k][o][q+1] = "B";
										else if(m2[j][k][o][q].substring(1,2).equals("0")) p2[j][k][o][q+1] = "B'";
										if(m2[j][k][o][q].substring(2,3).equals("1")) p2[j][k][o][q+1] = "C";
										else if(m2[j][k][o][q].substring(2,3).equals("0")) p2[j][k][o][q+1] = "C'";
										if(m2[j][k][o][q].substring(3,4).equals("1")) p2[j][k][o][q+1] = "D";
										else if(m2[j][k][o][q].substring(3,4).equals("0")) p2[j][k][o][q+1] = "D'";
										p2[j][k][o][q] = "A" + p2[j][k][o][q+1];
										
									}
									else if(m2[j][k][o][q].substring(0,1).equals("0"))
									{
										if(m2[j][k][o][q].substring(1,2).equals("1")) p2[j][k][o][q+1] = "B";
										else if(m2[j][k][o][q].substring(1,2).equals("0")) p2[j][k][o][q+1] = "B'";
										if(m2[j][k][o][q].substring(2,3).equals("1")) p2[j][k][o][q+1] = "C";
										else if(m2[j][k][o][q].substring(2,3).equals("0")) p2[j][k][o][q+1] = "C'";
										if(m2[j][k][o][q].substring(3,4).equals("1")) p2[j][k][o][q+1] = "D";
										else if(m2[j][k][o][q].substring(3,4).equals("0")) p2[j][k][o][q+1] = "D'";
										p2[j][k][o][q] = "A'" + p2[j][k][o][q+1];
									
									}
									else if(m2[j][k][o][q].substring(0,1).equals("5"))
									{
										if(m2[j][k][o][q].substring(1,2).equals("1"))
										{
											if(m2[j][k][o][q].substring(2,3).equals("1")) p2[j][k][o][q+1] = "C";
											else if(m2[j][k][o][q].substring(2,3).equals("0")) p2[j][k][o][q+1] = "C'";
											if(m2[j][k][o][q].substring(3,4).equals("1")) p2[j][k][o][q+1] = "D";
											else if(m2[j][k][o][q].substring(3,4).equals("0")) p2[j][k][o][q+1] = "D'";
											p2[j][k][o][q] = "B" + p2[j][k][o][q+1];
										}
										else if(m2[j][k][o][q].substring(1,2).equals("0"))
										{
											if(m2[j][k][o][q].substring(2,3).equals("1")) p2[j][k][o][q+1] = "C";
											else if(m2[j][k][o][q].substring(2,3).equals("0")) p2[j][k][o][q+1] = "C'";
											if(m2[j][k][o][q].substring(3,4).equals("1")) p2[j][k][o][q+1] = "D";
											else if(m2[j][k][o][q].substring(3,4).equals("0")) p2[j][k][o][q+1] = "D'";
											p2[j][k][o][q] = "B'" + p2[j][k][o][q+1];
										}
										else if(m2[j][k][o][q].substring(1,2).equals("6"))
										{
											if(m2[j][k][o][q].substring(2,3).equals("1")) p2[j][k][o][q+1] = "C";
											else if(m2[j][k][o][q].substring(2,3).equals("0")) p2[j][k][o][q+1] = "C'";
											if(m2[j][k][o][q].substring(3,4).equals("1")) p2[j][k][o][q+2] = "D";
											else if(m2[j][k][o][q].substring(3,4).equals("0")) p2[j][k][o][q+2] = "D'";
											p2[j][k][o][q] = p2[j][k][o][q+1] + p2[j][k][o][q+2];
										}
										
									}
								}
								else if(!m1[j][k].equals("3") && m1[j][k].length() == 4 && m2[j][k][o][q].length() != 4)
								{
									if(m1[j][k].substring(0,1).equals("1"))
									{
										if(m1[j][k].substring(1,2).equals("1"))
										{
											if(m1[j][k].substring(2,3).equals("1")) p1[j][k+1] = "C";
											else if(m1[j][k].substring(2,3).equals("0")) p1[j][k+1] = "C'";
											if(m1[j][k].substring(3,4).equals("1")) p1[j][k+1] = "D";
											else if(m1[j][k].substring(3,4).equals("0")) p1[j][k+1] = "D'";
											p1[j][k] = "AB" + p1[j][k+1];
										}
										else if(m1[j][k].substring(1,2).equals("0"))
										{
											if(m1[j][k].substring(2,3).equals("1")) p1[j][k+1] = "C";
											else if(m1[j][k].substring(2,3).equals("0")) p1[j][k+1] = "C'";
											if(m1[j][k].substring(3,4).equals("1")) p1[j][k+1] = "D";
											else if(m1[j][k].substring(3,4).equals("0")) p1[j][k+1] = "D'";
											p1[j][k] = "AB'" + p1[j][k+1];
										}
									}
									else if(m1[j][k].substring(0,1).equals("0"))
									{
										if(m1[j][k].substring(1,2).equals("1"))
										{
											if(m1[j][k].substring(2,3).equals("1")) p1[j][k+1] = "C";
											else if(m1[j][k].substring(2,3).equals("0")) p1[j][k+1] = "C'";
											if(m1[j][k].substring(3,4).equals("1")) p1[j][k+1] = "D";
											else if(m1[j][k].substring(3,4).equals("0")) p1[j][k+1] = "D'";
											p1[j][k] = "A'B" + p1[j][k+1];
										}
										else if(m1[j][k].substring(1,2).equals("0"))
										{
											if(m1[j][k].substring(2,3).equals("1")) p1[j][k+1] = "C";
											else if(m1[j][k].substring(2,3).equals("0")) p1[j][k+1] = "C'";
											if(m1[j][k].substring(3,4).equals("1")) p1[j][k+1] = "D";
											else if(m1[j][k].substring(3,4).equals("0")) p1[j][k+1] = "D'";
											p1[j][k] = "A'B'" + p1[j][k+1];
										}
									}
									else if(m1[j][k].substring(0,1).equals("5"))
									{
										if(m1[j][k].substring(1,2).equals("1"))
										{
											if(m1[j][k].substring(2,3).equals("1")) p1[j][k+1] = "C";
											else if(m1[j][k].substring(2,3).equals("0")) p1[j][k+1] = "C'";
											if(m1[j][k].substring(3,4).equals("1")) p1[j][k+2] = "D";
											else if(m1[j][k].substring(3,4).equals("0")) p1[j][k+2] = "D'";
											p1[j][k] = "B" + p1[j][k+1] + p1[j][k+2];
										}
										else if(m1[j][k].substring(1,2).equals("0"))
										{
											if(m1[j][k].substring(2,3).equals("1")) p1[j][k+1] = "C";
											else if(m1[j][k].substring(2,3).equals("0")) p1[j][k+1] = "C'";
											if(m1[j][k].substring(3,4).equals("1")) p1[j][k+1] = "D";
											else if(m1[j][k].substring(3,4).equals("0")) p1[j][k+1] = "D'";
											p1[j][k] = "B'" + p1[j][k+1] + p1[j][k+2];
										}
									}
								}
								else if(m[0] == 1) p4[0] = "A'B'C'D'";
								else if(m[1] == 1) p4[1] = "A'B'C'D";
								else if(m[2] == 1) p4[2] = "A'B'CD'";
								else if(m[3] == 1) p4[3] = "A'B'CD";
								else if(m[4] == 1) p4[4] = "A'BC'D'";
								else if(m[5] == 1) p4[5] = "A'BC'D";
								else if(m[6] == 1) p4[6] = "A'BCD'";
								else if(m[7] == 1) p4[7] = "A'BCD";
								else if(m[8] == 1) p4[8] = "AB'C'D'";
								else if(m[9] == 1) p4[9] = "AB'C'D";
								else if(m[10] == 1) p4[10] = "AB'CD'";
								else if(m[11] == 1) p4[11] = "AB'CD";
								else if(m[12] == 1) p4[12] = "ABC'D'";
								else if(m[13] == 1) p4[13] = "ABC'D";
								else if(m[14] == 1) p4[14] = "ABCD'";
								else if(m[15] == 1) p4[15] = "ABCD";
								
								if(!p3[j][k][o][q].equals("-") && m2[j][k][o][q].equals("9") && !m3[j][k][o][q].equals("-")) writer.print(p3[j][k][o][q] + ", ");
								if(!p2[j][k][o][q].equals("-") && m1[j][k].equals("9") && !m2[j][k][o][q].equals("4")) writer.print(p2[j][k][o][q] + ", ");
							}
						}
						if(!p1[j][k].equals("-") && m1[j][k].length() == 4 && m[j] == 0) writer.print(p1[j][k] + ", ");
					}
					if(!p4[j].equals("-")) writer.print(p4[j] + ", ");
				}
				if(!p.equals("-")) writer.print(p + " ");
				writer.println(" ");
				
				String e1[] = new String[32]; 
				for(int j = 0; j < 32; j++) e1[j] = "-";
				String e2[] = new String[32]; 
				for(int j = 0; j < 32; j++) e2[j] = "-";
				String e3[] = new String[32]; 
				for(int j = 0; j < 32; j++) e3[j] = "-";
				String e4[] = new String[32]; 
				for(int j = 0; j < 32; j++) e4[j] = "-";
				String e5[] = new String[32]; 
				for(int j = 0; j < 32; j++) e5[j] = "-";
				String e6[] = new String[32]; 
				for(int j = 0; j < 32; j++) e6[j] = "-";
				String e7[] = new String[32]; 
				for(int j = 0; j < 32; j++) e7[j] = "-";
				String e8[] = new String[32]; 
				for(int j = 0; j < 32; j++) e8[j] = "-";
				// judge what's the essential prime implicant
				for(int j = 0; j < 16; j++)
				{	
					for(int k = 1; k < 18; k++)
					{	
						for(int o = 2; o < 16; o++)
						{	
							for(int q = 3; q < 18; q++) 
							{
								if(count[j] == 1)
								{
									if(!p3[j][k][o][q].equals("-") && m3[j][k][o][q].length() == 4) e1[j+k] =  p3[j][k][o][q];
									else if(!p2[j][k][o][q].equals("-") && m2[j][k][o][q].length() == 4) e2[j+k] =  p2[j][k][o][q];
									else if(!p1[j][k].equals("-") &&  m1[j][k].length() == 4) e3[j+k] = p1[j][k];
									else if(!p4[j].equals("-")) e7[j+k] = p4[j];
								}
								else // judge what's the F
								{
									if(!p3[j][k][o][q].equals("-") && m3[j][k][o][q].length() == 4) e4[j+k] =  p3[j][k][o][q];
									else if(!p2[j][k][o][q].equals("-") && m2[j][k][o][q].length() == 4) e5[j+k] =  p2[j][k][o][q];
									else if(!p1[j][k].equals("-") &&  m1[j][k].length() == 4) e6[j+k] = p1[j][k];
									else if(!p4[j].equals("-")) e8[j+k] = p4[j];
								}
							}
						}
					}
				}
				
				writer.print("essential prime implicant: ");
				for(int j = 0; j < 32; j++) if(!e1[j].equals("-")) writer.print(e1[j] + ", ");
				for(int j = 0; j < 32; j++) if(!e2[j].equals("-")) writer.print(e2[j] + ", ");
				for(int j = 0; j < 32; j++) if(!e3[j].equals("-")) writer.print(e3[j] + ", ");
				for(int j = 0; j < 32; j++) if(!e7[j].equals("-")) writer.print(e7[j] + ", ");
				writer.println(" ");
				writer.print("F(A,B,C,D)= ");
				for(int j = 0; j < 32; j++) if(!e1[j].equals("-")) writer.print(e1[j] + "+ ");
				for(int j = 0; j < 32; j++) if(!e2[j].equals("-")) writer.print(e2[j] + "+ ");
				for(int j = 0; j < 32; j++) if(!e3[j].equals("-")) writer.print(e3[j] + "+ ");
				for(int j = 0; j < 32; j++) if(!e7[j].equals("-")) writer.print(e7[j] + "+ ");
				for(int j = 0; j < 32; j++) if(!e4[j].equals("-")) writer.print(e4[j] + "+ ");
				for(int j = 0; j < 32; j++) if(!e5[j].equals("-")) writer.print(e5[j] + "+ ");
				for(int j = 0; j < 32; j++) if(!e6[j].equals("-")) writer.print(e6[j] + "+ ");
				for(int j = 0; j < 32; j++) if(!e8[j].equals("-")) writer.print(e8[j] + "+ ");
				
			}
			writer.flush();
			writer.close();
			System.out.println("Output complete.");
		}
		catch(IOException e)
		{
			System.out.println("File can't be found!");
		}
		
	}
}	