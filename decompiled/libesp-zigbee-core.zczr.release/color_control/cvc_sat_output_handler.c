/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> cvc_sat_output_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void cvc_sat_output_handler(uint8_t ep_id,int32_t output,uint32_t remaining_time,uintptr_t user_ctx)

{
  uint8_t extraout_a0;
  uint16_t remaining_time_00;
  uint16_t attr_id;
  undefined1 auStack_11 [4];
  uint8_t saturation;
  
  remaining_time_00 = (uint16_t)remaining_time;
  attr_id = (uint16_t)user_ctx;
  if (output < 0) {
    attr_id = 0;
    remaining_time_00 = 0;
    output = __assert_func(0,0,0,0);
    ep_id = extraout_a0;
  }
  auStack_11[0] = (undefined1)output;
  zcl_message_set_color_control_attr_value(ep_id,attr_id,auStack_11);
  color_control_set_remaining_time(ep_id,remaining_time_00);
  return;
}

