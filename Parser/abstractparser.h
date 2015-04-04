#ifndef ABSTRACTPARSER_H
#define ABSTRACTPARSER_H

#include <QObject>

#include "keyword.h"

class AbstractParser : public QObject
{
  Q_OBJECT
public:
  explicit AbstractParser(QObject *parent = 0);


  QList<Word*> parseText(QString text);


  // Accessors
  //----------
  void addKeyWord(QString word)      ///< Append a new Keyword in the list
  {
    m_keyWordList << word;
  }

  QList<QString> &operator<<(QString word)    ///< Append a new Keyword in the list
  {
    addKeyWord(word);
    return m_keyWordList;
  }
  //----------


private:

  QStringList splitByKeyword(QString &str);
  KeyWord *searchForAKeyWord(QString str);
  bool isKeyword(QString word);


  QList<QString> m_keyWordList;    ///< The list of keyword to analyze
};

#endif // ABSTRACTPARSER_H
