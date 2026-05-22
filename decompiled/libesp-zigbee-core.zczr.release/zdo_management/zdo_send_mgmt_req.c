/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_management.o -> zdo_send_mgmt_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_send_mgmt_req(zdo_mgmt_req_handle_t handle,_Bool is_sync)

{
  int iVar1;
  undefined3 in_register_0000202d;
  int *piVar2;
  
  if (handle != (zdo_mgmt_req_handle_t)0x0) {
    iVar1 = core_globals_get();
    piVar2 = (int *)(iVar1 + 0xce0);
    iVar1 = *(int *)(iVar1 + 0xce0);
    while (iVar1 != 0) {
      piVar2 = (int *)*piVar2;
      iVar1 = *piVar2;
    }
    *(undefined4 *)((int)handle + 4) = 0;
    *piVar2 = (int)handle + 4;
    if (CONCAT31(in_register_0000202d,is_sync) == 0) {
      iVar1 = core_globals_get();
      tasklet_post(iVar1 + 0xce4);
    }
    else {
      zdo_mgmt_task(handle);
    }
    return 0;
  }
  return 2;
}

