/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
      pvVar1 = (void *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                                     ,0x17a,"esp_zb_zdo_leave_rsp_wrapper","result->rsp");
    }
    (*pcVar2)(0x85,*(undefined4 *)((int)pvVar1 + 4));
  }
_L0:
  free(user_ctx);
  return;
}

