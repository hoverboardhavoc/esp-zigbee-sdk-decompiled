/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app.o -> zdo_device_annce_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_device_annce_indication
               (undefined4 param_1,undefined4 param_2,undefined2 param_3,undefined1 param_4)

{
  undefined2 *puVar1;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined2 uStack_24;
  undefined1 auStack_22 [18];
  
  uStack_38 = param_1;
  uStack_34 = param_2;
  memset(auStack_22,0,0x10);
  uStack_24 = 5;
  puVar1 = (undefined2 *)zdo_app_signal_get_params(&uStack_24);
  *puVar1 = param_3;
  memcpy(puVar1 + 1,&uStack_38,8);
  *(undefined1 *)(puVar1 + 5) = param_4;
  zdo_app_put_signal(&uStack_24);
  return;
}

