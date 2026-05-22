/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_signal.o -> zdo_app_signal_add_handler_back
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_app_signal_add_handler_back(zdo_app_signal_handler_t handler)

{
  int iVar1;
  ezb_err_t eVar2;
  int iVar3;
  
  if (handler == (zdo_app_signal_handler_t)0x0) {
    eVar2 = 2;
  }
  else {
    iVar1 = core_globals_get();
    if (*(byte *)(iVar1 + 0xcbc) < 3) {
      iVar1 = core_globals_get();
      iVar3 = core_globals_get();
      *(zdo_app_signal_handler_t *)(iVar1 + (*(byte *)(iVar3 + 0xcbc) + 0x328) * 4 + 0x10) = handler
      ;
      iVar1 = core_globals_get();
      *(char *)(iVar1 + 0xcbc) = *(char *)(iVar1 + 0xcbc) + '\x01';
      eVar2 = 0;
    }
    else {
      eVar2 = 1;
    }
  }
  return eVar2;
}

