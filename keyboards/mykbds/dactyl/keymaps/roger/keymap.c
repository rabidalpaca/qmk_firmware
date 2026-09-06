#include QMK_KEYBOARD_H

enum repeat_line_keycodes {
    SQL_REPEAT_SINGLE = MS_CTLLC + 1,
    SQL_REPEAT_DOUBLE,
    SQL_REPEAT_COMMA,
    TRAINING_TOGGLE,
    SQL_REPEAT_DELETE_ROW,
};

// Runtime only: reconnecting or resetting always starts in normal mode.
static bool training_mode;
bool keyboard_training_enabled(void) {
    return training_mode;
}

// Note: Tri-layer behavior centralised in `layer_state_set_user`.
// _SYM + _MOUS -> _PSS. Using `MO(...)` (momentary) for layers
// makes tri-layer behavior simpler and more predictable than `TT(...)`.

// Defines names for use in layer keycodes and the keymap5
enum layer_names {
    _QWERTY = 0,
	_SYM,
    _MOUS,
    _FUNC,
	_PSS
};


enum combos {
  //sdfSTab,//replace
  odfDel,
  dfBsp,
  n56Bsp,//replace
  o56Del,
  jkEnt,
  fjLead,
  jklTab,
  vbTab,
  cvTab,
};

