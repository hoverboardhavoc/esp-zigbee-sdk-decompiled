/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_binding_table_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: table_info */
/* WARNING: Unknown calling convention */

void esp_zb_zdo_binding_table_rsp_wrapper(ezb_zdo_nwk_mgmt_bind_req_result_t *result,void *user_ctx)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  uint8_t uVar5;
  uint8_t uVar6;
  uint8_t uVar7;
  uint8_t uVar8;
  uint8_t uVar9;
  uint8_t uVar10;
  uint8_t uVar11;
  uint uVar12;
  uint extraout_a1;
  uint uVar13;
  ezb_zdp_nwk_mgmt_bind_table_entry_t *peVar14;
  char *pcVar15;
  uint8_t *puVar16;
  int in_a4;
  ezb_zdp_nwk_mgmt_bind_rsp_field_t *peVar17;
  int in_a6;
  code *pcVar18;
  undefined4 uStack_18;
  esp_zb_zdo_binding_table_info_t table_info;
  
                    /* WARNING: Load size is inaccurate */
  pcVar18 = *user_ctx;
  uStack_18 = 0;
  table_info.status = '\0';
  table_info.index = '\0';
  table_info.total = '\0';
  table_info.count = '\0';
  if (pcVar18 != (code *)0x0) {
    if (result->error == 0) {
      peVar17 = result->rsp;
      if (peVar17 == (ezb_zdp_nwk_mgmt_bind_rsp_field_t *)0x0) {
        pcVar15 = "result->rsp";
        uVar12 = __assert_func("//build/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                               ,0x1ca,"esp_zb_zdo_binding_table_rsp_wrapper");
        uVar13 = extraout_a1;
        goto _L0;
      }
      bVar1 = peVar17->binding_table_list_count;
      uStack_18 = CONCAT13(bVar1,CONCAT12(peVar17->binding_table_entries,
                                          CONCAT11(peVar17->start_index,peVar17->status)));
      if ((peVar17->binding_table_list != (ezb_zdp_nwk_mgmt_bind_table_entry_t *)0x0) &&
         (bVar1 != 0)) {
        table_info._0_4_ = calloc((uint)bVar1,0x1c);
        if ((void *)table_info._0_4_ != (void *)0x0) {
          uVar12 = 0;
          while (uVar12 < result->rsp->binding_table_list_count) {
            puVar16 = (uint8_t *)(table_info._0_4_ + uVar12 * 0x1c);
            in_a4 = uVar12 * 0x18;
            peVar14 = result->rsp->binding_table_list + uVar12;
            uVar5 = (peVar14->src_addr).field_0.u8[1];
            uVar6 = (peVar14->src_addr).field_0.u8[2];
            uVar7 = (peVar14->src_addr).field_0.u8[3];
            uVar8 = (peVar14->src_addr).field_0.u8[4];
            uVar9 = (peVar14->src_addr).field_0.u8[5];
            uVar10 = (peVar14->src_addr).field_0.u8[6];
            uVar11 = (peVar14->src_addr).field_0.u8[7];
            *puVar16 = (peVar14->src_addr).field_0.u8[0];
            puVar16[1] = uVar5;
            puVar16[2] = uVar6;
            puVar16[3] = uVar7;
            puVar16[4] = uVar8;
            puVar16[5] = uVar9;
            puVar16[6] = uVar10;
            puVar16[7] = uVar11;
            peVar17 = (ezb_zdp_nwk_mgmt_bind_rsp_field_t *)(uVar12 * 0x1c + table_info._0_4_);
            peVar17[1].status = result->rsp->binding_table_list[uVar12].src_ep;
            peVar14 = result->rsp->binding_table_list + uVar12;
            uVar2 = *(undefined1 *)((int)&peVar14->cluster_id + 1);
            peVar17[1].start_index = *(undefined1 *)&peVar14->cluster_id;
            peVar17[1].binding_table_list_count = uVar2;
            *(uint8_t *)&peVar17[1].binding_table_list =
                 result->rsp->binding_table_list[uVar12].dst_addr_mode;
            pcVar15 = (char *)(result->rsp->binding_table_list + uVar12);
            uVar13 = uVar12;
            in_a6 = table_info._0_4_;
            if (((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar15)->dst_addr_mode == '\x01') {
              *(ezb_shortaddr_t *)((int)&peVar17[1].binding_table_list + 2) =
                   (((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar15)->dst_addr).short_addr;
            }
            else {
_L0:
              uVar2 = *(undefined1 *)
                       ((int)&((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar15)->dst_addr + 1);
              uVar5 = *(uint8_t *)
                       ((int)&((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar15)->dst_addr + 2);
              uVar6 = *(uint8_t *)
                       ((int)&((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar15)->dst_addr + 3);
              uVar7 = *(uint8_t *)
                       ((int)&((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar15)->dst_addr + 4);
              uVar8 = *(uint8_t *)
                       ((int)&((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar15)->dst_addr + 5);
              uVar3 = *(undefined1 *)
                       ((int)&((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar15)->dst_addr + 6);
              uVar4 = *(undefined1 *)
                       ((int)&((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar15)->dst_addr + 7);
              *(undefined1 *)((int)&peVar17[1].binding_table_list + 2) =
                   *(undefined1 *)&((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar15)->dst_addr;
              *(undefined1 *)((int)&peVar17[1].binding_table_list + 3) = uVar2;
              peVar17[2].status = uVar5;
              peVar17[2].binding_table_entries = uVar6;
              peVar17[2].start_index = uVar7;
              peVar17[2].binding_table_list_count = uVar8;
              *(undefined1 *)&peVar17[2].binding_table_list = uVar3;
              *(undefined1 *)((int)&peVar17[2].binding_table_list + 1) = uVar4;
            }
            *(uint8_t *)((int)&peVar17[2].binding_table_list + 2) =
                 (&result->rsp->binding_table_list->dst_ep)[in_a4];
            if ((int)uVar13 < (int)(result->rsp->binding_table_list_count - 1)) {
              in_a6 = (uVar12 + 1) * 0x1c + in_a6;
            }
            else {
              in_a6 = 0;
            }
            peVar17[3].status = (char)in_a6;
            peVar17[3].binding_table_entries = (char)((uint)in_a6 >> 8);
            peVar17[3].start_index = (char)((uint)in_a6 >> 0x10);
            peVar17[3].binding_table_list_count = (char)((uint)in_a6 >> 0x18);
            uVar12 = uVar13 + 1 & 0xff;
          }
        }
      }
    }
    else {
      uStack_18 = 0x85;
    }
    (*pcVar18)(&uStack_18,*(undefined4 *)((int)user_ctx + 4));
  }
  if (table_info._0_4_ != 0) {
    free((void *)table_info._0_4_);
  }
  free(user_ctx);
  return;
}

