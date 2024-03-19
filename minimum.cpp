#include "minimum.hpp"
double minimum :: euclidian_norm(const std:: vector<double>& x)const{
    return std::sqrt(x[0]*x[0]+x[1]*x[1]);
} 
std::vector<double> minimum:: gradient_discent(){
     std::size_t j = 0;

    while (j < max_it) {
        update_alpha();
        std::vector<double> x_old = x0;
        std::vector<double> gradient = Df(x0[0], x0[1]);

        x0[0] -= alpha * gradient[0];
        x0[1] -= alpha * gradient[1];

        std::vector<double> x_cond = {x0[0] - x_old[0], x0[1] - x_old[1]};

        if (euclidian_norm(gradient) < tol || euclidian_norm(x_cond) < eps) {
            break;
        }

        ++j;
    }

    if (j < max_it) {
        convergence = true;
    }

    return x0;
}


