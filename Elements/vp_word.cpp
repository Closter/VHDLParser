#include "vp_word.h"

VP_Word::VP_Word(QObject *parent) :
  QObject(parent)
{
  word = "";
}


VP_Word::VP_Word(QString word_l, int lineNumber_l, int colNumber_l, VP_Word *previous, VP_Word *next, QObject *parent) :
  QObject(parent)
{
  // Update word's member
  word        = word_l;
  lineNumber  = lineNumber_l;
  colNumber   = colNumber_l;

  previousWord  = previous;
  nextWord      = next;
}


/**
 * @brief VP_Word::text
 * @return The text of this word.
 */
QString VP_Word::text()
{
  return word;
}


/**
 * @brief VP_Word::getLine
 * @return The line number of this word in the original file
 */
int VP_Word::getLine()
{
  return lineNumber;
}


/**
 * @brief VP_Word::getColumn
 * @return The column number of this word in the line
 */
int VP_Word::getColumn()
{
  return colNumber;
}


/**
 * @brief VP_Word::setNextWord Manage words chained list
 * @param next The next word in the line
 */
void VP_Word::setNextWord(VP_Word *next)
{
  nextWord = next;
}


/**
 * @brief VP_Word::setPreviousWord Manage words chained list
 * @param prev The previous word in the line
 */
void VP_Word::setPreviousWord(VP_Word *prev)
{
  previousWord = prev;
}


/**
 * @brief VP_Word::getNextWord Manage words chained list
 * @return next The next word in the line
 */
VP_Word *VP_Word::getNextWord()
{
  return nextWord;
}


/**
 * @brief VP_Word::getPreviousWord Manage words chained list
 * @return prev The previous word in the line
 */
VP_Word *VP_Word::getPreviousWord()
{
  return previousWord;
}



