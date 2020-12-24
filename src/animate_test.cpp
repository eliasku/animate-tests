#include "animate_test.hpp"

#include <ek/scenex/systems/main_flow.hpp>
#include <ek/scenex/data/SGFile.hpp>
#include <ek/scenex/base/Node.hpp>
#include <ek/scenex/asset2/builtin_assets.hpp>
#include <ek/scenex/2d/Transform2D.hpp>
#include <ek/scenex/2d/Camera2D.hpp>

namespace ek {

void main() {
    run_app<TestFlashApp>({"TestFlashApp", {1024, 768}});
}
}

using namespace ek;

TestFlashApp::TestFlashApp() : basic_application() {
}

void TestFlashApp::initialize() {
    basic_application::initialize();
    Camera2D::Main.get<Camera2D>().clearColorEnabled = true;
    Camera2D::Main.get<Camera2D>().clearColor = float4{0xFF666666_argb};
}

void TestFlashApp::preload() {
    basic_application::preload();
}

void TestFlashApp::update_frame(float dt) {
    basic_application::update_frame(dt);

    scene_pre_update(root, dt);

    //update_game_title_start(w);
    scene_post_update(root);
}

void TestFlashApp::render_frame() {
    if (started_) {
        basic_application::render_frame();
    }
}

void TestFlashApp::start_game() {
    ecs::get<Transform2D>(game).position.y += 100;
//    append(game, sg_create("patch9", "nine_patch_test"));
//    append(game, sg_create("tests", "test"));
    append(game, sg_create("demo_res", "icon"));
//    append(game, sg_create("test_0", "test"));
//    asset_t<sg_file> file{"test"};
//    if (!file.empty()) {
//        append(game, sg_create("test", file->scenes[0]));
//    }

//    append(game, sg_create("improvements", "scene3"));
//    append(game, sg_create("improvements", "scene1"));
//    auto an = sg_create("improvements", "scene2");
//    append(game, an);
//    ecs::get<transform_2d>(an).position.y += 500;
}

TestFlashApp::~TestFlashApp() = default;
