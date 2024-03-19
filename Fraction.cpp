#include "Fraction.hpp"

void Fraction :: update_alpha(){
    alpha = alpha_0/(0.2*Current_it +1);
}

std::vector<double> Fraction :: gradient_discent(){
     std::size_t j = 0;

    while (j < max_it) {
        Current_it = j;
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