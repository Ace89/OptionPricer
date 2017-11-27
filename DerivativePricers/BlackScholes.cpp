//
// Created by awais.talib.
//

#include "BlackScholes.h"

namespace OptionPricer
{
    IOptionPricers* BlackScholes::Clone() const
    {
        return new BlackScholes(*this);
    }

    double BlackScholes::GetValue(const OptionPricer::IOptionType* option)
    {
        // throw an error if option is an American put or if either the spot or strike is not a variable
        double d1, d2,price;
        double dt = option->GetMaturity();
        d1 = (std::log(option->GetSpot()/option->GetStrike()) + (_riskFree +_vol*_vol*0.5)*dt)/(_vol*std::sqrt(dt));
        d2 = d1 - _vol*std::sqrt(dt);

        if(option->GetPayoffType() == OptionPricer::PayoffType::Call)
        {
            price = option->GetSpot()*_distribution->GetCdf(d1) -
                    std::exp(-_riskFree*option->GetMaturity())*option->GetStrike()*_distribution->GetCdf(d2);
        }else
        {
            price = std::exp(-_riskFree*option->GetMaturity())*option->GetStrike()*_distribution->GetCdf(-d2) -
                    option->GetSpot()*_distribution->GetCdf(-d1);
        }

        return price;
    }


}


