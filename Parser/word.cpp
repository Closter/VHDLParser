#include "word.h"


Word::Word(QString text, int lineNumber, int colNumber, bool isEOL, bool isComment, Word *previous, Word *next, QObject *parent) :
  QObject(parent)
{
  // Update word's member
  m_wordText    = text;
  m_position    = QPoint(lineNumber, colNumber);

  m_previousWord  = previous;
  m_nextWord      = next;

  m_isEOL     = isEOL;
  m_isComment = isComment;
}


/**
 * @brief Word::nextWord Return the word next to this word.
 * @param onlyCode If False, return the next word, this word could be anything, a comment, a carriage return. If False, this word could only be a code.
 * @return
 */
Word *Word::nextWord(bool onlyCode)
{
  Word *w = m_nextWord; // Init on the next word

  if(!onlyCode)
    return m_nextWord;
  else
  {
    while(w != NULL)      // Run until no more next word
    {
      if((!w->isComment()) && // Not a comment, we get it !
         (!w->isEOL()))       // Not an end of line
        break;

      w = w->nextWord();  // Any next word
    }
  }

  return w;
}


/**
 * @brief Word::previousWord Return the word before this word.
 * @param onlyCode If False, return the word before, this word could be a anything. If True, this word could only be a word of code.
 * @return
 */
Word *Word::previousWord(bool onlyCode)
{
  Word *w = m_previousWord; // Init on the previous word

  if(onlyCode)
    return m_previousWord;
  else
  {
    while(w != NULL)      // Run until no more previous word
    {
      if(!w->isComment()) // Not a comment, we get it !
        break;
    }

    w = w->previousWord();  // Any previous word
  }

  return w;
}




/**
 * @brief Word::nextWord Return the word next to this word after nbWord.
 * nextWord(1) is equivalent to nextWord().
 * @param nbWord Nb word to skip
 * @param nextComment If true, return the next word, this word could be a comment. If False, this word could not be a comment.
 * @return NULL if no word exists or a pointer to the corresponding word.
 */
Word *Word::nextWord(int nbWord, bool onlyCode)
{
  Word *next = this;  // Start at this word

  for(int i=0; i<nbWord; i++)
  {
    if(next->nextWord(onlyCode) != NULL)  // Word exists
      next = next->nextWord(onlyCode);    // Jump to this word
    else
      return NULL;                // No word after this position
  }

  return next;
}


/**
 * @brief Word::previousWord Return the word befor to this word skipping nbWord.
 * previousWord(1) is equivalent to previousWord().
 * @param nbWord Nb word to skip
 * @param onlyCode If False, return the word before, this word could be a anything. If True, this word could only be a word of code.
 * @return NULL if no word exists or a pointer to the corresponding word.
 */
Word *Word::previousWord(int nbWord, bool onlyCode)
{
  Word *prev = this;  // Start at this word

  for(int i=0; i<nbWord; i++)
  {
    if(prev->previousWord(onlyCode) != NULL)  // Word exists
      prev = prev->previousWord(onlyCode);    // Jump to this word
    else
      return NULL;                    // No word after this position
  }

  return prev;
}

