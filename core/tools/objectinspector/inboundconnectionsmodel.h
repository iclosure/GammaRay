/*
  inboundconnectionsmodel.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2014 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Volker Krause <volker.krause@kdab.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GAMMARAY_INBOUNDCONNECTIONSMODEL_H
#define GAMMARAY_INBOUNDCONNECTIONSMODEL_H

#include <QAbstractItemModel>
#include <QPointer>
#include <QVector>

namespace GammaRay {

/** List of inbound connections on a given QObject. */
class InboundConnectionsModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit InboundConnectionsModel(QObject *parent = 0);
    ~InboundConnectionsModel();

    void setObject(QObject *object);

    int columnCount(const QModelIndex& parent) const;
    int rowCount(const QModelIndex& parent) const;
    QVariant data(const QModelIndex& index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

private:
    QPointer<QObject> m_object;
    struct Connection {
      QPointer<QObject> sender;
      int signalIndex;
      int slotIndex;
    };
    QVector<Connection> m_connections;
};
}

#endif // GAMMARAY_INBOUNDCONNECTIONSMODEL_H
