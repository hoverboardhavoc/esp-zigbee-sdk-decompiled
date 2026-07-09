/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app.o -> ezb_dev_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_dev_start(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  iVar1 = core_globals_get();
  if ((*(byte *)(iVar1 + 0xcf4) & 1) == 0) {
    iVar1 = zdo_dev_init();
    if (iVar1 == 0) {
      iVar2 = core_globals_get();
      *(byte *)(iVar2 + 0xcf4) = *(byte *)(iVar2 + 0xcf4) | 1;
      if (param_1 == 0) {
        uStack_20 = 0;
        uStack_1c = 0;
        uStack_18 = 0;
        uStack_14 = 0;
        uStack_24 = 1;
        zdo_app_put_signal(&uStack_24);
      }
      else {
        iVar1 = zdo_dev_start_continue();
      }
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