//const uint16_t PROGMEM sdf_combo[] = {KC_S, KC_D, KC_F, COMBO_END};//replace
const uint16_t PROGMEM odf_combo[] = {OSM(MOD_RSFT), KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM o56_combo[] = {OSM(MOD_RSFT), KC_KP_5, KC_KP_6, COMBO_END};
const uint16_t PROGMEM n56B_combo[] = {KC_KP_5, KC_KP_6, COMBO_END};
//const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_X, KC_C, COMBO_END};
combo_t key_combos[] = {
  //[sdfSTab] = COMBO(sdf_combo, S(KC_TAB)), //replace
  [odfDel] = COMBO(odf_combo, KC_DEL),
  [dfBsp] = COMBO(df_combo, KC_BSPC),
  [o56Del] = COMBO(o56_combo, KC_DEL),
  [n56Bsp] = COMBO(n56B_combo, KC_BSPC),
  //[fgLead] = COMBO(fg_combo, QK_LEAD),
  [jkEnt] = COMBO(jk_combo, KC_ENT),
  [fjLead] = COMBO(fj_combo, QK_LEAD),
  [jklTab] = COMBO(jkl_combo, KC_TAB),
  [vbTab] = COMBO(vb_combo, LCG(KC_RGHT)),
  [cvTab] = COMBO(cv_combo, LCG(KC_LEFT))
};

//#define XCTRX LT(0,KC_X)
//#define CCTRC LT(0,KC_C)
//#define VCTRV LT(0,KC_V)
//#define BCTRA LT(0,KC_B)
#define PAT LT(0,KC_P)
#define CMALT LT(0,KC_COMM)
#define DOTGT LT(0,KC_DOT)
#define SCLCL LT(0,KC_SCLN)
#define LBDLR LT(0,KC_E)
#define CTAMP LT(0,KC_R)
#define OCPAR LT(0,KC_9) //( and )
#define OCBRC LT(0,KC_8) //{ and }
#define OCBRK LT(0,KC_0) //[ and ]
#define QTDQT LT(0,KC_7) //single quote double quote,
#define PLSMN LT(0,KC_6) //plus minus
#define EQNEQ LT(0,KC_5) //equal not equal
#define SLBSL LT(0,KC_4) //slash backslash
#define QSUDR LT(0,KC_3) //question underline
#define EXCPI LT(0,KC_2) //eclamation pipe
#define GRVTI LT(0,KC_1) //grave tilda
#define ASTPC LT(0,KC_W) //Asterisk percent
#define QESC LT(0,KC_Q) //Q ESC
#define ZDOT LT(0,KC_T) //0 .
#define VDF LCG(KC_RGHT)
#define VDB LCG(KC_LEFT)
#define MY_1 KC_SECRET_1
#define MY_2 KC_SECRET_2
#define MY_3 KC_SECRET_3
#define MY_4 KC_SECRET_4
#define MY_5 KC_SECRET_5
#define MY_6 KC_SECRET_6
#define MY_7 KC_SECRET_7
#define MY_8 KC_SECRET_8
#define MY_9 KC_SECRET_9
#define MY_10 KC_SECRET_10
#define MY_11 KC_SECRET_11
#define MY_12 KC_SECRET_12
#define MY_13 KC_SECRET_13
#define MY_14 KC_SECRET_14
#define MY_15 KC_SECRET_15
#define MY_16 KC_SECRET_16
#define MY_17 KC_SECRET_17
#define MY_18 KC_SECRET_18
#define MY_19 KC_SECRET_19
#define MY_20 KC_SECRET_20
#define MY_21 KC_SECRET_21
#define MY_22 KC_SECRET_22
#define MY_23 KC_SECRET_23
#define MY_24 KC_SECRET_24
#define MY_25 KC_SECRET_25
#define MY_26 KC_SECRET_26
#define MY_27 KC_SECRET_27
#define MY_28 KC_SECRET_28
#define MY_29 KC_SECRET_29
#define MY_30 KC_SECRET_30
#define MY_31 KC_SECRET_31
#define MY_32 KC_SECRET_32
#define MY_33 KC_SECRET_33
#define MY_34 KC_SECRET_34
#define MY_35 KC_SECRET_35
#define MY_36 KC_SECRET_36


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_3x6_3(
        GRVTI,  QESC,         KC_W,         KC_E,         KC_R,        KC_T,              KC_Y,        KC_U,         KC_I,         KC_O,   PAT,        QTDQT, //MY_QTMCR,LT(0,KC_ESC)
        ASTPC,  KC_A,         KC_S,         KC_D,         KC_F,        KC_G,              KC_H,        KC_J,         KC_K,         KC_L, SCLCL,        SLBSL, //MY_OPMCR, //LT(0,KC_QUOT),LT(0,KC_Q)
        EXCPI,  KC_Z,         KC_X,         KC_C,         KC_V,        KC_B,              KC_N,        KC_M,        CMALT,        DOTGT, QSUDR,OSM(MOD_RCTL), //MY_EQMCR, //LT(0,KC_BSLS),S(KC_SLSH),LT(0,KC_W),MY_EXMCR
                            OSM(MOD_RALT),       KC_SPC,   MO(_MOUS),          MO(_SYM),   KC_ENT,      OSM(MOD_RSFT)
),
[_SYM] = LAYOUT_split_3x6_3(
LT(0,KC_9),    LBDLR,      KC_KP_7,      KC_KP_8,      KC_KP_9,    PLSMN,      XXXXXXX,       XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX, //LT(0,KC_PPLS),
LT(0,KC_0),    CTAMP,      KC_KP_4,      KC_KP_5,      KC_KP_6,    EQNEQ,      XXXXXXX,       XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
LT(0,KC_8),     ZDOT,      KC_KP_1,      KC_KP_2,      KC_KP_3,   KC_ENT,      XXXXXXX, OSM(MOD_RSFT),OSM(MOD_RCTL),OSM(MOD_RALT),OSM(MOD_RGUI),      XXXXXXX,
                               QK_LLCK,    MO(_FUNC),    _______,                      _______,     _______,   _______
),
[_MOUS] = LAYOUT_split_3x6_3(
 XXXXXXX,   XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,       KC_MUTE,           XXXXXXX,   XXXXXXX,        XXXXXXX,      XXXXXXX,     XXXXXXX,
C(KC_A),   C(KC_Z),      C(KC_C),      C(KC_X),      C(KC_V),          XXXXXXX,       KC_VOLU,       MS_BTN1,     MS_UP,    MS_BTN2,      XXXXXXX,     MS_WHLU,
 XXXXXXX,   QK_LLCK,      KC_LALT,      KC_LCTL,      KC_LSFT,          XXXXXXX,       KC_VOLD,       MS_LEFT,   MS_DOWN,    MS_RGHT,      XXXXXXX,     MS_WHLD,
                                _______,      _______ ,    _______ ,          _______ ,  MO(_FUNC) ,  QK_LLCK
),
[_FUNC] = LAYOUT_split_3x6_3(
 TRAINING_TOGGLE,   XXXXXXX,      SQL_REPEAT_DELETE_ROW,      SQL_REPEAT_COMMA,      SQL_REPEAT_SINGLE,          SQL_REPEAT_DOUBLE,       XXXXXXX,       KC_F2,     KC_F5,  KC_F10,    KC_F12,      XXXXXXX,
 XXXXXXX,   XXXXXXX,      XXXXXXX,      G(KC_R),  C(A(KC_DEL)),          G(KC_L),         XXXXXXX,         KC_HOME,       KC_UP,   KC_END,     XXXXXXX,      KC_PGUP,
 XXXXXXX,   XXXXXXX,      KC_LALT,      KC_RCTL,      KC_LSFT,          XXXXXXX,         XXXXXXX,         KC_LEFT,       KC_DOWN,    KC_RGHT,      XXXXXXX,       KC_PGDN,
                                QK_LLCK,      _______ ,    _______ ,          _______ ,  _______ ,  QK_LLCK
),
[_PSS] = LAYOUT_split_3x6_3(
MY_29,                 MY_17,    MY_23,     MY_5,        MY_18,              MY_20,            MY_25,         MY_21,       MY_9,    MY_15,       MY_16,    MY_32,
MY_30,				    MY_1,    MY_19,     MY_4,         MY_6,               MY_7,             MY_8,         MY_10,      MY_11,    MY_12,       MY_35,    MY_33,
MY_31,                 MY_26,    MY_24,     MY_3,        MY_22,               MY_2,            MY_14,         MY_13,      MY_27,    MY_28,       MY_36,    MY_34,
                               XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX
)
};

