public class multi 
{  

   public static void main(String[] args) 
   {  
		int a=1, b, m;
		do
		{
		
        for(b=1;b<=9;b++)
		{
			m=a*b;
			System.out.println(a+" * "+b+" = "+m);
		}
		 
        a++;  
        }while(a<=9);
    }  
}  
