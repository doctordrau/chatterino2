#pragma once

#include "messages/word.h"
#include "setting.h"
#include "settingssnapshot.h"

#include <QSettings>

namespace chatterino {

class SettingsManager : public QObject
{
    Q_OBJECT

public:
    void load();
    void save();

    messages::Word::Type getWordTypeMask();
    bool isIgnoredEmote(const QString &emote);
    QSettings &getQSettings();
    SettingsSnapshot createSnapshot();

signals:
    void wordTypeMaskChanged();

private:
    SettingsManager();

    // variables
    QSettings _settings;
    std::vector<std::reference_wrapper<BaseSetting>> _settingsItems;
    messages::Word::Type _wordTypeMask = messages::Word::Default;

    // methods
    void updateWordTypeMask();

public:
    // Settings
    Setting<QString> theme;
    Setting<float> themeHue;
    Setting<QString> selectedUser;
    Setting<float> emoteScale;
    Setting<float> mouseScrollMultiplier;
    Setting<bool> scaleEmotesByLineHeight;
    Setting<bool> showTimestamps;
    Setting<bool> showTimestampSeconds;
    Setting<bool> showLastMessageIndicator;
    Setting<bool> allowDouplicateMessages;
    Setting<bool> linksDoubleClickOnly;
    Setting<bool> hideEmptyInput;
    Setting<bool> showMessageLength;
    Setting<bool> seperateMessages;
    Setting<bool> mentionUsersWithAt;
    Setting<bool> allowCommandsAtEnd;
    Setting<bool> enableHighlights;
    Setting<bool> enableHighlightSound;
    Setting<bool> enableHighlightTaskbar;
    Setting<bool> customHighlightSound;
    Setting<bool> enableTwitchEmotes;
    Setting<bool> enableBttvEmotes;
    Setting<bool> enableFfzEmotes;
    Setting<bool> enableEmojis;
    Setting<bool> enableGifAnimations;
    Setting<bool> enableGifs;
    Setting<bool> inlineWhispers;
    Setting<bool> windowTopMost;
    Setting<bool> hideTabX;
    Setting<bool> hidePreferencesButton;
    Setting<bool> hideUserButton;
    Setting<bool> useCustomWindowFrame;

public:
    static SettingsManager &getInstance()
    {
        static SettingsManager instance;
        return instance;
    }

private:
};

}  // namespace chatterino
