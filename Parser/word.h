#ifndef WORD_H
#define WORD_H

#include <QObject>
#include <QPoint>

/**
 * @brief The Word class describe a word that compose a text to analyze.
 */
class Word : public QObject
{
  Q_OBJECT
public:
  explicit Word(QString text, int lineNumber = -1, int colNumber = -1, bool isEOL = false, bool isComment = false, Word *previous = 0, Word *next = 0, QObject *parent = 0);

  Word *nextWord(bool onlyCode = false);
  Word *previousWord(bool onlyCode = false);

  Word *nextWord(int nbWord, bool onlyCode = false);
  Word *previousWord(int nbWord, bool onlyCode = false);


  // Accessors
  //----------
  QString getText() ///< Return the string of this word
  {
    return m_wordText;
  }

  QPoint getPos() ///< Return the word position with x the line number and y the column number
  {
    return m_position;
  }

  int getLine() ///< Return the line number where this word is
  {
    return m_position.x();
  }

  int getColumn()  ///< Returne the column number of this word in the line, 0 based
  {
    return m_position.y();
  }

  void setNextWord(Word *next)
  {
    m_nextWord = next;
  }

  void setPreviousWord(Word *prev)
  {
    m_previousWord = prev;
  }

  bool isEOL()
  {
    return m_isEOL;
  }

  bool isComment()
  {
    return m_isComment;
  }

  //----------


private:

  QString m_wordText;   ///< The word's text
  QPoint  m_position;   ///< Position in the text : x for the line number and y for the column number

  // Chained list of word
  Word  *m_previousWord;  ///< The previous word in the line
  Word  *m_nextWord;      ///< The next word in the line

  bool m_isEOL;             ///< Flag indicating that the word is an end of line
  bool m_isComment;         ///< Flag indicating that the word is a comment
};

#endif // WORD_H
