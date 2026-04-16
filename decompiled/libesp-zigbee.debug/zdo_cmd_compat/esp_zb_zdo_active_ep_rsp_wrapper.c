/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_active_ep_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_active_ep_rsp_wrapper(ezb_zdo_active_ep_req_result_t *result,void *user_ctx)

{
  byte bVar1;
  void *pvVar2;
  int iVar3;
  code *pcVar4;
  ezb_zdp_active_ep_rsp_field_t *peVar5;
  
                    /* WARNING: Load size is inaccurate */
  pcVar4 = *user_ctx;
  if (pcVar4 != (code *)0x0) {
    iVar3 = result->error;
    pvVar2 = user_ctx;
    if (iVar3 == 0) {
      peVar5 = result->rsp;
      if (peVar5 != (ezb_zdp_active_ep_rsp_field_t *)0x0) {
        bVar1 = peVar5->active_ep_count;
        pvVar2 = calloc((uint)bVar1,1);
        if (pvVar2 != (void *)0x0) {
          memcpy(pvVar2,peVar5->active_ep_list,(uint)bVar1);
        }
        (*pcVar4)(result->rsp->status,result->rsp->active_ep_count,pvVar2,
                  *(undefined4 *)((int)user_ctx + 4));
        if (pvVar2 != (void *)0x0) {
          free(pvVar2);
        }
        goto _L0;
      }
      pvVar2 = (void *)__assert_func("//build/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                                     ,0x162,"esp_zb_zdo_active_ep_rsp_wrapper","result->rsp");
    }
    if (iVar3 == 7) {
      (*pcVar4)(0x85,0xff,0,*(undefined4 *)((int)pvVar2 + 4));
    }
  }
_L0:
  free(user_ctx);
  return;
}

