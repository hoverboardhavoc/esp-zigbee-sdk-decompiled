/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_btt_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 * nwk_btt_find(uint param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = &s_nwk_fwd;
  iVar2 = 0;
  while (((*(ushort *)(puVar1 + 0xf) != param_1 || (*(byte *)((int)puVar1 + 0x3e) != param_2)) ||
         (*(char *)((int)puVar1 + 0x3f) == '\0'))) {
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 2;
    if (iVar2 == 0x5a) {
      return (undefined2 *)0x0;
    }
  }
  return &DAT_00011430 + iVar2 * 4;
}

