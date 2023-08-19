/*
    SPDX-FileCopyrightText: 2006 Aaron Seigo <aseigo@kde.org>
    SPDX-FileCopyrightText: 2021 Alexander Lohnau <alexander.lohnau@gmx.de>

    SPDX-License-Identifier: LGPL-2.0-only
*/

#ifndef SYSTEMSETTINGSRUNNER_H
#define SYSTEMSETTINGSRUNNER_H

#include <KRunner/AbstractRunner>

class SystemsettingsRunner : public KRunner::AbstractRunner
{
    Q_OBJECT

public:
    explicit SystemsettingsRunner(QObject *parent, const KPluginMetaData &metaData);

    void match(KRunner::RunnerContext &context) override;
    void run(const KRunner::RunnerContext &context, const KRunner::QueryMatch &match) override;

protected Q_SLOTS:
    QMimeData *mimeDataForMatch(const KRunner::QueryMatch &match) override;

private:
    QList<KPluginMetaData> m_modules;
};

#endif
