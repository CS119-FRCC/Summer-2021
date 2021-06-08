# HW1: Ray-Sphere Intersection

## Overview

In the following homeworks, we will be building what is called a raytracer. You can read more about this [here](../README.md). To this end, in this homework, we will create a function that will determine whether a given `Sphere` is hit by a given `Ray`. This will be the basic building block of our raytracer, and allow us to create a scene in the future.

### Background

### Vectors

Almost all graphics programs utilize some additional libraries for storing geometric vectors and colors. We’ll be using the class `Vector3D` for colors, locations, directions, offsets, and whatever else we might need.

To this end, we also provided two `aliases`, `Point3D` and `Color`. I want to get across that these are `aliases`, at the end of the day, all these objects are simply `Vector3D`. We only have these names for our understanding.

We have given you header file located [here](./Vector3D/Vector3D.h). The code in here is confusing, and will look completely foreign to you. Thats ok! Here is an example of how to use it.

Say I wanted to create an object to represent a color. As discussed in class, a common way of representing colors is with integers from `0 - 255`, with `0` being black, and `255` being white. Here is how that would look.

```c++
Color black = {0, 0, 0};
Color white = {255, 255, 255};
Color red = {255, 0, 0};
Color magenta = {255, 0, 255};
```

We can also utilize this library to handle calculations for us. Let us say we wanted to find the dot product between two vectors, or create the vector that defines the distance between two points. We could do that with the following code.

```c++
Point3D origin = {0, 0, 0};
Point3D offABit = {5, 5, 5};
Vector3D distanceVector = offABit - origin;

Vector3D aVector = {2, 0, 0}
Vector3D anotherVector = {1, 1, 0}
int dotProduct = aVector.dot(anotherVector);
```

While the subtraction of two points gives us back a vector representing the distance between two points, in this case `{5, 5, 5}`, the `dot product` is solved by multiplying across the vectors. In this case, this is the following.

```
(2 * 1) + (0 * 1) + (0 * 0) = 2
```

In this case, the dot product of these two vectors is `2`.

While understanding of the nuances of points, vectors, colors, and so on is not critical to this course, I recommend a quick readup. [Here](https://en.wikipedia.org/wiki/Euclidean_vector) is the Wikipedia article to get you started. I also ***highly*** recommend a simply understanding of the dot product. [Here](https://betterexplained.com/articles/vector-calculus-understanding-the-dot-product/) is a good article on the subject.

### Rays

We need a little more information for our program than our `Vector3D` class can provide. We need another construct that represents a `Ray`. Let’s think of a `Ray` as a function `P(t) = A + tB`. Here `P` is a 3D position along a line in 3D. `A` is the `Ray origin` and `B` is the `Ray direction`. The `Ray` parameter `t` is a real number. Plug in a different `t` and `P(t)` moves the point along the `Ray`. Add in negative `t` values and you can go anywhere on the 3D line. For positive `t`, you get only the parts in front of `A`, and this is what is often called a half-line or a `Ray`.

![Ray](https://raytracing.github.io/images/fig-1.02-lerp.jpg)

We can implement a `Ray` therefore with the following code. In the following example, we create a `Ray` with an `origin` and a `direction` (`A`, `B`). We do not give it a determined `t` value.

```c++
Point3D origin = {0, 0, 0};
Vector3D direction = {2, 2, 0};
```

## Spheres and Intersection

Recall from way back in algebra that the equation for a `Sphere` centered at the `origin` of radius 𝑅 is `x² + y² + z² = R²`. Put another way, if a given point `(x, y, z)` is on the `Sphere`, then `x² + y² + z² = R²`. If the given point `(x, y, z)` is inside the `Sphere`, then `x² + y² + z² < R²`, and if a given point `(x, y, z)` is outside the `Sphere`, then `x² + y² + z² > R²`.

It gets uglier if the `Sphere` center is at `(Cx, Cy, Cz)`, instead of at the `origin`.

```
(x − Cx)² + (y − Cy)² + (z - Cz)² = R²
```

You might note that the vector from center `C = (Cx, Cy, Cz)` to point `P = (x, y, z)` is `(P − C)`, and therefore we can create the following formula.

```
(P − C) ⋅ (P − C) = (x − Cx)² + (y − Cy)² + (z - Cz)²
```

So the equation of the `Sphere` in vector form is the following.

```
(P − C) ⋅ (P − C) = R²
```

We can read this as "any point `P` that satisfies this equation is on the `Sphere`". We want to know if our `Ray` `P(t) = A + tB` ever hits the `Sphere` anywhere. If it does hit the `Sphere`, there is some `t` for which `P(t)` satisfies the `Sphere` equation. So we are looking for any `t` where the following is true.

```
(P(t) − C) ⋅ (P(t) − C) = R²
```

We can also expand into the full form of a `Ray` `P(t)`.

```
(A + tB − C) ⋅ (A + tB - C) = R²
```

If we expand that equation and move all the terms to the left hand side we get the following.

```
t²B ⋅ B + 2tB ⋅ (A − C) + (A − C) ⋅ (A − C) − R² = 0
```

The vectors and `R` in that equation are all constant and known. The unknown is `t`, and the equation is a [quadratic](https://en.wikipedia.org/wiki/Quadratic_formula), like you probably saw in your high school math class. You can solve for `t` and there is a square root part that is either positive (meaning two real solutions), negative (meaning no real solutions), or zero (meaning one real solution). In graphics, the algebra almost always relates very directly to the geometry. What we have is represented by the following image.

![Ray-sphere intersection results](https://raytracing.github.io/images/fig-1.04-ray-sphere.jpg)

In other words, we need to see if the discriminant of the quadratic equation is positive. If it is, the `Ray` hit the `Sphere`, otherwise, we are out of luck. Here is the discriminant, having solved the quadratic equation for `t`.

```
Remember the discriminant of the quadratic equation is: b² - 4ac

Hint:

a = (B ⋅ B)
b = (2 * (A - C) ⋅ B)
c = (A - C) ⋅ (A - C) - R²
```

## Your Task

Your job is to create a function (in C++ of course), to test whether a given `Ray` hits a given `Sphere`. To start you off, we have given you the following function.

```
bool hitSphere(const Point3D &sphereCenter, double radius, const Point3D &rayOrigin, const Vector3D &rayDirection) {
    // Add your HW1 code here, replacing the return statement
    return false
}
```

Notice that this function returns a `bool`, indicating whether the provided `Ray` did in fact hit the `Sphere` with the provided center and radius.

This function should be anywhere from `1 - 8` lines of code, depending on how compact you like to code. When I wrote it, I had `6` lines of code.

In addition, we provide two test cases for you. `TestOne` and `TestTwo`. This homework also requires that you add some test cases of your own, and it is critically important that you understand why the test cases provided `return` either `false` or `true`.

`Hint`: try changing `TestTwo`'s `sphereCenter` `y` coordinate from `0.50` to `0.49`. What happens?

## Requirements

1. Implement the `hitSphere` function.
2. Create `3` additional test cases to ensure that your function behaves as expected.
3. Ensure your code compiles without warnings, and runs without errors.
4. Submit your code as a zip file in the following format `LastName-HW1.zip`.
