#include <iostream>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <math.h>

using tp = std::tuple<double, double,double , double>;

#define  ESCAPE_THRESHOLD (double)6
#define MAX_ITERATIONS (double)255

class drawing {
private:
    static tp IterateUntilEscape(double x0, double y0);
    static sf::Color Get_color(double numIteration);
    static double Get_mu(double numIterations, double escapeDistance);
public:
    static void DrawFractal(tp, tp);
};