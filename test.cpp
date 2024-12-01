#include <cmath>
#include <cstddef>
#include <vector>
using namespace std;

class PhysicEngine {
  public:
    class Object2 {
      public:
        Object2(double x, double y, double r, double weight) : x(x), y(y), r(r), weight(weight), speedX(0), speedY(0) {
        }

        double getX() const {
            return x;
        }
        double getY() const {
            return y;
        }
        double getR() const {
            return r;
        }
        double getWeight() const {
            return weight;
        }
        double getSpeedX() const {
            return speedX;
        }
        double getSpeedY() const {
            return speedY;
        }

        void setSpeed(double sx, double sy) {
            speedX = sx;
            speedY = sy;
        }
        void setCircle(double nx, double ny, double nr) {
            x = nx;
            y = ny;
            r = nr;
        }

      private:
        double x, y, r, weight;
        double speedX, speedY;
    };

    PhysicEngine() : G(9.8), FPS(60) {
    }

    void setFPS(unsigned int fps) {
        FPS = fps;
    }
    unsigned int getFPS() const {
        return FPS;
    }
    void addObject(Object2 &object) {
        objects.push_back(&object);
    }
    void reset() {
        objects.clear();
    }

    void update() {
        double interval = 1.0 / FPS;

        for (auto obj : objects) {
            obj->setSpeed(obj->getSpeedX(), obj->getSpeedY() - G * interval);
            obj->setCircle(obj->getX() + obj->getSpeedX() * interval, obj->getY() + obj->getSpeedY() * interval,
                           obj->getR());

            // 地面碰撞檢查
            if (obj->getY() - obj->getR() < 0) {
                obj->setCircle(obj->getX(), obj->getR(), obj->getR());
                obj->setSpeed(obj->getSpeedX(), -obj->getSpeedY());
            }
        }

        // 檢查並處理物體間的碰撞
        for (size_t i = 0; i < objects.size(); ++i) {
            for (size_t j = i + 1; j < objects.size(); ++j) {
                handleCollision(*objects[i], *objects[j]);
            }
        }
    }

  private:
    void handleCollision(Object2 &a, Object2 &b) {
        // 計算距離與碰撞檢查
        double dx = a.getX() - b.getX();
        double dy = a.getY() - b.getY();
        double distance = sqrt(dx * dx + dy * dy);
        if (distance >= (a.getR() + b.getR()))
            return;

        // 單位向量
        double nx = dx / distance;
        double ny = dy / distance;

        // 相對速度
        double dvx = a.getSpeedX() - b.getSpeedX();
        double dvy = a.getSpeedY() - b.getSpeedY();

        // 判斷物體是否接近
        double dotProduct = dvx * nx + dvy * ny;
        if (dotProduct > 0)
            return;

        // 使用公式計算新速度
        double m1 = a.getWeight();
        double m2 = b.getWeight();
        double factor = 2 * dotProduct / (m1 + m2);

        a.setSpeed(a.getSpeedX() - factor * m2 * nx, a.getSpeedY() - factor * m2 * ny);
        b.setSpeed(b.getSpeedX() + factor * m1 * nx, b.getSpeedY() + factor * m1 * ny);
    }

    double G;
    unsigned int FPS;
    vector<Object2 *> objects;
};
