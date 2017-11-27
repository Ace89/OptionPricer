cmake_minimum_required(VERSION 3.7)
project(OptionPricer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Derivatives/IOptionType.h Derivatives/IOptionType.cpp DataStruct.h TestMethods.h TestMethods.cpp Derivatives/EuropeanCall.h Derivatives/EuropeanCall.cpp DerivativePricers/IOptionPricers.h DerivativePricers/BlackScholes.h DerivativePricers/BlackScholes.cpp Distribution/IDistribution.h Distribution/GaussianDistribution.h Distribution/GaussianDistribution.cpp OptionFactory.h OptionFactory.cpp)
add_executable(OptionPricer ${SOURCE_FILES})