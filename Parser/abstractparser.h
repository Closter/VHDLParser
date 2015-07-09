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
  void addSeparatorWord(QString word)      ///< Append a new Keyword in the list
  {
    m_separatorList << word;
  }

  QList<QString> &operator<<(QString word)    ///< Append a new Keyword in the list
  {
    addSeparatorWord(word);
    return m_separatorList;
  }

  void addLineCommentId(QString lineComment)  ///< Append a new line comment
  {
    m_lineComment << lineComment;
  }
  //----------


private:

  QStringList splitByKeyword(QString &str);
  KeyWord *searchForAKeyWord(QString str);
  bool isSeparator(QString word);
  bool isNewLine(QString word);


  QList<QString> m_separatorList;   ///< The list of separation word to analyze
  QList<QString> m_lineComment;     ///< The list of line comment identifiers
};

#endif // ABSTRACTPARSER_H
