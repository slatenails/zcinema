/*
 *  ZCinema: Zandronum demo launcher
 *  Copyright (C) 2013 Santeri Piippo
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ZCINEMA_CONFIG_H
#define ZCINEMA_CONFIG_H

#include <QDialog>
#include "main.h"
#include "types.h"

class QFormLayout;
class QNetworkReply;
class QHBoxLayout;
class QLabel;
class QAbstractButton;
class QLineEdit;
class Ui_ConfigBox;
class QNetworkAccessManager;

class ConfigBox : public QDialog {
	Q_OBJECT
	
public:
	explicit ConfigBox (QWidget* parent = null, Qt::WindowFlags f = 0);
	virtual ~ConfigBox();
	void addPath (str path);
	void initFromSettings();
	void saveSettings();
	void initVersions();
	
	static str getBinaryPath (QWidget* parent);
	
public slots:
	void addPath();
	void findPath();
	void delPath();
	void findZanBinary();
	void editBinaries();
	void buttonPressed (QAbstractButton* btn);
	
private:
	Ui_ConfigBox*        ui;
	list<QLineEdit*>   m_zanBinaries;
	list<QWidget*>     m_binaryLayoutWidgets;
	QFormLayout*       m_releaseLayout,
	           *       m_testLayout;
	
	void addVersion (const str& name, bool isRelease);
};

#endif // ZCINEMA_CONFIG_H