/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> cvc_sat_output_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void cvc_sat_output_handler(uint8_t ep_id,int32_t output,uint32_t remaining_time,uintptr_t user_ctx)

{
  uint8_t ep_id_00;
  int32_t iVar1;
  uint16_t remaining_time_00;
  uint16_t attr_id;
  undefined2 uStack_32;
  undefined1 auStack_11 [4];
  uint8_t saturation;
  
  if (-1 < output) {
    auStack_11[0] = (undefined1)output;
    zcl_message_set_color_control_attr_value(ep_id,(uint16_t)user_ctx,auStack_11);
    color_control_set_remaining_time(ep_id,(uint16_t)remaining_time);
    return;
  }
  attr_id = 0x2c40;
  remaining_time_00 = 0x6d58;
  iVar1 = __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x2dd,
                        "cvc_sat_output_handler","output >= 0");
  iVar1 = math_mod(iVar1,0xff00);
  uStack_32 = (short)iVar1;
  zcl_message_set_color_control_attr_value(ep_id_00,attr_id,&uStack_32);
  color_control_set_remaining_time(ep_id_00,remaining_time_00);
  return;
}

