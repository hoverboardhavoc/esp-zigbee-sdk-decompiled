/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
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
  char *pcVar3;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined2 uStack_18;
  char cStack_16;
  byte bStack_15;
  byte bStack_14;
  undefined1 uStack_13;
  
  iVar1 = core_globals_get();
  if (*(code **)(iVar1 + 0xad0) != (code *)0x0) {
    if (param_1 == 0) {
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xac0) = 0;
                    /* WARNING: Could not recover jumptable at 0x00010114. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar1 + 0xad0))(0,param_2,*(code **)(iVar1 + 0xad0));
      return;
    }
    if (((*(char *)(param_1 + 4) == '\x02') && (0xe < *(byte *)(param_1 + 0x16))) &&
       (pcVar3 = *(char **)(param_1 + 0x18), *pcVar3 == '\0')) {
      uStack_24 = *(undefined2 *)(param_1 + 6);
      uStack_13 = 0;
      uStack_22 = *(undefined2 *)(param_1 + 0xe);
      uStack_18 = *(undefined2 *)(param_1 + 0x10);
      bStack_15 = pcVar3[1] & 0xfU | pcVar3[1] & 0xf0U;
      bStack_14 = (byte)((ushort)*(undefined2 *)(param_1 + 0x12) >> 0xf) | (byte)pcVar3[2] >> 1 & 2
                  | ((byte)pcVar3[2] >> 7) << 2;
      cStack_16 = pcVar3[0xe];
      uStack_20 = *(undefined4 *)(pcVar3 + 3);
      uStack_1c = *(undefined4 *)(pcVar3 + 7);
      (**(code **)(iVar1 + 0xad0))(&uStack_24);
    }
  }
  return;
}

