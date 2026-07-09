/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> bdb_touchlink.o -> touchlink_zdo_leave_network
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_zdo_leave_network(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  code *pcStack_18;
  undefined4 uStack_14;
  
  pcStack_18 = (code *)0x0;
  uStack_14 = 0;
  iVar1 = zdo_create_mgmt_req(0x34);
  if (iVar1 == 0) {
    uVar4 = 3;
  }
  else {
    puVar2 = (undefined1 *)zdo_mgmt_req_get_param();
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    iVar3 = zdo_mgmt_req_get_param(iVar1);
    *(byte *)(iVar3 + 8) = *(byte *)(iVar3 + 8) & 0xfd;
    iVar3 = zdo_mgmt_req_get_param(iVar1);
    *(byte *)(iVar3 + 8) = *(byte *)(iVar3 + 8) & 0xfe;
    pcStack_18 = touchlink_zdo_leave_cb;
    uStack_14 = param_1;
    zdo_mgmt_req_set_user_ctx(iVar1,&pcStack_18);
    zdo_send_mgmt_req(iVar1,0);
    uVar4 = 0;
  }
  return uVar4;
}

