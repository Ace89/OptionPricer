//
// Created by awais.talib.
//

#include <cmath>
#include "GaussianDistribution.h"

namespace OptionPricer
{
    const double PI = 3.14159265;

    IDistribution* GaussianDistribution::Clone() const
    {
        return new GaussianDistribution(*this);
    }

    double GaussianDistribution::GetPdf(double x) const
    {
        return (1/std::sqrt(_variance*2*OptionPricer::PI))*std::exp(-((x-_mean)*(x-_mean))/(2*_variance));
    }

    double GaussianDistribution::GetCdf(double x) const
    {
        // -6.0 is sufficient to give a negligible truncation error to calc gaussian CDF
        double lb = -6.0;
        int n = 1000;

        // use the trapezoid rule, lb to be - infinite and ub to be x
        double integral = 0.0;

        double stepSize = double((x-lb)/n); // (b-a)/n

        for(int i=1;i<n;i++)
        {
            integral += 0.5*stepSize*(GetPdf((i-1)*stepSize)+GetPdf(i*stepSize));
        }

        return integral;
    }

}
