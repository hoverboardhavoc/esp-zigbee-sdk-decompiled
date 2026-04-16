/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_zdo_leave_network
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_zdo_leave_network(void *arg)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  ezb_err_t eVar4;
  code *pcStack_18;
  zdo_mgmt_req_user_ctx_t user_ctx;
  
  pcStack_18 = (code *)0x0;
  user_ctx.cb = (zdo_mgmt_user_callback_t)0x0;
  iVar1 = zdo_create_mgmt_req(0x34);
  if (iVar1 == 0) {
    eVar4 = 3;
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
    user_ctx.cb = (zdo_mgmt_user_callback_t)arg;
    zdo_mgmt_req_set_user_ctx(iVar1,&pcStack_18);
    zdo_send_mgmt_req(iVar1,0);
    eVar4 = 0;
  }
  return eVar4;
}

