#ifndef WORD_H
#define WORD_H

#include <QObject>

/**
 * @brief The Word class describe a word that compose a text to analyze.
 */
class Word : public QObject
{
  Q_OBJECT
public:
  explicit Word(QString text, int lineNumber = -1, int colNumber = -1, Word *previous = 0, Word *next = 0, QObject *parent = 0);


  // Accessors
  //----------
  QString getText() ///< Return the string of this word
  {
    return m_wordText;
  }

  int getLine() ///< Return the line number where this word is
  {
    return m_lineNumber;
  }

  int getColumn()  ///< Returne the column number of this word in the line, 0 based
  {
    return m_colNumber;
  }

  void setNextWord(Word *next)
  {
    m_nextWord = next;
  }

  void setPreviousWord(Word *prev)
  {
    m_previousWord = prev;
  }

  Word *getNextWord()
  {
    return m_nextWord;
  }

  Word *getPreviousWord()
  {
    return m_previousWord;
  }

  //----------


private:

  QString m_wordText;   ///< The word's text
  int     m_lineNumber; ///< Line number in the original file
  int     m_colNumber;  ///< Column number in the line

  // Chained list of word
  Word  *m_previousWord;  ///< The previous word in the line
  Word  *m_nextWord;      ///< The next word in the line
};

#endif // WORD_H
