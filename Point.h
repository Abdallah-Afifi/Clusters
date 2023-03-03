#ifndef POINT_H
#define POINT_H

class point {
public:
    // Constructors
    point();
    point(float x, float y);

    // Setter functions
    void setX(float x);
    void setY(float y);

    // Getter functions
    float getX() const;
    float getY() const;

    // Display function
    void display() const;

    // Distance function
    float distance(const point& p) const;

private:
    float x;
    float y;
};

#endif
