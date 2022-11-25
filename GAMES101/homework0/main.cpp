#include<cmath>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<iostream>

int main(){
	
	// matrix definition
	Eigen::Matrix3f transform;
	double a = 0.25f * acos(-1);
	transform << std::cos(a), -sin(a), 1,
		  sin(a), cos(a), 2,
		  0, 0, 1;
	std::cout << "transform Matrix:\n" << transform << std::endl;
	
	// vector definition
	Eigen::Vector3f p(2.0f, 1.0f, 1.0f);
	std::cout <<"start point:\n" << p << std::endl;
	
	// matrix multiply vector
	Eigen::Vector3f result = transform * p;
	std::cout << "final point:\n" << result << std::endl;
	
	return 0;
}
