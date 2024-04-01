/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> esp_zb_scheduler_alarm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_scheduler_alarm(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_1 * 1000 + 0x3bff;
  iVar1 = (int)((ulonglong)param_1 * 1000 >> 0x20) + (uint)(uVar2 < param_1 * 1000);
  uVar3 = uVar2 + iVar1;
  uVar3 = uVar2 - (uVar3 + (uVar3 < uVar2)) % 0xf;
  uVar2 = (iVar1 - (uint)(uVar2 < uVar3)) * -0x11111111 + uVar3 * -0x11111112 +
          (int)((ulonglong)uVar3 * 0xeeeeeeef >> 0x20);
  zb_schedule_app_alarm(uVar2 * 0x400000 | uVar3 * -0x11111111 >> 10,uVar2 >> 10);
  return;
}

