/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac.o -> nwk_mm_register_interface
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool nwk_mm_register_interface(undefined4 *param_1,undefined1 *param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = core_globals_get();
  bVar1 = (*(uint *)(iVar2 + 0xc7c) >> 5 & 3) != 0;
  if (!bVar1) {
    iVar2 = core_globals_get(1);
    *param_2 = 0;
    uVar3 = param_1[1];
    *(undefined4 *)(iVar2 + 0xc84) = *param_1;
    *(ushort *)(iVar2 + 0xc7c) =
         (ushort)((uVar3 & 1) << 7) | 0x20 | (ushort)(uVar3 << 7) & 0x100 |
         (ushort)(uVar3 << 7) & 0x200 | (ushort)(uVar3 << 7) & 0x400 |
         (ushort)((uVar3 >> 4 & 1) << 0xb) | *(ushort *)(iVar2 + 0xc7c) & 0xf000;
  }
  return bVar1;
}

