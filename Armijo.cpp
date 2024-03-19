#include "Armijo.hpp"

void Armijo :: update_alpha(){
    double initial_alpha = alpha;

    for (std::size_t i = 0; i < max_it; ++i) {
        std::vector<double> gradient = Df(x0[0], x0[1]);
        std::vector<double> x1 = {x0[0] - alpha * gradient[0], x0[1] - alpha * gradient[1]};
        double decrease_condition = f(x0[0], x0[1]) - f(x1[0], x1[1]);

        if (decrease_condition >= -0.1 * alpha * euclidian_norm(gradient)) {
            break; // Sufficient decrease condition met
        } else {
            alpha *= 0.5; // Reduce alpha
        }
    }

    // If max iterations reached, restore initial alpha
    if (alpha == initial_alpha) {
        alpha = initial_alpha;
    }
}
