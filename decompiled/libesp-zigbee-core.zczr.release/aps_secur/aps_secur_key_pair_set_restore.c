/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_key_pair_set_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_secur_key_pair_set_restore(void)

{
  ushort blk_nr;
  bool bVar1;
  uint16_t uVar2;
  aps_device_key_pair_t *paVar3;
  int iVar4;
  undefined2 extraout_var;
  int iVar5;
  ezb_err_t eVar6;
  uint uVar7;
  bitmap_t *blk_busy;
  undefined1 auStack_54 [4];
  ds_aps_key_pair_iterator_t itor;
  
  itor.data.supported_kn_methods = '\0';
  itor.data.supported_kn_secrets = '\0';
  itor.data.flags._0_1_ = '\0';
  bVar1 = false;
  ds_aps_key_pair_itor_read((ds_aps_key_pair_iterator_t *)auStack_54);
  while ((char)itor.data.flags == '\0') {
    paVar3 = aps_secur_get_key_pair_by_addr((ezb_extaddr_t *)auStack_54);
    if (paVar3 == (aps_device_key_pair_t *)0x0) {
      iVar5 = core_globals_get();
      iVar5 = *(int *)(iVar5 + 0x9a0);
      iVar4 = core_globals_get();
      blk_busy = *(bitmap_t **)(iVar4 + 0x9a4);
      iVar4 = core_globals_get();
      blk_nr = *(ushort *)(iVar4 + 0x9a8);
      uVar2 = mempool_alloc_idx(blk_busy,blk_nr);
      if (((uint)blk_nr <= CONCAT22(extraout_var,uVar2)) ||
         (paVar3 = (aps_device_key_pair_t *)(iVar5 + CONCAT22(extraout_var,uVar2) * 0x38),
         paVar3 == (aps_device_key_pair_t *)0x0)) goto _L0;
    }
    else {
      bVar1 = true;
    }
    memset(&paVar3->incoming_frame_cntr,0,0x2c);
    (paVar3->device_address).field_0.u8[0] = auStack_54[0];
    (paVar3->device_address).field_0.u8[1] = auStack_54[1];
    (paVar3->device_address).field_0.u8[3] = auStack_54[3];
    (paVar3->device_address).field_0.u8[4] = (uint8_t)itor.data.device_address.field_0.u64._0_4_;
    (paVar3->device_address).field_0.u8[5] =
         (uint8_t)((uint)itor.data.device_address.field_0._0_4_ >> 8);
    (paVar3->device_address).field_0.u8[6] =
         (uint8_t)((uint)itor.data.device_address.field_0._0_4_ >> 0x10);
    (paVar3->device_address).field_0.u8[7] =
         (uint8_t)((uint)itor.data.device_address.field_0._0_4_ >> 0x18);
    (paVar3->device_address).field_0.u8[2] = auStack_54[2];
    memcpy(paVar3->link_key,(void *)((int)&itor.data.device_address.field_0 + 4),0x10);
    memcpy(paVar3->passphrase,itor.data.link_key + 0xc,0x10);
    paVar3->outgoing_frame_cntr = itor.data.passphrase._12_4_;
    paVar3->supported_kn_methods = (undefined1)itor.data.outgoing_frame_cntr;
    paVar3->supported_kn_secrets = itor.data.outgoing_frame_cntr._1_1_;
    paVar3->field_8 = itor.data.outgoing_frame_cntr._2_2_;
    if ((char)itor.data.flags == '\0') {
      itor.data._44_2_ = itor.data._44_2_ + 1;
      ds_aps_key_pair_itor_read((ds_aps_key_pair_iterator_t *)auStack_54);
    }
  }
  if (bVar1) {
_L0:
    iVar5 = ds_internal_remove_entry(9,0xffffffff,0);
    if (iVar5 == 0) {
      iVar5 = core_globals_get();
      uVar7 = 0;
      while ((uVar7 = bitmap_find_next_bit
                                (*(undefined4 *)(iVar5 + 0x9a4),*(undefined2 *)(iVar5 + 0x9a8),uVar7
                                ), uVar7 < *(ushort *)(iVar5 + 0x9a8) &&
             (eVar6 = aps_secur_store_key_pair
                                ((aps_device_key_pair_t *)(uVar7 * 0x38 + *(int *)(iVar5 + 0x9a0))),
             eVar6 == 0))) {
        uVar7 = uVar7 + 1 & 0xffff;
      }
    }
  }
  return;
}

