#pragma once

#include <eigen3/Eigen/Eigen>
#include <algorithm>
#include <array>
#include <stdexcept>

class Triangle
{
public:
    Eigen::Vector3f v[3];

    Eigen::Vector3f color[3];
    Eigen::Vector2f tex_coords[3];
    Eigen::Vector3f normal[3];

    Triangle();

    Eigen::Vector3f a() const { return v[0]; }
    Eigen::Vector3f b() const { return v[1]; }
    Eigen::Vector3f c() const { return v[2]; }

    void setVertex(int ind, Eigen::Vector3f ver);
    void setNormal(int ind, Eigen::Vector3f n);
    void setColor(int ind, float r, float g, float b);
    void setTexCoord(int ind, float s, float t);
    std::array<Eigen::Vector4f, 3> toVector4() const;
};
