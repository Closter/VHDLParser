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
  explicit VP_Word(QString word_l, QObject *parent = 0);

  QString text();

private:
  QString word;   ///< The word's text

};

#endif // VP_WORD_H
