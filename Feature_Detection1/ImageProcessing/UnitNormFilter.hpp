#pragma once


/*
* File: ImagePyramid.hpp
* Created on: 9/2/2025
* Author : Moin Shaikh
*/

#ifndef FEATUREDETECTION_IMAGEPROCESSING_UNITNORMFILTER_HPP_
#define FEATUREDETECTION_IMAGEPROCESSING_UNITNORMFILTER_HPP_

#include"ImageFilter.hpp"

namespace ImageProcessing
{
	/**
 * Image filter that normalizes the pixel values by the norm of the whole
 * image. The norm can be any of OpenCV's norm constants, like NORM_L2 or
 * NORM_L1.
 * The input image must not have more than one channel and can be of any type. The
 * filtered image is of type CV_32F with the values in the same range.
 */
	class UnitNormFilter : public ImageFilter {
	public:

		/**
		 * Constructs a new filter that normalizes an image by its intensity-norm.
		 *
		 * @param[in] normType The norm type (see cv::norm).
		 */
		UnitNormFilter(int normType = cv::NORM_L2);

		using ImageFilter::applyTo;

		cv::Mat applyTo(const cv::Mat& image, cv::Mat& filtered) const;

		void applyInPlace(cv::Mat& image) const;

	private:

		/**
		 * Normalizes the given image of type CV_32FC1.
		 *
		 * @param[in,out] image The image that will be normalized. Has to be of type CV_32FC1.
		 */
		void normalize(cv::Mat& image) const;

		static const float eps; ///< Small value being added to the norm to prevent division by zero.
		int normType; ///< The norm type (see cv::norm).
	};
}

#endif //FEATUREDETECTION_IMAGEPROCESSING_UNITNORMFILTER_HPP_