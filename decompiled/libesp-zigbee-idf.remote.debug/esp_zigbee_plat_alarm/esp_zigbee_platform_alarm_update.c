/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_alarm.o -> esp_zigbee_platform_alarm_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zigbee_platform_alarm_update(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 extraout_a1;
  int iVar6;
  
  iVar6 = s_alarm_us;
  uVar2 = *(uint *)(param_1 + 0x20) * 1000000;
  uVar1 = *(int *)(param_1 + 0x28) + uVar2;
  iVar3 = (uint)(uVar1 < uVar2) +
          *(int *)(param_1 + 0x24) * 1000000 +
          (int)((ulonglong)*(uint *)(param_1 + 0x20) * 1000000 >> 0x20) +
          (*(int *)(param_1 + 0x28) >> 0x1f);
  if (s_is_us_running != '\0') {
    iVar5 = ezb_plat_micro_alarm_get_now();
    if (iVar5 - iVar6 < 0) {
      uVar2 = iVar6 - iVar5;
    }
    else {
      uVar2 = 0;
    }
    if ((iVar3 != 0) || (uVar2 < uVar1)) {
      iVar3 = 0;
      uVar1 = uVar2;
    }
  }
  iVar6 = s_alarm_ms;
  if (s_is_ms_running != '\0') {
    iVar5 = ezb_plat_milli_alarm_get_now();
    if (iVar5 - iVar6 < 0) {
      iVar6 = iVar6 - iVar5;
    }
    else {
      iVar6 = 0;
    }
    if ((iVar3 != 0) || ((uint)(iVar6 * 1000) < uVar1)) {
      iVar3 = 0;
      uVar1 = iVar6 * 1000;
    }
  }
  uVar4 = __udivdi3(uVar1,iVar3,1000000,0);
  *(undefined4 *)(param_1 + 0x20) = uVar4;
  *(undefined4 *)(param_1 + 0x24) = extraout_a1;
  uVar4 = __umoddi3(uVar1,iVar3,1000000,0);
  *(undefined4 *)(param_1 + 0x28) = uVar4;
  return;
}

