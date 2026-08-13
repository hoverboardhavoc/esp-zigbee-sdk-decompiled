/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_ref_by_short
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010b22) */
/* WARNING: Removing unreachable block (ram,0x00010b0e) */

undefined4 nwk_address_ref_by_short(uint param_1,undefined2 *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = core_globals_get();
  if (param_1 < 0xfff8) {
    uVar2 = search_short(iVar1 + 0xc4c,param_1);
    if (uVar2 < *(ushort *)(iVar1 + 0xc54)) {
      addr_table_lru_update(iVar1 + 0xc4c,uVar2);
      *param_2 = (short)uVar2;
      uVar3 = 0;
    }
    else {
      uVar3 = 5;
    }
  }
  else {
    uVar3 = 2;
  }
  return uVar3;
}

