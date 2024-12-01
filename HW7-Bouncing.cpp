#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#include <vector>

class Object {
  public:
    // 建構子，初始化物體的重量和速度
    Object(double W) : weight{W}, vx{0}, vy{0}, x{0}, y{0}, r{0} {
    }

    // 設定圓形物體的位置和半徑
    void setCircle(double X, double Y, double R) {
        x = X, y = Y, r = R;
    }

    // 設定物體的速度
    void setSpeed(double Vx, double Vy) {
        vx = Vx, vy = Vy;
    }

    // 取得物體的水平速度
    double &getSpeedX() {
        return vx;
    }

    // 取得物體的垂直速度
    double &getSpeedY() {
        return vy;
    }

    // 取得物體的水平位置
    double &getX() {
        return x;
    }

    // 取得物體的垂直位置
    double &getY() {
        return y;
    }

    // 取得物體的半徑
    double &getR() {
        return r;
    }

    // 取得物體的重量（常數）
    const double &getWeight() const {
        return weight;
    }

    // 取得物體的水平速度（常數）
    const double &getSpeedX() const {
        return vx;
    }

    // 取得物體的垂直速度（常數）
    const double &getSpeedY() const {
        return vy;
    }

    // 計算並取得物體的速度大小
    double getVelocity() const {
        return sqrt(vx * vx + vy * vy);
    }

    // 計算並取得物體的運動角度
    double getAngle() const {
        return atan2(vy, vx) * 180.0 / M_PI;
    }

    // 取得物體的水平位置（常數）
    const double &getX() const {
        return x;
    }

    // 取得物體的垂直位置（常數）
    const double &getY() const {
        return y;
    }

    // 取得物體的半徑（常數）
    const double &getR() const {
        return r;
    }

  private:
    double weight;  // 物體的重量
    double vx, vy;  // 物體的速度
    double x, y, r; // 物體的位置和半徑
};
#include <tuple>
using namespace std;

class PhysicEngine {
  public:
    // 建構子，初始化重力加速度和幀率
    PhysicEngine() : G(9.8), FPS(60) {
    }

    // 設定幀率
    void setFPS(unsigned int fps) {
        FPS = fps;
    }
    void reset() {
        objects.clear();
    }
    // 取得幀率
    unsigned int getFPS() const {
        return FPS;
    }

    // 新增物體到物理引擎中
    void addObject(const Object &object) {
        objects.push_back(object);
    }

    // 取得所有物體
    std::vector<Object> getObjects() const {
        return objects;
    }
    // 檢查兩個物體是否碰撞
    std::tuple<double, double, double, bool> CollidingCounting(const Object &a, const Object &b) {
        double dx = a.getX() - b.getX();
        double dy = a.getY() - b.getY();
        double distance = sqrt(dx * dx + dy * dy);
        bool isColliding = distance < (a.getR() + b.getR());
        return std::make_tuple(dx, dy, distance, isColliding);
    }

    // 處理兩個物體的碰撞
    void resolveCollision(Object &a, Object &b, tuple<double, double, double, bool> distance) {
        // distance = (dx, dy, distance, isColliding)
        double dvx = a.getSpeedX() - b.getSpeedX();
        double dvy = a.getSpeedY() - b.getSpeedY();

        // 如果速度在碰撞向量上的投影為正，則物體正在分離，不需要處理
        if (dvx * get<0>(distance) + dvy * get<1>(distance) > 0)
            return;

        double nx = get<0>(distance) / get<2>(distance);
        double ny = get<1>(distance) / get<2>(distance);
        double vn = dvx * nx + dvy * ny;
        if (vn > 0)
            return;

        // 碰撞響應
        double m1 = a.getWeight();
        double m2 = b.getWeight();
        double impulse = 2 * vn / (m1 + m2);

        a.getSpeedX() -= impulse * m2 * nx;
        a.getSpeedY() -= impulse * m2 * ny;
        b.getSpeedX() += impulse * m1 * nx;
        b.getSpeedY() += impulse * m1 * ny;
    }
    // 更新物理引擎中的物體狀態
    void update() {
        double interval = 1.0 / FPS;
        for (auto &obj : objects) {
            // 施加重力
            obj.getSpeedY() -= G * interval;

            // 更新位置
            obj.getX() += obj.getSpeedX() * interval;
            obj.getY() += obj.getSpeedY() * interval;

            // 檢查是否與地面碰撞
            if (obj.getY() - obj.getR() < 0) {
                obj.getY() = obj.getR();
                obj.getSpeedY() = -obj.getSpeedY();
            }
        }

        // 檢查物體之間的碰撞
        for (size_t i = 0; i < objects.size(); ++i) {
            for (size_t j = i + 1; j < objects.size(); ++j) {
                auto distance = CollidingCounting(objects[i], objects[j]);
                if (get<3>(distance)) {
                    resolveCollision(objects[i], objects[j], distance);
                }
            }
        }
    }

