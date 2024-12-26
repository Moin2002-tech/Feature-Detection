#pragma once

/*
* MorphableModel.hpp
* Created on: 5/9/2024
* Author : Moin Shaikh
*/


#ifndef FEATUREDETECTION_MORPHOBLE_MODEL_MORPHABLEMODEL_HPP_
#define FEATUREDETECTION_MORPHOBLE_MODEL_MORPHABLEMODEL_HPP_

#include"pcaModel.hpp"
#include"../Render/Mesh.hpp"

#include<boost/property_tree/ptree.hpp>
#include <boost/filesystem/path.hpp>

using Render::Mesh;
namespace MorphableModels
{
	class MorphableModel
	{
	public:
		/**
	 * Constructs a new Morphable Model.
	 *
	 * @param[in] a b
	 * 
	 * 
	 */
	
		MorphableModel();

		/**
		* Load a morphable model from a property tree node in a config file.
		* The function uses the file extension to determine which load
		* function to call.
		* Throws a std::runtime_exception if the extension is unrecognised.
		*
		* @param[in] configTree A node of a ptree.
		* @return A morphable model.
		*/
		static MorphableModel load(const boost::property_tree::ptree configTree);
		/**
		 * Todo.
		 *
		 * @param[in] h5file Todo.
		 * @param[in] landmarkVertexMappingFile Todo.
		 * @return TODO.
		 */

		//MorphableModel loadScmModel(boost::filesystem::path h5file, boost::filesystem::path landmarkVertexMappingFile, boost::filesystem::path isomapFile);
		static MorphableModel loadScmModel(boost::filesystem::path h5file, boost::filesystem::path landmarkVertexMappingFile, boost::filesystem::path isomapFile);

		static MorphableModel loadStatismoModel(boost::filesystem::path h5file);

		static std::vector<cv::Vec2f> loadIsomap(boost::filesystem::path isomapFile);

		PcaModel getShapeModel() const;
		PcaModel getColorModel() const;
		/**
		 * Returns the mean of the shape- and color model
		 * as a Mesh.
		 *
		 * @return The mean of the model.
		 */
		Render::Mesh getMean() const;
		/**
	 * Return the value of the mean at a given landmark.
	 *
	 * @param[in] landmarkIdentifier A landmark identifier (e.g. "center.nose.tip").
	 * @return A Vec3f containing the values at the given landmark.
	 * @throws out_of_range exception if the landmarkIdentifier does not exist in the model. // TODO test the javadoc!
	 */
	 //cv::Vec3f getMeanAtPoint(std::string landmarkIdentifier) const;

	 /**
	  * Return the value of the mean at a given vertex id.
	  *
	  * @param[in] vertexIndex A vertex id.
	  * @return A Vec3f containing the values at the given vertex id.
	  */
	  //cv::Vec3f getMeanAtPoint(unsigned int vertexIndex) const;

	  /**
	   * Draws a random sample from the model, where the coefficients
	   * for the shape- and color models are both drawn from a standard
	   * normal (or with the given standard deviation).
	   *
	   * @param[in] sigma The standard deviation. (TODO find out which one, sigma=var, sigmaSq=sdev)
	   * @return A random sample from the model.
	   */
		Render::Mesh drawSample(float sigma = 1.0f); // Todo sigmaShape, sigmaColor? or 2 functions?
		/**
		 * Returns a sample from the model with the given shape- and
		 * color PCA coefficients.
		 * If a vector is empty, the mean is used.
		 * TODO: Provide normalized, i.e. standardnormal distributed coeffs, we'll take care of the rest
		 *
		 * @param[in] shapeCoefficients The PCA coefficients used to generate the shape sample.
		 * @param[in] colorCoefficients The PCA coefficients used to generate the shape sample.
		 * @return A model instance with given coefficients.
		 */
		Render::Mesh drawSample(std::vector<float> shapeCoefficients, std::vector<float> colorCoefficients);

		//void setHasTextureCoordinates(bool hasTextureCoordinates);
	public:
		PcaModel shapeModel; ///< A PCA model of the shape
		PcaModel colorModel; ///< A PCA model of vertex color information

		bool hasTextureCoordinates = false; ///< 

		std::vector<cv::Vec2f> textureCoordinates; ///< 
	};
}



#endif //FEATUREDETECTION_MORPHOBLE_MODEL_MORPHABLEMODEL_HPP_
