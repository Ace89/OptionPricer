//
// Created by awais.talib.
//

#include "IOptionType.h"
#include <stdexcept>

namespace OptionPricer
{

    void IOptionType::SetSpot(double spot)
    {
        this->_spot = spot;
    }

    void IOptionType::SetSpot(const std::vector<double>& spotStrip)
    {
        this->_spotStrip = spotStrip;
    }

    void IOptionType::SetStrike(double strike)
    {
        this->_strike = strike;
    }

    void IOptionType::SetStrike(const std::vector<double>& strikeStrip)
    {
        this->_strikeStrip = strikeStrip;
    }

    void IOptionType::SetMaturity(double maturity)
    {
        this->_maturity = maturity;
    }

    void IOptionType::SetExerciseType(OptionPricer::ExerciseType type)
    {
        this->_exerciseType = type;
    }

    void IOptionType::SetPayoffType(OptionPricer::PayoffType payoffType)
    {
        this->_payoff = payoffType;
    }

    double IOptionType::GetSpot() const
    {
        return this->_spot;
    }

    std::vector<double> IOptionType::GetSpotStrip() const
    {
        if(this->_spotStrip.empty())
            throw std::invalid_argument("spot vector is empty");

        return this->_spotStrip;
    }

    double IOptionType::GetStrike() const
    {
        return this->_strike;
    }

    std::vector<double> IOptionType::GetStrikeStrip() const
    {
        if(this->_strikeStrip.empty())
            throw std::invalid_argument("strike vector is empty");

        return this->_strikeStrip;
    }

    double IOptionType::GetMaturity() const
    {
        return this->_maturity;
    }

    OptionPricer::ExerciseType IOptionType::GetExerciseType() const
    {
        return this->_exerciseType;
    }

    OptionPricer::PayoffType IOptionType::GetPayoffType() const
    {
        return this->_payoff;
    }

}

