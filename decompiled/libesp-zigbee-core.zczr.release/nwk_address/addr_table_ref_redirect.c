/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  cVar1 = *(char *)((int)tbl + iVar2 * 0x10 + 0xe);
  *(nwk_addr_ref_t *)((int)tbl + iVar3 * 0x10 + 0xc) = source_ref;
  *(char *)((int)tbl + iVar3 * 0x10 + 0xe) = *(char *)((int)tbl + iVar3 * 0x10 + 0xe) + cVar1;
  *(nwk_addr_ref_t *)((int)tbl + iVar2 * 0x10 + 0xc) = target_ref;
  *(byte *)((int)tbl + iVar2 * 0x10 + 0xf) = *(byte *)((int)tbl + iVar2 * 0x10 + 0xf) | 4;
  return;
}

