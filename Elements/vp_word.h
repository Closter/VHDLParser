#ifndef VP_WORD_H
#define VP_WORD_H

#include <QObject>

/**
 * @brief The VP_Word class manage an word element. This is the base
 * of all the code analysis.
 */
class VP_Word : public QObject
{
  Q_OBJECT
public:
  explicit VP_Word(QObject *parent = 0);
  explicit VP_Word(QString word_l, int lineNumber_l = 0, int colNumber_l = 0, VP_Word *previous = NULL, VP_Word *next = NULL, QObject *parent = 0);

  QString text();
  int getLine();
  int getColumn();

  void setNextWord(VP_Word *next);
  void setPreviousWord(VP_Word *prev);
  VP_Word *getNextWord();
  VP_Word *getPreviousWord();



private:

  QString word;       ///< The word's text
  int     lineNumber; ///< Line number in the original file
  int     colNumber;  ///< Column number in the line

  // Chained list of word
  VP_Word *previousWord;  ///< The previous word in the line
  VP_Word *nextWord;      ///< The next word in the line

};

#endif // VP_WORD_H
