/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac_proxy.o -> nwk_mm_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_mm_data_confirm(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = nwk_mm_iface_is_enabled();
  if (iVar1 != 0) {
    nwk_fwd_handle_data_confirm(param_1,param_2);
    return;
  }
  log_write(2,"nwk_multimac_proxy.c","MCPS-DATA.confirm from disabled iface[%d]");
  if ((param_2 != (int *)0x0) && (*param_2 != 0)) {
    zmsg_free();
    return;
  }
  return;
}

