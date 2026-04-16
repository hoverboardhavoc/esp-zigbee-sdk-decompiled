/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_app_put_leave_signal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_app_put_leave_signal(ezb_zdo_leave_type_t leave_type)

{
  ezb_zdo_leave_type_t *peVar1;
  undefined4 uStack_24;
  zdo_app_signal_t signal;
  
  signal.signal = 0;
  signal.parameters[0] = '\0';
  signal.parameters[1] = '\0';
  signal.parameters[2] = '\0';
  signal.parameters[3] = '\0';
  signal.parameters[4] = '\0';
  signal.parameters[5] = '\0';
  signal.parameters[6] = '\0';
  signal.parameters[7] = '\0';
  signal.parameters[8] = '\0';
  signal.parameters[9] = '\0';
  signal.parameters[10] = '\0';
  signal.parameters[0xb] = '\0';
  uStack_24 = 3;
  peVar1 = (ezb_zdo_leave_type_t *)zdo_app_signal_get_params(&uStack_24);
  *peVar1 = leave_type;
  zdo_app_put_signal(&uStack_24);
  return;
}

