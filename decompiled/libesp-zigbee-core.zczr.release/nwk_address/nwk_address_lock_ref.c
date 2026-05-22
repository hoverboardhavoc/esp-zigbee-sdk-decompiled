/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_lock_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_address_lock_ref(nwk_addr_ref_t ref)

{
  ushort ref_00;
  _Bool _Var1;
  undefined3 extraout_var;
  undefined2 in_register_0000202a;
  int iVar2;
  nwk_addr_table_t *tbl;
  uint uVar3;
  int iVar4;
  
  iVar2 = core_globals_get();
  tbl = (nwk_addr_table_t *)(iVar2 + 0xc4c);
  do_lock_ref(tbl,ref);
  iVar4 = *(int *)(iVar2 + 0xc50) + CONCAT22(in_register_0000202a,ref) * 0x12;
  if ((*(byte *)(iVar4 + 0x11) & 4) == 0) {
    return;
  }
  ref_00 = *(ushort *)(iVar4 + 0xe);
  _Var1 = check_table_ref(ref_00,tbl->ent_in_use,*(uint16_t *)(iVar2 + 0xc54));
  if (CONCAT31(extraout_var,_Var1) != 0) {
    iVar2 = *(int *)(iVar2 + 0xc50) + (uint)ref_00 * 0x12;
    uVar3 = (uint)*(byte *)(iVar2 + 0x10);
    if (uVar3 == 0xff) {
      __assert_func(0,0,0,0);
    }
    if (uVar3 == 0) {
      addr_table_lru_remove(tbl,ref_00);
    }
    *(char *)(iVar2 + 0x10) = *(char *)(iVar2 + 0x10) + '\x01';
  }
  return;
}

