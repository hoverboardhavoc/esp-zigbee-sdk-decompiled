/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app.o -> nwk_nlme_event_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_nlme_event_indication(char *param_1)

{
  char *pcVar1;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  pcVar1 = param_1;
  if (*param_1 != '\0') {
    if (*param_1 == '\x01') {
      uStack_24 = (uint)CONCAT12(param_1[2],0x204);
      goto _L0;
    }
    pcVar1 = (char *)__assert_func(0,0,0,0);
  }
  uStack_24 = CONCAT22(uStack_24._2_2_,0x203);
  memcpy((void *)((int)&uStack_24 + 2),pcVar1 + 2,6);
  if (param_1[2] == '\x10') {
    uStack_2c = 0;
    uStack_28 = 0;
    zdo_device_annce_req(&uStack_2c);
  }
_L0:
  zdo_app_put_signal(&uStack_24);
  return;
}

