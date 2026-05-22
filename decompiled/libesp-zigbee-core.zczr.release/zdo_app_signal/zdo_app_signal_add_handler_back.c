/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_signal.o -> zdo_app_signal_add_handler_back
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_app_signal_add_handler_back(zdo_app_signal_handler_t handler)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (handler != (zdo_app_signal_handler_t)0x0) {
    iVar2 = core_globals_get();
    bVar1 = 2 < *(byte *)(iVar2 + 0xcbc);
    if (!bVar1) {
      iVar2 = core_globals_get();
      iVar3 = core_globals_get();
      *(zdo_app_signal_handler_t *)(iVar2 + (*(byte *)(iVar3 + 0xcbc) + 0x328) * 4 + 0x10) = handler
      ;
      iVar2 = core_globals_get();
      *(char *)(iVar2 + 0xcbc) = *(char *)(iVar2 + 0xcbc) + '\x01';
    }
    return (uint)bVar1;
  }
  return 2;
}

