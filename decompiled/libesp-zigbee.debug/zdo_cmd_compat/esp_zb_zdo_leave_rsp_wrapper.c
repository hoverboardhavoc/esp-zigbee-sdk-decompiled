/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_leave_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_leave_rsp_wrapper(ezb_zdo_nwk_mgmt_leave_req_result_t *result,void *user_ctx)

{
  void *pvVar1;
  code *pcVar2;
  
                    /* WARNING: Load size is inaccurate */
  pcVar2 = *user_ctx;
  if (pcVar2 != (code *)0x0) {
    pvVar1 = user_ctx;
    if (result->error == 0) {
      if (result->rsp != (ezb_zdp_nwk_mgmt_leave_rsp_field_t *)0x0) {
        (*pcVar2)(result->rsp->status,*(undefined4 *)((int)user_ctx + 4));
        goto _L0;
      }
      pvVar1 = (void *)__assert_func("//build/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                                     ,0x17a,"esp_zb_zdo_leave_rsp_wrapper","result->rsp");
    }
    (*pcVar2)(0x85,*(undefined4 *)((int)pvVar1 + 4));
  }
_L0:
  free(user_ctx);
  return;
}

