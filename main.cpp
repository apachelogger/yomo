#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>

#include <KAboutData>
#include <KLocalizedString>

#include <KService>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    KAboutData aboutData("kubuntu-debug-installer",
                         i18n("Debug package installer"),
                         "1.0.0",
                         i18n("A debug package installer for Kubuntu"),
                         KAboutLicense::LicenseKey::GPL,
                         i18n("(C) 2010-2014 Harald Sitter"));

    aboutData.addAuthor(i18n("Harald Sitter"), QString(), QStringLiteral("sitter@kde.org"));

    qDebug() << "qt" << qVersion();
    qDebug() << "plugin paths" << app.libraryPaths();

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("FILES",
                                 i18n("Files to find debug packages for"));
    aboutData.setupCommandLine(&parser);
    parser.process(app);
    aboutData.processCommandLine(&parser);

    const auto files = parser.positionalArguments();
//    query = QStringLiteral("exist Exec and ('%1' =~ Name)").arg(term);
//    KService::List services = KServiceTypeTrader::self()->query(QStringLiteral("Application"), query);
    for (int i = 0; i < 5000000; ++i) {
        qDebug() << "loop";
        KService::List services;
        if (!services.isEmpty()) {
            qDebug() << "hai";
        }
    }

     return app.exec();
}
