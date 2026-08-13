/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_has_binding
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool aps_bind_table_has_binding(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = core_globals_get();
  iVar2 = param_2 - *(int *)(iVar2 + 0x974) >> 1;
  uVar1 = iVar2 * -0x55555555;
  iVar3 = core_globals_get();
  if ((uVar1 & 0xffff) < (uint)*(ushort *)(iVar3 + 0x97c)) goto _L0;
  do {
    __assert_func(0,0,0,0);
_L0:
    iVar3 = core_globals_get();
    iVar3 = *(int *)(iVar3 + 0x968);
    iVar4 = core_globals_get();
  } while ((int)(uint)*(ushort *)(iVar4 + 0x970) <= (param_1 - iVar3 >> 1) * -0x55555555);
  fence();
  fence();
  return ((uint)*(byte *)(param_1 + ((uint)(iVar2 * -0x55550000) >> 0x13) + 6) & 1 << (uVar1 & 7))
         != 0;
}

