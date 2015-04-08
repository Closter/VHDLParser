#include "word.h"


Word::Word(QString text, int lineNumber, int colNumber, bool isComment, Word *previous, Word *next, QObject *parent) :
  QObject(parent)
{
  // Update word's member
  m_wordText    = text;
  m_lineNumber  = lineNumber;
  m_colNumber   = colNumber;

  m_previousWord  = previous;
  m_nextWord      = next;

  m_isComment = isComment;
}


/**
 * @brief Word::nextWord Return the word next to this word after nbWord.
 * nextWord(1) is equivalent to nextWord().
 * @param nbWord Nb word to skip
 * @return NULL if no word exists or a pointer to the corresponding word.
 */
Word *Word::nextWord(int nbWord)
{
  Word *next = this;  // Start at this word

  for(int i=0; i<nbWord; i++)
  {
    if(next->nextWord() != NULL)  // Word exists
      next = next->nextWord();    // Jump to this word
    else
      return NULL;                // No word after this position
  }

  return next;
}


/**
 * @brief Word::previousWord Return the word befor to this word skipping nbWord.
 * previousWord(1) is equivalent to previousWord().
 * @param nbWord Nb word to skip
 * @return NULL if no word exists or a pointer to the corresponding word.
 */
Word *Word::previousWord(int nbWord)
{
  Word *prev = this;  // Start at this word

  for(int i=0; i<nbWord; i++)
  {
    if(prev->previousWord() != NULL)  // Word exists
      prev = prev->previousWord();    // Jump to this word
    else
      return NULL;                    // No word after this position
  }

  return prev;
}

