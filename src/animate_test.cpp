#include "animate_test.hpp"

#include <ek/scenex/systems/main_flow.hpp>
#include <ek/scenex/scene_system.hpp>
#include <ek/scenex/3d/static_mesh.hpp>
#include <ek/scenex/components/node.hpp>
#include <ek/scenex/data/sg_factory.hpp>
#include <ek/scenex/asset2/builtin_assets.hpp>
#include <ek/scenex/components/transform_2d.hpp>

namespace ek {

void main() {
    app::g_app.window_cfg = {"TestFlashApp", {1024, 768}};
    app::g_app.on_device_ready << [] {
        run_app<TestFlashApp>();
    };
    start_application();
}
}

using namespace ek;

TestFlashApp::TestFlashApp()
        : base_app_type() {
}

void TestFlashApp::initialize() {
    base_app_type::initialize();
    clear_color = float4{0xFF666666_argb};
}

void TestFlashApp::preload() {
    base_app_type::preload();

    clear_color_enabled = true;
}

void TestFlashApp::update_frame(float dt) {
    base_app_type::update_frame(dt);

    scene_pre_update(root, dt);

    //update_game_title_start(w);
    scene_post_update(root, dt);
}

void TestFlashApp::render_frame() {
//    base_app_type::render_frame();
    if (!started_) return;

    draw_node(root);
}

void TestFlashApp::start_game() {
    ecs::get<transform_2d>(game).matrix.ty += 100;
//    append(game, sg_create("patch9", "nine_patch_test"));
    append(game, sg_create("tests", "test"));
//    append(game, sg_create("test_0", "test"));
//    asset_t<sg_file> file{"test"};
//    if (!file.empty()) {
//        append(game, sg_create("test", file->scenes[0]));
//    }

//    append(game, sg_create("improvements", "scene3"));
//    append(game, sg_create("improvements", "scene1"));
//    auto an = sg_create("improvements", "scene2");
//    append(game, an);
//    ecs::get<transform_2d>(an).matrix.ty += 500;
}

TestFlashApp::~TestFlashApp() = default;
