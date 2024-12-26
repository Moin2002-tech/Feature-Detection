#pragma once


/*
* Hdf5Utils.hpp
* Created on: 4/9/2024
* Author : Moin Shaikh
*/




#ifndef FEATUREDETECTION_MORPHOBLE_MODEL_HDF5UTILS_HPP_
#define FEATUREDETECTION_MORPHOBLE_MODEL_HDF5UTILS_HPP_
#ifdef WITH_MORPHABLEMODEL_HDF5
#include<hdf5.h>
#include<H5Cpp.h>
#include<opencv2/core.hpp>
#include<vector>
#include"../Render/Mesh.hpp"

namespace MorphalModel
{
	namespace utils
	{
		class Hdf5Utils 
		{
			{
			public:
				static H5::H5File openFile(const std::string filename);
				static H5::Group openPath(H5::H5File & file, const std::string & path);

				static cv::Mat readMatrixFloat(const H5::CommonFG & fg, std::string name);
				static void readMatrixInt(const H5::CommonFG & fg, std::string name, cv::Mat & matrix);
				static void readVector(const H5::CommonFG & fg, std::string name, std::vector<float>&vector);
				static std::string readString(const H5::CommonFG & fg, std::string name);

				static bool existsObjectWithName(const H5::CommonFG & fg, const std::string & name);

				static render::Mesh readFromHdf5(std::string filename);
	
			
		};

	}
}
#endif //#ifdef WITH_MORPHABLEMODEL_HDF5
#endif //FEATUREDETECTION_MORPHOBLE_MODEL_HDF5UTILS_HPP_