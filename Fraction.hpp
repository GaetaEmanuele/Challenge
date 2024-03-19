#ifndef FRACTION_HPP
#define FRACTION_HPP
#include "minimum.hpp"

class Fraction : public minimum {
        private :
            void update_alpha() override;
            double alpha_0 = alpha;
            std::size_t Current_it =0;
        public:
            Fraction(const Fun& f_,const Function& Df_,double ep,double to,double it,const std::vector<double>& x_0,double alp):minimum(f_,Df_,ep,to,it,x_0,alp){};
            std::vector<double> gradient_discent() override;
};

#endif //EXPONENTIALDECAY_HPP