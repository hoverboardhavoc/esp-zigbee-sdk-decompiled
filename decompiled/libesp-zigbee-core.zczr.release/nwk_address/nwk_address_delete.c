/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_address_delete(nwk_addr_ref_t ref)

{
  _Bool _Var1;
  undefined2 in_register_0000202a;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  
  iVar2 = core_globals_get();
  _Var1 = check_table_ref(ref,*(bitmap_t **)(iVar2 + 0xcb0),*(uint16_t *)(iVar2 + 0xcb8));
  if (CONCAT31(extraout_var,_Var1) != 0) {
    iVar4 = CONCAT22(in_register_0000202a,ref) * 0x10;
    iVar3 = *(int *)(iVar2 + 0xcb4) + iVar4;
    if (*(char *)(iVar3 + 0xe) == '\0') {
      test_and_clr_bitmap(CONCAT22(in_register_0000202a,ref),*(bitmap_t **)(iVar2 + 0xcb0));
      addr_table_lru_remove((nwk_addr_table_t *)(iVar2 + 0xcb0),ref);
      memset((void *)(*(int *)(iVar2 + 0xcb4) + iVar4),0,0x10);
      return;
    }
    *(byte *)(iVar3 + 0xf) = *(byte *)(iVar3 + 0xf) | 8;
  }
  return;
}

