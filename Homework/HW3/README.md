# HW3: A Simple Image

## Overview

In this homework, you will utilize what we discussed in class to begin to output image files. To do this, we to read from an input file, and output a file of our own. This file will be an image with desired specifications, and create a gradient across its surface.

## Background

### The PPM Image Format

Here is a nice description from Wikipedia to start you off.

![PPM Description](https://raytracing.github.io/images/fig-1.01-ppm.jpg)

As you can see from the description, the file format is as follows. First, on `line 1`, the characters `P3`. Next, on `line 2`, the dimensions of the image, first `width`, then `height`. The third line describes the max value for a color, in our case `255`. Then we begin writing triplets to the file, each line being a row of our image. The triplets are composed of three parts, `r`, `g`, and `b`. 

In the example above, the first triplet is `255 0 0` or pure `red`. The fourth triplet is `255 255 0` or yellow, and begins the second row of the image. Also shown in the example is the use of a comment in our image, through the usage of the `#` character. We will not include any in our images, but if you want to add them in, feel free.

### Writing a Pixel

For each pixel in your image, you are going to need to know the color to write to your file. For this homework, we will utilize the following formula for each pixel.

```
red = (imageRow / totalImageRows) * 255;
green = (imageColumn / totalImageColumns) * 255;
blue = 64;
```

We want those calculations to be able to handle decimal numbers, but the final value of red, green, and blue need to be integers for our file format. You may need to use C++ style casting to make this happen.

### The CSC119 Driver File

In our class, we will use a unified file format to configure our raytracer image specifications.

For this homework, we only need to know some basic image specifications. To this end, the file will look something like as follows.

```
# CSC119 Driver File
# Written By Matthew Ernst

imageWidth 256
aspectRatio 1 1
```

This file format follows a similar style to the PPM image format, in that comments are allowed as long as they start with a hashtag. In any order, the file at this time may contain the following lines.

1. `imageWidth` followed by a integer designating the pixel width of the image
2. `aspectRatio` followed by two doubles designating the `aspectRatio` of the image.

You can read more about what an `aspectRatio` is [here](https://en.wikipedia.org/wiki/Aspect_ratio_(image)).

## Your Task

Implement the main function provided. This time, the code given is sparse, so you will have to think about how to produce this file on your own. You do not need `Vector3D` for this assignment, but you can choose to use its variant `Color` if you wish.

You will need to read an `CSC119 Driver File` to get your image specifications. To this end, produce some driver files of your own to test with.

This function should be anywhere from `50 - 80` lines of code, depending on how compact you like to code. When I wrote it, I had `80` lines of code. This may seem like a lot, but most of my code was opening files for reading and writing as discussed in class, and providing error messages if I failed to open a file. Also comments, whitespace, and other elements to keep my code clean.

You can think of this main function broken down into 2 main parts. The first being reading from the driver file and the second outputing to the .ppm file. Below goes into more detail.

### Reading Driver File

For this, you will need to have an ifstream and uses one of the arguments passed to the main program to open a stream to the input file. From here, you will want to provide an error message in the case that the file cannot be opened. Next, you will want to read through the file line by line. For each line, you will want to check the first token to see if it's either `imageWidth`, `aspectRatio`, or `#`. Depending on which it is, you will want to save the imageWidth, calculate the aspectRatio or continue to the next line. **Remember that input comes in as characters**. This means that they will need to be converted to their types.

### Outputing Image
For outputting the image, you will need to have an ofstream and uses one of the arguments passed to the main program to open a stream to the output file. Make sure to have the file have the extension ***.ppm***. To start, the output file should have `P3` on the first line. The next line will have `imageWidth`, `imageHeight`, and `255`. From here, based on your input values taken from the driver file, you will have a nested for loop that goes through the `imageWidth` and `imageHeight` to output pixel values. 


This time, we provide no test cases for you. You are going to need to test on your own! We will validate the image that your program produces against our own image, to verify correctness.

## Requirements

1. Implement the `main` function by reading from a driver file and outputting an image.
2. Ensure your code compiles without warnings, and runs without errors.
3. Submit your code as a zip file in the following format `LastName-HW3.zip`.
