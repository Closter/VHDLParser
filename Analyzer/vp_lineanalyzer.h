#ifndef VP_LINEANALYZER_H
#define VP_LINEANALYZER_H

#include "StdTypes.h"

#include <QObject>

#include "Elements/vp_word.h"

/**
 * @brief The VP_LineAnalyzer class contains all the necessary to analyze
 * a line of code.
 */
class VP_LineAnalyzer : public QObject
{
  Q_OBJECT
public:
  explicit VP_LineAnalyzer(QString lineText_l, U32 lineNumber_l, QObject *parent = 0);

  QList<VP_Word*> getWordList();

signals:

public slots:

private:

  QStringList lookForSpecialSeparator(QString &str);


  QString lineText; ///< The line text
  U32     lineNumber; ///< The first line number in the file

};

#endif // VP_LINEANALYZER_H
