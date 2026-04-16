/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_power_desc_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_power_desc_rsp_wrapper(ezb_zdo_power_desc_req_result_t *result,void *user_ctx)

{
  code *pcVar1;
  ezb_zdp_power_desc_rsp_field_t *peVar2;
  undefined4 uStack_18;
  esp_zb_zdo_power_desc_rsp_t power_desc_rsp;
  
                    /* WARNING: Load size is inaccurate */
  pcVar1 = *user_ctx;
  if (pcVar1 != (code *)0x0) {
    uStack_18 = 0;
    power_desc_rsp.status = '\0';
    power_desc_rsp._1_1_ = 0;
    if (result->error == 0) {
      peVar2 = result->rsp;
      if (peVar2 == (ezb_zdp_power_desc_rsp_field_t *)0x0) {
        __assert_func(0,0,0,0);
      }
      uStack_18 = CONCAT31(uStack_18._1_3_,peVar2->status);
      uStack_18 = CONCAT22(peVar2->nwk_addr_of_interest,(undefined2)uStack_18);
      power_desc_rsp._0_2_ = peVar2->power_desc;
    }
    else {
      uStack_18 = 0x85;
    }
    (*pcVar1)(&uStack_18,*(undefined4 *)((int)user_ctx + 4));
  }
  free(user_ctx);
  return;
}

