/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  _Var1 = check_table_ref(ref,*(bitmap_t **)(iVar2 + 0xc4c),*(uint16_t *)(iVar2 + 0xc54));
  if (CONCAT31(extraout_var,_Var1) != 0) {
    iVar4 = CONCAT22(in_register_0000202a,ref) * 0x12;
    iVar3 = *(int *)(iVar2 + 0xc50) + iVar4;
    if (*(char *)(iVar3 + 0x10) == '\0') {
      test_and_clr_bitmap(CONCAT22(in_register_0000202a,ref),*(bitmap_t **)(iVar2 + 0xc4c));
      addr_table_lru_remove((nwk_addr_table_t *)(iVar2 + 0xc4c),ref);
      memset((void *)(*(int *)(iVar2 + 0xc50) + iVar4),0,0x12);
      return;
    }
    *(byte *)(iVar3 + 0x11) = *(byte *)(iVar3 + 0x11) | 8;
  }
  return;
}

