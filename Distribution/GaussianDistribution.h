//
// Created by awais.talib.
//

#ifndef OPTIONPRICER_GAUSSIANDISTRIBUTION_H
#define OPTIONPRICER_GAUSSIANDISTRIBUTION_H

#include "IDistribution.h"
#include <math.h>

namespace OptionPricer
{

    class GaussianDistribution  : public IDistribution
    {
        public:
            GaussianDistribution(double mean, double variance) : _mean(mean), _variance(variance)
            {}

            IDistribution* Clone() const;

            double GetPdf(double x) const;

            double GetCdf(double x) const;

        private:
            double _mean;
            double _variance;
    };

}

#endif //OPTIONPRICER_GAUSSIANDISTRIBUTION_H
