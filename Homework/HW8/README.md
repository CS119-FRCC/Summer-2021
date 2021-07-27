# HW8: Antialiasing

## Overview

In this homework, we will take it easy and add a basic feature, antialiasing. The goal of this homework is to add new functionality, but also to allow for you to catch up with the homeworks, and get the help you need to make a truly special project you can leave this class with.

## Background

### Antialiasing

What is antialiasing? You have probably heard of this term used before. Essentially, it means that the edges of your objects are not hard defined into the image, and are gracefully blurred ever so slightly. This results in images our eyes are happier with.

To do this, all we need to do is send our initial Rays slightly off from their exact directions.

Do you remember our formulas for calculating `u` and `v` from [HW4](../HW4/README.md)? Here they are again for your reference.

```
u = i / imageWidth;
v = j / imageHeight;
```

All we need to do to add antialiasing is add a random double between `-1` and `1` to our `i` and `j` values.

```
u = (i + rand(-1, 1)) / imageWidth;
v = (j + rand(-1, 1)) / imageHeight;
```

Make sure that the Ray direction is different for every sample, if you were not doing that already.

## Your Task

Modify your code to implement `antialiasing` into your raytracer.

You will need to read an `CS119 driver file` to get your image specifications. To this end, produce some driver files of your own to test with.

This function should be anywhere from `200 - 300` lines of code, depending on how compact you like to code. When I wrote it, I had `240` lines of code.

This time, we provide no test cases for you. You are going to need to test on your own! We will validate the image that your program produces against our own image, to verify correctness.

## Requirements

1. Implement `antialiasing` into your raytracer.
2. Ensure your code compiles without warnings, and runs without errors.
3. Submit your code as a zip file in the following format `LastName-HW8.zip`.
