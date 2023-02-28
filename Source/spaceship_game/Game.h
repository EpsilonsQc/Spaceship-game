#pragma once

namespace Core
{
    class Game
    {
    protected:
        Game();
        bool _keepPlaying;

    public:
        virtual ~Game();

        void loop();

        virtual void handleInput() = 0;
        virtual void update() = 0;
        virtual void render() const = 0;
    };
}
