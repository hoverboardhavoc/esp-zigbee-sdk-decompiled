/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_mgmt_lqi_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_mgmt_lqi_rsp_wrapper(ezb_zdo_nwk_mgmt_lqi_req_result_t *result,void *user_ctx)

{
  undefined2 uVar1;
  undefined2 uVar2;
  ezb_zdp_nwk_mgmt_lqi_rsp_field_t *peVar3;
  int iVar4;
  ezb_zdp_nwk_mgmt_lqi_neighbor_table_entry_t *peVar5;
  code *pcVar6;
  uint uVar7;
  undefined4 uStack_38;
  esp_zb_zdo_mgmt_lqi_rsp_t lqi_rsp;
  
                    /* WARNING: Load size is inaccurate */
  pcVar6 = *user_ctx;
  if (pcVar6 != (code *)0x0) {
    uStack_38 = 0;
    lqi_rsp.status = '\0';
    lqi_rsp.neighbor_table_entries = '\0';
    lqi_rsp.start_index = '\0';
    lqi_rsp.neighbor_table_list_count = '\0';
    if (result->error == 0) {
      peVar3 = result->rsp;
      if (peVar3 == (ezb_zdp_nwk_mgmt_lqi_rsp_field_t *)0x0) {
        __assert_func(0,0,0,0);
      }
      uStack_38._0_1_ = peVar3->status;
      uStack_38._1_1_ = peVar3->neighbor_table_entries;
      uStack_38._2_1_ = peVar3->start_index;
      uStack_38._3_1_ = peVar3->neighbor_table_list_count;
      if ((peVar3->neighbor_table_list != (ezb_zdp_nwk_mgmt_lqi_neighbor_table_entry_t *)0x0) &&
         (peVar3->neighbor_table_list_count != 0)) {
        lqi_rsp._0_4_ = calloc((uint)peVar3->neighbor_table_list_count,0x16);
        uVar7 = 0;
        if ((void *)lqi_rsp._0_4_ != (void *)0x0) {
          for (; uVar7 < peVar3->neighbor_table_list_count; uVar7 = uVar7 + 1 & 0xff) {
            memcpy((void *)(lqi_rsp._0_4_ + uVar7 * 0x16),peVar3->neighbor_table_list + uVar7,8);
            iVar4 = lqi_rsp._0_4_ + uVar7 * 0x16;
            memcpy((void *)(iVar4 + 8),&result->rsp->neighbor_table_list[uVar7].extended_addr,8);
            peVar3 = result->rsp;
            peVar5 = peVar3->neighbor_table_list;
            uVar1 = *(undefined2 *)&peVar5[uVar7].field_0x12;
            uVar2 = *(undefined2 *)&peVar5[uVar7].field_0x12;
            *(ezb_shortaddr_t *)(iVar4 + 0x10) = peVar5[uVar7].nwk_addr;
            *(byte *)(iVar4 + 0x12) =
                 *(byte *)(iVar4 + 0x12) & 0x80 | (byte)uVar1 & 3 | (byte)uVar2 & 0xc |
                 (byte)*(undefined2 *)&peVar5[uVar7].field_0x12 & 0x70;
            *(byte *)(iVar4 + 0x13) =
                 (byte)((ushort)*(undefined2 *)&peVar5[uVar7].field_0x12 >> 8) & 3;
            *(uint8_t *)(iVar4 + 0x14) = peVar5[uVar7].device_depth;
            *(uint8_t *)(iVar4 + 0x15) = peVar5[uVar7].lqa;
          }
        }
      }
    }
    else {
      uStack_38 = 0x85;
    }
    (*pcVar6)(&uStack_38,*(undefined4 *)((int)user_ctx + 4));
    if (lqi_rsp._0_4_ != 0) {
      free((void *)lqi_rsp._0_4_);
    }
  }
  free(user_ctx);
  return;
}

