/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_set_restore
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
  bool bVar2;
  uint16_t uVar3;
  int iVar4;
  int iVar5;
  undefined2 extraout_var;
  aps_device_key_pair_t *__s;
  bitmap_t *blk_busy;
  undefined1 auStack_54 [4];
  ds_aps_key_pair_iterator_t itor;
  
  itor.data.supported_kn_methods = '\0';
  itor.data.supported_kn_secrets = '\0';
  itor.data.flags._0_1_ = '\0';
  ds_aps_key_pair_itor_read((ds_aps_key_pair_iterator_t *)auStack_54);
  bVar1 = false;
  do {
    if ((char)itor.data.flags != '\0') {
      bVar2 = false;
_L0:
      if ((bVar1) || (bVar2)) {
        aps_secur_key_pair_set_refresh_stored_key_pairs();
      }
      return;
    }
    __s = aps_secur_get_key_pair_by_addr((ezb_extaddr_t *)auStack_54);
    if (__s == (aps_device_key_pair_t *)0x0) {
      iVar4 = core_globals_get();
      iVar4 = *(int *)(iVar4 + 0x9a0);
      iVar5 = core_globals_get();
      blk_busy = *(bitmap_t **)(iVar5 + 0x9a4);
      iVar5 = core_globals_get();
      blk_nr = *(ushort *)(iVar5 + 0x9a8);
      uVar3 = mempool_alloc_idx(blk_busy,blk_nr);
      if ((uint)blk_nr <= CONCAT22(extraout_var,uVar3)) {
        bVar2 = true;
        goto _L0;
      }
      __s = (aps_device_key_pair_t *)(iVar4 + CONCAT22(extraout_var,uVar3) * 0x38);
      if (__s == (aps_device_key_pair_t *)0x0) {
        bVar2 = true;
        goto _L0;
      }
    }
    else {
      bVar1 = true;
    }
    memset(__s,0,0x38);
    (__s->device_address).field_0.u8[0] = auStack_54[0];
    (__s->device_address).field_0.u8[1] = auStack_54[1];
    (__s->device_address).field_0.u8[2] = auStack_54[2];
    (__s->device_address).field_0.u8[3] = auStack_54[3];
    (__s->device_address).field_0.u8[4] = (uint8_t)itor.data.device_address.field_0.u64._0_4_;
    (__s->device_address).field_0.u8[5] =
         (uint8_t)((uint)itor.data.device_address.field_0._0_4_ >> 8);
    (__s->device_address).field_0.u8[6] =
         (uint8_t)((uint)itor.data.device_address.field_0._0_4_ >> 0x10);
    (__s->device_address).field_0.u8[7] =
         (uint8_t)((uint)itor.data.device_address.field_0._0_4_ >> 0x18);
    memcpy(__s->link_key,(void *)((int)&itor.data.device_address.field_0 + 4),0x10);
    memcpy(__s->passphrase,itor.data.link_key + 0xc,0x10);
    __s->outgoing_frame_cntr = itor.data.passphrase._12_4_;
    __s->supported_kn_methods = (uint8_t)itor.data.outgoing_frame_cntr;
    __s->supported_kn_secrets = itor.data.outgoing_frame_cntr._1_1_;
    __s->field_8 = itor.data.outgoing_frame_cntr._2_2_;
    ds_aps_key_pair_next((ds_aps_key_pair_iterator_t *)auStack_54);
  } while( true );
}

