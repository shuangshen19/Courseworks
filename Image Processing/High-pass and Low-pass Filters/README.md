# High-pass and Low-pass Filters

## Descriptions:
Implement highpass and lowpass filters. 
Use the corresponding kernel and image convolution to get the new value.

Low-pass: 
1/9|1/9|1/9
:-----------------------------------|:------------------------------|:------------------------------
1/9|1/9|1/9
1/9|1/9|1/9

High-pass:
-1|-1|-1
:-----------------------------------|:------------------------------|:------------------------------
-1|8|-1
-1|-1|-1

## Diferences:
The main purpose of the low-pass filter is to remove noise and blur, so the resulting image will be more blurred; while the image from the high-pass filter emphasizes the edge position of the object, so it will filter out low-frequency waves and leave only a little through the value of the filter. The details are less visible.

## Program environment:
Implement on JAVA

