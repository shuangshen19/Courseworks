import java.util.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
import javax.imageio.*;
import java.awt.image.BufferedImage;

public class hw4
{
    public static void main(String argv[])
    {
		String Filename = "pre3.png"; // image file name 
		String Filename1 = "output3.png"; // image output file name 
		BufferedImage old; // origin image
		BufferedImage tmpIma; // image after wavelet transformation
		// load image
        try
        {
            old = ImageIO.read(new File(Filename));
        }
        catch(Exception e)
        {
            javax.swing.JOptionPane.showMessageDialog(null, "falty: " + Filename);
            old = null;
        }
        // change image to grayscale    
        tmpIma=new BufferedImage(old.getWidth(),old.getHeight(),BufferedImage.TYPE_INT_RGB);
        for(int i=0;i<old.getWidth();i++)
		{
            for(int j=0;j<old.getHeight();j++)
			{
                Color color=new Color(old.getRGB(i,j));
                int tmp=(int)(0.3*color.getRed()+0.6*color.getGreen()+0.1*color.getBlue());
                Color tmpcol=new Color(tmp,tmp,tmp);
                tmpIma.setRGB(i,j,tmpcol.getRGB());
            }
        }
		// do wavelet transformation
		int Height = old.getHeight();
        int Width = old.getWidth();
        int depth = 4; 
        int depthcount = 1; 
		double[][] pixels = new double[old.getWidth()][old.getHeight()];
		double[][] tmp = new double[old.getWidth()][old.getHeight()];
		double[][] tmp2 = new double[old.getWidth()][old.getHeight()];
		for(int i=0;i<old.getWidth();i++)
		{
            for(int j=0;j<old.getHeight();j++)
			{
				Color color=new Color(old.getRGB(i,j));
                pixels[i][j] = (int)(0.3*color.getRed()+0.6*color.getGreen()+0.1*color.getBlue());
            }
        }
        while (depthcount<=depth)
		{
            Width = old.getWidth()/depthcount;
            Height = old.getHeight()/depthcount;

            for (int i=0;i<Width;i++)
			{
                for (int j=0;j<Height/2;j++)
				{
					tmp[i][j] =  (pixels[i][2*j]+ pixels[i][2*j+1])/2;
					tmp[i][j+Height/2] = (pixels[i][2*j]- pixels[i][2*j+1])/2;
                }
            }
            for (int i=0;i<Width/2;i++)
			{
                for (int j=0;j<Height;j++)
				{
					tmp2[i][j] =  (tmp[2*i][j]+ tmp[2*i+1][j])/2;
					tmp2[i+Width/2][j] = (tmp[2*i][j]- tmp[2*i+1][j])/2;
                }
            }
			for(int i=0;i<old.getWidth();i++)
			{
				for(int j=0;j<old.getHeight();j++)
				{
					pixels[i][j] = tmp2[i][j];
				}
			}
            depthcount = depthcount*2;
        }
		// new value store to image 
		for(int i=0;i<old.getWidth();i++)
		{
			for(int j=0;j<old.getHeight();j++)
			{
				pixels[i][j] = Math.abs(pixels[i][j]);
				if(pixels[i][j]<205) pixels[i][j]= pixels[i][j]+50; // brighter
				else pixels[i][j] = 255;
				Color tmpcol=new Color((int)pixels[i][j],(int)pixels[i][j],(int)pixels[i][j]);
				tmpIma.setRGB(i,j,tmpcol.getRGB());
			}
		}
		// output file
		try 
		{
            File file1 = new File(Filename1);
            ImageIO.write(tmpIma, "png", file1);
        } 
		catch (Exception e) 
		{
            e.printStackTrace();
        }
	}
}
