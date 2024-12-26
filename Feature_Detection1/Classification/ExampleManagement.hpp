#pragma once
/*
ExampleManagement.hpp
* Created on: 1/10/2024
* Author : Moin Shaikh
*/


#ifndef FEATUREDETECTION_CLASSIFICATION_EXAMPLEMANAGEMENT_HPP_
#define FEATUREDETECTION_CLASSIFICATION_EXAMPLEMANAGEMENT_HPP_

#include<opencv2/core.hpp>
#include<memory>
#include<vector>
 /**
 * Stores and manages examples for training a classifier. Typically, the amount of training examples is budgeted,
 * meaning that there is a maximum amount of training examples that may be stored at a time.
 */
namespace Classification
{

	class ExampleManagement
	{
	public:
		/**
		* Iterator for training examples.
		*/
		class ExampleIterator
		{
		public:
			virtual ~ExampleIterator(){}

			/**
			* @return True if there is another training example to iterate over, false otherwise.
			*/
			virtual bool hasNext() const = 0;
			/**
			 * Retrieves the next training example.
			 *
			 * @return Next training example.
			*/
			virtual const cv::Mat& next() = 0;
		};

		virtual ~ExampleManagement() {}

		/**
			* Adds new training examples, which may lead to the deletion of some existing training examples.
			*
			* @param[in] newExamples Training examples to add.
		*/

		virtual void add(const std::vector<cv::Mat>& example) = 0;

		/**
			* Removes all training examples.
		*/
		virtual void clear() = 0;

		/**
			* @return Amount of training examples.
		*/
		virtual size_t size() = 0;
		/**
			* Determines whether there are enough examples for training.
			*
			* @return True if there are enough examples for training, false otherwise.
		*/
		virtual bool hasRequiredSize() const = 0;
		/**
			* @return Iterator for iterating over the training examples.
		*/
		//virtual std::unique_ptr<ExampleIterator> iterator() const = 0;
	};
}

#endif
