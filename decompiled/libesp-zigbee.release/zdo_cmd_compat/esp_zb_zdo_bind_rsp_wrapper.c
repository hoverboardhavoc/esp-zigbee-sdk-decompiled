/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_bind_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_bind_rsp_wrapper(ezb_zdp_bind_req_result_t *result,void *user_ctx)

{
  uint8_t uVar1;
  void *pvVar2;
  undefined4 uVar3;
  ezb_zdp_bind_rsp_field_t *peVar4;
  code *pcVar5;
  
                    /* WARNING: Load size is inaccurate */
  pcVar5 = *user_ctx;
  if (pcVar5 != (code *)0x0) {
    if (result->error == 0) {
      peVar4 = result->rsp;
      pvVar2 = user_ctx;
      if (peVar4 == (ezb_zdp_bind_rsp_field_t *)0x0) {
        pvVar2 = (void *)__assert_func(0,0,0,0);
      }
      uVar3 = *(undefined4 *)((int)pvVar2 + 4);
      uVar1 = peVar4->status;
    }
    else {
      if (result->error != 7) goto _L0;
      uVar3 = *(undefined4 *)((int)user_ctx + 4);
      uVar1 = 0x85;
    }
    (*pcVar5)(uVar1,uVar3);
  }
_L0:
  free(user_ctx);
  return;
}

