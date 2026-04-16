/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_active_scan_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_active_scan_wrapper(ezb_nwk_active_scan_result_t *result,void *user_ctx)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  void *__s1;
  
  uVar2 = (uint)*(byte *)((int)user_ctx + 0x1c4);
  if (result == (ezb_nwk_active_scan_result_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
    iVar3 = 0;
    if (uVar2 != 0) {
      iVar3 = (int)user_ctx + 4;
    }
    if (*user_ctx != (code *)0x0) {
      (**user_ctx)(0,uVar2,iVar3);
    }
    free(user_ctx);
    return;
  }
  if (uVar2 < 0x20) {
    __s1 = (void *)((int)user_ctx + 7);
    for (iVar3 = 0; iVar3 < (int)uVar2; iVar3 = iVar3 + 1) {
      iVar1 = memcmp(__s1,&result->extpanid,8);
      __s1 = (void *)((int)__s1 + 0xe);
      if (iVar1 == 0) {
        return;
      }
    }
    iVar3 = uVar2 * 0xe;
    *(ezb_panid_t *)((int)user_ctx + iVar3 + 4) = result->panid;
    *(byte *)((int)user_ctx + iVar3 + 6) = (byte)*(undefined2 *)&result->field_0x10 & 1;
    memcpy((void *)((int)user_ctx + iVar3 + 7),&result->extpanid,8);
    *(uint8_t *)((int)user_ctx + iVar3 + 0xf) = result->channel_number;
    *(byte *)((int)user_ctx + iVar3 + 0x10) = (byte)(*(ushort *)&result->field_0x10 >> 1) & 1;
    *(byte *)((int)user_ctx + iVar3 + 0x11) = (byte)(*(ushort *)&result->field_0x10 >> 2) & 1;
    *(char *)((int)user_ctx + 0x1c4) = *(char *)((int)user_ctx + 0x1c4) + '\x01';
  }
  return;
}

