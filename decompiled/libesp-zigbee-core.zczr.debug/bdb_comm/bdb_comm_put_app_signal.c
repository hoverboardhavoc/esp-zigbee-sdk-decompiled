/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_put_app_signal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bdb_comm_put_app_signal(ezb_app_signal_type_t signal,bdb_comm_status_t status)

{
  undefined4 uStack_24;
  zdo_app_signal_t app_signal;
  
  app_signal.signal = 0;
  app_signal.parameters[0] = '\0';
  app_signal.parameters[1] = '\0';
  app_signal.parameters[2] = '\0';
  app_signal.parameters[3] = '\0';
  app_signal.parameters[4] = '\0';
  app_signal.parameters[5] = '\0';
  app_signal.parameters[6] = '\0';
  app_signal.parameters[7] = '\0';
  app_signal.parameters[8] = '\0';
  app_signal.parameters[9] = '\0';
  app_signal.parameters[10] = '\0';
  app_signal.parameters[0xb] = '\0';
  uStack_24 = (uint)CONCAT12(status,signal);
  zdo_app_put_signal(&uStack_24);
  return;
}

