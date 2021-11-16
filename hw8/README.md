# Homework #8 : Resampling of Image

## 0. Goal

This project is to read an image file and identify the resolution and resmple it to a specified resolution.
I should use bilinear interpoliation in this project.

## 1. Environment

* Language: C++
* OS: Windows
* ISO C++ 14

## 2. Implementation

### 1) void bilinear_interp(Mat& image1, Mat& image2, int rate)
First, I used opencv2 library for image processing. 

Mat& image1, Mat& image2 ant int rate are the arguments of the function.

'image1' is the image which I want to resize. 'image1' should be in the same folder where the source code exists.
'image2' is the result image that resized 'imae1'.
'int rate' is the rate which I want to resize the image.

By using double for loop, search pixels of the image by int size. 

First, by dividing x and y with rate, find the coordinate of standard point, P1.
And by using the coordinates of P1 and Vec3b, find other 3 points, P2, P3 and P4.

Second, find the ratio of distances, fx_1, fx_2, fy_1 and fy_2.

With ratio of distances and P1~P4, and Vec3b method, make result image.

### 2) main

By using imread method, bring the image of the folder.
If image is empty, then there is no such image, so handles the error.

## 3. Result

Result is the attached image.
