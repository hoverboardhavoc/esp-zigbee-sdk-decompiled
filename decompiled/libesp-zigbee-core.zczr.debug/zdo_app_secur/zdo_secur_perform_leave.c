/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_secur.o -> zdo_secur_perform_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

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

