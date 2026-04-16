/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_active_ep_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_active_ep_rsp_wrapper(ezb_zdo_active_ep_req_result_t *result,void *user_ctx)

{
  byte bVar1;
  void *__dest;
  ezb_zdp_active_ep_rsp_field_t *peVar2;
  code *pcVar3;
  
                    /* WARNING: Load size is inaccurate */
  pcVar3 = *user_ctx;
  if (pcVar3 != (code *)0x0) {
    if (result->error == 0) {
      peVar2 = result->rsp;
      if (peVar2 == (ezb_zdp_active_ep_rsp_field_t *)0x0) {
        __assert_func(0,0,0,0);
      }
      bVar1 = peVar2->active_ep_count;
      __dest = calloc((uint)bVar1,1);
      if (__dest != (void *)0x0) {
        memcpy(__dest,peVar2->active_ep_list,(uint)bVar1);
      }
      (*pcVar3)(peVar2->status,peVar2->active_ep_count,__dest,*(undefined4 *)((int)user_ctx + 4));
      if (__dest != (void *)0x0) {
        free(__dest);
      }
    }
    else if (result->error == 7) {
      (*pcVar3)(0x85,0xff,0,*(undefined4 *)((int)user_ctx + 4));
    }
  }
  free(user_ctx);
  return;
}

