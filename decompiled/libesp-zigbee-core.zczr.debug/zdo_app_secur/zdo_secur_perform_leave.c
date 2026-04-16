/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_secur.o -> zdo_secur_perform_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void zdo_secur_perform_leave(void)

{
  int iVar1;
  int iVar2;
  code *pcStack_18;
  undefined4 uStack_14;
  
  iVar1 = zdo_create_mgmt_req(0x34);
  if (iVar1 != 0) {
    iVar2 = zdo_mgmt_req_get_param();
    *(byte *)(iVar2 + 8) = *(byte *)(iVar2 + 8) | 2;
    iVar2 = zdo_mgmt_req_get_param(iVar1);
    *(byte *)(iVar2 + 8) = *(byte *)(iVar2 + 8) & 0xfe;
    uStack_14 = 0;
    pcStack_18 = zdo_secur_finish_state_after_leave;
    zdo_mgmt_req_set_user_ctx(iVar1,&pcStack_18);
    zdo_send_mgmt_req(iVar1,0);
  }
  return;
}

