#pragma once

#define PCL_NO_PRECOMPILE
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

struct PointXYZIRGBxyz
{
	PCL_ADD_POINT4D; 
	PCL_ADD_INTENSITY;
	PCL_ADD_UNION_RGB;
	float nx; // normalized x
	float ny; // normalized y
	float nz; // normalized z
	std::uint8_t label; 
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW
} EIGEN_ALIGN16;

POINT_CLOUD_REGISTER_POINT_STRUCT(PointXYZIRGBxyz,
	(float, x, x) (float, y, y)
	(float, z, z) (float, intensity, intensity)
	(std::uint8_t, b, b) (std::uint8_t, g, g) (std::uint8_t, r, r) (std::uint8_t, a, a)
	(float, nx, nx) (float, ny, ny) (float, nz, nz) 
	(std::uint8_t, label, label)
)

typedef PointXYZIRGBxyz  PointTypeHD5;

inline void GetNormalized(PointTypeHD5& thePt, const PointTypeHD5& ptNormOri) {
	thePt.x = thePt.x - ptNormOri.x; thePt.y = thePt.y - ptNormOri.y; thePt.z = thePt.z - ptNormOri.z;
}