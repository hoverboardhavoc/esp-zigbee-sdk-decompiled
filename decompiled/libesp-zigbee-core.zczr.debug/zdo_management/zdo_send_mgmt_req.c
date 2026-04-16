/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_send_mgmt_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_send_mgmt_req(zdo_mgmt_req_handle_t handle,_Bool is_sync)

{
  int iVar1;
  ezb_err_t eVar2;
  undefined3 in_register_0000202d;
  int *piVar3;
  
  if (handle == (zdo_mgmt_req_handle_t)0x0) {
    eVar2 = 2;
  }
  else {
    iVar1 = core_globals_get();
    piVar3 = (int *)(iVar1 + 0xd44);
    iVar1 = *piVar3;
    while (iVar1 != 0) {
      piVar3 = (int *)*piVar3;
      iVar1 = *piVar3;
    }
    *(undefined4 *)((int)handle + 4) = 0;
    *piVar3 = (int)handle + 4;
    if (CONCAT31(in_register_0000202d,is_sync) == 0) {
      iVar1 = core_globals_get();
      tasklet_post(iVar1 + 0xd48);
      eVar2 = 0;
    }
    else {
      zdo_mgmt_task(handle);
      eVar2 = 0;
    }
  }
  return eVar2;
}

