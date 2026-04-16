/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> level_cvc_affect_with_on_off_output_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void level_cvc_affect_with_on_off_output_handler
               (uint8_t ep_id,int32_t output,uint32_t remaining_time,uintptr_t user_ctx)

{
  uintptr_t uStack_14;
  
  uStack_14 = user_ctx;
  zcl_message_level_set_attr_value(ep_id,(uint8_t)output);
  zcl_level_set_remaining_time(ep_id,(uint16_t)remaining_time);
  zcl_level_affect_on_off_action(ep_id,(uint8_t)output);
  if (remaining_time == 0) {
    level_srv_set_attr_value(ep_id,0,(uint8_t *)&uStack_14);
  }
  return;
}

