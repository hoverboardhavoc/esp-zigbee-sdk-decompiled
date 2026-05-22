/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app.o -> zdo_dev_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_dev_start(_Bool autostart)

{
  ezb_err_t eVar1;
  undefined3 in_register_00002029;
  int iVar2;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  iVar2 = core_globals_get();
  if ((*(byte *)(iVar2 + 0xcf4) & 1) == 0) {
    eVar1 = zdo_dev_init();
    if (eVar1 == 0) {
      iVar2 = core_globals_get();
      *(byte *)(iVar2 + 0xcf4) = *(byte *)(iVar2 + 0xcf4) | 1;
      if (CONCAT31(in_register_00002029,autostart) == 0) {
        uStack_20 = 0;
        uStack_1c = 0;
        uStack_18 = 0;
        uStack_14 = 0;
        uStack_24 = 1;
        zdo_app_put_signal(&uStack_24);
      }
      else {
        eVar1 = zdo_dev_start_continue();
      }
    }
  }
  else {
    eVar1 = 0;
  }
  return eVar1;
}

