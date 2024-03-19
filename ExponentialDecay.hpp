#ifndef EXPONENTIALDECAY_HPP
#define EXPONENTIALDECAY_HPP
#include "minimum.hpp"

class ExponentialDecay : public minimum {
        private :
            void update_alpha() override;
            double alpha_0 = 0;
            std::size_t Current_it = 0;
        public:
            ExponentialDecay(const Fun& f_,const Function& Df_,double ep,double to,double it,const std::vector<double>& x_0,double alp):minimum(f_,Df_,ep,to,it,x_0,alp){alpha_0=alpha;};
            std::vector<double> gradient_discent() override;
            double get_alpha_0()const{return alpha_0;};
};

#endif //EXPONENTIALDECAY_HPP