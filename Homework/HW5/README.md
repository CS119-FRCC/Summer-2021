# HW5: A Wild Sphere Appears

## Overview

In this homework, you begin to put together all of the elements we have been working on to create our first simple raytracer! It will need your code from HW1, as well as HW4. The image that is produced from this program will have our first view of a sphere inside our scene!

## Background

### Spheres

It would also be nice to be able to represent `Spheres` a little easier than we previously have been. To this end, lets utilize `structs`! Create a `struct` type called `Sphere`, and include within it the following properties that we have been working with. A new property for spheres is called `albedo`, which represents the kind of color that the sphere will reflect.

1. origin (Point3D)
2. radius (double)
3. albedo (Color)
4. material (string)
   
### Rays

It would also be nice to be able to represent `Rays` a little easier than we previously have been. Create a `struct` type called `Ray`, and include within it the following properties. We are going to need to keep track of the closest sphere our Ray hits when it travels, so that we don't render spheres that are **behind** another sphere. To do this, we add a third and fourth property. We will go over how we will use these properties in a later homework.

1. origin (Point3D)
2. direction (Vector3D)
3. closestSphere (Sphere)
4. distanceToClosestSphere (double) = std::numeric_limits<double>::max()

## Your Task

Modify your code to utilize the new structs as defined above, and also add the following functionality.

In `determineBounceVector`, modify your return value to be a `Ray`. This returned `Ray` has a `origin` of your `P` value from prior homeworks, and your direction is your normalized calculated bounce direction. Another small tweak here, we don't want to accidentally originate our new bounce Ray from inside (or even on) our `Sphere`. To get around this, lets nudge our Point forward in the direction we will be traveling just a tiny amount. Here is my return statement for reference.

```c++
return {P + bounce.normalize() * 0.01, bounce.normalize()};
```

Also, lets add a new possible material type. `light` will represent a Sphere that is a light in our scene. Our `determineBounceVector` function should throw the string `Light` if it hits a sphere with this material type. Lastly, we are no longer returning a "BounceVector". I would rename our function accordingly.

In `calculatePixelColor`, modify your code to call `determineBounceVector` (or whatever you change its name to). Utilize the following as your `Sphere`.

```
Sphere

origin: 0, 0, -5
radius: 2
albedo: 255 0 0
material: diffuse
```

If the `Ray` hits your `Sphere`, return the albedo of the sphere. A note about returning color from now on: We will want to handle color reflections differently than we have in previous homeworks. We want to return a `Color` value from `calculatePixelColor` that is between `0` and `1`, with `0` remaining equivelent to `0` and `1` being equivelent to our former `255`. This means that while in `calculatePixelColor` our colors will use this new decimal `Color` representation, in our `main` function, we will need to convert back to our traditional notation before outputting to our file. When I did this, I simply multiplied the color that I returned from `calculatePixelColor` by `255`. I also returned the `Sphere's` albedo divided by `255` from my `calculatePixelColor` function. 

If the `Ray` misses your `Sphere`, return black.

You will need to read an `CS119 Driver File` to get your image specifications. To this end, produce some driver files of your own to test with.

This function should be anywhere from `100 - 200` lines of code, depending on how compact you like to code. When I wrote it, I had `180` lines of code. This may seem like a lot, but most of my code was opening files for reading and writing as discussed in class, and providing error messages if I failed to open a file. Also comments, whitespace, and other elements to keep my code clean.

This time, again, we provide no test cases for you. You are going to need to test on your own! We will validate the image that your program produces against our own image, to verify correctness.

## Requirements

1. Modify the `calculatePixelColor` function, to now utilize `determineBounceVector` (or whatever you named it) to determine what `Color` a given `Ray` should return.
2. Modify the `determineBounceVector` as defined above.
3. Modify your code to use the new structs as defined above.
4. Ensure your code compiles without warnings, and runs without errors.
5. Submit your code as a zip file in the following format `LastName-HW5.zip`.
