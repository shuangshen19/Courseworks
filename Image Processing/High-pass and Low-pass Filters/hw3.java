import java.awt.Image.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;
import javax.imageio.*;
import java.awt.image.BufferedImage;
import java.awt.image.BufferedImageOp;
import java.awt.image.ConvolveOp;
import java.awt.image.Kernel;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.ImageIcon;

public class hw3
{
	String Filename = "pre3.png"; // image file name 
    BufferedImage old; // origin image
    BufferedImage tmpIma, tmpIma1, tmpIma2; // after convolution
    JFrame jf;
    public static void main(String argv[])
    {
        new hw3();
    }
    public hw3()
    {
		LoadFile();
		ChangPix();
		Filter();
		SetTable();
    }
	public void LoadFile()
    {
        try
        {
            old = ImageIO.read(new File(Filename));
        }
        catch(Exception e)
        {
            javax.swing.JOptionPane.showMessageDialog(null, "falty: " + Filename);
            old = null;
        }
    }
	public void ChangPix()
	{          
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
    }
	public void Filter()
	{
		float val = 1f/9f;
		// lowpass
		float[]data1 = {val, val, val, val, val, val, val, val, val}; 
		// highpass
		float[]data2 = {-1, -1, -1, -1, 8, -1, -1, -1, -1};
		Kernel kernel1 = new Kernel(3, 3, data1);
		Kernel kernel2 = new Kernel(3, 3, data2);
		BufferedImageOp ConOp1 = new ConvolveOp(kernel1);
		tmpIma1 = ConOp1.filter(tmpIma, null);
		BufferedImageOp ConOp2 = new ConvolveOp(kernel2);
		tmpIma2 = ConOp2.filter(tmpIma, null);
        for(int i=0;i<tmpIma2.getWidth();i++) // compare
		{
            for(int j=0;j<tmpIma2.getHeight();j++)
			{
                Color color=new Color(tmpIma2.getRGB(i,j));
				if(color.getRed()<0 || color.getGreen()<0 || color.getBlue()<0)
				{
					int tmp = 0;
					Color tmpcol=new Color(tmp,tmp,tmp);
					tmpIma2.setRGB(i,j,tmpcol.getRGB());
				}
				else if(color.getRed()>255 || color.getGreen()>255 || color.getBlue()>255)
				{
					int tmp = 255;
					Color tmpcol=new Color(tmp,tmp,tmp);
					tmpIma2.setRGB(i,j,tmpcol.getRGB());
				}
            }
        }
		try // output file
		{
            File file1 = new File("output3_1.png");
            ImageIO.write(tmpIma1, "png", file1);
			File file2 = new File("output3_2.png");
			ImageIO.write(tmpIma2, "png", file2);
        } 
		catch (Exception e) 
		{
            e.printStackTrace();
        }
	} 
	public void SetTable()    
    {
        jf = new JFrame("");
        JScrollPane scrollPane = new JScrollPane(new JLabel(new ImageIcon(tmpIma2)));
        jf.getContentPane().add(scrollPane);
		jf.pack();
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jf.setTitle("Convolution Image ");
        jf.setLocationRelativeTo(null);
        jf.setVisible(true);
    }
}
