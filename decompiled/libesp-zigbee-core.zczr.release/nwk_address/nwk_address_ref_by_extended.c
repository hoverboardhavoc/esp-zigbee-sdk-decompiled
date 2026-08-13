/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_ref_by_extended
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010a24) */
/* WARNING: Removing unreachable block (ram,0x00010a56) */

undefined4 nwk_address_ref_by_extended(int param_1,undefined2 *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar1 = core_globals_get();
  uVar4 = 2;
  if (param_1 != 0) {
    iVar2 = ezb_eui64_is_invalid(param_1);
    uVar4 = 2;
    if (iVar2 == 0) {
      uVar3 = search_extended(iVar1 + 0xc4c,param_1);
      if (uVar3 < *(ushort *)(iVar1 + 0xc54)) {
        addr_table_lru_update(iVar1 + 0xc4c,uVar3);
        *param_2 = (short)uVar3;
        uVar4 = 0;
      }
      else {
        uVar4 = 5;
      }
    }
  }
  return uVar4;
}

