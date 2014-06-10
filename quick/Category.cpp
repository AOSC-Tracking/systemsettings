/***************************************************************************
 *                                                                         *
 *   Copyright 2014 Sebastian Kügler <sebas@kde.org>                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#include "Category.h"
#include "MenuProxyModel.h"

#include <QDebug>

class CategoryPrivate
{
public:
    CategoryPrivate(Category *host)
        : q(host),
          categoriesModel(0) {
    }

    Category *q;

    QModelIndex modelIndex;
    MenuProxyModel *categoriesModel;
};

Category::Category(QModelIndex index, MenuProxyModel *model, QObject *parent) :
    QObject(parent),
    d(new CategoryPrivate(this))
{
    d->categoriesModel = model;
    d->modelIndex = index;

    // Data from model...
}

QString Category::name() const
{
    return d->categoriesModel->data(d->modelIndex, Qt::DisplayRole).toString();
}

QVariant Category::decoration() const
{
    return d->categoriesModel->data(d->modelIndex, Qt::DecorationRole);
}


Category::~Category()
{
    delete d;
}


