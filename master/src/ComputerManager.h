/*
 * ComputerManager.h - maintains and provides a computer object list
 *
 * Copyright (c) 2017 Tobias Doerffel <tobydox/at/users.sourceforge.net>
 *
 * This file is part of iTALC - http://italc.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

#ifndef COMPUTER_MANAGER_H
#define COMPUTER_MANAGER_H

#include <QAbstractItemModel>

#include "Computer.h"

class ComputerManager : public QObject
{
	Q_OBJECT
public:
	ComputerManager(QAbstractItemModel* networkObjectModel, QObject *parent = 0);

	const ComputerList& computerList() const
	{
		return m_computerList;
	}

signals:
	void computerListAboutToBeReset();
	void computerListReset();

	void computerAboutToBeInserted( int index );
	void computerInserted();

	void computerAboutToBeRemoved( int index );
	void computerRemoved();

	void dataChanged();

public slots:
	void updateComputerData();
	void reloadComputerList();
	void updateComputerList();

private:
	ComputerList getComputers( const QModelIndex& parent );

	QAbstractItemModel* m_networkObjectModel;
	ComputerList m_computerList;

};

#endif // COMPUTER_MANAGER_H