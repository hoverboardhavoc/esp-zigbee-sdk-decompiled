/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_bind_table_add(ezb_extaddr_t *src_addr,uint8_t src_ep,uint16_t cluster_id,
                            ezb_address_t *dst_addr,uint8_t dst_ep)

{
  _Bool _Var1;
  aps_bind_src_t *src;
  int iVar2;
  size_t sVar3;
  aps_bind_dst_t *dst;
  undefined3 extraout_var;
  bitmap_t *pbVar4;
  undefined3 in_register_00002039;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  void *pvVar9;
  undefined1 auStack_44 [4];
  ezb_extaddr_t dst_addr_1;
  dataset_bind_info_t bind_info;
  
  iVar5 = CONCAT31(in_register_00002039,dst_ep);
  dst = (aps_bind_dst_t *)(uint)src_ep;
  if (((uint)&dst[-1].field_0x5 & 0xff) < 0xfe) {
    uVar6 = (uint)dst_addr->addr_mode;
    if (uVar6 != 3) goto _L0;
    if (iVar5 != 0) {
      do {
        src = bind_table_find_src(src_addr,(uint8_t)dst,cluster_id);
        if (src == (aps_bind_src_t *)0x0) {
          iVar2 = core_globals_get();
          pvVar9 = *(void **)(iVar2 + 0x968);
          iVar2 = core_globals_get();
          pbVar4 = *(bitmap_t **)(iVar2 + 0x96c);
          sVar3 = bind_src_size();
          iVar2 = core_globals_get();
          src = (aps_bind_src_t *)
                mempool_alloc_ent(pvVar9,pbVar4,(uint16_t)sVar3,*(uint16_t *)(iVar2 + 0x970));
          if (src == (aps_bind_src_t *)0x0) {
            return 1;
          }
          sVar3 = bind_src_size();
          memset(src,0,sVar3);
          src->addr_ref = 0xffff;
          iVar2 = nwk_address_by_extended(src_addr,1,src);
          if (iVar2 != 0) goto _L0;
          src->src_ep = (uint8_t)dst;
          src->cluster_id = cluster_id;
        }
        dst = bind_table_find_dst(dst_addr,(uint8_t)iVar5);
        if (dst == (aps_bind_dst_t *)0x0) {
          iVar2 = core_globals_get();
          pvVar9 = *(void **)(iVar2 + 0x974);
          iVar2 = core_globals_get();
          pbVar4 = *(bitmap_t **)(iVar2 + 0x978);
          iVar2 = core_globals_get();
          dst = (aps_bind_dst_t *)mempool_alloc_ent(pvVar9,pbVar4,6,*(uint16_t *)(iVar2 + 0x97c));
          if (dst == (aps_bind_dst_t *)0x0) {
            iVar2 = 1;
_L0:
            _Var1 = bind_src_is_empty(src);
            if (CONCAT31(extraout_var,_Var1) != 0) {
              bind_src_table_free(src);
              return iVar2;
            }
            return iVar2;
          }
          memset(dst,0,6);
          if (dst_addr->addr_mode == '\x01') {
            (dst->field_0).extaddr.addr_ref = (dst_addr->u).short_addr;
            dst->field_0x5 = dst->field_0x5 | 1;
          }
          else {
            iVar2 = nwk_address_by_extended(&dst_addr->u,1,dst);
            if (iVar2 != 0) {
              bind_dst_table_free(dst);
              goto _L0;
            }
            (dst->field_0).extaddr.endpoint = (uint8_t)iVar5;
          }
        }
        iVar2 = core_globals_get();
        iVar5 = 0;
        iVar7 = (int)dst - *(int *)(iVar2 + 0x974) >> 1;
        src_addr = (ezb_extaddr_t *)(iVar7 * -0x55555555);
        iVar2 = core_globals_get();
        uVar6 = (uint)src_addr & 0xffff;
        if (uVar6 < *(ushort *)(iVar2 + 0x97c)) {
          uVar8 = 1 << ((uint)src_addr & 7) & 0xff;
          uVar6 = __atomic_fetch_or_1((int)&src[1].addr_ref + ((uint)(iVar7 * -0x55550000) >> 0x13),
                                      uVar8,5);
          if ((uVar8 & uVar6) != 0) {
            return 0;
          }
          dst->ref_cnt = dst->ref_cnt + '\x01';
          iVar2 = core_globals_get();
          if ((*(uint *)(iVar2 + 0x980) & 1) != 0) {
            return 0;
          }
          dst_addr_1.field_0.u64._4_4_ = 0;
          aps_bind_table_remove_stored_bind(src,dst);
          dst_addr_1.field_0.u8[6] = src->src_ep;
          dst_addr_1.field_0.u64._4_2_ = src->cluster_id;
          uVar6 = (byte)dst->field_0x5 & 1;
          if ((dst->field_0x5 & 1) != 0) {
            dst_addr_1.field_0.u8[7] = 0;
_L0:
            ds_internal_add_entry(6,(undefined1 *)((int)&dst_addr_1.field_0 + 4),0xc);
            return 0;
          }
          iVar2 = nwk_address_extended_by_ref(auStack_44);
          dst_addr = (ezb_address_t *)0x0;
          if (iVar2 == 0) {
            dst_addr_1.field_0.u8[7] = (dst->field_0).extaddr.endpoint;
            goto _L0;
          }
        }
        __assert_func(0,0,0,0);
_L0:
      } while (uVar6 == 1);
    }
  }
  return 2;
}

