
#include <iostream>
#include "TestMethods.h"
#include "Distribution/IDistribution.h"
#include "Distribution/GaussianDistribution.h"
#include "Derivatives/IOptionType.h"
#include "Derivatives/EuropeanCall.h"
#include "DerivativePricers/IOptionPricers.h"
#include "DerivativePricers/BlackScholes.h"
#include "OptionFactory.h"

#include <stdlib.h>
#include <stdio.h>


using namespace OptionPricer;

int main() {

    //<----------------------------- Option Inputs ----------------------------->
    double spotPrice = 100.0;
    double strikePrice = 95.0;
    double maturity = 1.0;
    double riskFreeRate = 0.02;
    double vol = 0.125;
    double distMean = 0.0;
    double distVar = 1.0;
    OptionPricer::ExerciseType exerciseType = OptionPricer::ExerciseType::European;
    OptionPricer::PayoffType payOff = OptionPricer::PayoffType::Call;

    //<----------------------------- Create Objects ----------------------------->
    OptionPricer::IDistribution* distribution = new GaussianDistribution(distMean,distVar);
    OptionFactory* factory = new OptionFactory();
    IOptionType* option = factory->CreateOption(spotPrice,strikePrice,maturity,exerciseType,payOff);
    // testing clone functionality
    IOptionType* clonedOption = option->Clone();
    IOptionPricers* optionPrice = new BlackScholes(riskFreeRate,vol,distribution);

    //<----------------------------- Perform Calculations ----------------------->
    std::cout<<"Factory Option Price: ";
    std::cout<< optionPrice->GetValue(option) << std::endl;
    std::cout<<"Cloned Option Price: ";
    std::cout<< optionPrice->GetValue(clonedOption) << std::endl;

    //<----------------------------- Delete Objects ----------------------------->
    delete clonedOption;
    delete option;
    delete optionPrice;
    delete distribution;

    std::cout<< 25u-50<<std::endl;

    std::printf("%s",std::getenv("PYTHONPATH"));

    return 0;
}