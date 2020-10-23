# Highpass and Lowpass Filters

## Descriptions:
Implement highpass and lowpass filters. 
Use the corresponding kernel and image convolution to get the new value.

LP: 
|||
:-----------------------------------|:------------------------------|:------------------------------
1/9|1/9|1/9
1/9|1/9|1/9
1/9|1/9|1/9

HP:
|||
:-----------------------------------|:------------------------------|:------------------------------
-1|-1|-1
-1|8|-1
-1|-1|-1

## Comparision
The nucleus is roughly separated, but the boundary cannot be formed perfectly, and there will be breaks or separations, and then the boundary part needs to be processed; and some nuclei that are too small or unclear, because my pre-processing uses color transforming to gray scale, so it may be blurred at the beginning.

## Program environment:
Implement on Python

