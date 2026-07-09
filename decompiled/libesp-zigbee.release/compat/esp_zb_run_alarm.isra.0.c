/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> compat.o -> esp_zb_run_alarm.isra.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_run_alarm_isra_0(void *param_1,int param_2,undefined4 *param_3)

{
  undefined4 *__ptr;
  int iVar1;
  undefined4 uStack_34;
  undefined4 *puStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  __ptr = (undefined4 *)malloc(0x10);
  if (__ptr == (undefined4 *)0x0) {
    return;
  }
  memcpy(__ptr + 1,param_1,0xc);
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_34 = 0x10000;
  puStack_30 = __ptr;
  iVar1 = esp_timer_create(&uStack_34,__ptr);
  if (iVar1 == 0) {
    iVar1 = esp_timer_start_once(*__ptr,param_2 * 1000,0);
    if (iVar1 == 0) {
      if (param_3 == (undefined4 *)0x0) {
        return;
      }
      *param_3 = __ptr;
      return;
    }
    esp_timer_delete(*__ptr);
  }
  free(__ptr);
  return;
}

