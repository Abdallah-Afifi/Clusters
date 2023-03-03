#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Point.h"

using namespace std;

// Function to compute the center of a cluster of points
point Center(point C[], int n) {
    float sumX = 0, sumY = 0;
    for (int i = 0; i < n; i++) {
        sumX += C[i].getX();
        sumY += C[i].getY();
    }
    float avgX = sumX / n;
    float avgY = sumY / n;
    point center(avgX, avgY);
    return center;
}

// Function to determine to which cluster a point belongs
char ClosestCluster(point A[], point B[], point p) {
    point centerA = Center(A, 200);
    point centerB = Center(B, 200);
    float distA = centerA.distance(p);
    float distB = centerB.distance(p);
    if (distA < distB) {
        return 'A';
    }
    else {
        return 'B';
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Generate points for cluster A
    point A[200];
    for (int i = 0; i < 200; i++) {
        float x = 70 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (20)));
        float y = 70 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (20)));
        A[i].setX(x);
        A[i].setY(y);
    }

    // Generate points for cluster B
    point B[200];
    for (int i = 0; i < 200; i++) {
        float x = 20 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (20)));
        float y = 20 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (20)));
        B[i].setX(x);
        B[i].setY(y);
    }

    // Generate points to classify
    point p[20];
    for (int i = 0; i < 20; i++) {
        float x = 5 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (95)));
        float y = 5 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (95)));
        p[i].setX(x);
        p[i].setY(y);
    }

    // Classify points and output results
    for (int i = 0; i < 20; i++) {
        char cluster = ClosestCluster(A, B, p[i]);
        cout << "Point " << i + 1 << " belongs to cluster " << cluster << endl;
    }

    return 0;
}
