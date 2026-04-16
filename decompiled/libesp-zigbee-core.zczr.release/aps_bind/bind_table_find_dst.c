/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> bind_table_find_dst
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

aps_bind_dst_t * bind_table_find_dst(ezb_address_t *dst_addr,uint8_t dst_ep)

{
  ezb_addr_mode_t eVar1;
  int iVar2;
  int iVar3;
  undefined3 in_register_0000202d;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  aps_bind_dst_t *paVar7;
  ezb_grpaddr_t eStack_38;
  ezb_extaddr_t tmp_dst_addr;
  
  iVar2 = core_globals_get();
  uVar4 = 0;
  do {
    uVar4 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar2 + 0x978),*(undefined2 *)(iVar2 + 0x97c),uVar4);
    if (*(ushort *)(iVar2 + 0x97c) <= uVar4) {
      return (aps_bind_dst_t *)0x0;
    }
    eVar1 = dst_addr->addr_mode;
    paVar7 = (aps_bind_dst_t *)(*(int *)(iVar2 + 0x974) + uVar4 * 6);
    if ((ushort)(eVar1 == '\x01') != (*(ushort *)&paVar7->ref_cnt >> 8 & 1)) goto _L0;
    if (eVar1 == '\x01') {
_L0:
      uVar6 = (uint)(dst_addr->u).short_addr;
      uVar5 = (uint)(paVar7->field_0).extaddr.addr_ref;
_L0:
      if (uVar5 == uVar6) {
        return paVar7;
      }
    }
    else {
      if (eVar1 != '\x03') {
_L0:
        __assert_func(0,0,0,0);
        goto _L0;
      }
      if ((CONCAT31(in_register_0000202d,dst_ep) == 0xff) ||
         ((uint)(paVar7->field_0).extaddr.endpoint == CONCAT31(in_register_0000202d,dst_ep))) {
        iVar3 = nwk_address_extended_by_ref((paVar7->field_0).extaddr.addr_ref,&eStack_38);
        if (iVar3 != 0) goto _L0;
        uVar6 = *(uint *)((int)&dst_addr->u + 4);
        uVar5 = tmp_dst_addr.field_0.u64._0_4_;
        if (eStack_38 != (dst_addr->u).group_addr) goto _L0;
        goto _L0;
      }
    }
_L0:
    uVar4 = uVar4 + 1 & 0xffff;
  } while( true );
}

