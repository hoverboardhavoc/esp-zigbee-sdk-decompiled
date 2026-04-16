/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_power_desc_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_power_desc_rsp_wrapper(ezb_zdo_power_desc_req_result_t *result,void *user_ctx)

{
  ezb_zdp_power_desc_rsp_field_t *peVar1;
  code *pcVar2;
  undefined4 uStack_18;
  esp_zb_zdo_power_desc_rsp_t power_desc_rsp;
  
                    /* WARNING: Load size is inaccurate */
  pcVar2 = *user_ctx;
  if (pcVar2 == (code *)0x0) goto _L0;
  uStack_18 = 0;
  power_desc_rsp.status = '\0';
  power_desc_rsp._1_1_ = 0;
  if (result->error == 0) {
    peVar1 = result->rsp;
    if (peVar1 == (ezb_zdp_power_desc_rsp_field_t *)0x0) {
      __assert_func("//build/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c",300
                    ,"esp_zb_zdo_power_desc_rsp_wrapper","result->rsp");
      goto _L0;
    }
    uStack_18 = CONCAT22(peVar1->nwk_addr_of_interest,(ushort)peVar1->status);
    power_desc_rsp._0_2_ = peVar1->power_desc;
  }
  else {
_L0:
    uStack_18 = CONCAT31(uStack_18._1_3_,0x85);
  }
  (*pcVar2)(&uStack_18,*(undefined4 *)((int)user_ctx + 4));
_L0:
  free(user_ctx);
  return;
}

