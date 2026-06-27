#include "systems/App.h"
#include "core/VaultEntry.h"

int main() {
    App app;
    if(!app.init()) return 1;

    // test entry
    VaultEntry entry("Netflix", "myemail@gmail.com", "abc123", "netflix.com", "streaming", "2024-01-15", Category::LOGIN);
    app.addEntry(entry);

    app.run();
    app.shutdown();
}