#define SEND_SQL(x) send_string_with_delay_P(PSTR(x), SQL_TYPE_DELAY_MS)

static void sql_select_template(void) {
    SEND_SQL("SELECT \n*\nFROM\n\nWHERE\n\nORDER BY 1"SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP));
}

static void sql_count_select_template(void) {
    SEND_SQL("SELECT\nCOUNT(*) as CntOf\n");
    SEND_SQL("FROM\n\nWHERE\nGROUP BY\nORDER BY 1"SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP));
}

static void sql_inner_join(void) {
    SEND_SQL("\nINNER JOIN  AS B ON");
}

static void sql_left_outer_join(void) {
    SEND_SQL("\nLEFT OUTER JOIN  AS B ON");
}

static void sql_where_equals(void) {
    SEND_SQL("\nWHERE  = "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
}

static void sql_where_in(void) {
    SEND_SQL("\nWHERE  IN ()"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
}

static void sql_where_like(void) {
    SEND_SQL("\nWHERE  LIKE '%'"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
}

static void sql_where_is_null(void) {
    SEND_SQL("\nWHERE  IS NULL"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
}

static void sql_where_between(void) {
    SEND_SQL("\nWHERE  BETWEEN  AND"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
}

static void sql_count_as(void) {
    SEND_SQL("COUNT(*) as CntOf,\n");
}

static void sql_max_as(void) {
    SEND_SQL("MAX() as MaxOf," SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
}

static void sql_min_as(void) {
    SEND_SQL("MIN() as MinOf," SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
}

static void sql_declare_columns_search(void) {
    SEND_SQL("DECLARE @col NVARCHAR(200) = NULL; -- set to search text or leave NULL\n");
    SEND_SQL("DECLARE @tbl NVARCHAR(200) = NULL;\n");
    SEND_SQL("DECLARE @sch NVARCHAR(200) = NULL;\n");
    SEND_SQL("DECLARE @dtype NVARCHAR(100) = NULL; -- optional data type filter\n\n");
    SEND_SQL("SELECT TABLE_CATALOG, TABLE_SCHEMA, TABLE_NAME, COLUMN_NAME, ORDINAL_POSITION, \n");
    SEND_SQL("       DATA_TYPE, CHARACTER_MAXIMUM_LENGTH, NUMERIC_PRECISION, NUMERIC_SCALE, IS_NULLABLE, COLUMN_DEFAULT\n");
    SEND_SQL("FROM INFORMATION_SCHEMA.COLUMNS\n");
    SEND_SQL("WHERE (@col   IS NULL OR COLUMN_NAME LIKE '%%' + @col + '%%')\n");
    SEND_SQL("  AND (@tbl   IS NULL OR TABLE_NAME  LIKE '%%' + @tbl + '%%')\n");
    SEND_SQL("  AND (@sch   IS NULL OR TABLE_SCHEMA LIKE '%%' + @sch + '%%')\n");
    SEND_SQL("  AND (@dtype IS NULL OR DATA_TYPE    = @dtype)\n");
    SEND_SQL("ORDER BY TABLE_SCHEMA, TABLE_NAME, ORDINAL_POSITION");
    SEND_SQL(SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP));
}

static void sql_search_procs(void) {
    SEND_SQL("-- Search for text inside stored procedure definitions\n");
    SEND_SQL("DECLARE @search NVARCHAR(200) = ''\n");
    SEND_SQL("SELECT o.name    AS object_name,\n");
    SEND_SQL("       s.name    AS schema_name,\n");
    SEND_SQL("       m.definition\n");
    SEND_SQL("FROM sys.sql_modules m\n");
    SEND_SQL("JOIN sys.objects   o ON m.object_id = o.object_id\n");
    SEND_SQL("JOIN sys.schemas   s ON o.schema_id = s.schema_id\n");
    SEND_SQL("WHERE m.definition LIKE '%%' + @search + '%%'\n");
    SEND_SQL("  AND o.type IN ('P','PC') -- P = SQL Stored Procedure, PC = Assembly (CLR) Stored Proc\n");
    SEND_SQL("ORDER BY s.name, o.name\n");
    SEND_SQL(SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP));
}

static void sql_query_store(void) {
    SEND_SQL("DECLARE @HoursBack int = 24;\n");
    SEND_SQL("DECLARE @Since datetimeoffset = DATEADD(HOUR, -@HoursBack, SYSDATETIMEOFFSET());\n");
    SEND_SQL("-- Current database; Query Store must contain captured runtime data.\n");
    SEND_SQL("-- Includes whole aggregation intervals overlapping the lookback window.\n");
    SEND_SQL(";WITH totals AS (\n");
    SEND_SQL("    SELECT p.query_id,\n");
    SEND_SQL("           SUM(rs.count_executions) AS executions,\n");
    SEND_SQL("           SUM(rs.avg_duration * rs.count_executions) / 1000.0 AS total_duration_ms,\n");
    SEND_SQL("           MAX(rs.last_execution_time) AS last_execution_time\n");
    SEND_SQL("    FROM sys.query_store_runtime_stats AS rs\n");
    SEND_SQL("    JOIN sys.query_store_runtime_stats_interval AS i\n");
    SEND_SQL("      ON i.runtime_stats_interval_id = rs.runtime_stats_interval_id\n");
    SEND_SQL("    JOIN sys.query_store_plan AS p ON p.plan_id = rs.plan_id\n");
    SEND_SQL("    WHERE i.end_time > @Since\n");
    SEND_SQL("      AND rs.execution_type = 0\n");
    SEND_SQL("    GROUP BY p.query_id\n");
    SEND_SQL(")\n");
    SEND_SQL("SELECT TOP (25) t.query_id, t.executions,\n");
    SEND_SQL("       t.total_duration_ms,\n");
    SEND_SQL("       t.total_duration_ms / NULLIF(t.executions, 0) AS avg_duration_ms,\n");
    SEND_SQL("       t.last_execution_time, qt.query_sql_text\n");
    SEND_SQL("FROM totals AS t\n");
    SEND_SQL("JOIN sys.query_store_query AS q ON q.query_id = t.query_id\n");
    SEND_SQL("JOIN sys.query_store_query_text AS qt ON qt.query_text_id = q.query_text_id\n");
    SEND_SQL("ORDER BY t.total_duration_ms DESC;");
    SEND_SQL(SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_END) SS_TAP(X_LEFT) SS_DOWN(X_LSFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_UP(X_LSFT));
}

static void sql_declare_int(void) {
    SEND_SQL("DECLARE @int INT = ");
}

static void sql_declare_str(void) {
    SEND_SQL("DECLARE @str VARCHAR(50) = ''"SS_TAP(X_LEFT));
}

static void sql_declare_dttm(void) {
    SEND_SQL("DECLARE @dttm DATETIME = ''"SS_TAP(X_LEFT));
}

static void sql_wrap_single_quotes(void) {
    SEND_SQL(SS_TAP(X_HOME)"'"SS_TAP(X_END)"',"SS_TAP(X_DOWN));
}

static void sql_wrap_double_quotes(void) {
    SEND_SQL(SS_TAP(X_HOME)"\""SS_TAP(X_END)"\","SS_TAP(X_DOWN));
}




// Delete line contents, then the following newline if present.
// Uses editor Home/End behavior; no clipboard changes.
static void sql_delete_row(void) {
    SEND_SQL(SS_TAP(X_HOME) SS_DOWN(X_LSFT) SS_TAP(X_END) SS_UP(X_LSFT) SS_TAP(X_DEL) SS_TAP(X_DEL));
}

static void sql_line_comma(void) {
    SEND_SQL(SS_TAP(X_END)","SS_TAP(X_DOWN));
}

static void sql_row_number(void) {
    SEND_SQL("ROW_NUMBER() OVER (ORDER BY ) AS RowNum" SS_TAP(X_END) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
}

static void sql_top_template(void) {
    SEND_SQL("SELECT TOP (100) *\nFROM \nWHERE ;" SS_TAP(X_UP) SS_TAP(X_END));
}

static void sql_proc_template(void) {
    SEND_SQL("CREATE OR ALTER PROCEDURE dbo.\nAS\nBEGIN\n    SET NOCOUNT ON;\n\nEND;\nGO" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_END));
}

static void sql_update_template(void) {
    SEND_SQL("UPDATE \nSET  = \nWHERE  = ;" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_END));
}

static void sql_upsert_template(void) {
    SEND_SQL("MERGE INTO dbo. AS target\nUSING (SELECT @key AS [KeyColumn], @value AS [ValueColumn]) AS source\nON target.[KeyColumn] = source.[KeyColumn]\nWHEN MATCHED THEN\n    UPDATE SET target.[ValueColumn] = source.[ValueColumn]\nWHEN NOT MATCHED BY TARGET THEN\n    INSERT ([KeyColumn], [ValueColumn])\n    VALUES (source.[KeyColumn], source.[ValueColumn]);" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_END) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
}

static void sql_transaction_template(void) {
    SEND_SQL("SET XACT_ABORT ON;\nBEGIN TRY\n    BEGIN TRANSACTION;\n    \n    COMMIT TRANSACTION;\nEND TRY\nBEGIN CATCH\n    IF XACT_STATE() <> 0 ROLLBACK TRANSACTION;\n    THROW;\nEND CATCH;" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_END));
}

static void sql_external_user_template(void) {
    SEND_SQL("DECLARE @UserName sysname = N'';\nIF NULLIF(@UserName, N'') IS NULL\n    THROW 50000, 'Enter the external user name.', 1;\nDECLARE @sql nvarchar(max) =\n    N'CREATE USER ' + QUOTENAME(@UserName) + N' FROM EXTERNAL PROVIDER;'\n    + N' ALTER ROLE db_datareader ADD MEMBER ' + QUOTENAME(@UserName) + N';';\nEXEC sys.sp_executesql @sql;" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_END) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
}

typedef struct {
    uint8_t mods;
    uint8_t weak_mods;
} sql_mod_state_t;

static sql_mod_state_t sql_mods_begin(void) {
    const sql_mod_state_t saved = {get_mods(), get_weak_mods()};
    clear_mods();
    clear_weak_mods();
    // Pending one-shot modifiers are consumed, not restored.
    clear_oneshot_mods();
    send_keyboard_report();
    return saved;
}

static void sql_mods_end(sql_mod_state_t saved) {
    set_mods(saved.mods);
    set_weak_mods(saved.weak_mods);
    send_keyboard_report();
}

// Only the most recently pressed repeat key repeats. No blocking inter-repeat wait.
static uint16_t active_line_repeat;
static uint32_t line_repeat_timer;

static void run_line_repeat(uint16_t keycode) {
    const sql_mod_state_t saved = sql_mods_begin();
    switch (keycode) {
        case SQL_REPEAT_SINGLE: sql_wrap_single_quotes(); break;
        case SQL_REPEAT_DOUBLE: sql_wrap_double_quotes(); break;
        case SQL_REPEAT_COMMA: sql_line_comma(); break;
        case SQL_REPEAT_DELETE_ROW: sql_delete_row(); break;
    }
    sql_mods_end(saved);
    // Measure the pause from completion of the previous action.
    line_repeat_timer = timer_read32();
}

// Practice reports the matched sequence without running its SQL action.
static void run_leader_action(void (*action)(void), const char *sequence) {
    if (training_mode) {
        send_string("{LEAD:");
        send_string(sequence);
        send_string("}");
    } else {
        action();
    }
}

void leader_end_user(void) {
    const sql_mod_state_t saved = sql_mods_begin();
    if (leader_sequence_one_key(KC_A)) {
        run_leader_action(sql_count_as, "A");
    } else if (leader_sequence_one_key(KC_D)) {
        run_leader_action(sql_declare_int, "D");
    } else if (leader_sequence_two_keys(KC_D, KC_S)) {
        run_leader_action(sql_declare_str, "DS");
    } else if (leader_sequence_two_keys(KC_D, KC_T)) {
        run_leader_action(sql_declare_dttm, "DT");
    } else if (leader_sequence_two_keys(KC_E, KC_U)) {
        run_leader_action(sql_external_user_template, "EU");

    } else if (leader_sequence_one_key(KC_H)) {
        run_leader_action(sql_declare_columns_search, "H");
    } else if (leader_sequence_two_keys(KC_H, KC_U)) {
        run_leader_action(sql_query_store, "HU");
    } else if (leader_sequence_two_keys(KC_H, KC_S)) {
        run_leader_action(sql_search_procs, "HS");
    } else if (leader_sequence_one_key(KC_J)) {
        run_leader_action(sql_inner_join, "J");
    } else if (leader_sequence_two_keys(KC_J, KC_O)) {
        run_leader_action(sql_left_outer_join, "JO");
    } else if (leader_sequence_two_keys(KC_A, KC_N)) {
        run_leader_action(sql_min_as, "AN");
    } else if (leader_sequence_two_keys(KC_A, KC_X)) {
        run_leader_action(sql_max_as, "AX");
    } else if (leader_sequence_one_key(KC_R)) {
        run_leader_action(sql_row_number, "R");
    } else if (leader_sequence_one_key(KC_T)) {
        run_leader_action(sql_select_template, "T");
    } else if (leader_sequence_two_keys(KC_T, KC_C)) {
        run_leader_action(sql_count_select_template, "TC");
    } else if (leader_sequence_two_keys(KC_T, KC_S)) {
        run_leader_action(sql_proc_template, "TS");
    } else if (leader_sequence_two_keys(KC_T, KC_T)) {
        run_leader_action(sql_top_template, "TT");
    } else if (leader_sequence_two_keys(KC_T, KC_R)) {
        run_leader_action(sql_transaction_template, "TR");
    } else if (leader_sequence_two_keys(KC_T, KC_U)) {
        run_leader_action(sql_update_template, "TU");
    } else if (leader_sequence_two_keys(KC_T, KC_M)) {
        run_leader_action(sql_upsert_template, "TM");
    } else if (leader_sequence_one_key(KC_W)) {
        run_leader_action(sql_where_equals, "W");
    } else if (leader_sequence_two_keys(KC_W, KC_B)) {
        run_leader_action(sql_where_between, "WB");
    } else if (leader_sequence_two_keys(KC_W, KC_I)) {
        run_leader_action(sql_where_in, "WI");
    } else if (leader_sequence_two_keys(KC_W, KC_L)) {
        run_leader_action(sql_where_like, "WL");
    } else if (leader_sequence_two_keys(KC_W, KC_N)) {
        run_leader_action(sql_where_is_null, "WN");
    }
    sql_mods_end(saved);
}
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(0,KC_T):
            return TAPPING_TERM + 100;
        case LT(0,KC_P):
            return TAPPING_TERM + 100;
        case LT(0,KC_Q):
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}
bool modlocked;


bool get_combo_must_press_in_order(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        /* List combos here that you want to only activate if their keys
         * are pressed in the same order as they are defined in the combo's key
         * array. */
        default:
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(0,KC_P):
            // Do not select the hold action when another key is tapped.pppp@.>,<
            return false;
        case LT(0,KC_Q):
            // Do not select the hold action when another key is tapped.
            return false;
        case LT(0,KC_7):
            // Do not select the hold action when another key is tapped.
            return false;
        default:
            // Immediately select the hold action when another key is tapped.
            return true;
    }
}

const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}
);
const rgblight_segment_t PROGMEM my_sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_func_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_mous_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM my_pss_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM _yes_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_GREEN} );
const rgblight_segment_t PROGMEM training_indicator[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_ORANGE} );
const rgblight_segment_t PROGMEM pending_mod_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_WHITE} );




