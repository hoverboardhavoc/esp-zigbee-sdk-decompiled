/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_bind_table_restore(void)

{
  int iVar1;
  ezb_extaddr_t *src_addr;
  ezb_err_t eVar2;
  undefined1 auStack_2c [4];
  ezb_address_t dst_addr;
  uint8_t uStack_1e;
  uint8_t uStack_1d;
  ds_bind_info_iterator_t itor;
  
  iVar1 = core_globals_get();
  itor.data.field_3._4_2_ = 0;
  itor.data.field_3._6_1_ = 0;
  *(byte *)(iVar1 + 0x980) = *(byte *)(iVar1 + 0x980) | 1;
  ds_bind_info_itor_read((ds_bind_info_iterator_t *)((int)&dst_addr.u + 6));
  while( true ) {
    if (itor.data.field_3._6_1_ != '\0') {
      iVar1 = core_globals_get();
      *(byte *)(iVar1 + 0x980) = *(byte *)(iVar1 + 0x980) & 0xfe;
      return;
    }
    if (uStack_1d == '\0') {
      memset(auStack_2c + 1,0,9);
      auStack_2c[0] = '\x01';
      auStack_2c._2_2_ = itor.data.cluster_id;
    }
    else {
      auStack_2c[0] = '\x03';
      memcpy(auStack_2c + 2,&itor,8);
    }
    src_addr = (ezb_extaddr_t *)nwk_get_extended_address();
    eVar2 = aps_bind_table_add(src_addr,uStack_1e,dst_addr.u._6_2_,(ezb_address_t *)auStack_2c,
                               uStack_1d);
    if (eVar2 != 0) break;
    if (itor.data.field_3._6_1_ == '\0') {
      itor.data.field_3._4_2_ = itor.data.field_3._4_2_ + 1;
      ds_bind_info_itor_read((ds_bind_info_iterator_t *)((int)&dst_addr.u + 6));
    }
  }
  return;
}

