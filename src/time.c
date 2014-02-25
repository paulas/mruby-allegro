#include <mruby.h>
#include <allegro5/allegro.h>
#include "mruby-allegro.h"

static mrb_value
rest(mrb_state *mrb, mrb_value self)
{
  mrb_float f;
  mrb_get_args(mrb, "f", &f);
  al_rest(f);
  return mrb_float_value(mrb, f);
}

static mrb_value
current_time(mrb_state *mrb, mrb_value self)
{
  return mrb_float_value(mrb, al_get_time());
}

void
mruby_allegro_time_init(mrb_state *mrb)
{
  struct RClass *am = M_ALLEGRO;
  mrb_define_module_function(mrb, am, "rest", rest, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, am, "time", current_time, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, am, "current_time", current_time, MRB_ARGS_NONE());
}
