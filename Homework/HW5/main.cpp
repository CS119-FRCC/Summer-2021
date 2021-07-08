#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <limits>
#include <chrono>

#include "../Vector3D/Vector3D.h"

using namespace std;

int main(int argc, char** argv) {
		// IO Stream Setup

    cout << boolalpha;
    cout << "Testing hitSphere Function" << '\n';

    const Point3D rayOrigin = {0, 0, 0};
    const Vector3D rayDirection = {0, 0, -1};

    // Test One

    const Point3D testOneSphereCenter = {0, 0, -1};
    const double testOneSphereRadius = 0.5;

    double testOneT;
    try {
        testOneT = hitSphere(testOneSphereCenter, testOneSphereRadius, rayOrigin, rayDirection);
    } catch (...) {
        testOneT = -1;
    }

    cout << "Test One: " << '\n';
    cout << '\t' << "Expected: " << 0.5 << '\n';
    cout << '\t' << "Actual: " << testOneT << '\n';

    // Test Two

    const Point3D testTwoSphereCenter = {0, 0.50, -1};
    const double testTwoSphereRadius = 0.50;

    double testTwoT;
    try {
        testTwoT = hitSphere(testTwoSphereCenter, testTwoSphereRadius, rayOrigin, rayDirection);
    } catch (...) {
        testTwoT = -1;
    }
    
    cout << "Test Two: " << '\n';
    cout << '\t' << "Expected: " << -1 << '\n';
    cout << '\t' << "Actual: " << testTwoT << '\n';

    cout << '\n' << "Testing determineBounceVector Function" << '\n' << '\n';

    // Test Three

    const Point3D testThreeSphereCenter = {0, 0, -1};
    const double testThreeSphereRadius = 0.50;
    const string testThreeSphereMaterial = "metal";

    try {
        const Vector3D testThreeT = determineBounceVector(testThreeSphereCenter, testThreeSphereRadius, testThreeSphereMaterial, rayOrigin, rayDirection);
        cout << "Test Three: " << '\n';
        cout << '\t' << "Expected: " << "{0, 0, 1}" << '\n';
        cout << '\t' << "Actual: " << testThreeT << '\n';
    } catch (...) {
        cout << "Test Three Incorrectly Threw An Error" << '\n';
    }

    // Test Four

    const Point3D testFourSphereCenter = {0.25, 0, -1};
    const double testFourSphereRadius = 0.50;
    const string testFourSphereMaterial = "metal";

    try {
        const Vector3D testFourT = determineBounceVector(testFourSphereCenter, testFourSphereRadius, testFourSphereMaterial, rayOrigin, rayDirection);
        cout << "Test Four: " << '\n';
        cout << '\t' << "Expected: " << "{-0.866025, 0, 0.5}" << '\n';
        cout << '\t' << "Actual: " << testFourT << '\n';
    } catch (...) {
        cout << "Test Four Incorrectly Threw An Error" << '\n';
    }

    // Test Five

    const Point3D testFiveSphereCenter = {0, 0, -1};
    const double testFiveSphereRadius = 0.50;
    const string testFiveSphereMaterial = "glass";

    try {
        const Vector3D testFiveT = determineBounceVector(testFiveSphereCenter, testFiveSphereRadius, testFiveSphereMaterial, rayOrigin, rayDirection);
        cout << "Test Five: " << '\n';
        cout << '\t' << "Expected: " << "{0, 0, -1}" << '\n';
        cout << '\t' << "Actual: " << testFiveT << '\n';
    } catch (...) {
        cout << "Test Five Incorrectly Threw An Error" << '\n';
    }

    return 0;
}

