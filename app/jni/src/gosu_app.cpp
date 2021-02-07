#include <Gosu/Gosu.hpp>
#include <SDL.h>

class GameWindow : public Gosu::Window
{
#define WIDTH 4
#define HEIGHT 28
#define COLOR 0xffffffff

public:
    GameWindow()
            : Window(Gosu::screen_width(), Gosu::screen_height())
    {
        set_caption("Gosu Tutorial Game");
    }

    void update() override
    {
    }

    void draw() override
    {
        Gosu::Graphics::draw_rect(0, 0, width(), height(), 0xff555555, 0);
        Gosu::Graphics::draw_rect(10, 10, width() - 20, height() - 20, 0xffff8800, 0);

        // H
        Gosu::Graphics::draw_rect(28, 28, WIDTH, HEIGHT, COLOR, 0);
        Gosu::Graphics::draw_rect(28, 28 + HEIGHT / 2 - WIDTH / 2, HEIGHT / 2, WIDTH, COLOR, 0);
        Gosu::Graphics::draw_rect(28 + HEIGHT / 2, 28, WIDTH, HEIGHT, COLOR, 0);

        // I
        Gosu::Graphics::draw_rect(28 + HEIGHT, 28, WIDTH, HEIGHT, COLOR, 0);
        Gosu::Graphics::draw_rect(28 + HEIGHT - 5, 28, HEIGHT / 2, WIDTH, COLOR, 0);
        Gosu::Graphics::draw_rect(28 + HEIGHT - 5, 28 + HEIGHT - WIDTH, HEIGHT / 2, WIDTH, COLOR, 0);
    }
};

int main(int argc, char *argv[])
{
    GameWindow window;
    window.show();
}
