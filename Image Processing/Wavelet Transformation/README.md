# Wavelet Transformation

## Descriptions:
I use Haar's Wavelet transformation.
* read the png image
* convert the image to grayscale
* perform wavelet transformation. 
  
I use a 2-dimensional array for Haar and level = 3:

Average value: average the two adjacent images, making the new image resolution half of the original
Difference value: average the difference between two adjacent images and record the detailed information of the image

The above average value stores the overall information of the image, and the difference makes it possible to restore all the information of the image during reconstruction. Finally, the grayscale is increased by 50 to increase the brightness.

## Program environment:
Implement on JAVA

