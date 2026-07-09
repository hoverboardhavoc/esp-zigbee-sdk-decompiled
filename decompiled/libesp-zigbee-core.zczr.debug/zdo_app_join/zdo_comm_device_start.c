/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_device_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_comm_device_start(void)

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
    tasklet_post(iVar2 + 0xcc4);
  }
  return iVar1;
}

