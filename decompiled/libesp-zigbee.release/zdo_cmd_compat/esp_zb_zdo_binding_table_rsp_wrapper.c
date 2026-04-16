/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_binding_table_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_binding_table_rsp_wrapper(ezb_zdo_nwk_mgmt_bind_req_result_t *result,void *user_ctx)

{
  byte bVar1;
  uint8_t uVar2;
  undefined4 uVar3;
  ezb_zdp_nwk_mgmt_bind_rsp_field_t *peVar4;
  uint uVar5;
  int iVar6;
  ezb_zdp_nwk_mgmt_bind_table_entry_t *peVar7;
  int iVar8;
  int iVar9;
  code *pcVar10;
  undefined4 uStack_48;
  esp_zb_zdo_binding_table_info_t table_info;
  
                    /* WARNING: Load size is inaccurate */
  pcVar10 = *user_ctx;
  uStack_48 = 0;
  table_info.status = '\0';
  table_info.index = '\0';
  table_info.total = '\0';
  table_info.count = '\0';
  if (pcVar10 != (code *)0x0) {
    if (result->error == 0) {
      peVar4 = result->rsp;
      if (peVar4 == (ezb_zdp_nwk_mgmt_bind_rsp_field_t *)0x0) {
        __assert_func(0,0,0,0);
      }
      bVar1 = peVar4->binding_table_list_count;
      uStack_48 = CONCAT13(bVar1,CONCAT12(peVar4->binding_table_entries,
                                          CONCAT11(peVar4->start_index,peVar4->status)));
      if ((peVar4->binding_table_list != (ezb_zdp_nwk_mgmt_bind_table_entry_t *)0x0) && (bVar1 != 0)
         ) {
        table_info._0_4_ = calloc((uint)bVar1,0x1c);
        if ((void *)table_info._0_4_ != (void *)0x0) {
          uVar5 = 0;
          do {
            iVar9 = uVar5 * 0x1c;
            memcpy((void *)(table_info._0_4_ + iVar9),peVar4->binding_table_list + uVar5,8);
            uVar3 = table_info._0_4_;
            peVar7 = result->rsp->binding_table_list;
            iVar8 = table_info._0_4_ + iVar9;
            *(uint8_t *)(iVar8 + 8) = peVar7[uVar5].src_ep;
            *(uint16_t *)(iVar8 + 10) = peVar7[uVar5].cluster_id;
            uVar2 = peVar7[uVar5].dst_addr_mode;
            *(uint8_t *)(iVar8 + 0xc) = uVar2;
            if (uVar2 == '\x01') {
              *(ezb_shortaddr_t *)(iVar8 + 0xe) = peVar7[uVar5].dst_addr.short_addr;
            }
            else {
              memcpy((void *)(iVar8 + 0xe),&peVar7[uVar5].dst_addr,8);
            }
            peVar4 = result->rsp;
            iVar6 = 0;
            *(uint8_t *)(iVar8 + 0x16) = peVar4->binding_table_list[uVar5].dst_ep;
            bVar1 = peVar4->binding_table_list_count;
            if ((int)uVar5 < (int)(bVar1 - 1)) {
              iVar6 = uVar3 + iVar9 + 0x1c;
            }
            *(int *)(iVar8 + 0x18) = iVar6;
            uVar5 = uVar5 + 1 & 0xff;
          } while (uVar5 < bVar1);
        }
      }
    }
    else {
      uStack_48 = 0x85;
    }
    (*pcVar10)(&uStack_48,*(undefined4 *)((int)user_ctx + 4));
  }
  if (table_info._0_4_ != 0) {
    free((void *)table_info._0_4_);
  }
  free(user_ctx);
  return;
}

