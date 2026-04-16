/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_node_desc_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: node_desc_rsp */
/* WARNING: Unknown calling convention */

void esp_zb_zdo_node_desc_rsp_wrapper(ezb_zdo_node_desc_req_result_t *result,void *user_ctx)

{
  ezb_zdp_node_desc_rsp_field_t *peVar1;
  ezb_zdp_status_t eVar2;
  ezb_shortaddr_t eVar3;
  uint16_t *puVar4;
  undefined4 uVar5;
  code *pcVar6;
  uint16_t local_20;
  uint8_t uStack_1e;
  undefined1 uStack_1d;
  esp_zb_af_node_desc_t node_desc_rsp;
  
  puVar4 = &local_20;
                    /* WARNING: Load size is inaccurate */
  pcVar6 = *user_ctx;
  if (pcVar6 != (code *)0x0) {
    if (result->error == 0) {
      peVar1 = result->rsp;
      if (peVar1 == (ezb_zdp_node_desc_rsp_field_t *)0x0) {
        __assert_func(0,0,0,0);
      }
      memset(&uStack_1d,0,0xd);
      local_20 = (peVar1->node_desc).node_flags;
      uVar5 = *(undefined4 *)((int)user_ctx + 4);
      uStack_1e = (peVar1->node_desc).mac_capability_flags;
      node_desc_rsp.node_desc_flags = (peVar1->node_desc).manufacturer_code;
      node_desc_rsp.mac_capability_flags = (peVar1->node_desc).max_buf_size;
      node_desc_rsp.manufacturer_code = (peVar1->node_desc).max_incoming_transfer_size;
      node_desc_rsp._6_2_ = (peVar1->node_desc).server_mask;
      node_desc_rsp.max_incoming_transfer_size = (peVar1->node_desc).max_outgoing_transfer_size;
      node_desc_rsp.server_mask._0_1_ = (peVar1->node_desc).desc_capability_field;
      eVar3 = peVar1->nwk_addr_of_interest;
      eVar2 = peVar1->status;
    }
    else {
      uVar5 = *(undefined4 *)((int)user_ctx + 4);
      puVar4 = (uint16_t *)0x0;
      eVar3 = 0xffff;
      eVar2 = 0x85;
    }
    (*pcVar6)(eVar2,eVar3,puVar4,uVar5);
  }
  free(user_ctx);
  return;
}

