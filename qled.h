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


#ifndef QLED_H
#define QLED_H

#include <Qt>
#include <QWidget>

#include <QtUiPlugin/QDesignerCustomWidgetInterface>
#include <QtUiPlugin/QDesignerExportWidget>

#include <QColor>
#include <QtSvg>
#include <QSvgRenderer>
#include <QtXml/QDomDocument>

// My Qt designer widget plugin class

#ifdef CUSTOM_CREATOR_PLUGIN
#define MY_PLUGIN_EXPORT QDESIGNER_WIDGET_EXPORT
#else
#define MY_PLUGIN_EXPORT
#endif

class MY_PLUGIN_EXPORT QLed : public QWidget {

    Q_OBJECT

    Q_ENUMS (ledShape)
    Q_PROPERTY(bool value READ value WRITE setValue)
    Q_PROPERTY(QColor color READ color WRITE setColor)
    Q_PROPERTY(QColor onColor READ onColor WRITE setOnColor)
    Q_PROPERTY(QColor offColor READ offColor WRITE setOffColor)
    Q_PROPERTY(ledShape shape READ shape WRITE setShape)

public:
    QLed(QWidget* parent = 0);
    virtual ~QLed();
    bool value() const {
        return m_value;
    }
    enum ledShape { Circle = 0, Square, Triangle, Rounded};
    QColor color() const {
        return m_onColor;
    }
    QColor onColor() const {
        return m_onColor;
    }
    QColor offColor() const {
        return m_offColor;
    }
    ledShape shape() const {
        return m_shape;
    }

public slots:
    void setValue(bool);
    void setColor(QColor, int=350);
    void setOnColor(QColor);
    void setOffColor(QColor);
    void setShape(ledShape);
    void toggleValue();

protected:
    bool m_value;
    QColor m_onColor, m_offColor;
    const int l1=180, l2=130; // LED 3D effect shading factors
    ledShape m_shape;
    QStringList shapes;
    void paintEvent(QPaintEvent* event);

private:
    QSvgRenderer* renderer ;
};

#endif
