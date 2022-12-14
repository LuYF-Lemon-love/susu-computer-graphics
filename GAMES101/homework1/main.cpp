#include "Triangle.hpp"
#include "rasterizer.hpp"
#include <eigen3/Eigen/Eigen>
#include <opencv2/opencv.hpp>
#include <iostream>

constexpr double MY_PI = 3.1415926;

Eigen::Matrix4f get_rotation(Eigen::Vector3f axis, float angle) {
    double rad_angle = angle / 180 * MY_PI;
    Eigen::Matrix4f I, N, Rod;
    Eigen::Vector4f axis_4f;
    Eigen::RowVector4f axis_row;

    axis_4f << axis.x(), axis.y(), axis.z(), 0;
    axis_row << axis.x(), axis.y(), axis.z(), 0;

    I = Eigen::Matrix4f::Identity();

    N << 0, -axis.z(), axis.y(), 0,
         axis.z(), 0, -axis.x(), 0,
         -axis.y(), axis.x(), 0, 0,
         0, 0, 0, 1;
    
    Rod = cos(rad_angle) * I + (1 - cos(rad_angle)) * axis_4f * axis_row + sin(rad_angle) * N;
    Rod(3, 3) = 1;
    return Rod;
}

Eigen::Matrix4f get_model_matrix(float rotation_angle)
{
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the model matrix for rotating the triangle around the Z axis.
    // Then return it.
    float angle = rotation_angle / 180 * MY_PI;
    model(0, 0)= cos(angle);
    model(0, 1) = -sin(angle);
    model(1, 0) = sin(angle);
    model(1, 1) = cos(angle);
    return model;
}

Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, -eye_pos[0],
                 0, 1, 0, -eye_pos[1],
                 0, 0, 1, -eye_pos[2],
                 0, 0, 0, 1;

    view = translate * view;

    return view;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
                                      float zNear, float zFar)
{
    // Students will implement this function

    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the projection matrix for the given parameters.
    // Then return it.
    float eye_angle = eye_fov / 180 * MY_PI;
    float t, b, l, r;
    t = zNear * tan(eye_angle /2);
    r = t * aspect_ratio;
    b = -t;
    l = -r;
    Eigen::Matrix4f perspective;
    Eigen::Matrix4f translate;
    Eigen::Matrix4f scale;
    perspective << zNear, 0, 0, 0,
                   0, zNear, 0, 0,
                   0, 0, -(zNear + zFar), -zNear * zFar,
                   0, 0, 1, 0;
    
    translate << 1, 0, 0, 0,
                 0, 1, 0, 0,
                 0, 0, 1, (zNear + zFar) / 2,
                 0, 0, 0, 1;

    scale << 2 / (r - l), 0, 0, 0,
             0, 2 / (t - b), 0, 0,
             0, 0, 2 / (zFar - zNear), 0,
             0, 0, 0, 1;

    projection = scale * translate * perspective * projection;

    return projection;
}

int main(int argc, const char** argv)
{
    float angle = 0;
    bool command_line = false;
    std::string filename = "output.png";

    if (argc >= 3) {
        command_line = true;
        angle = std::stof(argv[2]); // -r by default
        if (argc == 4) {
            filename = std::string(argv[3]);
        }
        else
            return 0;
    }

    rst::rasterizer r(700, 700);

    Eigen::Vector3f eye_pos = {0, 0, 5};

    std::vector<Eigen::Vector3f> pos{{2, 0, -2}, {0, 2, -2}, {-2, 0, -2}};

    std::vector<Eigen::Vector3i> ind{{0, 1, 2}};

    auto pos_id = r.load_positions(pos);
    auto ind_id = r.load_indices(ind);

    if (command_line) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);

        cv::imwrite(filename, image);

        return 0;
    }

    bool rflag = false;
    Eigen::Vector3f axis(0, 0, 1);
    double angle_axis = 0, d_angle;
    int key = 0;
    int frame_count = 0;

    std::cout << "Please enter the axis and angle:" << std::endl;
    std::cin >> axis.x() >> axis.y() >> axis.z() >> d_angle;

    while (key != 27) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        if (rflag)
            r.set_rodrigues(get_rotation(axis, angle_axis));
        else
            r.set_rodrigues(get_rotation({ 0,0,1 }, 0));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);

        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);
        key = cv::waitKey(10);

        std::cout << "frame count: " << frame_count++ << '\n';

        if (key == 'a') {
            angle += 10;
        }
        else if (key == 'd') {
            angle -= 10;
        }
        else if (key == 'r') {
            //??????r???????????????????????????
            rflag = true;
            angle_axis += d_angle;
        }
    }

    return 0;
}