  private:
    double G;               // 重力加速度
    unsigned int FPS;       // 幀率
    vector<Object> objects; // 物體列表
};

// 物理引擎類別
class PhysicEngine2 {
  public:
    // 構造函數，初始化幀率為60，對象列表為空
    PhysicEngine2() : t{60}, p{} {
    }
    // 重力加速度常數
    double G = 9.8;

    // 設置幀率
    void setFPS(unsigned int FPS) {
        t = FPS;
    }
    // 獲取當前幀率
    unsigned int getFPS() {
        return t;
    }
    // 添加對象到物理引擎中
    void addObject(const Object &object) {
        p.push_back(object);
    }

    // 獲取當前所有對象
    std::vector<Object> getObjects() {
        return p;
    }
    // 重置物理引擎，清空所有對象
    void reset() {
        p.clear();
    }
    // 更新物理引擎中的所有對象
    void update() {
        double dt = 1.0 / t;
        // 更新每個對象的位置和速度
        for (auto &i : p) {
            i.setSpeed(i.getSpeedX(), i.getSpeedY() - G * dt);
            i.setCircle(i.getX() + i.getSpeedX() * dt, std::max(i.getR(), i.getY() + i.getSpeedY() * dt), i.getR());
        }
        // 檢查並處理對象之間的碰撞
        for (size_t i = 0; i < p.size(); ++i) {
            Object &it1 = p[i];
            for (size_t j = i + 1; j < p.size(); ++j) {
                Object &it2 = p[j];
                double dx = it1.getX() - it2.getX();
                double dy = it1.getY() - it2.getY();
                double dvx = it1.getSpeedX() - it2.getSpeedX();
                double dvy = it1.getSpeedY() - it2.getSpeedY();
                double dr = it1.getR() + it2.getR();

                double d = sqrt(dx * dx + dy * dy);
                double overlap = dr - d;
                if (overlap > 0) {
                    double overlapX = overlap * dx / d;
                    double overlapY = overlap * dy / d;

                    it1.setCircle(it1.getX() + overlapX / 2, it1.getY() + overlapY / 2, it1.getR());
                    it2.setCircle(it2.getX() - overlapX / 2, it2.getY() - overlapY / 2, it2.getR());
                }

                if (overlap >= 0) {
                    double vx1 = it1.getSpeedX();
                    double vx2 = it2.getSpeedX();
                    double vy1 = it1.getSpeedY();
                    double vy2 = it2.getSpeedY();
                    double m1 = it1.getWeight();
                    double m2 = it2.getWeight();

                    double vx1_t = vx1 - 2 * m2 / (m1 + m2) * (dvx * dx + dvy * dy) / pow(d, 2) * dx;
                    double vx2_t = vx2 - 2 * m1 / (m1 + m2) * (dvx * dx + dvy * dy) / pow(d, 2) * -dx;
                    double vy1_t = vy1 - 2 * m2 / (m1 + m2) * (dvx * dx + dvy * dy) / pow(d, 2) * dy;
                    double vy2_t = vy2 - 2 * m1 / (m1 + m2) * (dvx * dx + dvy * dy) / pow(d, 2) * -dy;

                    it1.setSpeed(vx1_t, vy1_t);
                    it2.setSpeed(vx2_t, vy2_t);
                }
            }
        }
        // 檢查並處理對象與地面的碰撞
        for (auto &i : p) {
            if (i.getY() - i.getR() <= 0) {
                i.setSpeed(i.getSpeedX(), abs(i.getSpeedY()));
            }
        }
    }

  private:
    // 幀率
    unsigned int t;
    // 對象列表
    std::vector<Object> p;
};
