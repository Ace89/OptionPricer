//
// Created by awais.talib.
//

#ifndef OPTIONPRICER_IDISTRIBUTION_H
#define OPTIONPRICER_IDISTRIBUTION_H

#include <iostream>

namespace OptionPricer
{
    class IDistribution
    {
        private:

        public:

            IDistribution(){}
            ~IDistribution()
            {
                std::cout<<"Deleting distribution object"<<std::endl;
            }

            virtual IDistribution* Clone() const =0;

            virtual double GetPdf(double x) const = 0;
            virtual double GetCdf(double x) const = 0;
    };
}

#endif //OPTIONPRICER_IDISTRIBUTION_H
