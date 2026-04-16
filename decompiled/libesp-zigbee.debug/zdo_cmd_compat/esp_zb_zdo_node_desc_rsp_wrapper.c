/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_node_desc_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_node_desc_rsp_wrapper(ezb_zdo_node_desc_req_result_t *result,void *user_ctx)

{
  uint3 uVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined1 uVar5;
  void *pvVar6;
  code *pcVar7;
  ezb_zdp_node_desc_rsp_field_t *peVar8;
  uint local_20;
  esp_zb_af_node_desc_t node_desc_rsp;
  
                    /* WARNING: Load size is inaccurate */
  pcVar7 = *user_ctx;
  if (pcVar7 != (code *)0x0) {
    pvVar6 = user_ctx;
    if (result->error == 0) {
      if (result->rsp != (ezb_zdp_node_desc_rsp_field_t *)0x0) {
        peVar8 = result->rsp;
        uVar1._0_2_ = (peVar8->node_desc).node_flags;
        uVar1._2_1_ = (peVar8->node_desc).mac_capability_flags;
        local_20 = (uint)uVar1;
        uVar2 = (peVar8->node_desc).manufacturer_code;
        uVar3 = (peVar8->node_desc).max_buf_size;
        node_desc_rsp.mac_capability_flags = uVar3;
        node_desc_rsp.node_desc_flags = uVar2;
        node_desc_rsp._3_1_ = 0;
        node_desc_rsp._4_4_ = *(undefined4 *)&(peVar8->node_desc).max_incoming_transfer_size;
        uVar4 = (peVar8->node_desc).max_outgoing_transfer_size;
        uVar5 = (peVar8->node_desc).desc_capability_field;
        node_desc_rsp.server_mask._0_1_ = uVar5;
        node_desc_rsp.max_incoming_transfer_size = uVar4;
        node_desc_rsp.server_mask._1_1_ = 0;
        (*pcVar7)(peVar8->status,peVar8->nwk_addr_of_interest,&local_20,
                  *(undefined4 *)((int)user_ctx + 4));
        goto _L0;
      }
      pvVar6 = (void *)__assert_func("//build/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                                     ,0x111,"esp_zb_zdo_node_desc_rsp_wrapper","result->rsp");
    }
    (*pcVar7)(0x85,0xffff,0,*(undefined4 *)((int)pvVar6 + 4));
  }
_L0:
  free(user_ctx);
  return;
}

