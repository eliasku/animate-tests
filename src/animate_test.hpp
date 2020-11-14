#pragma once

#include <ek/scenex/app/basic_application.hpp>

class TestFlashApp : public ek::basic_application {
public:
    TestFlashApp();

    ~TestFlashApp() override;

    void initialize() override;

    void preload() override;

protected:
    void update_frame(float dt) override;

    void render_frame() override;

    void start_game() override;
};

