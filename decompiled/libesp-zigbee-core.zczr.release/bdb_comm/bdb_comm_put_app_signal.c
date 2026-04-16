/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_comm_put_app_signal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bdb_comm_put_app_signal(ezb_app_signal_type_t signal,bdb_comm_status_t status)

{
  ezb_app_signal_type_t eStack_24;
  bdb_comm_status_t bStack_22;
  undefined1 uStack_21;
  zdo_app_signal_t app_signal;
  
  memset(&uStack_21,0,0xf);
  eStack_24 = signal;
  bStack_22 = status;
  zdo_app_put_signal(&eStack_24);
  return;
}

