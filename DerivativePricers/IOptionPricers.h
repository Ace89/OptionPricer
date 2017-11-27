//
// Created by awais.talib.
//

#ifndef OPTIONPRICER_IOPTIONPRICERS_H
#define OPTIONPRICER_IOPTIONPRICERS_H

#include "../Derivatives/IOptionType.h"

namespace OptionPricer
{

    class IOptionPricers
    {
        protected:

        public:
            IOptionPricers(){}

            ~IOptionPricers()
            {
                std::cout<<"Deleting option pricer"<<std::endl;
            }

            virtual IOptionPricers* Clone() const =0;

            virtual double GetValue(const OptionPricer::IOptionType* option) = 0;
    };

}

#endif //OPTIONPRICER_IOPTIONPRICERS_H
