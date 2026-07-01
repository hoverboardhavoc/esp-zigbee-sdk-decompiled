/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: itor */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_neighbor_table_restore(void)

{
  bool bVar1;
  int iVar2;
  nwk_neighbor_t *nbr;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStack_28 [4];
  ds_child_info_iterator_t itor;
  
  itor.data._16_2_ = 0;
  itor.data._18_1_ = 0;
  ds_child_info_itor_read((ds_child_info_iterator_t *)auStack_28);
  bVar1 = false;
  iVar2 = 0;
  do {
    if (itor.data._18_1_ != '\0') {
_L0:
      if ((bVar1) || (iVar2 != 0)) {
        nbt_refresh_stored_children();
      }
      return;
    }
    nbr = nwk_neighbor_table_get_by_extended((ezb_extaddr_t *)&itor);
    if (nbr == (nwk_neighbor_t *)0x0) {
      nbr = nwk_neighbor_table_new(false);
      if (nbr == (nwk_neighbor_t *)0x0) {
        iVar2 = 1;
        goto _L0;
      }
    }
    else {
      bVar1 = true;
    }
    memset(nbr,0,0x1c);
    iVar2 = nwk_address_update(&itor,auStack_28._2_2_,nbr);
    if (iVar2 == 0) {
      nwk_address_lock_ref(nbr->addr_ref);
      uVar5 = *(uint *)&nbr->field_0xc;
      *(uint *)&nbr->field_0xc = uVar5 & 0xfffffffc | 2;
      *(uint *)&nbr->field_0xc = uVar5 & 0xfffffc3c | 0x42;
      iVar3 = core_globals_get();
      uVar5 = (*(byte *)(iVar3 + 0xa3c) + 1 & 0xf) << 2;
      uVar6 = *(uint *)&nbr->field_0xc;
      *(uint *)&nbr->field_0xc = uVar6 & 0xffffffc3 | uVar5;
      uVar4 = (itor.data.extaddr.field_0.u8[6] & 0x1f) << 0xd;
      *(uint *)&nbr->field_0xc = uVar6 & 0xfffc1fc3 | uVar5 | uVar4;
      nbr->key_seq = itor.data.extaddr.field_0.u8[7];
      *(uint *)&nbr->field_0xc =
           uVar6 & 0xfffc1bc3 | uVar5 | uVar4 | ((uint)itor.data._12_4_ >> 4 & 1) << 10;
      (nbr->dev).r.router_info = itor.data.extaddr.field_0.u64._4_2_;
      nwk_neighbor_zed_set_timeout(nbr,(byte)itor.data._12_4_ & 0xf);
    }
    else {
      if (iVar2 != 0xd) goto _L0;
      log_write(1,"nwk_neighbor.c","Address conflicts on stored child 0x%016llx(0x%04hx)",
                itor.data._0_4_,itor.data.extaddr.field_0.u64._0_4_,auStack_28._2_2_);
    }
    ds_child_info_next((ds_child_info_iterator_t *)auStack_28);
  } while( true );
}

