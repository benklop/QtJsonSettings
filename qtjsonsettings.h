#ifndef QTJSONSETTINGS_H
#define QTJSONSETTINGS_H

#include <QtCore/QCoreApplication>
#include <QtCore/QString>
#include <QtCore/QSettings>

class QIODevice;

#if defined(QTJSONSETTINGS_EXPORTS)
#  define QTJSONSETTINGS_EXPORT Q_DECL_EXPORT
#elif defined(QTJSONSETTINGS_IMPORTS)
#  define QTJSONSETTINGS_EXPORT  Q_DECL_IMPORT  /**/
#else
#  define QTJSONSETTINGS_EXPORT   /**/
#endif

/**
 * @brief Class for storing application setting in xml file. This class implements QSettings interface.
 *
 * @class QtXmlSettings qtxmlsettings.h
 */
class QTJSONSETTINGS_EXPORT QtJsonSettings: public QSettings
{
  Q_OBJECT
  public:
    static const QSettings::Format json_format;

    static bool readJsonFile(QIODevice &device, QSettings::SettingsMap &map);
    static bool writeJsonFile(QIODevice &device,
      const QSettings::SettingsMap &map);
};

#endif // #ifndef QTJSONSETTINGS_H
