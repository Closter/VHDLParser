#ifndef ABSTRACTPARSER_H
#define ABSTRACTPARSER_H

#include <QObject>

#include "keyword.h"

class AbstractParser : public QObject
{
  Q_OBJECT
public:
  explicit AbstractParser(QObject *parent = 0);


  QList<Word*> parse(QString &text);


  // Accessors
  //----------
  void addKeyWord(QString word)      ///< Append a new Keyword in the list
  {
    m_specCharList << word;
  }

  QList<QString> &operator<<(QString word)    ///< Append a new Keyword in the list
  {
    addKeyWord(word);
    return m_specCharList;
  }

  void addLineCommentId(QString lineComment)  ///< Append a new line comment
  {
    m_lineComment << lineComment;
  }
  //----------


private:

  QStringList splitByKeyword(QString &str);
  KeyWord *searchForAKeyWord(QString str);
  bool isKeyword(QString word);
  bool isNewLine(QString word);


  QList<QString> m_specCharList;  ///< The list of keyword to analyze
  QList<QString> m_lineComment;   ///< The list of line comment identifiers
};

#endif // ABSTRACTPARSER_H
