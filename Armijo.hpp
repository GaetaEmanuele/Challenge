#ifndef ARMIJO_HPP
#define ARMIJO_HPP
#include "minimum.hpp"
class Armijo : public minimum {
        private :
            void update_alpha() override;
            double alpha_0 = alpha;
        public:
            Armijo(const Fun& f_,const Function& Df_,double ep,double to,double it,const std::vector<double>& x_0,double alp):minimum(f_,Df_,ep,to,it,x_0,alp){};
            
};

#endif //ARMIJO_HPP