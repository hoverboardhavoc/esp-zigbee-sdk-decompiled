/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_active_scan_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_active_scan_wrapper(ezb_nwk_active_scan_result_t *result,void *user_ctx)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (result == (ezb_nwk_active_scan_result_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
    iVar1 = 0;
    if (*(char *)((int)user_ctx + 0x1c4) != '\0') {
      iVar1 = (int)user_ctx + 4;
    }
    if (*user_ctx != (code *)0x0) {
      (**user_ctx)(0,iVar1);
    }
    free(user_ctx);
  }
  else {
    uVar3 = (uint)*(byte *)((int)user_ctx + 0x1c4);
    if (uVar3 < 0x20) {
      for (iVar1 = 0; iVar1 < (int)uVar3; iVar1 = iVar1 + 1) {
        iVar2 = memcmp((void *)((int)user_ctx + iVar1 * 0xe + 7),&result->extpanid,8);
        if (iVar2 == 0) {
          return;
        }
      }
      ezb_active_scan_result_to_esp
                (result,(esp_zb_network_descriptor_t *)((int)user_ctx + uVar3 * 0xe + 4));
      *(char *)((int)user_ctx + 0x1c4) = *(char *)((int)user_ctx + 0x1c4) + '\x01';
    }
  }
  return;
}

