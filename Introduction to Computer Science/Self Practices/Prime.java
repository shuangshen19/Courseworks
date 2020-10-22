public class Prime 
{  

   public static void main(String[] args) 
   {  
   
		System.out.print("Please input a number:");
		int a = ConsoleIn.readLineInt();//if a=5
		
        for(int i=2;i<=a;i++)//i=2,3,4,5
	    {  
           boolean flag=true;
		   
           for(int j=2;j<i;j++)//j=2,3,4
		   {  
              if(i%j==0)//
			  {  
              flag=false;  
              break;  
			  }  
			  
           }  
		   
           if(!flag) continue;
		   
           System.out.println(i);  
        }  
    }  
}  
