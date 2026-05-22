/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> addr_table_ref_redirect
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void addr_table_ref_redirect
               (nwk_addr_table_t *tbl,nwk_addr_ref_t source_ref,nwk_addr_ref_t target_ref)

{
  char cVar1;
  undefined2 in_register_0000202e;
  int iVar2;
  undefined2 in_register_00002032;
  int iVar3;
  nwk_addr_table_ent_t *source;
  
  iVar3 = CONCAT22(in_register_00002032,target_ref);
  iVar2 = CONCAT22(in_register_0000202e,source_ref);
  cVar1 = *(char *)((int)tbl + iVar2 * 0x12 + 0x10);
  *(nwk_addr_ref_t *)((int)tbl + iVar3 * 0x12 + 0xe) = source_ref;
  *(char *)((int)tbl + iVar3 * 0x12 + 0x10) = *(char *)((int)tbl + iVar3 * 0x12 + 0x10) + cVar1;
  *(nwk_addr_ref_t *)((int)tbl + iVar2 * 0x12 + 0xe) = target_ref;
  *(byte *)((int)tbl + iVar2 * 0x12 + 0x11) = *(byte *)((int)tbl + iVar2 * 0x12 + 0x11) | 4;
  return;
}

