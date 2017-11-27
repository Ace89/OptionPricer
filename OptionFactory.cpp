//
// Created by awais.talib.
//

#include "OptionFactory.h"

namespace OptionPricer
{

    IOptionType* OptionFactory::CreateOption(double spot,
                                            double strike,
                                            double maturity,
                                            OptionPricer::ExerciseType exerciseType,
                                            OptionPricer::PayoffType payoffType)
    {
            IOptionType* option = new OptionPricer::EuropeanCall();
            option->SetExerciseType(exerciseType);
            option->SetMaturity(maturity);
            option->SetPayoffType(payoffType);
            option->SetSpot(spot);
            option->SetStrike(strike);
            return option;
    }

    IOptionType* OptionFactory::CreateOption(double spot,
                                            std::vector<double>& strikeStrip,
                                            double maturity,
                                            OptionPricer::ExerciseType exerciseType,
                                            OptionPricer::PayoffType payoffType)
    {
        IOptionType* option = new OptionPricer::EuropeanCall();
        option->SetExerciseType(exerciseType);
        option->SetMaturity(maturity);
        option->SetPayoffType(payoffType);
        option->SetSpot(spot);
        option->SetStrike(strikeStrip);
        return option;
    }

    IOptionType* OptionFactory::CreateOption(std::vector<double>& spotStrip,
                                            double strike,
                                            double maturity,
                                            OptionPricer::ExerciseType exerciseType,
                                            OptionPricer::PayoffType payoffType)
    {
        IOptionType* option = new OptionPricer::EuropeanCall();
        option->SetExerciseType(exerciseType);
        option->SetMaturity(maturity);
        option->SetPayoffType(payoffType);
        option->SetSpot(spotStrip);
        option->SetStrike(strike);
        return option;
    }

}



