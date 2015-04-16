#ifndef VP_ENTITY_H
#define VP_ENTITY_H

#include <QObject>

#include <QPoint>


/**
 * @brief The VP_Entity class describe an entity.
 */
class VP_Entity : public QObject
{
  Q_OBJECT
public:
  explicit VP_Entity(QString name, QPoint posDeclaration, QObject *parent = 0);

  // Accessors
  //----------
  QPoint getDeclarationPos()
  {
    return m_posDeclaration;
  }

  QString getName()
  {
    return m_name;
  }

  //----------

private:

  QPoint  m_posDeclaration;   ///< Entity's declaration position (x for line number and y for col number)

  QString m_name;             ///< Entity's name

};

#endif // VP_ENTITY_H
