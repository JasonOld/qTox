/*
    Copyright © 2014-2019 by The qTox Project Contributors

    This file is part of qTox, a Qt-based graphical interface for Tox.

    qTox is libre software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    qTox is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with qTox.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "../chatlinecontent.h"

#include <QObject>
#include <QPixmap>
#include <QTimer>

class QVariantAnimation;

class Spinner : public ChatLineContent
{
    Q_OBJECT
public:
    Spinner(const QString& img, QSize size, qreal speed);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                       QWidget* widget) override;
    void setWidth(qreal width) override;
    qreal getAscent() const override;

private slots:
    void timeout();

private:
    static constexpr int framerate = 30; // 30Hz
    QSize size;
    QPixmap pmap;
    qreal rotSpeed;
    qreal curRot;
    QTimer timer;
    qreal alpha = 0.0;
    QVariantAnimation* blendAnimation;
};
