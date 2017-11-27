//
// Created by awais.talib.
//

#ifndef OPTIONPRICER_BLACKSCHOLES_H
#define OPTIONPRICER_BLACKSCHOLES_H

#include "IOptionPricers.h"
#include "../Distribution/IDistribution.h"
#include <cmath>

namespace OptionPricer
{

    class BlackScholes : public IOptionPricers
    {
        public:
            BlackScholes(double riskFree, double vol,const OptionPricer::IDistribution* distribution)
                    : _vol(vol), _riskFree(riskFree), _distribution(distribution)
            {}

            IOptionPricers* Clone() const;

            double GetValue(const OptionPricer::IOptionType* option);
        private:
            double                          _vol;
            double                          _riskFree;
            const OptionPricer::IDistribution*    _distribution;
    };

}
#endif //OPTIONPRICER_BLACKSCHOLES_H
