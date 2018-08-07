#include "BrowserExtension.hpp"
#include "RunGui.hpp"
#include "singletons/Paths.hpp"
#include "singletons/Settings.hpp"

#include <QApplication>
#include <QStringList>

#include <messages/Image.hpp>

using namespace chatterino;

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    // convert char** to QStringList
    auto args = QStringList();
    std::transform(argv + 1, argv + argc, std::back_inserter(args),
                   [&](auto s) { return s; });

    // run in gui mode or browser extension host mode
    if (shouldRunBrowserExtensionHost(args)) {
        runBrowserExtensionHost();
    } else {
        Paths paths;
        Settings settings(paths);

        runGui(a, paths, settings);
    }
}
