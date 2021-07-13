# HW6: Creating A Scene

## Overview

In this homework, we will modify our driver file to add support for `Spheres`, and add support for rendering multiple `Spheres`. In addition, we will modify our `calculatePixelColor` function to add support for detecting the "closest" hit `Sphere`.

## Background

### Modifications To The CS119 Driver File

As mentioned in the previous homework, in our class, we will use a unified file format to configure our raytracer image specifications.

For this homework, we will add the `sphere` property, which will be followed by the following attributes.

1. `x`, `y`, `z` position in the scene (doubles)
2. `radius` of the sphere (double)
3. `r`, `g`, `b` albedo color (integers)
4. `material` of the sphere (string: `diffuse`, `metal`, `glass`, `light`)

### Modifications To `calculatePixelColor`

For this homework, we will modify your `calculatePixelColor` function. Firstly, up until this point, we have only been detecting one hard coded `Sphere`. Now, for each `Sphere` specified in our driver file, try to hit the sphere using `determineBounceVector` (or whatever you named it). We need to catch strings thrown by this function, and handle them in the following ways. 

If a light is hit, return the albedo of the light.
If nothing is hit, continue on through our loop.

If we do hit something, we need to first check if it is the closest item that our `Ray` has yet hit. We want to render the closest items to our camera assuming items are behind each other. To do this, we first need to know the distance from where we originated, to where we hit the `Sphere`. Here is a formula to calculate that. In the following formula, the `|` symbol represents `length`.

```
distanceToHit = |sphereHitPoint - rayOrigin|
```

If this distance is less than our `distanceToClosestSphere`, which is stored in our `Ray` struct, we will do the following steps.

1. Assign the `Rays` closest `Sphere` to the one we hit
2. Update the `Rays` distance to the closest `Sphere` with the calculated distance shown above
3. Store the resulting `Vector` from the bounce somewhere beyond the scope of your loop
4. Update a variable that indicates whether we hit a `Sphere` at all, which should also be stored beyond the scope of your loop

After your loop is over, we will need to do the following.

If we hit any `Spheres`, return our `Rays` closest `Sphere's` albedo. Otherwise, return black.

## Your Task

Modify your code to implement the new `Sphere` parameter in the driver file specification. In addition, modify your `calculatePixelColor` method to handle finding the closest Sphere, as described above.

You will need to read an `CS119 driver file` to get your image specifications. To this end, produce some driver files of your own to test with.

This function should be anywhere from `150 - 250` lines of code, depending on how compact you like to code. When I wrote it, I had `220` lines of code.

This time, we provide no test cases for you. You are going to need to test on your own! We will validate the image that your program produces against our own image, to verify correctness.

## Requirements

1. Modify the `calculatePixelColor` function to handle nearest `Sphere` calulations.
2. Add the `sphere` parameter to your driver file.
3. Ensure your code compiles without warnings, and runs without errors.
4. Submit your code as a zip file in the following format `LastName-HW6.zip`.
