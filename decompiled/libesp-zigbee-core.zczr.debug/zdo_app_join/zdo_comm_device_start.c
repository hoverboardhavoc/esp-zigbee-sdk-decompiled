/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_device_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_comm_device_start(void)

{
  int iVar1;
  int iVar2;
  undefined2 uStack_14;
  undefined1 uStack_12;
  
  ds_save_common_data();
  iVar1 = nwk_is_device_zczr();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    uStack_14 = 0;
    uStack_12 = 0;
    iVar1 = nwk_start_router(&uStack_14);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = nwk_permit_joining(0);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  iVar2 = nwk_is_device_zed();
  if ((iVar2 == 0) || (iVar1 = nwk_start_end_device(), iVar1 == 0)) {
    iVar2 = core_globals_get();
    tasklet_post(iVar2 + 0xd28);
  }
  return iVar1;
}

