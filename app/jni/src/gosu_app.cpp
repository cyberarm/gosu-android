#include <Gosu/Gosu.hpp>
#include <SDL.h>
#include <android/log.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <jni.h>

class GameWindow : public Gosu::Window
{
#define WIDTH 16.0
#define HEIGHT 128.0
#define COLOR 0xffffffff
    Gosu::Font font;
    Gosu::Image logo;

public:
    GameWindow()
            : Window(Gosu::screen_width(), Gosu::screen_height(), Gosu::WF_FULLSCREEN | Gosu::WF_RESIZABLE), font(128, "daniel.ttf")
    {

        resize(Gosu::screen_width(), Gosu::screen_height(), resizable());
        __android_log_print(android_LogPriority::ANDROID_LOG_VERBOSE, "Gosu", "SCREEN Width: %d, Height: %d\n", Gosu::screen_width(), Gosu::screen_height());
        __android_log_print(android_LogPriority::ANDROID_LOG_VERBOSE, "Gosu", "Width: %d, Height: %d\n", width(), height());
        __android_log_print(android_LogPriority::ANDROID_LOG_VERBOSE, "Gosu", "Font: %s, size: %d\n", font.name().c_str(), font.height());

        logo = Gosu::Image("gosu.png");
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
        Gosu::Graphics::draw_rect(28 + HEIGHT + HEIGHT / 8, 28, WIDTH, HEIGHT, COLOR, 0);
        Gosu::Graphics::draw_rect(28 + HEIGHT - 5, 28, HEIGHT / 2, WIDTH, COLOR, 0);
        Gosu::Graphics::draw_rect(28 + HEIGHT - 5, 28 + HEIGHT - WIDTH, HEIGHT / 2, WIDTH, COLOR, 0);

        double ratio =  width() * (60.0 / Gosu::fps()) - 20;
        Gosu::Graphics::draw_rect(10, 10 + HEIGHT + WIDTH + 10, ratio, 20, 0xff008800, 0);

        if (Gosu::milliseconds() > 2000) {
            font.draw_text("Hello World", 10, 400, 10);
            font.draw_text(std::string("FPS: " + std::to_string(Gosu::fps())), 10, 700, 10);
        }

        logo.draw(10, 500, 10, 10, 10);
    }
};

int main(int argc, char *argv[])
{
    GameWindow window;
    window.show();
    return 0;
}
