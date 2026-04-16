/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_bind_table_add(ezb_extaddr_t *src_addr,uint8_t src_ep,uint16_t cluster_id,
                            ezb_address_t *dst_addr,uint8_t dst_ep)

{
  ushort uVar1;
  _Bool _Var2;
  uint16_t uVar3;
  aps_bind_src_t *src;
  aps_bind_dst_t *dst;
  size_t sVar4;
  undefined2 extraout_var_00;
  int iVar5;
  int iVar6;
  undefined2 extraout_var_01;
  undefined3 extraout_var;
  undefined3 in_register_00002039;
  bitmap_t *pbVar7;
  
  if (0xfd < (byte)(src_ep - 1)) {
    return 2;
  }
  if (((dst_addr->addr_mode != '\x03') || (CONCAT31(in_register_00002039,dst_ep) == 0)) &&
     (dst_addr->addr_mode != '\x01')) {
    return 2;
  }
  src = bind_table_find_src(src_addr,src_ep,cluster_id);
  if (src == (aps_bind_src_t *)0x0) {
    iVar5 = core_globals_get();
    iVar6 = *(int *)(iVar5 + 0x968);
    iVar5 = core_globals_get();
    pbVar7 = *(bitmap_t **)(iVar5 + 0x96c);
    sVar4 = bind_src_size();
    iVar5 = core_globals_get();
    uVar1 = *(ushort *)(iVar5 + 0x970);
    uVar3 = mempool_alloc_idx(pbVar7,uVar1);
    if ((uint)uVar1 <= CONCAT22(extraout_var_00,uVar3)) {
      return 1;
    }
    src = (aps_bind_src_t *)(iVar6 + (sVar4 & 0xffff) * CONCAT22(extraout_var_00,uVar3));
    if (src == (aps_bind_src_t *)0x0) {
      return 1;
    }
    sVar4 = bind_src_size();
    memset(src,0,sVar4);
    src->addr_ref = 0xffff;
    iVar5 = nwk_address_by_extended(src_addr,1,src);
    if (iVar5 != 0) goto _L0;
    src->src_ep = src_ep;
    src->cluster_id = cluster_id;
  }
  dst = bind_table_find_dst(dst_addr,dst_ep);
  if (dst != (aps_bind_dst_t *)0x0) goto _L0;
  iVar5 = core_globals_get();
  iVar5 = *(int *)(iVar5 + 0x974);
  iVar6 = core_globals_get();
  pbVar7 = *(bitmap_t **)(iVar6 + 0x978);
  iVar6 = core_globals_get();
  uVar1 = *(ushort *)(iVar6 + 0x97c);
  uVar3 = mempool_alloc_idx(pbVar7,uVar1);
  if (CONCAT22(extraout_var_01,uVar3) < (uint)uVar1) {
    dst = (aps_bind_dst_t *)(iVar5 + CONCAT22(extraout_var_01,uVar3) * 6);
    if (dst != (aps_bind_dst_t *)0x0) {
      *(undefined1 *)&dst->field_0 = 0;
      *(undefined1 *)((int)&dst->field_0 + 1) = 0;
      (dst->field_0).extaddr.endpoint = '\0';
      *(undefined1 *)((int)&dst->field_0 + 3) = 0;
      dst->ref_cnt = '\0';
      dst->field_0x5 = 0;
      if (dst_addr->addr_mode == '\x01') {
        (dst->field_0).extaddr.addr_ref = (dst_addr->u).short_addr;
        dst->field_0x5 = dst->field_0x5 | 1;
      }
      else {
        iVar5 = nwk_address_by_extended(&dst_addr->u,1,dst);
        if (iVar5 != 0) {
          bind_dst_table_free(dst);
          goto _L0;
        }
        (dst->field_0).extaddr.endpoint = dst_ep;
      }
_L0:
      bind_table_bind(src,dst);
      return 0;
    }
    iVar5 = 1;
  }
  else {
    iVar5 = 1;
  }
_L0:
  _Var2 = bind_src_is_empty(src);
  if (CONCAT31(extraout_var,_Var2) != 0) {
    bind_src_table_free(src);
  }
  return iVar5;
}

