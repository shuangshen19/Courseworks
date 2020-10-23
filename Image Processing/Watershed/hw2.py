import numpy as np
import cv2
from matplotlib import pyplot as plt

def getOutImg(markers):
    # Black: marker > 1 && marker = -1
    # White: marker = 1 
    img = np.ones(markers.shape)*255
    img[markers>1] = 0
    img[markers==(-1)] = 0
	# Turn pixels near objects to black
    img[0,:] = img[:,0] = img[-1,:] = img[:,-1] = 255
    return img
	
# Input the image	
img = cv2.imread('pre_tumor.png')
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
ret, thresh = cv2.threshold(gray,0,255,cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)
# Noise removal
kernel = np.ones((3,3),np.uint8)
opening = cv2.morphologyEx(thresh,cv2.MORPH_OPEN,kernel, iterations = 2)
# Sure background area
sure_bg = cv2.dilate(opening,kernel,iterations=3)
# Finding sure foreground area
sure_fg = cv2.erode(opening,kernel,iterations=3)
unknown = cv2.subtract(sure_bg,sure_fg)
# Marker labelling
ret, markers = cv2.connectedComponents(sure_fg)
# Add one to all labels so that sure background is not 0, but 1
markers = markers+1
# Mark the region of unknown with zero
markers[unknown==255] = 0
# Do Watershed
markers = cv2.watershed(img,markers)
img[markers == -1] = [255,0,0]
# Get the output image
OutputImg = getOutImg(markers)
cv2.imwrite('output2.png', OutputImg)
