/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> test_utils.o -> ezb_nwk_concentrator_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_nwk_concentrator_start(uint8_t radius,uint8_t disc_sp_time,uint8_t disc_time)

{
  int iVar1;
  ezb_err_t eVar2;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  
  if (CONCAT31(in_register_0000202d,disc_sp_time) <= CONCAT31(in_register_00002031,disc_time)) {
    iVar1 = core_globals_get();
    *(uint8_t *)(iVar1 + 0x9f9) = radius;
    iVar1 = core_globals_get();
    *(uint8_t *)(iVar1 + 0x9fb) = disc_sp_time;
    iVar1 = core_globals_get();
    *(uint8_t *)(iVar1 + 0x9fa) = disc_time;
    eVar2 = nwk_concentrator_start();
    return eVar2;
  }
  return 2;
}

