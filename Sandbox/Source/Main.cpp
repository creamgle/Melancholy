#include <Melancholy/Core.h>

using namespace Melancholy;

int main() {
    MFATAL("This is a test... {}", 3.14f);
    MERROR("This is a test... {}", 3.14f);
    MWARN("This is a test... {}", 3.14f);
    MINFO("This is a test... {}", 3.14f);
    MTRACE("This is a test... {}", 3.14f);
    MDEBUG("This is a test... {}", 3.14f);

    MASSERT(true == false, "This is a test assert");
}