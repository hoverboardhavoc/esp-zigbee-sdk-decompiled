/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_comm_start_top_level_commissioning
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t bdb_comm_start_top_level_commissioning(uint8_t mode_mask)

{
  int iVar1;
  ezb_err_t eVar2;
  
  iVar1 = core_globals_get();
  if ((*(char *)(iVar1 + 0xd4f) == '\0') &&
     (iVar1 = core_globals_get(), *(char *)(iVar1 + 0xd4e) == '\x06')) {
    iVar1 = core_globals_get();
    *(uint8_t *)(iVar1 + 0xd4f) = mode_mask;
    iVar1 = zdo_dev_joined();
    if (iVar1 != 0) {
      iVar1 = core_globals_get();
      tasklet_post(iVar1 + 0xd3c);
      return 0;
    }
    eVar2 = zdo_dev_start_continue();
    return eVar2;
  }
  return 9;
}

