#include "Melancholy/Core.h"
#include "Melancholy/Core/Application.h"

using namespace Melancholy;

class SandboxApp : public Application {
public:
    ~SandboxApp() override = default;

    bool Create() override {
        MTRACE("Creating sandbox app...");
        return true;
    }
};

int main() {
    Application* app = new SandboxApp();
    app->Run();
    delete app;
}