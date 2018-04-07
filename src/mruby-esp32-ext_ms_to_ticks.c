#include <mruby.h>
#include <freertos/FreeRTOS.h>

/*
 * Convert micro seconds to ticks
 *
 *     ESP32.ms_to_ticks(10)
 */
static mrb_value mrb_esp32_ms_to_ticks(mrb_state *mrb, mrb_value self) {
  int ms;
  mrb_get_args(mrb, "i", &ms);
  return mrb_fixnum_value(ms / portTICK_RATE_MS);
}

void mrb_esp32_ext_ms_to_ticks_gem_init(mrb_state* mrb) {
  struct RClass *mrb_esp32;

  /* ESP32 */
  mrb_esp32 = mrb_define_module(mrb, "ESP32");

  mrb_define_class_method(mrb, mrb_esp32, "ms_to_ticks", mrb_esp32_ms_to_ticks, MRB_ARGS_REQ(1));
}

void mrb_esp32_ext_ms_to_ticks_gem_final(mrb_state* mrb) {
}