const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_qwerty_layer,//
    my_sym_layer,    // Overrides caps lock layer
    my_mous_layer,    // Overrides caps lock layer
    my_func_layer,    // Overrides other layers
    my_pss_layer,     // Overrides other layers
    _yes_layer,
    pending_mod_layer,
    training_indicator
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Let QMK compute the tri-layer state (SYM + MOUS -> PSS)
    state = update_tri_layer_state(state, _SYM, _MOUS, _PSS);

    rgblight_set_layer_state(1, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(2, layer_state_cmp(state, _MOUS));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FUNC));
    rgblight_set_layer_state(4, layer_state_cmp(state, _PSS));

    // Debug: print active layer when it changes (requires CONSOLE_ENABLE)
#ifdef CONSOLE_ENABLE
    static uint8_t last_active = 0xFF;
    uint8_t active = biton32(state);
    if (active != last_active) {
        uprintf("layer_state_set_user: active=%u (state=0x%08X)\n", active, state);
        last_active = active;
    }
#endif

    return state;
}


__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void housekeeping_task_user(void) {
    if (active_line_repeat) {
        if (get_highest_layer(layer_state) != _FUNC) {
            active_line_repeat = 0;
        } else if (timer_elapsed32(line_repeat_timer) >= SQL_LINE_REPEAT_INTERVAL_MS) {
            run_line_repeat(active_line_repeat);
        }
    }
  #ifdef RGBLIGHT_TIMEOUT
  check_rgb_timeout();
  #endif

  /* rest of the function code here */
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef RGBLIGHT_TIMEOUT
  if (record->event.pressed) refresh_rgb();
  #endif

  /* rest of the function code here */
}

