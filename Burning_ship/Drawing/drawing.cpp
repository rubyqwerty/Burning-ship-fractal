#include "drawing.h"

tp drawing::IterateUntilEscape(double x0, double y0) {
    double x = 0, y = 0, numIterations = 0;
    while ((x*x + y*y < ESCAPE_THRESHOLD) && (numIterations < MAX_ITERATIONS)) {
        double x_next = x*x - y*y + x0;
        double y_next = 2*abs(x*y) + y0;
        x = x_next, y = y_next;
        numIterations++;
    }
    return {numIterations, x*x + y*y, 0, 0};
}

sf::Color drawing::Get_color(double numIteration) {
    return {
        255,
        (sf::Uint8)(numIteration * 7),
        0,
       (sf::Uint8)(numIteration * 15)
    };
}

double drawing::Get_mu(double numIterations, double escapeDistance) {
    return numIterations + 1 - log(escapeDistance) / log(2);
}

void drawing::DrawFractal(tp Xrange, tp Yrange) {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Горящие корабли");
    double Width = window.getSize().x;
    double Height = window.getSize().y;

    sf::VertexArray pointmap(sf::Points, 2000 *2000);

    for (int i = 0; i < Height; i++) {
        for (int j = 0; j < Width; j++) {
            double x0 = std::get<0>(Xrange) + j*(std::get<1>(Xrange) - std::get<0>(Xrange)) / Width;
            double y0 = std::get<0>(Yrange) + i*(std::get<1>(Yrange) - std::get<0>(Yrange)) / Height;

            double pixelIndex = 4*i*Width +  4*j;

            auto coor = IterateUntilEscape(x0, y0);
            if (std::get<0>(coor) != MAX_ITERATIONS) {
                auto mu = Get_mu(std::get<0>(coor), std::get<1>(coor));
                pointmap[pixelIndex].position = sf::Vector2f(j, i);
                pointmap[pixelIndex].color = Get_color(mu);
            }
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(pointmap);
        window.display();
    }


}
