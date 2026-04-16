/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_mgmt_lqi_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: lqi_rsp */
/* WARNING: Unknown calling convention */

void esp_zb_zdo_mgmt_lqi_rsp_wrapper(ezb_zdo_nwk_mgmt_lqi_req_result_t *result,void *user_ctx)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  uint8_t uVar5;
  uint8_t uVar6;
  uint8_t uVar7;
  uint uVar8;
  ezb_zdp_nwk_mgmt_lqi_neighbor_table_entry_t *peVar9;
  char *pcVar10;
  ezb_zdp_nwk_mgmt_lqi_rsp_field_t *peVar11;
  uint8_t *puVar12;
  int iVar13;
  code *pcVar14;
  undefined4 uStack_18;
  esp_zb_zdo_mgmt_lqi_rsp_t lqi_rsp;
  
                    /* WARNING: Load size is inaccurate */
  pcVar14 = *user_ctx;
  if (pcVar14 != (code *)0x0) {
    uStack_18 = 0;
    lqi_rsp.status = '\0';
    lqi_rsp.neighbor_table_entries = '\0';
    lqi_rsp.start_index = '\0';
    lqi_rsp.neighbor_table_list_count = '\0';
    if (result->error == 0) {
      peVar11 = result->rsp;
      if (peVar11 == (ezb_zdp_nwk_mgmt_lqi_rsp_field_t *)0x0) {
        pcVar10 = "result->rsp";
        uVar8 = __assert_func("//build/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                              ,0x19d,"esp_zb_zdo_mgmt_lqi_rsp_wrapper");
        goto _L0;
      }
      uStack_18._0_1_ = peVar11->status;
      uStack_18._1_1_ = peVar11->neighbor_table_entries;
      uStack_18._2_1_ = peVar11->start_index;
      uStack_18._3_1_ = peVar11->neighbor_table_list_count;
      if (((peVar11->neighbor_table_list != (ezb_zdp_nwk_mgmt_lqi_neighbor_table_entry_t *)0x0) &&
          (peVar11->neighbor_table_list_count != 0)) &&
         (lqi_rsp._0_4_ = calloc((uint)peVar11->neighbor_table_list_count,0x16),
         (void *)lqi_rsp._0_4_ != (void *)0x0)) {
        for (uVar8 = 0; pcVar10 = (char *)result->rsp,
            uVar8 < ((ezb_zdp_nwk_mgmt_lqi_rsp_field_t *)pcVar10)->neighbor_table_list_count;
            uVar8 = uVar8 + 1 & 0xff) {
_L0:
          puVar12 = (uint8_t *)(lqi_rsp._0_4_ + uVar8 * 0x16);
          peVar9 = ((ezb_zdp_nwk_mgmt_lqi_rsp_field_t *)pcVar10)->neighbor_table_list + uVar8;
          uVar1 = (peVar9->extended_pan_id).field_0.u8[1];
          uVar2 = (peVar9->extended_pan_id).field_0.u8[2];
          uVar3 = (peVar9->extended_pan_id).field_0.u8[3];
          uVar4 = (peVar9->extended_pan_id).field_0.u8[4];
          uVar5 = (peVar9->extended_pan_id).field_0.u8[5];
          uVar6 = (peVar9->extended_pan_id).field_0.u8[6];
          uVar7 = (peVar9->extended_pan_id).field_0.u8[7];
          *puVar12 = (peVar9->extended_pan_id).field_0.u8[0];
          puVar12[1] = uVar1;
          puVar12[2] = uVar2;
          puVar12[3] = uVar3;
          puVar12[4] = uVar4;
          puVar12[5] = uVar5;
          puVar12[6] = uVar6;
          puVar12[7] = uVar7;
          iVar13 = lqi_rsp._0_4_ + uVar8 * 0x16;
          peVar9 = result->rsp->neighbor_table_list;
          uVar1 = peVar9[uVar8].extended_addr.field_0.u8[1];
          uVar2 = peVar9[uVar8].extended_addr.field_0.u8[2];
          uVar3 = peVar9[uVar8].extended_addr.field_0.u8[3];
          uVar4 = peVar9[uVar8].extended_addr.field_0.u8[4];
          uVar5 = peVar9[uVar8].extended_addr.field_0.u8[5];
          uVar6 = peVar9[uVar8].extended_addr.field_0.u8[6];
          uVar7 = peVar9[uVar8].extended_addr.field_0.u8[7];
          *(uint8_t *)(iVar13 + 8) = peVar9[uVar8].extended_addr.field_0.u8[0];
          *(uint8_t *)(iVar13 + 9) = uVar1;
          *(uint8_t *)(iVar13 + 10) = uVar2;
          *(uint8_t *)(iVar13 + 0xb) = uVar3;
          *(uint8_t *)(iVar13 + 0xc) = uVar4;
          *(uint8_t *)(iVar13 + 0xd) = uVar5;
          *(uint8_t *)(iVar13 + 0xe) = uVar6;
          *(uint8_t *)(iVar13 + 0xf) = uVar7;
          *(ezb_shortaddr_t *)(iVar13 + 0x10) = result->rsp->neighbor_table_list[uVar8].nwk_addr;
          *(byte *)(iVar13 + 0x12) =
               *(byte *)(iVar13 + 0x12) & 0xfc |
               (byte)*(undefined2 *)&result->rsp->neighbor_table_list[uVar8].field_0x12 & 3;
          *(byte *)(iVar13 + 0x12) =
               (byte)((*(ushort *)&result->rsp->neighbor_table_list[uVar8].field_0x12 >> 2 & 3) << 2
                     ) | *(byte *)(iVar13 + 0x12) & 0xf3;
          *(byte *)(iVar13 + 0x12) =
               (byte)((*(ushort *)&result->rsp->neighbor_table_list[uVar8].field_0x12 >> 4 & 7) << 4
                     ) | *(byte *)(iVar13 + 0x12) & 0x8f;
          *(byte *)(iVar13 + 0x13) =
               (byte)((ushort)*(undefined2 *)&result->rsp->neighbor_table_list[uVar8].field_0x12 >>
                     8) & 3;
          *(uint8_t *)(iVar13 + 0x14) = result->rsp->neighbor_table_list[uVar8].device_depth;
          *(uint8_t *)(iVar13 + 0x15) = result->rsp->neighbor_table_list[uVar8].lqa;
        }
      }
    }
    else {
      uStack_18 = 0x85;
    }
    (*pcVar14)(&uStack_18,*(undefined4 *)((int)user_ctx + 4));
    if (lqi_rsp._0_4_ != 0) {
      free((void *)lqi_rsp._0_4_);
    }
  }
  free(user_ctx);
  return;
}

