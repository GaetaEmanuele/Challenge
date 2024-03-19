#include <iostream>
#include <vector>
#include <functional>
#include "data.h"
#include "minimum.hpp"
#include "Armijo.hpp"
#include "ExponentialDecay.hpp"
#include "Fraction.hpp"

enum Alpha{armijo,exponential,fractional};

double f (const double& x1,const double& x2){
        return (x1*x2 + 4*(x1*x1*x1*x1)+x2*x2+3*x1);
        };

std::vector<double> Df(const double& x1, const double& x2){
        std::vector<double>res(2);
        res[0] = x2+16*x1*x1*x1+3;
        res[1] = x1+2*x2;
        return res;
}
int main(int argc, char **argv){
        data u;
        Alpha choice = Alpha::armijo;
        switch (choice)
        {
        case armijo:{
                Armijo a(f,Df,u.eps,u.tol,u.max_it,u.x0,u.alpha);
                auto result = a.gradient_discent();
                std::cout<<"This is Armijo method"<<std::endl;
                std::cout<<"This are the coordinates of the global minimum:"<<std::endl;
                for(std::size_t i=0;i<result.size();++i){
                        std::cout<<result[i]<<" ";
                }
                double f_min = f(result[0],result[1]);
                std::cout<<std::endl;
                std::cout<<"the min value of the function is: "<<f_min<<std::endl;
                        break;}
        
        case exponential:{
                std::cout<<"This is Exponential method"<<std::endl;
                std::cout<<"This are the coordinates of the global minimum:"<<std::endl;
                ExponentialDecay e(f,Df,u.eps,u.tol,u.max_it,u.x0,u.alpha);
                auto result2 = e.gradient_discent();
                for(std::size_t i=0;i<result2.size();++i){
                        std::cout<<result2[i]<<" ";
                }
                std::cout<<std::endl;
                double f_min = f(result2[0],result2[1]);
                std::cout<<"the min value of the function is: "<<f_min<<std::endl;
                break;}
        case fractional:{
                std::cout<<"This is Ratio method"<<std::endl;
                std::cout<<"This are the coordinates of the global minimum:"<<std::endl;
                Fraction fr(f,Df,u.eps,u.tol,u.max_it,u.x0,u.alpha);
                auto result3 = fr.gradient_discent();
                for(std::size_t i=0;i<result3.size();++i){
                        std::cout<<result3[i]<<" ";
                }
                std::cout<<std::endl;
                double f_min = f(result3[0],result3[1]);
                std::cout<<"the min value of the function is: "<<f_min<<std::endl;
                break;}

        }
        return 0;
}