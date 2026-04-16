/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_dup.o -> aps_dup_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_dup_table_add(aps_dup_table_t *tbl,aps_header_t *aps_hdr)

{
  byte bVar1;
  byte bVar2;
  aps_dup_t *paVar3;
  uint uVar4;
  uint16_t uVar5;
  undefined2 extraout_var;
  int iVar6;
  uint uVar7;
  ushort uVar8;
  ushort uVar9;
  
  paVar3 = tbl->ents;
  uVar9 = tbl->ent_nr;
  uVar5 = mempool_alloc_idx(tbl->ent_in_use,uVar9);
  if (CONCAT22(extraout_var,uVar5) < (uint)uVar9) {
    paVar3 = paVar3 + CONCAT22(extraout_var,uVar5);
  }
  else {
    paVar3 = (aps_dup_t *)0x0;
  }
  if (paVar3 == (aps_dup_t *)0x0) {
    uVar9 = 0xff;
    uVar4 = 0;
    uVar7 = 0;
    while (uVar7 = bitmap_find_next_bit(tbl->ent_in_use,tbl->ent_nr,uVar7), uVar7 < tbl->ent_nr) {
      uVar8 = *(ushort *)&tbl->ents[uVar7].aps_cntr >> 8 & 0x3f;
      if (uVar8 < uVar9) {
        uVar4 = uVar7;
        uVar9 = uVar8;
      }
      uVar7 = uVar7 + 1 & 0xffff;
    }
    paVar3 = tbl->ents + uVar4;
  }
  paVar3->src_addr = (aps_hdr->addr_info).src_addr;
  paVar3->aps_cntr = aps_hdr->aps_cntr;
  paVar3->field_0x3 = ((aps_hdr->fcf & 0xc) == 0) << 6 | paVar3->field_0x3 & 0xbf;
  bVar2 = ((aps_hdr->fcf & 3) == 1) << 7;
  bVar1 = paVar3->field_0x3;
  paVar3->field_0x3 = bVar2 | bVar1 & 0x7f;
  paVar3->field_0x3 = bVar2 | bVar1 & 0x40 | 7;
  iVar6 = time_ticker_is_receiver_registered(4);
  if (iVar6 == 0) {
    time_ticker_register_receiver(4);
  }
  return;
}

