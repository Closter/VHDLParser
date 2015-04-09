#include "abstractparser.h"

#include <QStringList>


#define ABSTRACT_PARSE_EOL  "\n"

AbstractParser::AbstractParser(QObject *parent) :
  QObject(parent)
{
  m_specCharList << ABSTRACT_PARSE_EOL;  // Add new line character as a keyword to manage the line count
}

/**
 * @brief AbstractParser::parseText
 * @param text The string to parse
 * @return A list of all word contains in the text (excluding space and carriage return)
 */
QList<Word*> AbstractParser::parse(QString &text)
{
  QList<Word*> list; // The list to return, empty at first

  if(!text.isEmpty()) // Some characters in this line
  {
    QStringList strList = text.split(" ", QString::SkipEmptyParts); // Get each space separated word separately

    // Manage case when no espace before or after a special separator
    //---------------------------------------------------------------
    QStringList finalStrList;

    foreach(QString str, strList)
      finalStrList << splitByKeyword(str); // Construct the final list of words
    //---------------------------------------------------------------

    // Construct the list of parser words
    int ixCol = 0;
    int lastIxNewLine = 0;
    int nbCarBeforeThisLine = 0;
    int lineNumber = 1;
    int colNumber = 1;
    int charNumber = 1;
    bool isCommentActive = false;
    foreach(QString str, finalStrList)
    {
      // Manage comment
      bool thisWordIsComment = false;
      if(!isCommentActive) // Not in a comment
      {
        foreach(QString lineComment, m_lineComment) // Check if this is a new comment
        {
          if(str == lineComment)
          {
            thisWordIsComment = true;
            break;
          }
        }

        isCommentActive = thisWordIsComment;
      }
      else  // Already into a line comment
      {
        thisWordIsComment = true;

        if(str == ABSTRACT_PARSE_EOL) // End of a line comment
          isCommentActive = false;    // And the last comment
      }


      // Calculate col number
      charNumber = text.indexOf(str, ixCol) + 1;
      ixCol = charNumber;
      colNumber = charNumber - nbCarBeforeThisLine;

      // Create the new Word
      Word *newWord = 0;
      if(isKeyword(str))
      {
        newWord = new KeyWord(str, lineNumber, colNumber);

        // Manage new line (it's consider temporaly as a keyword)
        if(isNewLine(str))
        {
          lineNumber++;
          lastIxNewLine = text.indexOf(str, lastIxNewLine+1);
          nbCarBeforeThisLine += colNumber;
        }

      }
      else
        newWord = new Word(str, lineNumber, colNumber, thisWordIsComment);

      if(newWord != 0)
      {
        // To chained words
        bool firstWord = list.isEmpty();
        if(!firstWord)  // Not the first word in the line
        {
          newWord->setPreviousWord(list.last());
          list.last()->setNextWord(newWord);
        }

        list << newWord;
      }


    }
  }

  return list;

}


/**
 * @brief AbstractParser::splitByKeyword Search for a special separator character to separate it from
 * other words.
 * @param str String to analyze.
 * @return A list of string with each separated word.
 */
QStringList AbstractParser::splitByKeyword(QString &str)
{
  QStringList list;

  if(str.length() > 1)
  {
    KeyWord *kw = searchForAKeyWord(str);  // Search for a separator character

    if(kw != NULL) // Founded
    {
      int kwIndex = kw->getColumn();

      // Has to be separated
      if(kwIndex != 0) // If null, there is no char before the special separator
      {
        list << str.left(kwIndex);
        str = str.remove(0, kwIndex); // First word before special separator. This word is removed from the string
      }

      int sepNbChar = kw->getText().length(); // Get the number of char from this special separator

      delete kw;  // Don't need anymore

      list << str.left(sepNbChar);
      str = str.remove(0, sepNbChar); // First word before special separator. This word is removed from the string

      if(str.length() > 0)  // Some char to look for
        list << splitByKeyword(str); // Restart this
    }
    else
      list << str;
  }
  else
    list << str;

  return list;
}


/**
 * @brief AbstractParser::indexOfAKeyWord
 * @param str String to analyze
 * @return A new KeyWord object initialize with the keyword text and the column number if a keyword was found, else NULL.
 */
KeyWord *AbstractParser::searchForAKeyWord(QString str)
{
  int     ix    = str.length();  // Init at maximum
  bool    found = false;
  QString foundedKw;

  foreach(QString kw, m_specCharList)
  {
    int ixFound = str.indexOf(kw); // Look for this index
    if(ixFound != -1) // This keyword is present
    {
      if(ixFound < ix)  // He's befor the precedent found keyword
      {
        ix = ixFound;
        found = true;   // At least one keyword founded
        foundedKw = kw;
      }
    }
  }

  if(!found)
    return NULL;  // No keyword found

  return new KeyWord(foundedKw, -1, ix);
}



/**
 * @brief AbstractParser::isKeyword Check if the string is a keyword
 * @param word  Th string's word
 * @return True if it's a keyword otherwise False
 */
bool AbstractParser::isKeyword(QString word)
{
  return m_specCharList.contains(word);
}


/**
 * @brief AbstractParser::isNewLine
 * @param word String to check if it indeicates a new line
 * @return True if it indicate a new line, otherwise false
 */
bool AbstractParser::isNewLine(QString word)
{
  if(word == "\n")
    return true;

  return false;
}
