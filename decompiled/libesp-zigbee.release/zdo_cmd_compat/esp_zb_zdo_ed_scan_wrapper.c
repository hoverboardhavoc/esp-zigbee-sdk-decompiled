/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_ed_scan_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_ed_scan_wrapper(ezb_nwk_ed_scan_result_t *result,void *user_ctx)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)((int)user_ctx + 0x24);
  uVar2 = (uint)uVar1;
  if (result != (ezb_nwk_ed_scan_result_t *)0x0) {
    if (uVar2 < 0x10) {
      *(uint8_t *)((int)user_ctx + uVar2 * 2 + 4) = result->channel_number;
      *(int8_t *)((int)user_ctx + uVar2 * 2 + 5) = result->max_rssi;
      *(ushort *)((int)user_ctx + 0x24) = uVar1 + 1;
    }
    return;
  }
                    /* WARNING: Load size is inaccurate */
  iVar3 = 0;
  if (uVar2 != 0) {
    iVar3 = (int)user_ctx + 4;
  }
  if (*user_ctx != (code *)0x0) {
    (**user_ctx)(0,iVar3);
  }
  free(user_ctx);
  return;
}

