/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_scheduler_alarm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_scheduler_alarm(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 extraout_a1;
  
  uVar1 = __udivdi3((uint)(param_3 * 1000 + 0x3bff < param_3 * 1000) +
                    (int)((ulonglong)param_3 * 1000 >> 0x20),0x3c00,0);
  zb_schedule_app_alarm(param_1,param_2,uVar1,extraout_a1);
  return;
}

