//
// Created by awais.talib.
//

#ifndef OPTIONPRICER_EUROPEANCALL_H
#define OPTIONPRICER_EUROPEANCALL_H

#include "IOptionType.h"
#include <cmath>

namespace OptionPricer
{
    class EuropeanCall : public IOptionType
    {
        public:
            EuropeanCall(){}

            ~EuropeanCall()
            {
                std::cout<<"Euro call object is being deleted"<<std::endl;
            }

            IOptionType* Clone() const;

            double GetPayOff(double spot, double strike) const;

            double GetPayOff(double spot, const std::vector<double>& strikeStrip) const;

            double GetPayOff(const std::vector<double>& spotStrip, double strike) const;

        private:
    };
}

#endif //OPTIONPRICER_EUROPEANCALL_H
