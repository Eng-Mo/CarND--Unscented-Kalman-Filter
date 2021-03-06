#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */

	VectorXd rmse(4);
	rmse << 0,0,0,0;

	// TODO: YOUR CODE HERE

	// check the validity of the following inputs:
	//  * the estimation vector size should not be zero
	//  * the estimation vector size should equal ground truth vector size
	// ... your code here
	if (estimations.size()!=ground_truth.size())
	{
		return rmse;

	}


		//accumulate squared residuals
	for(int i=0; i < estimations.size(); ++i){

		VectorXd resdual=estimations[i]-ground_truth[i];
		resdual=resdual.array()*resdual.array();
		rmse+=resdual;

		// ... your code here

	}
	rmse=rmse/estimations.size();
	rmse=rmse.array().sqrt();



	//calculate the mean
	// ... your code here

	//calculate the squared root
	// ... your code here

	//return the result
	return rmse;
}
