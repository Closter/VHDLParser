#include "vp_lineanalyzer.h"

#include "vhdlparser.h"

#include <QStringList>

VP_LineAnalyzer::VP_LineAnalyzer(QString lineText_l, int lineNumber_l, QObject *parent) :
  QObject(parent)
{
  lineText = lineText_l;
  lineNumber = lineNumber_l;
}


/**
 * @brief VP_LineAnalyzer::getWordList
 * @return The list of word contains in this line.
 */
QList<VP_Word*> VP_LineAnalyzer::getWordList()
{
  QList<VP_Word*> list; // The list to return, empty at first

  if(!lineText.isEmpty()) // Some characters in this line
  {
    QStringList strList = lineText.split(" ", QString::SkipEmptyParts); // Get each space separated word separately

    // Manage case when no espace before or after a special separator
    //---------------------------------------------------------------
    QStringList finalStrList;

    foreach(QString str, strList)
      finalStrList << lookForSpecialSeparator(str); // Construct the final list of words
    //---------------------------------------------------------------

    // Construct the list of parser words
    int ix = 0;
    foreach(QString str, finalStrList)
    {
      // Calculate col number
      int colNumber = lineText.indexOf(str, ix) + ix;

      // Create the new Word
      VP_Word *newWord = new VP_Word(str, lineNumber, colNumber);

      // To chained words
      bool firstWord = list.isEmpty();
      if(!firstWord)  // Not the first word in the line
      {
        newWord->setPreviousWord(list.last());
        list.last()->setNextWord(newWord);
      }

      list << newWord;

      ix += str.length(); // To calculate the col number

    }
  }

  return list;
}


/**
 * @brief VP_LineAnalyzer::lookForSpecialSeparator Search for a special separator character to separate it from
 * other words.
 * @param str String to analyze.
 * @return A list of string with each separated word.
 */
QStringList VP_LineAnalyzer::lookForSpecialSeparator(QString &str)
{
  QStringList list;

  if(str.length() > 1) // Only on or more character word
  {
    int sepCarIx = str.indexOf(QRegExp(VP_VHDL_SX_SEP_CAR_REGEXP)); // Search for a separator character

    if(sepCarIx >= 0) // Founded
    {
      // Has to be separated
      if(sepCarIx != 0) // If null, there is no char before the special separator
      {
        list << str.left(sepCarIx);
        str = str.remove(0, sepCarIx); // First word before special separator. This word is removed from the string
      }

      // Get the number of char from this special separator
      //---------------------------------------------------
      int sepNbChar = 0;
      if(str.indexOf(QRegExp(VP_VHDL_SX_SEP_CAR_2CAR_REGEXP)) == 0) // It's a two char separator
        sepNbChar = 2;
      else if(str.indexOf(QRegExp(VP_VHDL_SX_SEP_CAR_1CAR_REGEXP)) == 0)  // It's a one char separator
        sepNbChar = 1;
      //---------------------------------------------------

      list << str.left(sepNbChar);
      str = str.remove(0, sepNbChar); // First word before special separator. This word is removed from the string

      if(str.length() > 0)  // Some char to look for
        list << lookForSpecialSeparator(str); // Restart this
    }
    else
      list << str;
  }
  else
    list << str;

  return list;
}

