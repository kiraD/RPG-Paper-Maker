/*
    RPG Paper Maker Copyright (C) 2017 Marie Laporte

    This file is part of RPG Paper Maker.

    RPG Paper Maker is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    RPG Paper Maker is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SYSTEMDATAS_H
#define SYSTEMDATAS_H

#include <QStandardItemModel>
#include "serializable.h"
#include "primitivevalue.h"

// -------------------------------------------------------
//
//  CLASS SystemDatas
//
//  Contains all the system datas regrouping general project datas,
//  and menus datas.
//  The data file is located in Content/Datas/system.json
//
// -------------------------------------------------------

class SystemDatas : public Serializable
{
public:
    SystemDatas();
    virtual ~SystemDatas();
    void read(QString path);
    SystemDatas(QString path);
    int portionsRay() const;
    int squareSize() const;
    void setIdMapHero(int i);
    void setIdObjectHero(int i);
    QString pathBR() const;
    void setPathBR(QString p);
    int framesAnimation() const;
    void setFramesAnimation(int f);

    QStandardItemModel* modelCurrencies() const;
    QStandardItemModel* modelItemsTypes() const;
    void setDefault();
    virtual void read(const QJsonObject &json);
    virtual void write(QJsonObject &json) const;

private:
    int m_portionsRay;
    int m_squareSize;
    int m_idMapHero;
    int m_idObjectHero;
    QString m_pathBR;
    int m_framesAnimation;
    QStandardItemModel* m_modelCurrencies;
    QStandardItemModel* m_modelItemsTypes;
};

#endif // SYSTEMDATAS_H
