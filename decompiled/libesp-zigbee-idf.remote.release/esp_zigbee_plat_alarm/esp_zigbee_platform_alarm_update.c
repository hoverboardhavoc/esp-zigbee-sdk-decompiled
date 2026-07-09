/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_alarm.o -> esp_zigbee_platform_alarm_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zigbee_platform_alarm_update(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 extraout_a1;
  
  iVar1 = s_alarm_us;
  uVar3 = *(uint *)(param_1 + 0x20) * 1000000;
  uVar2 = *(int *)(param_1 + 0x28) + uVar3;
  iVar4 = (uint)(uVar2 < uVar3) +
          *(int *)(param_1 + 0x24) * 1000000 +
          (int)((ulonglong)*(uint *)(param_1 + 0x20) * 1000000 >> 0x20) +
          (*(int *)(param_1 + 0x28) >> 0x1f);
  if (s_is_us_running != '\0') {
    iVar5 = ezb_plat_micro_alarm_get_now();
    uVar3 = iVar1 - iVar5 & iVar5 - iVar1 >> 0x1f;
    if ((iVar4 != 0) || (uVar3 < uVar2)) {
      iVar4 = 0;
      uVar2 = uVar3;
    }
  }
  iVar1 = s_alarm_ms;
  if (s_is_ms_running != '\0') {
    iVar5 = ezb_plat_milli_alarm_get_now();
    uVar3 = (iVar1 - iVar5 & iVar5 - iVar1 >> 0x1f) * 1000;
    if ((iVar4 != 0) || (uVar3 < uVar2)) {
      iVar4 = 0;
      uVar2 = uVar3;
    }
  }
  uVar6 = __udivdi3(uVar2,iVar4,1000000,0);
  *(undefined4 *)(param_1 + 0x20) = uVar6;
  *(undefined4 *)(param_1 + 0x24) = extraout_a1;
  uVar6 = __umoddi3(uVar2,iVar4,1000000,0);
  *(undefined4 *)(param_1 + 0x28) = uVar6;
  return;
}

