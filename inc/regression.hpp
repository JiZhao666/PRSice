// This file is part of PRSice2.0, copyright (C) 2016-2017
// Shing Wan Choi, Jack Euesden, Cathryn M. Lewis, Paul F. O’Reilly
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef PRSICE_REGRESSION_H_
#define PRSICE_REGRESSION_H_

#include "misc.hpp"
#include <Eigen/Dense>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <limits>
#include <math.h>
#include <stdexcept>

namespace Regression
{
void linear_regression(const Eigen::VectorXd& y, const Eigen::MatrixXd& A,
                       double& p_value, double& r2, double& r2_adjust,
                       double& coeff, double& standard_error, size_t thread = 1,
                       bool intercept = true);
void glm(const Eigen::VectorXd& y, const Eigen::MatrixXd& x, double& p_value,
         double& r2, double& coeff, double& standard_error,
         size_t max_iter = 25, size_t thread = 1, bool intercept = true);
Eigen::VectorXd logit_linkinv(const Eigen::VectorXd& eta);
Eigen::VectorXd logit_variance(const Eigen::VectorXd& eta);
Eigen::VectorXd logit_mu_eta(const Eigen::VectorXd& eta);
Eigen::VectorXd binomial_dev_resids(const Eigen::VectorXd& y,
                                    const Eigen::VectorXd& mu,
                                    const Eigen::VectorXd& wt);
double binomial_dev_resids_sum(const Eigen::VectorXd& y,
                               const Eigen::VectorXd& mu,
                               const Eigen::VectorXd& wt);
void logit_both(const Eigen::VectorXd& eta, Eigen::VectorXd& g,
                Eigen::VectorXd& gprime);
inline double y_log_y(double y, double mu)
{
    return (y != 0.) ? (y * log(y / mu)) : 0;
}
}

#endif /* PRSICE_REGRESSION_H_ */
