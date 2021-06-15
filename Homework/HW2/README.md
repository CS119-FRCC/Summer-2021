# HW2: Bouncing Rays

## Overview

In [HW1](../HW1/README.md), we created a function to calculate whether a given `Ray` intersected a given `Sphere`. In this homework, we will expand upon that to determine what direction the ray begins to travel, after it bounces off the sphere.

## Background

When a light `Ray` hits a given `Sphere`, it doesn't just stop in the middle of space. We see this every day when we look outside. Light bouncing off objects everywhere until it happens to end up in our retinas. The way the light bounces off an object is determined by the material it bounces off of. For example, mirrors are weird. There are three types of materials we will implement in our raytracer: `Diffuse`, `Metal`, and `Glass`.

### Diffuse Materials

Diffuse objects that don’t emit light merely take on the color of their surroundings, but they modulate that with their own intrinsic color. Light that reflects off a diffuse surface has its direction randomized. So, if we send three `Rays` into a crack between two diffuse surfaces they will each have different random behavior.

![](https://raytracing.github.io/images/fig-1.08-light-bounce.jpg)

To calculate the new direction for a Diffuse material, we adhere to this formula.

```
newDirection = hitPoint + hitNormalVector + kindaRandomDirection
```

Lets go through each part separately.

#### Hit Point

In the last homework, we created a function to calculate if a given `Ray` hit a `Sphere`. We need to expand upon our prior work to obtain the point of contact with the sphere. To do this, we need to revisit some math from the previous homework.

Remember that we calculated the point of contact of the `Sphere` as the solution to the following equation, where we solve for `t`.

```
(P(t) − C) ⋅ (P(t) − C) = R²
```

To check if we hit the sphere, we checked if the discriminant was negative (no real roots). Your first task is to modify the function you wrote in the previous homework to meet the following criteria.

1. The function should return a double.
2. The function should throw a reasonable `string` if the `Sphere` is missed by the `Ray`.
3. The function should return `t` if the `Sphere` is hit by the `Ray`.

We can then utilize this `t` value to solve for `P`. The `t` value can be solved for using the full [quadratic formula](https://en.wikipedia.org/wiki/Quadratic_formula). You already calculated `a`, `b`, and `c` from that equation in the last homework, plug them in! We will be using the negative solution to the equation.

#### Normal Vector

First, let’s get ourselves a surface normal so we can shade. This is a vector that is perpendicular to the surface at the point of intersection. For a `Sphere`, the outward normal is in the direction of the hit point minus the center divided by the radius.

![Surface Normal Geometry](https://raytracing.github.io/images/fig-1.05-sphere-normal.jpg)

On the earth, this implies that the vector from the earth’s center to you points straight up. To calculate the surface normal, we can utilize the following formula, depicted in the picture above, where `N` is the surface normal of the `Sphere`.

```
N = (P - C) / R
```

To solve for `P`, we need to know `t`. Luckily, we are already calculating `P` in the section above!

#### Kinda Random Direction

To accurately portray the `random` part of the random bounce, we will need to utilize random numbers to generate a bounce pattern. To make this easy for you, we have provided the following function.

```
Vector3D randomVector = makeRandomUnitVector();
```

### Metal Materials

![](https://raytracing.github.io/images/fig-1.11-reflection.jpg)

For a metal material, the formula to calculate the bounce is as follows, where again `B` is the `Ray` direction, and `N` is the surface normal of the sphere. The mathematics here are not too important, but if you are curious, we are calculating a perfect reflection, without accidentally falling through the object we are hitting.

```
newDirection = B - 2 * (B ⋅ N) * N
```

An important consideration to make when calculating metal reflections, is that the value that results from the calculation may not be `normalized`. We haven't discussed what this means, because it's not too important. That being said, we need to do it here. So, you should know that there is a way to normalize a vector. Your code will likely still work even without normalization, but we should be normalizing it for utmost accuracy.

```
Vector3D exampleVector = {3, 3, 3};
Vector3D normalizedVector = exampleVector.normalize();
```

### Glass (Dialetrics)

Glass is hard, because we need to consider [Snells Law](https://en.wikipedia.org/wiki/Snell%27s_law). Here is a picture that demonstrates the concept of refraction.

![Snells Law](https://raytracing.github.io/images/fig-1.13-refraction.jpg)

How do we go about solving for the resulting bounce? Well, in an attempt to not overload you with how much math we are doing, lets just say the following equations show the solution to the problem.

```
ResultBounce = ResultBounce(perpendicular) + ResultBounce(parallel)
ResultBounce(perpendicular) = refractionCoefficient * (B + (-B ⋅ N) * N)
ResultBounce(parallel) = -√(1 - |ResultBounce(perpendicular)|²) * N
```

In the formula above `|` do not imply absolute value. They imply the length of the vector. Here is how you can access that. The length of a vector is calculated as the square root of the dot product of a vector with itself.

```
Vector3D lengthVector = {2, 2, 2};
double length = lengthVector.length(); // sqrt(12)
```

In this class our refraction coefficient will be `1.5`.

## Your Task

Your job is twofold. As previously discussed, modify the function you wrote in HW1 to handle the new `return` strategy. Next, implement the following function that has been provided to you, to determine the vector of the resulting bounce after hitting a sphere.

```
Vector3D determineBounceVector(const Point3D &sphereCenter, double radius, const string& sphereMaterial, const Point3D &rayOrigin, const Vector3D &rayDirection) {
    // Add your HW2 code here, replacing the return statement
    return Vector3D();
}
```

Notice that this function returns a `Vector3D`, showing the direction that the provided `Ray` will bounce off the  `Sphere` with the provided center and radius.

This function should be anywhere from `6 - 15` lines of code, depending on how compact you like to code. When I wrote it, I had `11` lines of code.

In addition, we provide four test cases for you. `TestOne` - `TestFour` The first two test your new `hitSphere` function. The last two test your new `determineBounceVector` function. This homework also requires that you add a test case of your own.

## Requirements

1. Refactor the `hitSphere` function.
2. Implement the `determineBounceVector` function.
3. Create `1` additional test case to ensure that your function behaves as expected.
4. Ensure your code compiles without warnings, and runs without errors.
5. Submit your code as a zip file in the following format `LastName-HW2.zip`.
