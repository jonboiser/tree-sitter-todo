module.exports = grammar({
  name: "todo",
  rules: {
    comment_block: $ => repeat($.comment_with_todo),
    comment_with_todo: $ => seq($.todo_keyword, $.todo_content),
    todo_keyword: $ => /TODO|HACK/,
    todo_content: $ => /.*\n/,
  }
});
