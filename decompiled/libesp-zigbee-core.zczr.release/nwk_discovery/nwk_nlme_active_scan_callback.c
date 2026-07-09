/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_discovery.o -> nwk_nlme_active_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_nlme_active_scan_callback(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined2 uStack_18;
  undefined1 uStack_16;
  byte bStack_15;
  byte bStack_14;
  undefined1 uStack_13;
  
  iVar1 = core_globals_get();
  if (*(code **)(iVar1 + 0xad0) != (code *)0x0) {
    if (param_1 == 0) {
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xac0) = 0;
                    /* WARNING: Could not recover jumptable at 0x00010104. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar1 + 0xad0))(0,param_2,*(code **)(iVar1 + 0xad0));
      return;
    }
    if (*(char *)(param_1 + 4) == '\x02') {
      uStack_24 = *(undefined2 *)(param_1 + 6);
      iVar2 = *(int *)(param_1 + 0x18);
      uStack_13 = 0;
      uStack_22 = *(undefined2 *)(param_1 + 0xe);
      uStack_18 = *(undefined2 *)(param_1 + 0x10);
      bStack_15 = *(byte *)(iVar2 + 1) & 0xf | *(byte *)(iVar2 + 1) & 0xf0;
      bStack_14 = (byte)((ushort)*(undefined2 *)(param_1 + 0x12) >> 0xf) |
                  *(byte *)(iVar2 + 2) >> 1 & 2 | (*(byte *)(iVar2 + 2) >> 7) << 2;
      uStack_16 = *(undefined1 *)(iVar2 + 0xe);
      uStack_20 = *(undefined4 *)(iVar2 + 3);
      uStack_1c = *(undefined4 *)(iVar2 + 7);
      (**(code **)(iVar1 + 0xad0))(&uStack_24);
    }
  }
  return;
}

