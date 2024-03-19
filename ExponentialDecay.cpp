#include "ExponentialDecay.hpp"

void ExponentialDecay :: update_alpha(){
    //std::cout<<"iteration= "<<Current_it<<"alpha_0= "<<alpha_0<<std::endl;
    alpha = alpha_0/(std::exp(0.2*Current_it));
    //std::cout<<"alpha= "<<alpha<<std::endl;
}

std::vector<double> ExponentialDecay:: gradient_discent(){

    while (Current_it < max_it) {
        update_alpha();
        std::vector<double> x_old = x0;
        std::vector<double> gradient = Df(x0[0], x0[1]);

        x0[0] -= alpha * gradient[0];
        x0[1] -= alpha * gradient[1];

        std::vector<double> x_cond = {x0[0] - x_old[0], x0[1] - x_old[1]};

        if (euclidian_norm(gradient) < tol || euclidian_norm(x_cond) < eps) {
            break;
        }
        ++Current_it;
    }

    if (Current_it < max_it) {
        convergence = true;
    }

    return x0;
}
