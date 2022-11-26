#ifndef RASTERIZER_TRIANGLE_H
#define RASTERIZER_TRIANGLE_H

#include <eigen3/Eigen/Eigen>
#include <algorithm>
#include <array>
#include <stdexcept>

using namespace Eigen;
class Triangle
{
public:
    Eigen::Vector3f v[3];

    Eigen::Vector3f color[3];      // color at each vertex;
    Eigen::Vector2f tex_coords[3]; // texture u,v
    Eigen::Vector3f normal[3];     // normal vector for each vertex

    // Texture *tex;
    Triangle();

    Eigen::Vector3f a() const { return v[0]; }
    Eigen::Vector3f b() const { return v[1]; }
    Eigen::Vector3f c() const { return v[2]; }

    void setVertex(int ind, Vector3f ver); /*set i-th vertex coordinates */
    void setNormal(int ind, Vector3f n);   /*set i-th vertex normal vector*/
    void setColor(int ind, float r, float g, float b); /*set i-th vertex color*/
    void setTexCoord(int ind, float s,
                     float t); /*set i-th vertex texture coordinate*/
    std::array<Vector4f, 3> toVector4() const;
};

#endif // RASTERIZER_TRIANGLE_H
