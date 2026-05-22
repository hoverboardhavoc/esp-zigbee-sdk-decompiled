/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_table_dump_dst
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bind_table_dump_dst(aps_bind_dst_t *dst)

{
  ushort uVar1;
  uint uVar2;
  _Bool _Var3;
  uint16_t uVar4;
  uint16_t uVar5;
  int iVar6;
  ezb_extaddr_t *src_addr;
  aps_bind_src_t *src;
  aps_bind_dst_t *dst_00;
  size_t sVar7;
  undefined2 extraout_var_00;
  int iVar8;
  undefined2 extraout_var_01;
  undefined3 extraout_var;
  int extraout_a1;
  char *dst_addr_00;
  int iVar9;
  bitmap_t *pbVar10;
  undefined4 uStack_18;
  ezb_extaddr_t dst_addr;
  
  iVar6 = core_globals_get();
  iVar9 = -0x55555555;
  uVar2 = ((int)dst - *(int *)(iVar6 + 0x974) >> 1) * -0x55555555;
  if ((dst->field_0x5 & 1) != 0) {
    log_write(3,"aps_bind.c",0x10eb4,uVar2 & 0xffff,(dst->field_0).extaddr.addr_ref);
    return;
  }
  iVar6 = nwk_address_extended_by_ref((dst->field_0).extaddr.addr_ref,&uStack_18);
  if (iVar6 == 0) {
    log_write(3,"aps_bind.c",0x10ec8,uVar2 & 0xffff,uStack_18,dst_addr.field_0.u64._0_4_,
              (dst->field_0).extaddr.endpoint);
    return;
  }
  dst_addr_00 = "(nwk_address_extended_by_ref(dst->extaddr.addr_ref, &dst_addr)) == 0";
  uVar5 = 0x1c64;
  src_addr = (ezb_extaddr_t *)
             __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x1c7);
  if (0xfd < (extraout_a1 - 1U & 0xff)) {
    return;
  }
  if (((((ezb_address_t *)dst_addr_00)->addr_mode != '\x03') || (iVar9 == 0)) &&
     (((ezb_address_t *)dst_addr_00)->addr_mode != '\x01')) {
    return;
  }
  src = bind_table_find_src(src_addr,(uint8_t)extraout_a1,uVar5);
  if (src == (aps_bind_src_t *)0x0) {
    iVar6 = core_globals_get();
    iVar8 = *(int *)(iVar6 + 0x968);
    iVar6 = core_globals_get();
    pbVar10 = *(bitmap_t **)(iVar6 + 0x96c);
    sVar7 = bind_src_size();
    iVar6 = core_globals_get();
    uVar1 = *(ushort *)(iVar6 + 0x970);
    uVar4 = mempool_alloc_idx(pbVar10,uVar1);
    if ((uint)uVar1 <= CONCAT22(extraout_var_00,uVar4)) {
      return;
    }
    src = (aps_bind_src_t *)(iVar8 + (sVar7 & 0xffff) * CONCAT22(extraout_var_00,uVar4));
    if (src == (aps_bind_src_t *)0x0) {
      return;
    }
    sVar7 = bind_src_size();
    memset(src,0,sVar7);
    src->addr_ref = 0xffff;
    iVar6 = nwk_address_by_extended(src_addr,1,src);
    if (iVar6 == 0) {
      src->src_ep = (uint8_t)extraout_a1;
      src->cluster_id = uVar5;
      goto _L0;
    }
_L0:
    _Var3 = bind_src_is_empty(src);
    if (CONCAT31(extraout_var,_Var3) != 0) {
      bind_src_table_free(src);
    }
  }
  else {
_L0:
    dst_00 = bind_table_find_dst((ezb_address_t *)dst_addr_00,(uint8_t)iVar9);
    if (dst_00 == (aps_bind_dst_t *)0x0) {
      iVar6 = core_globals_get();
      iVar6 = *(int *)(iVar6 + 0x974);
      iVar8 = core_globals_get();
      pbVar10 = *(bitmap_t **)(iVar8 + 0x978);
      iVar8 = core_globals_get();
      uVar1 = *(ushort *)(iVar8 + 0x97c);
      uVar5 = mempool_alloc_idx(pbVar10,uVar1);
      if (((uint)uVar1 <= CONCAT22(extraout_var_01,uVar5)) ||
         (dst_00 = (aps_bind_dst_t *)(iVar6 + CONCAT22(extraout_var_01,uVar5) * 6),
         dst_00 == (aps_bind_dst_t *)0x0)) goto _L0;
      *(undefined1 *)&dst_00->field_0 = 0;
      *(undefined1 *)((int)&dst_00->field_0 + 1) = 0;
      (dst_00->field_0).extaddr.endpoint = '\0';
      *(undefined1 *)((int)&dst_00->field_0 + 3) = 0;
      dst_00->ref_cnt = '\0';
      dst_00->field_0x5 = 0;
      if (((ezb_address_t *)dst_addr_00)->addr_mode == '\x01') {
        (dst_00->field_0).extaddr.addr_ref = (((ezb_address_t *)dst_addr_00)->u).short_addr;
        dst_00->field_0x5 = dst_00->field_0x5 | 1;
      }
      else {
        iVar6 = nwk_address_by_extended(&((ezb_address_t *)dst_addr_00)->u,1,dst_00);
        if (iVar6 != 0) {
          bind_dst_table_free(dst_00);
          goto _L0;
        }
        (dst_00->field_0).extaddr.endpoint = (uint8_t)iVar9;
      }
    }
    bind_table_bind(src,dst_00);
  }
  return;
}

