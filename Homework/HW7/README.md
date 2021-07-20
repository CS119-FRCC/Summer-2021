# HW7: Raytracing (For Real)

## Overview

In this homework, we will modify our driver file to add support for `Spheres`, and add support for rendering multiple `Spheres`. In addition, we will modify our `calculatePixelColor` function to add support for detecting the "closest" hit `Sphere`.

## Background

### How Do Shadows Work

As you have seen, we have implemented code to handle color calculations if we hit a `Sphere`. But how do we know how light or how dark a certain part of the `Sphere` should be? To figure this out, we can use the properties of randomness. When we hit a `Sphere`, we bounce off in a semi-random direction, as we have defined in our `determineBounceVector` (or whatever you have called it) function. We would like to continue to bounce our `Rays` around our scene until 1 of 2 things happens.

1. We hit a light. In the case of hitting a light, we return the multiplication of all the colors we have hit so far multiplied by the color of the light. This is a successful trace.
2. We run out of `depth`. This is a safeguard that we must put in to ensure that a `Ray` doesn't bounce around forever. We will define `depth` in this class to be `10`, but it could be anything. Essentially, this `depth` of `10` indicates that if after `10` bounces we have still not hit a light, we need to return black.

A good question at this point would be: what if we run our code and all of our bounces randomly decided not to hit the light? Well, this is where we will use the premise of `samples`. Here is the theory. On **average**, the `Rays` will bounce around and hit the light proportionally to the amount of light that that pixel would recieve. We will need to get enough data to produce an average, so to this end, we need to implement the following changes.

### Modifications To The CS119 Driver File

As mentioned in the previous homework, in our class, we will use a unified file format to configure our raytracer image specifications.

For this homework, we will add the `samples` property, which will be followed by an integer denoting the number of samples we would like to raytrace for each pixel.

### Modifications To `calculatePixelColor`

For this homework, we will modify your `calculatePixelColor` function ever so slightly. Up until this point, after we have finished determining which `Sphere` we hit closest, we returned the albedo of that `Sphere`. Now, we want to continue to bounce. 

Add another property to our `calculatePixelColor` function called `depth` and give it a default value of `10`. Modify our if condition that checks if we hit a `Sphere` to also check if we are at a `depth` greater than or equal to `0`. If we miss all `Spheres` or if we our beyond the max `depth`, we return black. If we do enter our if condition, `return` the albedo of the `Sphere` as previously defined, but multiply this color by a new **recursive** function call to `calculatePixelColor`. Make sure that our new bounce `Ray` is what is passed in as our `Ray`, and lower depth by 1 to ensure we don't bounce forever.

### Modifications To `main`

We will modify your `main` function ever so slightly. Up until this point, for each pixel, we have sent a singular `Ray` into our scene, and printed the color returned by this `Ray` to the image. Now, we will send `samples` number of `Rays` into our scene, adding each of the colors returned until we are finished. Then, we will divide this sum by the number of samples to calculate our average color.

## Your Task

Modify your code to implement the changes to the functions as described above. 

A word of warning. The example driver file that is included within this homework took my computer almost 6 hours to run. Bouncing `Rays` and calculating `Sphere` intersections slows down even the strongest of computers. You may want to adjust `imageSize` and `samples` accordingly. 

A note about samples. You should be able to make out an image at `5` samples. `10` samples produces a skeleton image. `100` samples produces a grainy image. `1000` samples produces a good image. `10000` samples produces a near perfect image.

You will need to read an `CS119 driver file` to get your image specifications. To this end, produce some driver files of your own to test with.

This function should be anywhere from `200 - 300` lines of code, depending on how compact you like to code. When I wrote it, I had `240` lines of code.

This time, we provide no test cases for you. You are going to need to test on your own! We will validate the image that your program produces against our own image, to verify correctness.

## Requirements

1. Modify the `calculatePixelColor` function to handle the **recursive** bounce call.
2. Add the `samples` parameter to your driver file.
3. Add sampling average calculations to your main function.
4. Ensure your code compiles without warnings, and runs without errors.
5. Submit your code as a zip file in the following format `LastName-HW6.zip`.
