//
// Created by awais.talib.
//

#ifndef OPTIONPRICER_OPTIONFACTORY_H
#define OPTIONPRICER_OPTIONFACTORY_H

#include "Derivatives/EuropeanCall.h"

namespace OptionPricer
{

    class OptionFactory
    {
        private:

        public:

            OptionFactory(){}

            IOptionType* CreateOption(double spot,
                                     double strike,
                                     double maturity,
                                     OptionPricer::ExerciseType exerciseType,
                                     OptionPricer::PayoffType payoffType);

            // To be used for exotic options such as asians for pricing in monte carlo
            IOptionType* CreateOption(std::vector<double>& spotStrip,
                                     double strike,
                                     double maturity,
                                     OptionPricer::ExerciseType exerciseType,
                                     OptionPricer::PayoffType payoffType);

            // To be used for exotic options such as lookbacks etc for pricing in monte carlo
            IOptionType* CreateOption(double spot,
                                     std::vector<double>& strikeStrip,
                                     double maturity,
                                     OptionPricer::ExerciseType exerciseType,
                                     OptionPricer::PayoffType payoffType);
    };

}


#endif //OPTIONPRICER_OPTIONFACTORY_H
