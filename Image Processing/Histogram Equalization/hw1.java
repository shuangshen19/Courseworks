import java.util.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
import javax.imageio.*;
import java.awt.image.BufferedImage;

public class hw1
{
	String Filename="pre_tumor.png"; // image file name 
    BufferedImage image; // origin image
    BufferedImage tmpIma; // color to grayscale
	BufferedImage tmpImaAfter; // after grayscale histogram equalization
    JFrame jf;
    public static void main(String argv[])
    {
        new hw1();
    }
    public hw1()
    {
		LoadFile();
		ChangPix();
		HE(); // histogram equalization
		SetTable();
    }
	
    public void LoadFile()
    {
        try
        {
            image=ImageIO.read(new File(Filename));
        }
        catch(Exception e)
        {
            javax.swing.JOptionPane.showMessageDialog(null, "falty: " + Filename);
            image=null;
        }
    }
	
    public void ChangPix()
	{          
        tmpIma=new BufferedImage(image.getWidth(),image.getHeight(),BufferedImage.TYPE_INT_RGB);
        for(int i=0;i<image.getWidth();i++)
		{
            for(int j=0;j<image.getHeight();j++)
			{
                Color color=new Color(image.getRGB(i,j));
                int tmp=(int)(0.3*color.getRed()+0.6*color.getGreen()+0.1*color.getBlue());
                Color tmpcol=new Color(tmp,tmp,tmp);
                tmpIma.setRGB(i,j,tmpcol.getRGB());
            }
        }
    }
	
	public void HE() // histogram equalization
	{
		tmpImaAfter=new BufferedImage(image.getWidth(),image.getHeight(),BufferedImage.TYPE_INT_RGB);
		int TotalPix=image.getWidth()*image.getHeight();
		int[] histogram = new int[256];

		for (int x = 0; x < image.getWidth(); x++) 
		{
			for (int y = 0; y < image.getHeight(); y++) 
			{
				Color color=new Color(tmpIma.getRGB(x,y));
				histogram[color.getRed()]++;
			}
		}

		int[] chistogram = new int[256]; // change histogram
		chistogram[0] = histogram[0]; // probability
		for(int i=1;i<256;i++)
		{
			chistogram[i] = chistogram[i-1] + histogram[i];
		}

		float[] arr = new float[256]; // mapping histogram
		for(int i=0;i<256;i++)
		{
			arr[i] =  (float)((chistogram[i]*255.0)/(float)TotalPix);
		}
		// mapping
		for (int x = 0; x < image.getWidth(); x++) 
		{
			for (int y = 0; y < image.getHeight(); y++) 
			{
				Color color=new Color(tmpIma.getRGB(x,y));
				int nVal = (int) arr[color.getRed()];
				Color tmpcolor=new Color(nVal,nVal,nVal);
				tmpImaAfter.setRGB(x,y,tmpcolor.getRGB());
			}
		}
		// output file
		try 
		{
            File file = new File("output5.png");
            ImageIO.write(tmpImaAfter, "png", file);
        } 
		catch (Exception e) 
		{
            e.printStackTrace();
        }
	}
	
    public void SetTable()    
    {
        jf = new JFrame("");
        JScrollPane scrollPane = new JScrollPane(new JLabel(new ImageIcon(tmpImaAfter)));
        jf.getContentPane().add(scrollPane);
		jf.pack();
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jf.setTitle(Filename+" after histogram equalization "+image.getWidth()+" x "+image.getHeight());
        jf.setLocationRelativeTo(null);
        jf.setVisible(true);
    }
}