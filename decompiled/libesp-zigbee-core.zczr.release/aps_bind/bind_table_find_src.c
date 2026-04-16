/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> bind_table_find_src
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

aps_bind_src_t * bind_table_find_src(ezb_extaddr_t *src_addr,uint8_t src_ep,uint16_t cluster_id)

{
  int iVar1;
  size_t sVar2;
  undefined3 in_register_0000202d;
  undefined2 in_register_00002032;
  uint uVar3;
  aps_bind_src_t *tmp_src;
  int iVar4;
  aps_bind_src_t *paVar5;
  int iStack_28;
  ezb_extaddr_t tmp_src_addr;
  
  iVar1 = core_globals_get();
  uVar3 = 0;
  do {
    uVar3 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar1 + 0x96c),*(undefined2 *)(iVar1 + 0x970),uVar3);
    if (*(ushort *)(iVar1 + 0x970) <= uVar3) {
      return (aps_bind_src_t *)0x0;
    }
    iVar4 = *(int *)(iVar1 + 0x968);
    sVar2 = bind_src_size();
    paVar5 = (aps_bind_src_t *)(iVar4 + uVar3 * sVar2);
    if (((uint)paVar5->src_ep == CONCAT31(in_register_0000202d,src_ep)) &&
       ((uint)paVar5->cluster_id == CONCAT22(in_register_00002032,cluster_id))) {
      iVar4 = nwk_address_extended_by_ref(paVar5->addr_ref,&iStack_28);
      if (iVar4 != 0) {
        __assert_func(0,0,0,0);
      }
      if ((iStack_28 == *(int *)&src_addr->field_0) &&
         (tmp_src_addr.field_0.u64._0_4_ == *(int *)((int)&src_addr->field_0 + 4))) {
        return paVar5;
      }
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while( true );
}

