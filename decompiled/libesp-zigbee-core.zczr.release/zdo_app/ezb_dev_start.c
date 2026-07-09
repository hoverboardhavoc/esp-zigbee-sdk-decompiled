/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app.o -> ezb_dev_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_dev_start(int param_1)

{
  int iVar1;
  undefined2 uStack_24;
  undefined1 auStack_22 [22];
  
  iVar1 = core_globals_get();
  if ((*(byte *)(iVar1 + 0xcf4) & 1) == 0) {
    ds_restore_common_data();
    aps_bind_table_restore();
    aps_group_table_restore();
    aps_secur_key_pair_set_restore();
    iVar1 = core_globals_get();
    *(byte *)(iVar1 + 0xcf4) = *(byte *)(iVar1 + 0xcf4) | 1;
    if (param_1 == 0) {
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

