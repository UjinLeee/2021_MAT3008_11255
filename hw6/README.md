# Homework #6

## 0. Goal

This project is programming on random number genration by using
1. Uniform distribution in [a, b] 
2. Gaussian distribution with mean mean = m, standard deviation = s.

And the goal is composed by following 3 steps:
- Generate 1000 samples and draw a histogram (100 intervals for each distribution, a = -3, b = 2, m = 0.5, s = 1.5)
- Repeat the same job with varying the number of samples : 100, 1000, 10000, 100000.
- Discuss the shape of the histograms in terms of the number of samples.

## 1. Environment

* language: C, Python
* OS: Windows and Linux 

## 2. Implementation

In main.c, I generate samples with various numbers and make put the results into each input file. 
And, then by using the result files, draw the histograms by using python.

Also, for random seeds, I used function time.

1) Uniform distribution

For Uniform distribution, I used 'ran0.c' in numerical recipes.
In ran0.c, it returns a uniform random deviate between 0.0 and 1.0, but in our project, we should returns between -3.0 and 2.0.
In other words, the length of the interval increases from 1 to 5, and the start points moves from 0.0 to -3.0.
So, I multiply the return value of ran0 by 5, and subtract 3.

2) Gaussian distribution

For Gaussian distribution, I used 'ran1.c' and 'gasdev.c' in numerical recipes.
In gasdev.c, it returns a normally distributed deviae with zero mean and unit variance, but in our case, the value of the mean is 0.5, and s is 1.5.
So, similar with uniform distribution,  I multiply the return value of gasdev by 1.5 and add 0.5.

3) Histogram

In hw6.py, I import matplotlib for drawing histograms.
And by using the result files, I put the data into the lists.
And, I saved the result histograms in 'result.png' file.

## 3. Result

In uniform distribution, as the number of samples increases, the differences between the results decreases.

In Gaussian distribution, as the number of samples increases, the shape of the histogram is becoming more and more like a normal distribution.