uint8_t mod_state;

void oneshot_mods_changed_user(uint8_t mods) {
    // Read the full state: some QMK versions pass only newly added bits.
    rgblight_set_layer_state(6, get_oneshot_mods() != 0);
}

void oneshot_locked_mods_changed_user(uint8_t mods) {
    // Show the green LED overlay while any one-shot modifier is locked.
    modlocked = (mods & (MOD_MASK_SHIFT | MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI)) != 0;
    rgblight_set_layer_state(5, modlocked);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == TRAINING_TOGGLE) {
        if (record->event.pressed) {
            active_line_repeat = 0;
            training_mode = !training_mode;
            rgblight_set_layer_state(7, training_mode);
        }
        return false;
    }

    switch (keycode) {
        case SQL_REPEAT_SINGLE:
        case SQL_REPEAT_DOUBLE:
        case SQL_REPEAT_COMMA:
        case SQL_REPEAT_DELETE_ROW:
            if (record->event.pressed) {
                active_line_repeat = keycode;
                run_line_repeat(keycode);
            } else if (active_line_repeat == keycode) {
                active_line_repeat = 0;
            }
            return false;
    }

        mod_state = get_mods();
        switch (keycode) {
            case KC_BSPC:
                {
                // Initialize a boolean variable that keeps track
                // of the delete key status: registered or not?
                static bool delkey_registered;
                if (record->event.pressed) {
                    // Include tapped one-shot Shift as well as held Shift.
                    const uint8_t oneshot_mods = get_oneshot_mods();
                    if ((mod_state | oneshot_mods) & MOD_MASK_SHIFT) {
                        // First temporarily canceling both shifts so that
                        // shift isn't applied to the KC_DEL keycode
                        del_mods(MOD_MASK_SHIFT);
                        // Consume one-shot Shift so it does not affect Delete or the next key.
                        del_oneshot_mods(MOD_MASK_SHIFT);
                        register_code(KC_DEL);
                        // Update the boolean variable to reflect the status of KC_DEL
                        delkey_registered = true;
                        // Reapplying modifier state so that the held shift key(s)
                        // still work even after having tapped the Backspace/Delete key.
                        set_mods(mod_state);
                        return false;
                    }
                } else { // on release of KC_BSPC
                    // In case KC_DEL is still being sent even after the release of KC_BSPC
                    if (delkey_registered) {
                        unregister_code(KC_DEL);
                        delkey_registered = false;
                        return false;
                    }
                }
                // Let QMK process the KC_BSPC keycode as usual outside of shift
                return true;
            }
        case GRVTI:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("`"), 10);
                tap_code(KC_GRV);
            } else if (record->event.pressed) {
                send_string_with_delay_P(PSTR("~"), 10);
            }
		return false;
         case EXCPI:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("!"), 10);
                tap_code16(KC_EXLM);
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("|"), 10);
                tap_code16(KC_PIPE);
            }
			return false;
         case LBDLR:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("#"), 10);
                tap_code16(S(KC_3));  //#
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("$"), 10);
                tap_code16(S(KC_4));  //$
            }
			return false;
         case CTAMP:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("^"), 10);
                tap_code16(S(KC_6));  //^
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("&"), 10);
                tap_code16(S(KC_7));  //&
            }
			return false;
         case ZDOT:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("0"), 10);
                tap_code16(KC_0);  //0
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("."), 10);
                tap_code16(KC_DOT);  //.
            }
			return false;
        case QSUDR:
           if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("?"), 10);
                tap_code16(KC_QUES);  //?
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("_"), 10);
                tap_code16(KC_UNDS);  //_
            }
			return false;
         case SLBSL:
           if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("/"), 10);
                tap_code16(KC_SLASH);  //?
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("\\"), 10);
                 tap_code16(KC_BSLS);  //r
            }
			return false;
         case EQNEQ:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("="), 10);
                tap_code16(KC_EQL);  //=
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("!="), 10);
                tap_code16(KC_EXLM);  //!
                tap_code16(KC_EQL);  //=
            }
			return false;
         case QESC:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("q"), 10);
                tap_code(KC_Q);
            } else if (record->event.pressed) {
                tap_code(KC_ESC);
            }
			return false;
        case PLSMN:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("+"), 10);
                tap_code16(S(KC_EQL));  //+
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("-"), 10);
                tap_code16(KC_MINS);  //-
            }
			return false;
         case QTDQT:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("'"), 10);
                tap_code(KC_QUOT);  //'
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("\""), 10);
                tap_code16(S(KC_QUOT));  //"
            }
			return false;

         case PAT:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P); // Intercept tap function to send x p
            } else if (record->event.pressed) {
                tap_code16(S(KC_2)); // Intercept hold @
            }
			return false;

         case OCBRC:
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_LBRC)); // Tap: opening brace
            } else if (record->event.pressed) {
                tap_code16(S(KC_RBRC)); // Hold: closing brace
                tap_code16(KC_LEFT); //to move inside
            }
			return false;
         case OCPAR:
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_9)); // Intercept tap function to send 9
            } else if (record->event.pressed) {
                tap_code16(S(KC_0)); // Intercept hold function to send )
                tap_code16(KC_LEFT); //to move ide
            }
			return false;
         case OCBRK:
            if (record->tap.count && record->event.pressed) {
               tap_code16(KC_LBRC); // Tap: opening bracket
            } else if (record->event.pressed) {
                tap_code16(KC_RBRC); // Hold: closing bracket
                tap_code16(KC_LEFT); //to move inside
            }
			return false;
         case ASTPC:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("*"), 10);
                tap_code16(KC_ASTR);
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("%"), 10);
                tap_code16(KC_PERC);
            }
			return false;
         case CMALT:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_COMM); // Intercept tap function to send ,
            } else if (record->event.pressed) {
                tap_code16(S(KC_COMM)); // Intercept hold function to send <
            }
			return false;
         case DOTGT:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_DOT); // Intercept tap function to send .
            } else if (record->event.pressed) {
                tap_code16(S(KC_DOT)); // Intercept hold function to send >
            }
			return false;
         case SCLCL:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_SCLN); // Intercept tap function to send;
            } else if (record->event.pressed) {
                tap_code16(S(KC_SCLN)); // Intercept hold function to send :
            }
			return false;

            //}
    }
	return process_record_secrets(keycode, record);
}

