/***************************************************************************
 *   Copyright (C) 2020 by Adam Kisari                                     *
 *   github.com/wwrx   or   kisari.net                                     *
 *                                                                         *
 *   This work is based on original work by P. Sereno (2010)               *
 *   http://www.sereno-online.com                                          *
 *   Artwork based on Jean-Victor Balin's Open Clip Art Library            *
 *   jean.victor.balin@gmail.com                                           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License           *
 *   version 3 as published by the Free Software Foundation                *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Lesser General Public License for more details.                   *
 *   https://www.gnu.org/licenses/lgpl-3.0.html                            *
 ***************************************************************************/


#include "qled.h"

/*!
  \brief QLed: this is the QLed constructor.
  \param parent: The Parent Widget
*/
QLed::QLed(QWidget* parent)
    : QWidget(parent) {
    m_value = false;
    m_onColor = QColor("green");
    m_offColor = QColor("grey");
    m_shape = Circle;
    shapes << ":/resources/circle.svg" << ":/resources/square.svg" << ":/resources/triang.svg" << ":/resources/round.svg";

    renderer = new QSvgRenderer();
}
QLed::~QLed() {
    delete renderer;
}


/*!
  \brief My implementation of the currently unimplemented QDomDocument::elementById
  \param QDomElement root, QString id
  \return QDomElement or a null element if id was not found
*/
QDomElement getElementById(const QDomElement root, const QString id)
{
    if (root.attribute("id") == id) {
        return root.toElement();
    }
    QDomElement elem = root.firstChild().toElement();
    while(!elem.isNull())
    {
        if (elem.attribute("id") == id) {
            return elem.toElement();
        }
        if (elem.hasChildNodes()) {
            QDomElement childElem = getElementById(elem, id);
            if(!childElem.isNull()){
                return childElem.toElement();
            }
        }
        elem = elem.nextSibling().toElement();
    }
    return QDomElement();
}


/*!
  \brief paintEvent: painting method
  \param QPaintEvent *
  \return void
*/
void QLed::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QString ledShape = shapes[m_shape];
    QString styleTxt1, styleTxt2;
    if(m_value){
        styleTxt1 = "stop-color:" + m_onColor.darker(l1).name() + ";stop-opacity:1;";
        styleTxt2 = "stop-color:" + m_onColor.lighter(l2).name() + ";stop-opacity:1;";
    }
    else {
        styleTxt1 = "stop-color:" + m_offColor.darker(l1).name() + ";stop-opacity:1;";
        styleTxt2 = "stop-color:" + m_offColor.lighter(l2).name() + ";stop-opacity:1;";
    }

    // open svg resource load contents to qbytearray, then
    // load svg contents to xml document and edit contents
    QFile file(ledShape);
    file.open(QIODevice::ReadOnly);
    QByteArray baData = file.readAll();
    file.close();
    QDomDocument doc;
    doc.setContent(baData);
    QDomElement root = doc.documentElement();

    getElementById(root, "stop31").setAttribute("style", styleTxt1);
    getElementById(root, "stop32").setAttribute("style", styleTxt2);

    renderer->load(doc.toByteArray());
    renderer->render(&painter);
}


/*!
  \brief setColor: this method allows to change the On/Off color simultaneously (the off color will be a darker shade)
  \param ledColor newColor
  \return void
*/
void QLed::setColor(QColor newColor, int factor) {
    m_onColor = newColor;
    m_offColor = newColor.darker(factor);
    update();
}


/*!
  \brief setOnColor: this method allows to change the On color
  \param ledColor newColor
  \return void
*/
void QLed::setOnColor(QColor newColor) {
    m_onColor = newColor;
    update();
}


/*!
  \brief setOffColor: this method allows to change the Off color
  \param ledColor newColor
  \return void
*/
void QLed::setOffColor(QColor newColor) {
    m_offColor = newColor;
    update();
}


/*!
  \brief setShape: this method allows to change the led shape {Circle,Square,Triangle,Rounded rectangle}
  \param ledColor newColor
  \return void
*/
void QLed::setShape(ledShape newShape) {
    m_shape = newShape;
    update();
}


/*!
  \brief setValue: this method allows to set the led value {true,false}
  \param ledColor newColor
  \return void
*/
void QLed::setValue(bool value) {
    m_value = value;
    update();
}


/*!
  \brief toggleValue: this method toggles the led value
  \param ledColor newColor
  \return void
*/
void QLed::toggleValue() {
    m_value = !m_value;
    update();
    return;
}
