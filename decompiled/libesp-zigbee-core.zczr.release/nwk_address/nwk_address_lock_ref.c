/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  tbl = (nwk_addr_table_t *)(iVar2 + 0xcb0);
  do_lock_ref(tbl,ref);
  iVar4 = *(int *)(iVar2 + 0xcb4) + CONCAT22(in_register_0000202a,ref) * 0x10;
  if ((*(byte *)(iVar4 + 0xf) & 4) == 0) {
    return;
  }
  ref_00 = *(ushort *)(iVar4 + 0xc);
  _Var1 = check_table_ref(ref_00,tbl->ent_in_use,*(uint16_t *)(iVar2 + 0xcb8));
  if (CONCAT31(extraout_var,_Var1) != 0) {
    iVar2 = *(int *)(iVar2 + 0xcb4) + (uint)ref_00 * 0x10;
    uVar3 = (uint)*(byte *)(iVar2 + 0xe);
    if (uVar3 == 0xff) {
      __assert_func(0,0,0,0);
    }
    if (uVar3 == 0) {
      addr_table_lru_remove(tbl,ref_00);
    }
    *(char *)(iVar2 + 0xe) = *(char *)(iVar2 + 0xe) + '\x01';
  }
  return;
}

