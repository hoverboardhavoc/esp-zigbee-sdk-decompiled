/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> cvc_enhanced_hue_output_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void cvc_enhanced_hue_output_handler
               (uint8_t ep_id,int32_t output,uint32_t remaining_time,uintptr_t user_ctx)

{
  int iVar1;
  undefined2 auStack_12 [2];
  uint16_t ex_hue;
  
  iVar1 = output % 0x10000;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x10000;
  }
  auStack_12[0] = (undefined2)iVar1;
  zcl_message_set_color_control_attr_value(ep_id,(uint16_t)user_ctx,auStack_12);
  color_control_set_remaining_time(ep_id,(uint16_t)remaining_time);
  return;
}

