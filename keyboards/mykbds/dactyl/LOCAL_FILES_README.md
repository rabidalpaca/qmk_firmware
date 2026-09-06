# Dactyl Keyboard Configuration - Local Files Management

## Critical Local-Only Files

The following files are **LOCAL ONLY** and should NOT be committed to git or deleted during repository updates:

### secrets.c and secrets.h
- **Location**: `keyboards/mykbds/dactyl/`
- **Purpose**: Contains sensitive credentials, API keys, and secret macros
- **Status**: Gitignored (defined in root `.gitignore`)
- **Important**: These files are referenced in `rules.mk` but are not tracked by git
- **On repo sync**: Manually restore from backup if deleted

## Files Referenced in rules.mk

The `rules.mk` contains: `SRC += secrets.c`

This means:
- The build system expects `secrets.c` to exist
- If `secrets.c` is missing, compilation will fail with: `No rule to make target 'keyboards/mykbds/dactyl/secrets.c'`
- The file must be present locally even though it's gitignored

## Before Any Repository Update

1. **Backup these files**: `secrets.c`, `secrets.h`
2. **After pulling upstream changes**:
   - Verify `secrets.c` and `secrets.h` still exist
   - If missing, restore from backup or previous commit
3. **Alternative approach**: Remove `SRC += secrets.c` from `rules.mk` if secrets are no longer needed

## Recovery Instructions

If secrets files are deleted:
```bash
# Restore from previous commit
git show HEAD~1:keyboards/mykbds/dactyl/secrets.c > keyboards/mykbds/dactyl/secrets.c

# Or restore from backup
Copy-Item -Path "D:\raqmknewold\mykbds\dactyl\secrets.c" -Destination "d:\raqmk\qmk_firmware\keyboards\mykbds\dactyl\secrets.c" -Force
```

## See Also
- `.gitignore` - Contains patterns for ignored files
- `keyboards/mykbds/dactyl/rules.mk` - Build configuration
