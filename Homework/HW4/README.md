# HW4: Creating A Camera

## Overview

In this homework, you will utilize what we discussed in class to create a structure representing the camera. To do this, we to read from an input file, in the format of the CS119 Driver File as discussed in previous homework.

## Background

### What Is A Raytracer

By now, we have implemented many of the basic building blocks of a raytracer. But what is a raytracer? Well, it helps to go back to human anatomy a bit to understand what we are trying to accomplish. Fundamentally, light hits our retina, and our retina sends that image to our brains to produce an image. But where does this light come from? Well, it bounces off of everthing around us, and originates from light sources (including the sun)! Lets say we wanted to model this behavior inside of a program. We could create some light sources, and we could calculate every possible ray of light that comes out of them, and we could bounce those rays around and see which ones hit our eyes. We would then know what kind of image to produce!

This is hard however, because the complexity of modeling every ray of light that comes off of the sun is very, very big. So let me propose a new suggestion: we define how many `pixels` our `eye` has, and we work ***backwards*** to figure out which light it came from. ***This*** is what a raytracer does.

### The Camera

So what do we need to do to create a scene? Well, the involved steps are 

1. Calculate the `Ray` from our `eye` to the `pixel`
2. Determine which `Spheres` the `Ray` intersects
3. Compute a `Color` for that intersection point

We have already written code for `step 2`, but now its time to work back to `step 1`.

To do this, lets define the following elements. The following image can be used as a reference.

![Camera Geometry](https://raytracing.github.io/images/fig-1.03-cam-geom.jpg)

First, our `eye`. In the image, this is at `{ 0, 0, 0 }`. We also need the concept of a `Virtual Viewport`. Think of this as a movie screen. We are sitting in the theater, but we are looking at an image in front of us. 

The `Virtual Viewport` has the same `aspect ratio` as our eventual image. Our program will allow the user to configure the `imageWidth` and `viewportWidth`. In the image above, the black box is our `Virtual Viewport`.

Lastly, we need to set the distance between our `eye` and the `Virtual Viewport`. This is referred to as the `focal length`. In our driver file, it will be called `focalLength`. An important thing to note is that for our raytracer, the `-z` direction will always be the direction of our `Ray's` travel from our eye, to the `VirtualViewport`, and lastly into our scene.

### Modifications To The CS119 Driver File

As mentioned in the previous homework, in our class, we will use a unified file format to configure our raytracer image specifications.

For this homework, we will add the following properties:

1. `eye`, which will be followed by three doubles denoting the `x`, `y`, and `z` coordinates of our `eye` in the scene
2. `viewportWidth`, which will be followed by an integer denoting the width of the `Virtual Viewport`
3. `focalLength`, which will be followed by an double denoting the distance between our `eye` and the `Virtual Viewport`

Here is an example driver file to get you started.

```
# CS119 Driver File
# Written By Matthew Ernst

imageWidth 1024
aspectRatio 16 9
eye 0 0 0
viewportWidth 4
focalLength 1
```

### Some More Info

A couple of other things to get you started. What follows is a formula to derive the top left corner of the `Virtual Viewport`. This can be useful in calculating your resulting `Ray` for a pixel.

In the following formula, `horizontal` is the `viewportWidth` (in `Vector3D` form), and `vertical` is the `viewportHeight` (in `Vector3D` form). And `distance` is `focalLength` (in `Vector3D` form).

```
topLeftCorner = eye - (horizontal / 2) + (vertical / 2) - distance
```

Another important thing to mention is the following formula, used for calculating what `Point3D` in the `Virtual Viewport` our `Ray` hits from. In this formula, `u` is a measure of how far the pixel is in the horizontal direction from the top left corner of the image, while `v` is a measure of how far the pixel is in the vertical direction from the top left corner of the image.

```
Ray viewPortOrigin = topLeftCorner + u * horizontal - v * vertical
```

Lastly, now is a good time to talk about clamping. It may be possible that in the next several iterations of our raytracer, the color that is returned from `calculatePixelColor` may be less than `0` or greater than `255`. In these cases, we will want to ensure that our color values do not go out of bounds. To this end, clamp values that are greater than `255` to `255` and values less than `0` to `0`.

## Your Task

Create a function called `calculatePixelColor`. It should takes a `Point3D` and a `Vector3D` called `rayOrigin` and `rayDirection` respectively. It should return a `Color`.

This function will calculate its color via the following formula. In this formula, the `|` indicates absolute value. 

```
red = |rayDirection(x)| * 255 - 50
green = |rayDirection(y)| * 255 - 50
blue = |rayDirection(z)| * 255 - 50
```

Remember that we can access specific parts of a `Vector3D`, `Point3D`, or `Color` using `[]`, as follows. Remember that in Computer Science, we start numbering with 0.

```
Vector3D example = {0, 1, 2};
yComponent = example[1];
```

One more thing, `Color` is made up of doubles, so it might be a good idea to make sure that what you write to your file are ints. You may need to use C++ style casting to make this happen, as discussed in [HW3](../HW3/README.md).

Modify your main function from [HW3](../HW3/README.md) to read in the new driver file properties, and create `Rays` from the `eye`, to the point on the `Virtual Viewbox` for each pixel. Send this `Ray` as properties to the `calculateRayColor` function. Remember, to create a `Vector3D` representing the direction of our `Ray`, we can subtract two `Point3Ds`: `pointOnVirtualViewBox` - `eye`.

You will need to read an `CS119 Driver File` to get your image specifications. To this end, produce some driver files of your own to test with.

This function should be anywhere from `100 - 150` lines of code, depending on how compact you like to code. When I wrote it, I had `130` lines of code. This may seem like a lot, but most of my code was opening files for reading and writing as discussed in class, and providing error messages if I failed to open a file. Also comments, whitespace, and other elements to keep my code clean.

This time, again, we provide no test cases for you. You are going to need to test on your own! We will validate the image that your program produces against our own image, to verify correctness.

## Requirements

1. Implement the `calculatePixelColor` function, which returns the color of the pixel based on the rayDirection.
2. Modify the `main` function to read the updated driver file, and create a `Virtual Viewbox` for our scene.
3. Ensure your code compiles without warnings, and runs without errors.
4. Submit your code as a zip file in the following format `LastName-HW4.zip`.
