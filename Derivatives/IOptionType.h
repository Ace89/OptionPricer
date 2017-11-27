//
// Created by awais.talib.
//

#ifndef OPTIONPRICER_OPTIONTYPE_H
#define OPTIONPRICER_OPTIONTYPE_H

#include <iostream>
#include <vector>

namespace OptionPricer {
    /*
     * Designed to be an abstract base class
     * */
    enum ExerciseType
    {
        European,
        American,
        Bermudan
    };

    enum PayoffType
    {
        Call,
        Put
    };

    class IOptionType
    {
        public:

            IOptionType(){}

            ~IOptionType()
            {
                std::cout<<"Option type object is being deleted"<<std::endl;
            }

            // Cannot have virtual copy constructors so using a clone method
            virtual IOptionType* Clone() const =0;

            void SetSpot(double spot);

            void SetSpot(const std::vector<double>& spotStrip);

            void SetStrike(double strike);

            void SetStrike(const std::vector<double>& strikeStrip);

            void SetMaturity(double maturity);

            void SetExerciseType(OptionPricer::ExerciseType type);

            void SetPayoffType(OptionPricer::PayoffType payoffType);

            double GetSpot() const;

            std::vector<double> GetSpotStrip() const;

            double GetStrike() const;

            std::vector<double> GetStrikeStrip() const;

            double GetMaturity() const;

            OptionPricer::ExerciseType GetExerciseType() const;

            OptionPricer::PayoffType GetPayoffType() const;

            virtual double GetPayOff(double spot, double strike) const = 0;

            virtual double GetPayOff(double spot, const std::vector<double>& strikeStrip) const = 0;

            virtual double GetPayOff(const std::vector<double>& spotStrip, double strike) const = 0;

        protected:  // if I set these to private then only friend class will have access
            std::vector<double> _spotStrip;
            std::vector<double> _strikeStrip;
            double              _spot;
            double              _strike;
            double              _maturity;
            ExerciseType        _exerciseType;
            PayoffType          _payoff;
    };
}

#endif //OPTIONPRICER_OPTIONTYPE_H
