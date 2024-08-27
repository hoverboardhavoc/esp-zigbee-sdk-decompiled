/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_schedule_user_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_schedule_user_cb(int param_1)

{
  undefined4 *puVar1;
  
  if (param_1 == 0) {
    param_1 = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_core.c"
                        ,0x520);
  }
  puVar1 = (undefined4 *)zb_buf_get_tail_func(8);
  if ((code *)*puVar1 != (code *)0x0) {
    (*(code *)*puVar1)(puVar1[1]);
  }
  zb_buf_free_func(param_1);
  return;
}

