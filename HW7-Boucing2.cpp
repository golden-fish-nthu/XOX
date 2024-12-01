
#define M_PI 3.14159265358979323846
class Object {
  public:
    Object(double W) : weight{W}, vx{0}, vy{0}, x{0}, y{0}, r{0} {
    }

    void setCircle(double X, double Y, double R) {
        x = X, y = Y, r = R;
    }

    void setSpeed(double Vx, double Vy) {
        vx = Vx, vy = Vy;
    }

    double &getSpeedX() {
        return vx;
    }

    double &getSpeedY() {
        return vy;
    }

    double &getX() {
        return x;
    }

    double &getY() {
        return y;
    }

    double &getR() {
        return r;
    }

    const double &getWeight() const {
        return weight;
    }

    const double &getSpeedX() const {
        return vx;
    }

    const double &getSpeedY() const {
        return vy;
    }

    double getVelocity() const {
        return sqrt(vx * vx + vy * vy);
    }

    double getAngle() const {
        return atan2(vy, vx) * 180.0 / M_PI;
    }

    const double &getX() const {
        return x;
    }

    const double &getY() const {
        return y;
    }

    const double &getR() const {
        return r;
    }

  private:
    double weight;
    double vx, vy;
    double x, y, r;
};

#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

class PhysicEngine {
  public:
    PhysicEngine() : G(9.8), FPS(60) {
    }

    void setFPS(unsigned int FPS) {
        this->FPS = FPS;
    }

    unsigned int getFPS() const {
        return FPS;
    }

    void addObject(const Object &object) {
        objects.push_back(object);
    }

    std::vector<Object> getObjects() const {
        return objects;
    }

    void update() {
        double dt = 1.0 / FPS;

        // Apply gravity and update positions
        for (auto &object : objects) {
            object.setSpeed(object.getSpeedX(), object.getSpeedY() - G * dt);
            object.setCircle(object.getX() + object.getSpeedX() * dt,
                             std::max(object.getR(), object.getY() + object.getSpeedY() * dt), object.getR());
        }

        // Handle collisions
        for (size_t i = 0; i < objects.size(); i++) {
            for (size_t j = i + 1; j < objects.size(); j++) {
                auto [dx, dy, distance, isColliding] = CollidingCounting(objects[i], objects[j]);
                if (isColliding) {
                    resolveCollision(objects[i], objects[j]);
                }
            }
        }

        for (auto &i : objects) {
            if (i.getY() - i.getR() <= 0) {
                i.setSpeed(i.getSpeedX(), abs(i.getSpeedY()));
            }
        }
    }

  private:
    double G;
    unsigned int FPS;
    std::vector<Object> objects;

    void resolveCollision(Object &a, Object &b) {
        double dx = a.getX() - b.getX();
        double dy = a.getY() - b.getY();
        double distanceSquared = dx * dx + dy * dy;

        // Ensure no division by zero
        if (distanceSquared == 0)
            return;

        double dvx = a.getSpeedX() - b.getSpeedX();
        double dvy = a.getSpeedY() - b.getSpeedY();
        double dotProduct = dvx * dx + dvy * dy;

        double m1 = a.getWeight();
        double m2 = b.getWeight();

        double factor = 2.0 * dotProduct / ((m1 + m2) * distanceSquared);

        // Update velocities
        a.setSpeed(a.getSpeedX() - factor * m2 * dx, a.getSpeedY() - factor * m2 * dy);
        b.setSpeed(b.getSpeedX() + factor * m1 * dx, b.getSpeedY() + factor * m1 * dy);
    }

    std::tuple<double, double, double, bool> CollidingCounting(const Object &a, const Object &b) const {
        double dx = a.getX() - b.getX();
        double dy = a.getY() - b.getY();
        double distance = sqrt(dx * dx + dy * dy);
        bool isColliding = distance < (a.getR() + b.getR());
        return {dx, dy, distance, isColliding};
    }
};
