/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_core.o -> zdo_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_init(void)

{
  int iVar1;
  ezb_err_t eVar2;
  
  zdo_comm_init();
  zdo_secur_init();
  iVar1 = zdo_management_init();
  eVar2 = -1;
  if (iVar1 == 0) {
    iVar1 = zdo_packet_scheduler_init();
    eVar2 = -(uint)(iVar1 != 0);
  }
  return eVar2;
}

