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
    Gosu::Sample sample;
    std::vector<Gosu::Touch> current_touches;

public:
    GameWindow()
            : Window(Gosu::screen_width(), Gosu::screen_height(), Gosu::WF_FULLSCREEN), font(128, "daniel.ttf"), sample("beep.wav")
    {
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

        double ratio =  width() * (Gosu::fps() / 60.0) - 20;
        Gosu::Graphics::draw_rect(10, 10 + HEIGHT + WIDTH + 10, ratio, 20, 0xff008800, 0);

        if (Gosu::milliseconds() > 2000) {
            font.draw_text("Hello World", 10, 400, 10);
        }

        font.draw_text(std::string("FPS: " + std::to_string(Gosu::fps())), 10, 700, 10);
        font.draw_text(std::string("Width: " + std::to_string(width()) + "\nHeight: " + std::to_string(height())), 10, 828, 10);

        logo.draw(10, 500, 10, 10, 10);

        for (int i = 0; i < current_touches.size(); ++i) {
            Gosu::Touch touch = current_touches[i];
            int size = 128;

            Gosu::Graphics::draw_rect((touch.x) - size / 2.0, (touch.y) - size / 2.0, size, size, Gosu::Color::AQUA, 10);
        }
    }

    void touch_began(Gosu::Touch touch) override
    {
        __android_log_print(android_LogPriority::ANDROID_LOG_VERBOSE, "Gosu", "Touch began: id: %i, x: %f, y: %f\n", touch.sdl_id, touch.x, touch.y);
        current_touches.emplace_back(touch);

        sample.play(1, 1, false);
    }

    void touch_moved(Gosu::Touch touch) override
    {
        __android_log_print(android_LogPriority::ANDROID_LOG_VERBOSE, "Gosu", "Touch moved: id: %i, x: %f, y: %f\n", touch.sdl_id, touch.x, touch.y);

        for (int i = 0; i < current_touches.size(); ++i) {
            Gosu::Touch *_touch = &current_touches.at(i);

            if (touch.sdl_id == _touch->sdl_id)
            {
                _touch->x = touch.x;
                _touch->y = touch.y;
                break;
            }
        }
    }

    void touch_ended(Gosu::Touch touch) override
    {
        __android_log_print(android_LogPriority::ANDROID_LOG_VERBOSE, "Gosu", "Touch ended: id: %i, x: %f, y: %f\n", touch.sdl_id, touch.x, touch.y);

        for (int i = 0; i < current_touches.size(); ++i) {
            Gosu::Touch _touch = current_touches.at(i);

            if (touch.sdl_id == _touch.sdl_id)
            {
                current_touches.erase(current_touches.begin(), current_touches.begin() + i);
            }
        }
    }
};

int main(int argc, char *argv[])
{
    GameWindow window;
    window.show();
    return 0;
}
