# Dactyl practice

Open index.html in a browser. Choose Symbols or Mouse keys and Start session. Use Show hint or Skip when needed. Escape pauses. No server, account, or network is used; scores last for the session only.

For secret-name practice, compile and flash the runtime-toggle firmware once. On Function, tap the far-left top key to toggle training. The orange LED overrides other layer colors while training is on. Confirm the orange LED using the checkbox in the app. Secret keys now send `{TRAIN:01}` through `{TRAIN:36}`. Toggle Function + the far-left top key again to restore normal secret output. Training is not saved: reset/reconnect starts in normal mode. Never use secret keys in the app unless the orange training indicator is on.

Regenerate cards after keymap/label edits:

    python dactyl/keymaps/roger/trainer/build_cards.py

Only labels from the leading secrets.h comment enter the app. Secret values are not included. Mouse movement detection is approximate and needs the pointer in the practice area. Browser/OS shortcuts and physical mice cannot be distinguished from QMK output. Firmware and device behavior need testing on your keyboard.

## Leader practice
Select Leader actions after enabling the orange training indicator. The prompt names a SQL action; enter its leader sequence. Training sends `{LEAD:...}` instead of executing the macro. This requires flashing the updated firmware once. Normal mode still types SQL.
