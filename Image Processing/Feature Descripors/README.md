# Feature Descripors

## Descriptions:
Convert the image into grayscale format and then perform feature identification. For feature identification and classification, I used the following methods:
1. Extract the SIFT features of the pictures in the training set by picture category
2. Group the features into K classes (its size is K) to form the visual vocabulary of this class
3. Count the "word frequency" of K words in vocabulary for the pictures in the training set, and get the corresponding histogram
4. Use the histogram as a sample to construct the training data and test data of the SVM

That is, first SIFT → k-means → SVM and then the result of classify is obtained. Therefore, I imagined using SIFT to train descriptors and then become bag of words. The new test image is classified by substituting SVM and bag of words, but in reality due to time and some bugs, the classification could not be completed successfully during the work, so first submit the identified files.

## Classification Basis:
SIFT is an operation element based on scale space that maintains invariance to image scaling and rotation.
SIFT features are local features of the image, and the following are punctuation features:
1. Maintain invariance to rotation, scale scaling, and brightness changes, and also have a certain degree of stability to viewing angle changes, noise, etc.
2. Unique and rich in information, suitable for fast and accurate matching in a large amount of data
3. Multi-quantity, even a few objects can produce a large number of SIFT feature vectors
4. Scalability, it can be easily combined with other forms of feature vectors

This method is used to extract some features that remain invariant in the image. SIFT divides the points on the image into different subsets. These subsets often belong to isolated points, continuous curves or continuous regions, and are based on their respective different features reflected in image information distinguish different types of targets, perform quantitative analysis on the image, and classify each pixel or area in the image or image into one of several categories. One is to replace human visual interpretation.
The SIFT feature extraction algorithm includes 5 key steps:
1. Generate Difference of Gaussians (DOG), scale space construction
2. Extremum detection in scale space
3. Precisely locate the location of feature points
4. Determine feature point information
5. Generate feature point vector

K-Means sets K cluster centers one by one, calculates the shortest distance from each point to the set cluster center, and uses the nth power of the shortest distance as the probability to determine the next cluster center; therefore, the longer the distance, the greater the probability. The basic concept of SVM is to construct a plane in the sample input space or feature space to maximize the distance between the plane and the two types of sample sets, so as to obtain the best generalization ability.

## Program environment:
Implement on Python

