#ifndef MRUBY_ALLEGRO_H
#define MRUBY_ALLEGRO_H

#ifndef mrb_bool_value
#define mrb_bool_value(val) ((val) ? mrb_true_value() : mrb_false_value())
#endif

#define M_ALLEGRO (mrb_class_obj_get(mrb, "Al"))
#define E_ALLEGRO_ERROR (mrb_class_obj_get(mrb, "AllegroError"))
#define C_ALLEGRO_BITMAP (get_allegro_const(mrb, "Bitmap", 6))
#define C_ALLEGRO_COLOR (get_allegro_const(mrb, "Color", 5))
#define C_ALLEGRO_DISPLAY (get_allegro_const(mrb, "Display", 7))
#define C_ALLEGRO_EVENT (get_allegro_const(mrb, "Event", 5))
#define C_ALLEGRO_EVENTSOURCE (get_allegro_const(mrb, "EventSource", 11))
#define C_ALLEGRO_EVENTQUEUE (get_allegro_const(mrb, "EventQueue", 10))
#define C_ALLEGRO_FONT (get_allegro_const(mrb, "Font", 4))

#define Check_Destroyed(mrb, obj, t, sval) do {\
  Data_Get_Struct(mrb, obj, & t ## _data_type, sval);\
  if (!sval) {\
    mrb_raise(mrb, E_ALLEGRO_ERROR, #t " is destroyed");\
  }\
} while(0)

#define Destroyed(o) (mrb_bool_value(!DATA_PTR(o)))

extern struct mrb_data_type bitmap_data_type;
extern struct mrb_data_type color_data_type;
extern struct mrb_data_type display_data_type;
extern struct mrb_data_type event_data_type;
extern struct mrb_data_type eventsource_data_type;
extern struct mrb_data_type eventqueue_data_type;
extern struct mrb_data_type font_data_type;

void *safe_malloc(mrb_state *, size_t);
struct RClass *get_allegro_const(mrb_state *, const char *, int);
mrb_value version_to_hash(mrb_state *, uint32_t);
unsigned char clamp_uc(mrb_int);
int clamp_int(mrb_int);
float clamp_f(mrb_float);
int bitmap_get_flags(mrb_state *, unsigned, mrb_sym, mrb_sym);

#endif
