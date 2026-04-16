/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> search_extended
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_addr_ref_t search_extended(nwk_addr_table_t *tbl,ezb_extaddr_t *extaddr)

{
  int iVar1;
  void *__s2;
  uint uVar2;
  uint uVar3;
  nwk_addr_table_ent_t *__s2_00;
  
  uVar2 = 0;
  while (uVar2 = bitmap_find_next_bit(tbl->ent_in_use,tbl->ent_nr,uVar2), uVar2 < tbl->ent_nr) {
    __s2_00 = tbl->ents + uVar2;
    if ((*(ushort *)&__s2_00->ref_cnt >> 10 & 1) == 0) {
      uVar3 = (uint)(__s2_00->extaddr_c).oui_ref;
      iVar1 = core_globals_get();
      __s2 = (void *)0x0;
      if (uVar3 < 0x20) {
        __s2 = (void *)(iVar1 + uVar3 * 3 + 0xc4a);
      }
      iVar1 = memcmp((void *)((int)&extaddr->field_0 + 5),__s2,3);
      if ((iVar1 == 0) && (iVar1 = memcmp(extaddr,__s2_00,5), iVar1 == 0)) break;
    }
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return (nwk_addr_ref_t)uVar2;
}

