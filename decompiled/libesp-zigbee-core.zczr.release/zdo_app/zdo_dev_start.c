/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app.o -> zdo_dev_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_dev_start(_Bool autostart)

{
  undefined3 in_register_00002029;
  int iVar1;
  undefined2 uStack_24;
  undefined1 auStack_22 [22];
  
  iVar1 = core_globals_get();
  if ((*(byte *)(iVar1 + 0xd58) & 1) == 0) {
    ds_restore_common_data();
    aps_bind_table_restore();
    aps_group_table_restore();
    aps_secur_key_pair_set_restore();
    iVar1 = core_globals_get();
    *(byte *)(iVar1 + 0xd58) = *(byte *)(iVar1 + 0xd58) | 1;
    if (CONCAT31(in_register_00002029,autostart) == 0) {
      memset(auStack_22,0,0x10);
      uStack_24 = 1;
      zdo_app_put_signal(&uStack_24);
    }
    else {
      zdo_commissioning_start();
    }
  }
  return 0;
}

