/*
 * Copyright (c) 2022, Filiph Sandström <filiph.sandstrom@filfatstudios.com>
 * Copyright (c) 2023, Cameron Youell <cameronyouell@gmail.com>
 * Copyright (c) 2024, Jamie Mansfield <jmansfield@cadixdev.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/ByteString.h>
#include <AK/OwnPtr.h>

#include <QPoint>
#include <QSettings>
#include <QSize>

namespace Ladybird {

class Settings : public QObject {
    Q_OBJECT

public:
    Settings(Settings const&) = delete;
    Settings& operator=(Settings const&) = delete;

    static Settings* the()
    {
        static Settings instance;
        return &instance;
    }

    ByteString directory();

    Optional<QPoint> last_position();
    void set_last_position(QPoint const& last_position);

    QSize last_size();
    void set_last_size(QSize const& last_size);

    bool is_maximized();
    void set_is_maximized(bool is_maximized);

    QStringList preferred_languages();
    void set_preferred_languages(QStringList const& languages);

    struct EngineProvider {
        QString name;
        QString url;
    };
    EngineProvider autocomplete_engine();
    void set_autocomplete_engine(EngineProvider const& engine);

    bool enable_autocomplete();
    void set_enable_autocomplete(bool enable);

    bool enable_do_not_track();
    void set_enable_do_not_track(bool enable);

    bool enable_autoplay();
    void set_enable_autoplay(bool enable);

    bool show_menubar();
    void set_show_menubar(bool show_menubar);

signals:
    void show_menubar_changed(bool show_menubar);
    void preferred_languages_changed(QStringList const& languages);
    void enable_do_not_track_changed(bool enable);
    void enable_autoplay_changed(bool enable);

protected:
    Settings();

private:
    OwnPtr<QSettings> m_qsettings;
};

}
