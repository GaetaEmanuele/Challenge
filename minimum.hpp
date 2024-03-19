#ifndef MINIMUM_HPP
#define MINIMUM_HPP
#include<iostream>
#include<vector>
#include<functional>
#include <cmath>

class minimum {
    protected:
        using Fun = std :: function<double(const double&,const double&)>;
        using Function = std :: function<std::vector<double>(const double&,const double&)>;
        double eps;
        double tol;
        std::size_t max_it;
        Fun f;
        Function Df;
        std::vector<double> x0;
        double alpha;
        double euclidian_norm(const std::vector<double>& x)const;
        virtual void update_alpha()=0;
        bool convergence = false;
    public:
        minimum(const Fun& f_,const Function& Df_,double eps_,double tol_,std::size_t it,const std::vector<double>& x_init,double alpha_):f(f_),Df(Df_),eps(eps_),tol(tol_),max_it(it),x0(x_init),alpha(alpha_){};
        //minimum(utility u):minimum(u.f,u.Df,u.eps,u.tol,u.max_it,u.x0,u.alpha){};
        virtual std::vector<double> gradient_discent();
        bool is_converged()const{return convergence;};
};

#endif //MINIMUM_HPP