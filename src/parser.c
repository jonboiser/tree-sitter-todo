#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 7
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 6
#define ALIAS_COUNT 0
#define TOKEN_COUNT 3
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 2

enum {
  sym_todo_keyword = 1,
  sym_todo_content = 2,
  sym_comment_block = 3,
  sym_comment_with_todo = 4,
  aux_sym_comment_block_repeat1 = 5,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_todo_keyword] = "todo_keyword",
  [sym_todo_content] = "todo_content",
  [sym_comment_block] = "comment_block",
  [sym_comment_with_todo] = "comment_with_todo",
  [aux_sym_comment_block_repeat1] = "comment_block_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_todo_keyword] = sym_todo_keyword,
  [sym_todo_content] = sym_todo_content,
  [sym_comment_block] = sym_comment_block,
  [sym_comment_with_todo] = sym_comment_with_todo,
  [aux_sym_comment_block_repeat1] = aux_sym_comment_block_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_todo_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_todo_content] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_block] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_with_todo] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_comment_block_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static TSSymbol ts_alias_sequences[1][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(9);
      if (lookahead == 'H') ADVANCE(3);
      if (lookahead == 'T') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(11);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == 'A') ADVANCE(4);
      END_STATE();
    case 4:
      if (lookahead == 'C') ADVANCE(6);
      END_STATE();
    case 5:
      if (lookahead == 'D') ADVANCE(8);
      END_STATE();
    case 6:
      if (lookahead == 'K') ADVANCE(10);
      END_STATE();
    case 7:
      if (lookahead == 'O') ADVANCE(5);
      END_STATE();
    case 8:
      if (lookahead == 'O') ADVANCE(10);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_todo_keyword);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_todo_content);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_todo_content);
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_todo_keyword] = ACTIONS(1),
  },
  [1] = {
    [sym_comment_block] = STATE(6),
    [sym_comment_with_todo] = STATE(2),
    [aux_sym_comment_block_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_todo_keyword] = ACTIONS(5),
  },
  [2] = {
    [sym_comment_with_todo] = STATE(3),
    [aux_sym_comment_block_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(7),
    [sym_todo_keyword] = ACTIONS(5),
  },
  [3] = {
    [sym_comment_with_todo] = STATE(3),
    [aux_sym_comment_block_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(9),
    [sym_todo_keyword] = ACTIONS(11),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(14), 2,
      ts_builtin_sym_end,
      sym_todo_keyword,
  [5] = 1,
    ACTIONS(16), 1,
      sym_todo_content,
  [9] = 1,
    ACTIONS(18), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 5,
  [SMALL_STATE(6)] = 9,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = false}, RECOVER(),
  [3] = {.count = 1, .reusable = true}, REDUCE(sym_comment_block, 0),
  [5] = {.count = 1, .reusable = true}, SHIFT(5),
  [7] = {.count = 1, .reusable = true}, REDUCE(sym_comment_block, 1),
  [9] = {.count = 1, .reusable = true}, REDUCE(aux_sym_comment_block_repeat1, 2),
  [11] = {.count = 2, .reusable = true}, REDUCE(aux_sym_comment_block_repeat1, 2), SHIFT_REPEAT(5),
  [14] = {.count = 1, .reusable = true}, REDUCE(sym_comment_with_todo, 2),
  [16] = {.count = 1, .reusable = true}, SHIFT(4),
  [18] = {.count = 1, .reusable = true},  ACCEPT_INPUT(),
};

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_todo(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const unsigned short *)ts_parse_table,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .symbol_names = ts_symbol_names,
    .public_symbol_map = ts_symbol_map,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
  };
  return &language;
}
