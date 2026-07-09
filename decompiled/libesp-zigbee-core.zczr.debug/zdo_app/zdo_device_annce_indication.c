/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app.o -> zdo_device_annce_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_device_annce_indication
               (undefined4 param_1,undefined4 param_2,undefined2 param_3,undefined1 param_4)

{
  undefined2 *puVar1;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined2 uStack_32;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_24 = 5;
  puVar1 = (undefined2 *)zdo_app_signal_get_params(&uStack_24);
  *puVar1 = param_3;
  uStack_38 = (undefined2)param_1;
  uStack_36 = (undefined2)((uint)param_1 >> 0x10);
  uStack_34 = (undefined2)param_2;
  uStack_32 = (undefined2)((uint)param_2 >> 0x10);
  puVar1[1] = uStack_38;
  puVar1[2] = uStack_36;
  puVar1[3] = uStack_34;
  puVar1[4] = uStack_32;
  *(undefined1 *)(puVar1 + 5) = param_4;
  zdo_app_put_signal(&uStack_24);
  return;
}

