/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  if ((*(byte *)(iVar1 + 0xcf4) & 1) == 0) {
    ds_restore_common_data();
    aps_bind_table_restore();
    aps_group_table_restore();
    aps_secur_key_pair_set_restore();
    iVar1 = core_globals_get();
    *(byte *)(iVar1 + 0xcf4) = *(byte *)(iVar1 + 0xcf4) | 1;
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

