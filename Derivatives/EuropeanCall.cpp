//
// Created by awais.talib.
//

#include "EuropeanCall.h"

namespace OptionPricer
{

    IOptionType* EuropeanCall::Clone() const
    {

        return new EuropeanCall(*this);
    }

    double EuropeanCall::GetPayOff(double spot, double strike) const
    {
        return std::max(spot-strike,0.0);
    }

    double EuropeanCall::GetPayOff(const std::vector<double> &spotStrip, double strike) const
    {
        // This will not be used
        return 0.0;
    }

    double EuropeanCall::GetPayOff(double spot, const std::vector<double> &strikeStrip) const
    {
        // This will not be used
        return 0.0;
    }

}