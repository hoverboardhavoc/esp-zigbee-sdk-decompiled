/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_by_extended
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_address_by_extended(int param_1,int param_2,int param_3,undefined2 *param_4)

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
      iVar2 = iVar1 + 0xc4c;
      uVar3 = search_extended(iVar2,param_1);
      if (uVar3 < *(ushort *)(iVar1 + 0xc54)) {
        addr_table_lru_update(iVar2,uVar3);
      }
      else {
        if (param_2 == 0) {
          return 5;
        }
        uVar3 = addr_table_add(iVar2,0xffff,param_1);
        if (*(ushort *)(iVar1 + 0xc54) <= uVar3) {
          return 1;
        }
      }
      *param_4 = (short)uVar3;
      if (param_3 != 0) {
        nwk_address_lock_ref(uVar3);
      }
      uVar4 = 0;
    }
  }
  return uVar4;
}

