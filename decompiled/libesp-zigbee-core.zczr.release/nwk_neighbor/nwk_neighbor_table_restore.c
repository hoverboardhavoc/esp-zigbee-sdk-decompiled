/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_neighbor_table_restore(void)

{
  byte bVar1;
  bool bVar2;
  nwk_neighbor_t *pnVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_38 [4];
  ds_child_info_iterator_t itor;
  
  itor.data._16_2_ = 0;
  itor.data._18_1_ = 0;
  bVar2 = false;
  ds_child_info_itor_read((ds_child_info_iterator_t *)auStack_38);
  iVar4 = 0;
  while (itor.data._18_1_ == '\0') {
    pnVar3 = nwk_neighbor_table_get_by_extended((ezb_extaddr_t *)&itor);
    if (pnVar3 == (nwk_neighbor_t *)0x0) {
      pnVar3 = nwk_neighbor_table_new(false);
      if (pnVar3 == (nwk_neighbor_t *)0x0) goto _L0;
    }
    else {
      bVar2 = true;
    }
    memset(pnVar3,0,0x20);
    iVar4 = nwk_address_update(&itor,auStack_38._2_2_,pnVar3);
    if (iVar4 == 0) {
      nwk_address_lock_ref(pnVar3->addr_ref);
      *(ushort *)&pnVar3->field_0xc = *(ushort *)&pnVar3->field_0xc & 0xfc3c | 0x42;
      iVar5 = core_globals_get();
      bVar1 = *(byte *)(iVar5 + 0xa3c);
      pnVar3->key_seq = itor.data.extaddr.field_0.u8[7];
      *(uint *)&pnVar3->field_0xc =
           (itor.data._12_4_ & 0x10) << 6 | (bVar1 + 1 & 0xf) << 2 |
           (itor.data.extaddr.field_0.u8[6] & 0x1f) << 0xd |
           *(uint *)&pnVar3->field_0xc & 0xfffc1bc3;
      (pnVar3->dev).r.router_info = itor.data.extaddr.field_0.u64._4_2_;
      nwk_neighbor_zed_set_timeout(pnVar3,(byte)itor.data._12_4_ & 0xf);
    }
    else {
      if (iVar4 != 0xd) goto _L0;
      log_write(1,"nwk_neighbor.c","Address conflicts on stored child 0x%016llx(0x%04hx)",
                itor.data._0_4_,itor.data.extaddr.field_0.u64._0_4_,auStack_38._2_2_);
    }
    if (itor.data._18_1_ == '\0') {
      itor.data._16_2_ = itor.data._16_2_ + 1;
      ds_child_info_itor_read((ds_child_info_iterator_t *)auStack_38);
    }
  }
  if ((bVar2) || (iVar4 != 0)) {
_L0:
    iVar4 = ds_internal_remove_entry(4,0xffffffff,0);
    pnVar3 = (nwk_neighbor_t *)0x0;
    while ((iVar4 == 0 && (pnVar3 = nwk_child_table_next(pnVar3), pnVar3 != (nwk_neighbor_t *)0x0)))
    {
      iVar4 = nwk_neighbor_table_store_child(pnVar3);
    }
  }
  return;
}

