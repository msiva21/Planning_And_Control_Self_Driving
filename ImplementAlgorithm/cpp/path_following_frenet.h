#ifndef PATH_FOLLOWING_FRENET_H
#define PATH_FOLLOWING_FRENET_H

#include <vector>
#include <iostream>
#include <cmath>
#include "lib/spline.h"

class pathFollowingFrenet 
{
  private:
    
    /* fixed parameters */
    const double dt = 0.05;       // time step
    const double vr = 10.0;       // longditudinal velocity

    /* state variables */ 
    double s_;
    double e_;
    double theta_e_;

    /* spline variables */
    tk::spline spline_;           // the spline function, spline_ := s(t)
    double kappa_s_;              // curvature w.r.t. s, kappa_s_ := kappa(s)

    /* control variables */
    double omega_;                // calculated control input
    double k_theta_e_;
    double k_e_;

  public:
    pathFollowingFrenet(double s, 
                        double e, 
                        double theta_e);
    ~pathFollowingFrenet();

    void fitSpline(std::vector<double>& posX, 
                   std::vector<double>& posY);
    void setControlGains(double k_theta_e, 
                         double k_e);
    void calControlInput();
    void propagate();             // execute the propagation for one step
};

#endif /* PATH_FOLLOWING_FRENET_H */